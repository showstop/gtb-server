#ifndef __TR_DB_CONNECTION__
#define __TR_DB_CONNECTION__

#if defined(WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include <string>
#include <sqlext.h>
#include <sqltypes.h>
#include <boost/scoped_ptr.hpp>

namespace db {

	class prepared_statement;
	class connection 
	{
	public:
		connection();
		virtual ~connection();

		bool connect(const std::string& conn_str);
		void disconnect();

		bool prepare(const std::string& query, boost::scoped_ptr<prepared_statement>& pstmt);
		bool execute(const boost::scoped_ptr<prepared_statement>& pstmt);

		bool check_connect();

		bool begin_transaction();
		bool commit();
		bool rollback();

		void wait_for_output_param(const boost::scoped_ptr<prepared_statement>& pstmt);
		bool push_for_save_blob(const boost::scoped_ptr<prepared_statement>& pstmt);

		bool change_db(const std::string& db_name);

		const std::string& get_err_str() const;
	private:
		bool set_auto_commit(bool isAutoCommit);
		bool handle_error(SQLSMALLINT nHandleType,SQLHANDLE hHandle, std::string& err);

		void query_for_connection();
	private:
		struct impl;
		impl* pimpl_;

		friend class connection_pool;
	};

}


#endif