#ifndef __TR_DB_ODBC__
#define __TR_DB_ODBC__

#if defined(WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include <xNet/sb_define.h>
#include <string>
#include <sqlext.h>
#include <sqltypes.h>
#include <boost/scoped_ptr.hpp>

namespace db 
{
	const int DEFAULT_BUFFER_LEN = 8192;

	class prepared_statement
	{
		friend class connection;
	public:
		prepared_statement(SQLHSTMT stmt);
		virtual ~prepared_statement();

		SQLHSTMT get_stmt() const;
		void close();
		bool fetch();

		int get_int(int idx) const;
		int64 get_int64(int idx) const;
		float get_float(int idx) const;
		double get_double(int idx) const;
		std::string get_string(int idx) const;
		std::string get_wstring(int idx) const;

		std::string get_large_string(int idx, int len) const;
		bool get_blob(int idx, void* data, int len) const;

		void set_int(int idx, const int value);
		void set_int64(int idx, const int64 value);
		void set_float(int idx, const float value);
		void set_double(int idx, const double value);
		void set_string(int idx, const std::string& value);
		void set_wstring(int idx, const std::wstring& value);

		void set_blob(int idx, void* data, int size);

		void set_int_output(int idx, int& value);
		void set_int64_output(int idx, int64& value);
		void set_float_output(int idx, float& value);
		void set_double_output(int idx, double& value);
		void set_wstring_output(int idx, wchar_t* value, int size);
		void set_string_output(int idx, char* value, int size);

		const char* get_error_str() const;
	private:
		void set_error_str(const std::string& str);
		void get_blob_data(void*& data, int& size) const;
	private:
		struct impl;
		impl* pimpl_;

	};

	typedef boost::scoped_ptr<prepared_statement> prepared_statement_ptr;

	class connection_pool
	{
	public:
		connection_pool();
		virtual ~connection_pool();

		bool prepare(const std::string& query, prepared_statement_ptr& pstmt);
		bool execute(const prepared_statement_ptr& pstmt);

		bool begin_transaction();
		bool commit();
		bool rollback();

		void wait_for_output_param(const prepared_statement_ptr& pstmt);
		bool push_for_save_blob(const prepared_statement_ptr& pstmt);

		bool change_db(const std::string& db_name);

		static bool init_pool(int pool_size, const char* conn_str, char* err);
		static void uninit_pool();
	private:
		struct impl;
		impl* pimpl_;
	};
}


#endif
