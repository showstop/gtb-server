#ifndef __K_CONFIG__
#define __K_CONFIG__

#include <util/IniFileConfig.h>
#include <util/file_path_finder.h>

namespace env {

	namespace config
	{
		struct sys_info
		{
			std::string name;
			int auth_proc_thread_count;
			int16 server_version;

			std::string log_server_ip;
			uint16 log_server_port;
		};

		struct db_info
		{
			std::string game_conn_str;
		};

		struct xNet_info
		{
			std::string group_name;
		};

		struct gc_info
		{
			bool no_delay;
			int deactivated_link_dead_time;
			int session_expired_time;
			int net_thread_count;
			int working_thread_count;
		};

		class configurator
		{
		private:
			configurator()
			{
			}
			~configurator()
			{
				ini_.Close();
			}
		private:
			void load_sys_info()
			{
				ini_.SelectSection("System");
				sys_config_.name = ini_.GetStringValue("Name", "");
				sys_config_.auth_proc_thread_count = ini_.GetInt32Value("AuthProcThreadCount", 2);
				sys_config_.server_version = ini_.GetInt16Value("ServerVersion", 0);
				sys_config_.log_server_ip = ini_.GetStringValue("LogServerIP", "");
				sys_config_.log_server_port = ini_.GetInt16Value("LogServerPort", 0);

			}
			void load_db_info()
			{
				ini_.SelectSection("DB");
				db_config_.game_conn_str = ini_.GetStringValue("GameDBConnStr", "");
			}
			
			void load_gc_info()
			{
				ini_.SelectSection("GameClient");
				gc_config_.no_delay = ini_.GetBoolValue("NoDelay", true);
				gc_config_.deactivated_link_dead_time = ini_.GetInt32Value("DeactivateLinkDeadTime", 2) * 1000;
				gc_config_.session_expired_time = ini_.GetInt32Value("SessionExpiredTime", 5) * 1000;
				gc_config_.net_thread_count = ini_.GetInt32Value("NetworkThreadCount", 3);
				gc_config_.working_thread_count = ini_.GetInt32Value("WorkingThreadCount", 4);
			}

		public:
			static configurator& instance()
			{
				static configurator t;
				return t;
			}

			bool load_ini(const std::string& path)
			{
				if (false == ini_.Open(helper::GetAbsPathName(path).c_str()))
					return false;
				reload();
				return true;
			}
			void reload()
			{
				load_sys_info();
				load_db_info();
				load_gc_info();
			}

			const sys_info& get_sys_info() const
			{
				return sys_config_;
			}

			const db_info& get_db_info() const
			{
				return db_config_;
			}

			const gc_info& get_gc_info() const
			{
				return gc_config_;
			}

		private:
			mutable sys_info sys_config_;
			mutable db_info db_config_;
			mutable gc_info gc_config_;

			mutable IniFileConfig ini_;
		};
	}
}
typedef env::config::configurator configurator;

#endif