#ifndef __K_SB_HELPER_UTIL__
#define __K_SB_HELPER_UTIL__

#include <sstream>
#include <boost/lexical_cast.hpp>
#include <json/json.h>
#include <xNet/link_base.h>
//#pragma comment(lib, "version.lib")

namespace helper
{
	template <class T>
	static std::map<T, int32> prop_json2map(const std::string& info)
	{
		std::map<T, int32> ret;

		Json::Reader reader;
		Json::Value root;
		if (false == reader.parse(info, root))
			return ret;

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto key = static_cast<T>(boost::lexical_cast<int32>(std::string(it.memberName())));
			auto val = (*it).asInt();
			ret.insert(std::make_pair(key, val));
		}
		return ret;
	}

	template <class T>
	static std::string prop_map2json(std::map<T, int32>& info)
	{
		Json::FastWriter writer;
		Json::Value root;

		for (auto it = info.begin(); it != info.end(); ++it)
		{
			std::ostringstream os;
			os << it->first;
			root[os.str()] = it->second;
		}

		return writer.write(root);
	}

	template <class T>
	static std::vector<T> prop_json2vector(const std::string& info)
	{
		std::vector<T> ret;

		Json::Reader reader;
		Json::Value root;
		if (false == reader.parse(info, root))
			return ret;

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			ret.push_back((*it).asInt());
		}
		return ret;
	}

	template <class T>
	static std::string prop_vector2json(std::vector<T>& info)
	{
		Json::FastWriter writer;
		Json::Value root;

		std::ostringstream os;
		for (auto it = info.begin(); it != info.end(); ++it)
		{
			root.append(Json::Value((*it)));
		}

		return writer.write(root);
	}

	static SpringCat::System::Stream dr2stream(const SpringCat::Wave::object_base& msg)
	{
		SpringCat::System::Stream ret;
		msg.serialize(ret);
		return ret;
	}

	static bool load_dr(SpringCat::System::SmartHeap::Block blob, SpringCat::Wave::object_base& msg)
	{
		SpringCat::System::Stream s;
		s.Attach(blob);
		return msg.deserialize(s);
	}

	static void dr2array(const SpringCat::Wave::object_base& msg, std::vector<int8>& arr)
	{
		SpringCat::System::Stream stream;
		msg.serialize(stream);
		arr.assign(stream.GetLength(), 0x00);
		memcpy(&arr[0], stream.GetRawPtr(), stream.GetLength());
	}

	static void array2dr(const std::vector<int8>& arr, SpringCat::Wave::object_base& msg)
	{
		SpringCat::System::Stream stream;
		stream.Write(&arr[0], arr.size());
		msg.deserialize(stream);
	}

	static std::string get_remote_address(network::link_ptr_t link)
	{
		if(!link.get())	return " ";

		SpringCat::Network::Endpoint remote_endpoint(BaseCat::Network::Link::GetRemoteEndpoint(link->get_raw_link_ptr()));
		std::ostringstream os;
		os << remote_endpoint.GetIPAddress() << ":" << remote_endpoint.GetPort();
		return os.str();
	}

	static std::string get_remote_ip(network::link_ptr_t link)
	{
		if(!link.get())	return "";

		SpringCat::Network::Endpoint remote_endpoint(BaseCat::Network::Link::GetRemoteEndpoint(link->get_raw_link_ptr()));
		return remote_endpoint.GetIPAddress();
	}

	static uint16 get_remote_port(network::link_ptr_t link)
	{
		if(!link.get())	return 0;

		SpringCat::Network::Endpoint remote_endpoint(BaseCat::Network::Link::GetRemoteEndpoint(link->get_raw_link_ptr()));
		return remote_endpoint.GetPort();
	}

	static std::string convert_ip(uint32 ip)
	{
		struct sockaddr_in sa;
		sa.sin_addr.s_addr = ip;
		return inet_ntoa(sa.sin_addr);
	}

	static uint32 convert_ip(const std::string& ip)
	{
		return inet_addr(ip.c_str());
	}

	static float refine_float(float d)
	{
		return static_cast<float>(floor((d * pow(10, 2) + 0.5)) / pow(10, 2));
	}
}

#endif