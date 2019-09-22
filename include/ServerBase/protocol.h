#ifndef __K_SB_PROTOCOL__
#define __K_SB_PROTOCOL__

#include <BaseCat/System.h>

namespace protocol {

	const unsigned short PROTOCOL_VERSION_1 = 0x10;

	// header 14 bytes
#pragma pack(push, 1)
	struct packet_header
	{
		packet_header()
			: version(PROTOCOL_VERSION_1), session_id(0), msgid(0), length(0) {}

		unsigned char version;	// protocol ver
		unsigned char flag;		// flag
		int session_id;	// session_id
		int msgid;		// payload msg id
		int length;		// total length
	};
#pragma pack(pop)

	static void build(int session_id, const unsigned char flag, const SpringCat::Wave::object_base& msg, SpringCat::System::Stream& stream)
	{
		packet_header header;

		header.session_id = session_id;
		header.flag = flag;
		header.msgid = msg.runtime_type_info().id();
		header.length = msg.size() + sizeof(packet_header);

		stream.Write(&header, sizeof(packet_header));
		msg.serialize(stream);
	}

	inline void build(int session_id, const SpringCat::Wave::object_base& msg, SpringCat::System::Stream& stream)
	{
		build(session_id, 0, msg, stream);
	}

	enum ParseRet
	{
		SUCCESS = 0,
		MISMATCH_PROTOCOL_VERSION,
		NEED_MORE_PACKET,
		TOO_LARGE_PACKET,
	};

	const int MAX_PACKET_SIZE = 1024*1024*1024;		//1mb

	static ParseRet parse(BaseCat::System::Stream::Handle stream, int& length)
	{
		size_t total_len = BaseCat::System::Stream::GetLength(stream);
		if(total_len > MAX_PACKET_SIZE)	return TOO_LARGE_PACKET;
		if (total_len >= sizeof(packet_header))
		{
			packet_header header;
			if(sizeof(packet_header) == BaseCat::System::Stream::Peek(stream, &header, sizeof(packet_header)))
			{
				if(PROTOCOL_VERSION_1 != header.version)
					return MISMATCH_PROTOCOL_VERSION;

				if (total_len < static_cast<size_t>(header.length) )
					return NEED_MORE_PACKET;
			}
			length = header.length;
			return SUCCESS;
		}
		return NEED_MORE_PACKET;
	}

	template <typename Stream1T, typename Stream2T>
	bool extract_message(Stream1T& stream_packet, packet_header& header, Stream2T& payload)
	{
		if(false == stream_packet.Read(&header, sizeof(packet_header)))
			return false;

		payload.Attach(stream_packet.Detach());
		return true;
	}
	
}

#endif
