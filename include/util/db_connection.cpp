#include "db_connection.h"
#include "db_odbc.h"
#include <SpringCat/SpringCat.h>
#include <xNet/sb_define.h>
#include "timer_queue.h"

namespace db {

	struct connection::impl
	{
		friend class connection;
		impl()
			: sqlEnv_(NULL), sqlConn_(NULL), connection_check_timer_id_(0)
		{
			
		}
		virtual ~impl()
		{

		}
	private:
		std::string conn_str_;
		std::string err_;

		uint32 connection_check_timer_id_;

		SQLHENV sqlEnv_;
		SQLHDBC sqlConn_;
		BaseCat::System::Threading::CriticalSection csQuery_;
	};

	inline bool check_returncode(SQLRETURN return_code)
	{
		return ((return_code != SQL_SUCCESS) && (return_code != SQL_SUCCESS_WITH_INFO) && (return_code != SQL_NEED_DATA));
	}

	static void on_connection_check(uint32 timer_id, void* context)
	{
		connection* conn = static_cast<connection*>(context);
		conn->check_connect();
	}

	connection::connection()
		: pimpl_(new impl)
	{
		ScopedLock lock(pimpl_->csQuery_);

		std::string err;
		SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &pimpl_->sqlEnv_);
		if(check_returncode(ret))
		{
			handle_error(SQL_HANDLE_ENV, pimpl_->sqlEnv_, err);
		}
		ret = SQLSetEnvAttr(pimpl_->sqlEnv_, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, SQL_IS_INTEGER);
		if (check_returncode(ret))
		{
			handle_error(SQL_HANDLE_ENV, pimpl_->sqlEnv_, err);
		}
		//	std::locale::global(std::locale(""));
	}

	connection::~connection()
	{
		disconnect();
		pimpl_->csQuery_.Lock();

		if (pimpl_->sqlConn_ != NULL) 
		{
			SQLFreeHandle(SQL_HANDLE_DBC, pimpl_->sqlConn_);
			pimpl_->sqlConn_ = NULL;
		}
		if (pimpl_->sqlEnv_ != NULL)
		{
			SQLFreeHandle(SQL_HANDLE_ENV, pimpl_->sqlEnv_);
			pimpl_->sqlEnv_ = NULL;
		}
		pimpl_->csQuery_.Unlock();
		delete pimpl_;
		pimpl_ = NULL;
	}

	bool connection::handle_error(SQLSMALLINT nHandleType,SQLHANDLE hHandle, std::string& err)
	{
		unsigned char szSqlState[6] = {0, };
		unsigned char szMessageText[512] = {0, };
		SQLINTEGER nNativeError = 0;
		SQLSMALLINT nTextLen = 0;

		int i = 1;
		SQLRETURN res = 0;
		while ((res = SQLGetDiagRecA(nHandleType, hHandle, static_cast<SQLUSMALLINT>(i), szSqlState, &nNativeError, szMessageText, 512, &nTextLen)) != SQL_NO_DATA)
		{
			char errorMsgText[512] = {0, };
			sprintf(errorMsgText, "index=[%d], state=[%s], desc=[%s], native=[%d]",i, szSqlState, szMessageText, nNativeError);
			err = errorMsgText;
			if(res == SQL_INVALID_HANDLE)
				break;

			if(++i > 10)
				break;
		}

		return true;
	}

	bool connection::check_connect()
	{
		ScopedLock lock(pimpl_->csQuery_);

		if(NULL == pimpl_->sqlConn_)
		{
			return connect(pimpl_->conn_str_);
		}

		SQLINTEGER value;
		SQLINTEGER cb = 0;
		SQLRETURN ret = SQLGetConnectAttr(pimpl_->sqlConn_, SQL_ATTR_CONNECTION_DEAD, &value, 
			SQL_IS_INTEGER, &cb);

		if(ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO)
			return false;

		if(value == SQL_CD_TRUE)
		{
			disconnect();
			return connect(pimpl_->conn_str_);
		}
		//query_for_connection();
		return true;
	}

	void connection::query_for_connection()
	{
		prepared_statement_ptr pstmt;
		prepare("select 1", pstmt);
		execute(pstmt);
	}

	bool connection::connect(const std::string& conn_str)
	{
		ScopedLock lock(pimpl_->csQuery_);

		pimpl_->conn_str_ = conn_str;

		// Allocate connection handle.
		SQLRETURN nReturn = SQLAllocHandle(SQL_HANDLE_DBC, pimpl_->sqlEnv_, &pimpl_->sqlConn_);
		if (check_returncode(nReturn))
		{
			handle_error(SQL_HANDLE_ENV, pimpl_->sqlEnv_, pimpl_->err_);
			return false;
		}
		
		int16 ret_size = 0;
		char tmp[1024] = {0, };
		nReturn = SQLDriverConnectA(pimpl_->sqlConn_, nullptr, 
			reinterpret_cast<unsigned char *>(const_cast<char *>(pimpl_->conn_str_.c_str())),
			static_cast<int16>(pimpl_->conn_str_.length()),
			reinterpret_cast<unsigned char *>(tmp),
			static_cast<int16>(sizeof(tmp)),
			&ret_size,
			SQL_DRIVER_NOPROMPT);
		
		if (check_returncode(nReturn))
		{   
			handle_error(SQL_HANDLE_DBC, pimpl_->sqlConn_, pimpl_->err_);
			SQLFreeHandle(SQL_HANDLE_DBC, pimpl_->sqlConn_);
			pimpl_->sqlConn_ = NULL;
			return false;
		}
		return true;
	}

	void connection::disconnect()
	{
		ScopedLock lock(pimpl_->csQuery_);

		// Disconnection
		if (pimpl_->sqlConn_ != NULL)
		{
			SQLDisconnect(pimpl_->sqlConn_);
		}
	}

	bool connection::prepare(const std::string& query, prepared_statement_ptr& pstmt)
	{
		ScopedLock lock(pimpl_->csQuery_);

		SQLHSTMT hstmt = NULL;
		SQLAllocHandle(SQL_HANDLE_STMT, pimpl_->sqlConn_, &hstmt);

		SQLRETURN nErrorCode = SQLPrepareA(hstmt, reinterpret_cast<unsigned char *>(const_cast<char *>(query.c_str())), SQL_NTS);

		if(false == check_returncode(nErrorCode))
		{
			pstmt.reset(new prepared_statement(hstmt));
			return true;
		}
		std::string err;
		handle_error(SQL_HANDLE_STMT, hstmt, err);
		pimpl_->err_ = err;
		return false;
	}

	bool connection::execute(const prepared_statement_ptr& pstmt)
	{
		ScopedLock lock(pimpl_->csQuery_);
		SQLHSTMT hstmt = pstmt->get_stmt();
		SQLRETURN nErrorCode = SQLExecute(hstmt);
		if (check_returncode(nErrorCode))
		{
			std::string err;
			if (pimpl_->sqlConn_ != NULL)
			{
				handle_error(SQL_HANDLE_STMT, hstmt, err);
				pstmt->set_error_str(err);
				pimpl_->err_ = err;
			}
			return false;
		}
		return true;
	}

	bool connection::begin_transaction()
	{
		pimpl_->csQuery_.Lock();
		return set_auto_commit(false);
	}

	bool connection::commit()
	{
		SQLRETURN nReturn = SQLEndTran(SQL_HANDLE_DBC, pimpl_->sqlConn_, SQL_COMMIT);
		if (check_returncode(nReturn))
		{
			handle_error(SQL_HANDLE_DBC, pimpl_->sqlConn_, pimpl_->err_);
			pimpl_->csQuery_.Unlock();
			return false;
		}
		set_auto_commit(true);
		pimpl_->csQuery_.Unlock();
		return true;
	}

	bool connection::rollback()
	{
		SQLRETURN nReturn = SQLEndTran(SQL_HANDLE_DBC, pimpl_->sqlConn_, SQL_ROLLBACK);
		if (check_returncode(nReturn))
		{
			handle_error(SQL_HANDLE_DBC, pimpl_->sqlConn_, pimpl_->err_);
			set_auto_commit(true);
			pimpl_->csQuery_.Unlock();
			return false;
		}
		set_auto_commit(true);
		pimpl_->csQuery_.Unlock();
		return true;
	}

	void connection::wait_for_output_param(const prepared_statement_ptr& pstmt)
	{
		while ( SQLMoreResults(pstmt->get_stmt())  != SQL_NO_DATA );
	}

	bool connection::push_for_save_blob(const prepared_statement_ptr& p)
	{
		PTR param_id = NULL;
		SQLRETURN ret = 0;
		prepared_statement* pstmt(p.get());
		while(SQL_NEED_DATA == (ret = SQLParamData(pstmt->get_stmt(), &param_id)))
		{
			int blob_size = 0;
			void* blobs = NULL;
			pstmt->get_blob_data(blobs, blob_size);
			if(blobs == NULL || blob_size == 0)	return false;

			int unit_size = 1024;
			int offset = 0;
			while(blob_size > unit_size)
			{
				ret = SQLPutData(pstmt->get_stmt(), static_cast<char*>(blobs) + offset, unit_size);
				blob_size -= unit_size;
				offset += unit_size;
			}
			ret = SQLPutData(pstmt->get_stmt(), static_cast<char*>(blobs) + offset, blob_size);
		}

		if (pimpl_->sqlConn_ != NULL)
		{
			handle_error(SQL_HANDLE_STMT, pstmt->get_stmt(), pimpl_->err_);
			pstmt->set_error_str(pimpl_->err_);
			if(!pimpl_->err_.empty())
				return false;
		}
		return true;
	}

	bool connection::set_auto_commit(bool isAutoCommit)
	{
		SQLRETURN nReturn = 0;

		if (isAutoCommit) 	
			nReturn = SQLSetConnectAttr(pimpl_->sqlConn_, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)SQL_AUTOCOMMIT_ON, 0);
		else 
			nReturn = SQLSetConnectAttr(pimpl_->sqlConn_, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)SQL_AUTOCOMMIT_OFF, 0);
		if (check_returncode(nReturn))
		{
			handle_error(SQL_HANDLE_DBC, pimpl_->sqlConn_, pimpl_->err_);
			return false;
		}
		return true;
	}

	bool connection::change_db(const std::string& db_name)
	{
		ScopedLock lock(pimpl_->csQuery_);

		SQLHSTMT hstmt = NULL;
		SQLAllocHandle(SQL_HANDLE_STMT, pimpl_->sqlConn_, &hstmt);
		
		std::string query = "USE " + db_name;
		SQLPrepareA(hstmt, reinterpret_cast<unsigned char *>(const_cast<char *>(query.c_str())), SQL_NTS);
		if(check_returncode(SQLExecute(hstmt)))
			return false;
		return true;
	}

	const std::string& connection::get_err_str() const
	{
		return pimpl_->err_;
	}


}