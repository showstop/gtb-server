#include "db_odbc.h"
#include "db_connection.h"
#include <ctime>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "string_util.h"
#include <xNet/sb_define.h>

namespace db
{
	struct value_store
	{
		value_store(int i)
			: i32_(i) {}
		value_store(int64 i)
			: i64_(i) {}
		value_store(double d) 
			: d_(d) {}
		value_store(float f)
			: f_(f) {}
		value_store(const std::string& s)
			: s_(s) {}
		value_store(const std::wstring& ws)
			: ws_(ws) {}
		virtual ~value_store() {}

		int i32_;
		int64 i64_;
		double d_;
		float f_;
		std::string s_;
		std::wstring ws_;
	};
	typedef boost::shared_ptr<value_store> value_store_ptr_t;

	struct prepared_statement::impl
	{
		friend class prepared_statement;
		impl(SQLHSTMT stmt)
			: stmt_(stmt), blob_ind_(0), blob_size_(0), blob_(NULL)
		{

		}
		virtual ~impl()
		{
			guard_.clear();
		}
	private:
		// for blob
		SQLLEN blob_ind_;
		int blob_size_;
		void* blob_;
	private:
		std::string query_;
		std::string errorStr_;
		volatile SQLHSTMT stmt_;
		std::vector<value_store_ptr_t> guard_;
	};
	inline bool check_returncode(SQLRETURN return_code)
	{
		return ((return_code != SQL_SUCCESS) && (return_code != SQL_SUCCESS_WITH_INFO));
	}

	prepared_statement::prepared_statement(SQLHSTMT stmt)
		: pimpl_(new impl(stmt))
	{

	}

	prepared_statement::~prepared_statement()
	{
		close();
		delete pimpl_;
		pimpl_ = NULL;
	}

	void prepared_statement::close()
	{
		SQLFreeHandle(SQL_HANDLE_STMT, pimpl_->stmt_);
		pimpl_->stmt_ = NULL;
	}

	bool prepared_statement::fetch(void)
	{
		if (pimpl_->stmt_ == NULL) return false;

		SQLRETURN ret = SQLFetch(pimpl_->stmt_);
		if (ret == SQL_NO_DATA) return false;
		if (check_returncode(ret))
		{
			return false;
		}
		return true;
	}

	int prepared_statement::get_int(int idx) const
	{
		int ret = 0;
		SQLLEN num = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_LONG, &ret, sizeof(ret), &num);

		if (check_returncode(errorCode))
			return ret;

		return ret;
	}

	int64 prepared_statement::get_int64(int idx) const
	{
		int64 ret = 0;
		SQLLEN num = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_SBIGINT, &ret, sizeof(ret), &num);

		if (check_returncode(errorCode))
		{
			return ret;
		}
		return ret;
	}

	float prepared_statement::get_float(int idx) const
	{
		float ret = 0.0f;
		SQLLEN num = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_FLOAT, &ret, sizeof(ret), &num);

		if (check_returncode(errorCode))
		{
			return ret;
		}
		return ret;
	}

	double prepared_statement::get_double(int idx) const
	{
		double ret = 0.0;
		SQLLEN num = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_DOUBLE, &ret, sizeof(ret), &num);

		if (check_returncode(errorCode))
		{
			return ret;
		}
		return ret;
	}

	std::string prepared_statement::get_string(int idx) const
	{
		char buff[DEFAULT_BUFFER_LEN] = { 0, };
		SQLLEN cbString = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_CHAR, buff, sizeof(buff), &cbString);
		if (check_returncode(errorCode))
		{
			return std::string(buff);
		}
		return std::string(buff);
	}

	std::string prepared_statement::get_wstring(int idx) const
	{
		wchar_t buff[DEFAULT_BUFFER_LEN] = { 0, };
		SQLLEN cbString = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_WCHAR, buff, sizeof(buff), &cbString);
		if (check_returncode(errorCode))
		{
			return util::wcs_to_mbs(std::wstring(buff));
		}
		return util::wcs_to_mbs(std::wstring(buff));
	}

	std::string prepared_statement::get_large_string(int idx, int len) const
	{
		if (len < DEFAULT_BUFFER_LEN)
		{
			return get_string(idx);
		}

		char* buff = (char*)malloc(len);
		memset(buff, 0x00, len);

		std::string ret;
		SQLLEN cbString = SQL_NTS;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_CHAR, buff, len, &cbString);
		
		ret = std::string(buff);
		free(buff);

		return ret;
	}

	bool prepared_statement::get_blob(int idx, void* data, int len) const
	{
		wchar_t buff[1024] = {0, };
		SQLLEN blob_size = 0;
		SQLRETURN errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_BINARY, data, 0, &blob_size);
		if(errorCode == SQL_SUCCESS_WITH_INFO)
		{
			errorCode = SQLGetData(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_C_DEFAULT, data, blob_size, &blob_size);
			if (check_returncode(errorCode))
			{
				return false;
			}
		}
		return true;
	}

	void prepared_statement::set_int(int idx, const int value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_INTEGER,
			SQL_INTEGER, 0, 0, (SQLPOINTER)&p->i32_, 0, NULL);
	}

	void prepared_statement::set_int64(int idx, const int64 value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_C_SBIGINT,
			SQL_BIGINT, 0, 0, (SQLPOINTER)&p->i64_, 0, NULL);
	}

	void prepared_statement::set_float(int idx, const float value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_C_FLOAT,
			SQL_REAL, 0, 0, (SQLPOINTER)&p->f_, 0, NULL);
	}

	void prepared_statement::set_double(int idx, const double value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_C_DOUBLE,
			SQL_REAL, 0, 0, (SQLPOINTER)&p->d_, 0, NULL);
	}

	void prepared_statement::set_string(int idx, const std::string& value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		int len = static_cast<int>(p->s_.length());
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_C_CHAR,
			SQL_CHAR, (SQLINTEGER)len, 0, (SQLPOINTER*)p->s_.c_str(), (SQLINTEGER)len, NULL);
	}

	void prepared_statement::set_wstring(int idx, const std::wstring& value)
	{
		value_store_ptr_t p(new value_store(value));
		pimpl_->guard_.push_back(p);

		int len = static_cast<int>(p->ws_.length()) * 2;
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_INPUT, SQL_C_WCHAR,
			SQL_WCHAR, (SQLINTEGER)len, 0, (SQLPOINTER*)p->ws_.c_str(), (SQLINTEGER)len, NULL);
	}

	void prepared_statement::set_int_output(int idx, int& value)
	{
		SQLLEN param = SQL_NTS;
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_INTEGER,
			SQL_INTEGER, 0, 0, (SQLPOINTER)&value, sizeof(SQLINTEGER), &param);
	}

	void prepared_statement::set_int64_output(int idx, int64& value)
	{
		SQLLEN param = SQL_NTS;
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_C_SBIGINT,
			SQL_BIGINT, 0, 0, (SQLPOINTER)&value, sizeof(int64), &param);
	}

	void prepared_statement::set_float_output(int idx, float& value)
	{
		SQLLEN param = SQL_NTS;
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_C_FLOAT,
			SQL_REAL, 0, 0, (SQLPOINTER)&value, sizeof(float), &param);
	}

	void prepared_statement::set_double_output(int idx, double& value)
	{
		SQLLEN param = SQL_NTS;
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_C_DOUBLE,
			SQL_REAL, 0, 0, (SQLPOINTER)&value, sizeof(double), &param);
	}

	void prepared_statement::set_wstring_output(int idx, wchar_t* value, int size)
	{
		SQLLEN param = SQL_NTS;

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_C_WCHAR,
			SQL_WCHAR, (SQLINTEGER)size, 0, (SQLPOINTER*)value, (SQLINTEGER)size, &param);
	}

	void prepared_statement::set_string_output(int idx, char* value, int size)
	{
		SQLLEN param = SQL_NTS;

		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, (SQLUSMALLINT)idx, SQL_PARAM_OUTPUT, SQL_C_CHAR,
			SQL_CHAR, (SQLINTEGER)size, 0, (SQLPOINTER*)value, (SQLINTEGER)size, &param);
	}

	void prepared_statement::set_blob(int idx, void* data, int size)
	{
		SQLRETURN errorCode = SQLBindParameter(pimpl_->stmt_, idx, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_LONGVARBINARY, 
			size, 0, (void*)0, 0, (SQLLEN*)&pimpl_->blob_ind_);
		pimpl_->blob_ind_ = SQL_LEN_DATA_AT_EXEC(0);
		pimpl_->blob_ = data;
		pimpl_->blob_size_ = size;
	}

	SQLHSTMT prepared_statement::get_stmt() const
	{
		return pimpl_->stmt_;
	}

	const char* prepared_statement::get_error_str() const
	{
		return pimpl_->errorStr_.c_str();
	}

	void prepared_statement::set_error_str(const std::string& str)
	{
		pimpl_->errorStr_ = str;
	}

	void prepared_statement::get_blob_data(void*& data, int& size) const
	{
		data = pimpl_->blob_;
		size = pimpl_->blob_size_;
	}
		
	// connection pool
	typedef boost::shared_ptr<connection> connection_ptr;
	struct connection_pool::impl
	{
	private:
		connection_ptr conn_;

	public:
		friend class connection_pool;
		impl()
		{

		}
		virtual ~impl()
		{

		}
	private:
		static bool make_new_connection(connection_ptr& ptr)
		{
			connection_ptr conn(new connection());
			if (conn->connect(conn_str_))
			{
				ptr = conn;
				return true;
			}
			else
			{
				err_ = conn->get_err_str();
				return false;
			}
		}
	private:
		static std::string conn_str_;
		static std::string err_;
	};

	std::string connection_pool::impl::conn_str_;
	std::string connection_pool::impl::err_;


	std::vector<connection_ptr> pool_;
	bool shutdown_pool_ = false;
	BaseCat::System::Threading::CriticalSection pool_lock_;

	connection_pool::connection_pool()
		: pimpl_(new impl)
	{
		ScopedLock lock(pool_lock_);
		if (pool_.empty())
		{
			pimpl_->make_new_connection(pimpl_->conn_);
		}
		else
		{
			pimpl_->conn_ = pool_.back();
			pool_.pop_back();

			pimpl_->conn_->check_connect();
		}
	}

	connection_pool::~connection_pool()
	{
		ScopedLock lock(pool_lock_);
		if(!shutdown_pool_)
			pool_.push_back(pimpl_->conn_);
		delete pimpl_;
		pimpl_ = NULL;
	}

	bool connection_pool::execute(const prepared_statement_ptr& pstmt)
	{
		return pimpl_->conn_->execute(pstmt);
	}

	bool connection_pool::prepare(const std::string& query, prepared_statement_ptr& pstmt)
	{
		return pimpl_->conn_->prepare(query, pstmt);
	}

	bool connection_pool::begin_transaction()
	{
		return pimpl_->conn_->begin_transaction();
	}

	bool connection_pool::commit()
	{
		return pimpl_->conn_->commit();
	}

	bool connection_pool::rollback()
	{
		return pimpl_->conn_->rollback();
	}

	void connection_pool::wait_for_output_param(const prepared_statement_ptr& pstmt)
	{
		return pimpl_->conn_->wait_for_output_param(pstmt);
	}

	bool connection_pool::push_for_save_blob(const prepared_statement_ptr& pstmt)
	{
		return pimpl_->conn_->push_for_save_blob(pstmt);
	}

	bool connection_pool::change_db(const std::string& db_name)
	{
		return pimpl_->conn_->change_db(db_name);
	}

	bool connection_pool::init_pool(int pool_size, const char* conn_str, char* err)
	{
		impl::conn_str_ = conn_str;
		for (int idx = 0; idx < pool_size; ++idx)
		{
			connection_ptr conn;
			if (impl::make_new_connection(conn))
			{
				pool_.push_back(conn);
			}
			else
			{
				if(err)
					strcpy(err, impl::err_.c_str());
				return false;
			}
		}
		return true;
	}

	void connection_pool::uninit_pool()
	{
		ScopedLock lock(pool_lock_);
		shutdown_pool_ = true;
		pool_.clear();
	}
}
