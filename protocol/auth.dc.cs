// Generated by the DRCat compiler. DO NOT EDIT!

using System.Collections.Generic;
using System.IO;
using System;


namespace protocol
{

    // ================================================================================================

    public class session_key_req : Yippee.Net.IObjectBase
    {
        private static Yippee.Net.TypeInfo session_key_reqTypeInfo_ = new Yippee.Net.TypeInfo(0x4771A11, "protocol.session_key_req");

        public session_key_req()
        {
        }
        public session_key_req(session_key_req from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return session_key_reqTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new session_key_req();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new session_key_req(this);
        }
        public void Clear()
        {
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((session_key_req)from);
        }
        public void CopyFrom(session_key_req from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((session_key_req)from);
        }
        public void MergeFrom(session_key_req from)
        {
            if (from == this)
            {
                return;
            }
        }
        public bool Serialize(Stream stream)
        {
            return true;
        }
        public bool Deserialize(Stream stream)
        {
            return true;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class session_key_ans : Yippee.Net.IObjectBase
    {
        private byte[] key_ = new byte[0];
        private byte[] iv_ = new byte[0];
        private static Yippee.Net.TypeInfo session_key_ansTypeInfo_ = new Yippee.Net.TypeInfo(0x4772683, "protocol.session_key_ans");

        public session_key_ans()
        {
        }
        public session_key_ans(session_key_ans from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return session_key_ansTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new session_key_ans();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new session_key_ans(this);
        }
        public void Clear()
        {
            // key
            Array.Resize(ref key_, 0);
            // iv
            Array.Resize(ref iv_, 0);
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // key
            totalSize += sizeof(uint);
            totalSize += sizeof(byte) * key_.Length;
            // iv
            totalSize += sizeof(uint);
            totalSize += sizeof(byte) * iv_.Length;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((session_key_ans)from);
        }
        public void CopyFrom(session_key_ans from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((session_key_ans)from);
        }
        public void MergeFrom(session_key_ans from)
        {
            if (from == this)
            {
                return;
            }

            // key
            int keyLength = key_.Length;
            Array.Resize(ref key_, keyLength + from.key_.Length);
            Array.Copy(from.key_, 0, key_, keyLength, from.key_.Length);
            // iv
            int ivLength = iv_.Length;
            Array.Resize(ref iv_, ivLength + from.iv_.Length);
            Array.Copy(from.iv_, 0, iv_, ivLength, from.iv_.Length);
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // key
            if (Yippee.Net.Internal.Serialize(output, key_) == false)
            {
                return false;
            }
            // iv
            if (Yippee.Net.Internal.Serialize(output, iv_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // key
            if (Yippee.Net.Internal.Deserialize(input, out key_) == false)
            {
                return false;
            }
            // iv
            if (Yippee.Net.Internal.Deserialize(input, out iv_) == false)
            {
                return false;
            }

            return true;
        }
        public byte[] GetKey()
        {
            return key_;
        }
        public byte GetKey(int index)
        {
            return key_[index];
        }
        public void SetKey(int index, byte value)
        {
            key_[index] = value;
        }
        public void SetKey(byte[] value)
        {
            key_ = value;
        }
        public void AddKey(byte value)
        {
            Array.Resize(ref key_, key_.Length + 1);
            key_[key_.Length - 1] = value;
        }
        public byte[] GetIv()
        {
            return iv_;
        }
        public byte GetIv(int index)
        {
            return iv_[index];
        }
        public void SetIv(int index, byte value)
        {
            iv_[index] = value;
        }
        public void SetIv(byte[] value)
        {
            iv_ = value;
        }
        public void AddIv(byte value)
        {
            Array.Resize(ref iv_, iv_.Length + 1);
            iv_[iv_.Length - 1] = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class login_req : Yippee.Net.IObjectBase
    {
        private LoginType loginType_;
        private short version_;
        private String accToken_ = "";
        private static Yippee.Net.TypeInfo login_reqTypeInfo_ = new Yippee.Net.TypeInfo(0x2EC52C1, "protocol.login_req");

        public login_req()
        {
        }
        public login_req(login_req from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return login_reqTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new login_req();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new login_req(this);
        }
        public void Clear()
        {
            // loginType
            loginType_ = 0;
            // version
            version_ = 0;
            // accToken
            accToken_ = "";
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // loginType
            totalSize += sizeof(int);
            // version
            totalSize += Yippee.Net.Internal.Size(version_);
            // accToken
            totalSize += Yippee.Net.Internal.SizeUTF8String(accToken_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((login_req)from);
        }
        public void CopyFrom(login_req from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((login_req)from);
        }
        public void MergeFrom(login_req from)
        {
            if (from == this)
            {
                return;
            }

            // loginType
            SetLoginType(from.GetLoginType());
            // version
            SetVersion(from.GetVersion());
            // accToken
            SetAccToken(from.GetAccToken());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // loginType
            {
                int value = (int)loginType_;
                if (Yippee.Net.Internal.Serialize(output, value) == false)
                {
                    return false;
                }
            }
            // version
            if (Yippee.Net.Internal.Serialize(output, version_) == false)
            {
                return false;
            }
            // accToken
            if (Yippee.Net.Internal.SerializeUTF8String(output, accToken_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // loginType
            {
                int value = 0;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                loginType_ = (LoginType)value;
            }
            // version
            if (Yippee.Net.Internal.Deserialize(input, out version_) == false)
            {
                return false;
            }
            // accToken
            if (Yippee.Net.Internal.DeserializeUTF8String(input, out accToken_) == false)
            {
                return false;
            }

            return true;
        }
        public LoginType GetLoginType()
        {
            return loginType_;
        }
        public void SetLoginType(LoginType value)
        {
            loginType_ = value;
        }
        public short GetVersion()
        {
            return version_;
        }
        public void SetVersion(short value)
        {
            version_ = value;
        }
        public String GetAccToken()
        {
            return accToken_;
        }
        public void SetAccToken(String value)
        {
            accToken_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class login_ans : Yippee.Net.IObjectBase
    {
        private short result_;
        private int sessionId_;
        private long serverTimestamp_;
        private server_address assignedLsAddr_ = new server_address();
        private TutorialProgress progress_;
        private static Yippee.Net.TypeInfo login_ansTypeInfo_ = new Yippee.Net.TypeInfo(0x2EC6E53, "protocol.login_ans");

        public login_ans()
        {
        }
        public login_ans(login_ans from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return login_ansTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new login_ans();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new login_ans(this);
        }
        public void Clear()
        {
            // result
            result_ = 0;
            // sessionId
            sessionId_ = 0;
            // serverTimestamp
            serverTimestamp_ = 0;
            // assignedLsAddr
            assignedLsAddr_.Clear();
            // progress
            progress_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // result
            totalSize += Yippee.Net.Internal.Size(result_);
            // sessionId
            totalSize += Yippee.Net.Internal.Size(sessionId_);
            // serverTimestamp
            totalSize += Yippee.Net.Internal.Size(serverTimestamp_);
            // assignedLsAddr
            totalSize += Yippee.Net.Internal.Size(assignedLsAddr_);
            // progress
            totalSize += sizeof(int);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((login_ans)from);
        }
        public void CopyFrom(login_ans from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((login_ans)from);
        }
        public void MergeFrom(login_ans from)
        {
            if (from == this)
            {
                return;
            }

            // result
            SetResult(from.GetResult());
            // sessionId
            SetSessionId(from.GetSessionId());
            // serverTimestamp
            SetServerTimestamp(from.GetServerTimestamp());
            // assignedLsAddr
            SetAssignedLsAddr(from.GetAssignedLsAddr());
            // progress
            SetProgress(from.GetProgress());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // result
            if (Yippee.Net.Internal.Serialize(output, result_) == false)
            {
                return false;
            }
            // sessionId
            if (Yippee.Net.Internal.Serialize(output, sessionId_) == false)
            {
                return false;
            }
            // serverTimestamp
            if (Yippee.Net.Internal.Serialize(output, serverTimestamp_) == false)
            {
                return false;
            }
            // assignedLsAddr
            if (assignedLsAddr_.Serialize(stream) == false)
            {
                return false;
            }
            // progress
            {
                int value = (int)progress_;
                if (Yippee.Net.Internal.Serialize(output, value) == false)
                {
                    return false;
                }
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // result
            if (Yippee.Net.Internal.Deserialize(input, out result_) == false)
            {
                return false;
            }
            // sessionId
            if (Yippee.Net.Internal.Deserialize(input, out sessionId_) == false)
            {
                return false;
            }
            // serverTimestamp
            if (Yippee.Net.Internal.Deserialize(input, out serverTimestamp_) == false)
            {
                return false;
            }
            // assignedLsAddr
            if (assignedLsAddr_.Deserialize(stream) == false)
            {
                return false;
            }
            // progress
            {
                int value = 0;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                progress_ = (TutorialProgress)value;
            }

            return true;
        }
        public short GetResult()
        {
            return result_;
        }
        public void SetResult(short value)
        {
            result_ = value;
        }
        public int GetSessionId()
        {
            return sessionId_;
        }
        public void SetSessionId(int value)
        {
            sessionId_ = value;
        }
        public long GetServerTimestamp()
        {
            return serverTimestamp_;
        }
        public void SetServerTimestamp(long value)
        {
            serverTimestamp_ = value;
        }
        public server_address GetAssignedLsAddr()
        {
            return assignedLsAddr_;
        }
        public void SetAssignedLsAddr(server_address value)
        {
            assignedLsAddr_ = value;
        }
        public TutorialProgress GetProgress()
        {
            return progress_;
        }
        public void SetProgress(TutorialProgress value)
        {
            progress_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class logout_req : Yippee.Net.IObjectBase
    {
        private int sessionId_;
        private static Yippee.Net.TypeInfo logout_reqTypeInfo_ = new Yippee.Net.TypeInfo(0x44BC8F1, "protocol.logout_req");

        public logout_req()
        {
        }
        public logout_req(logout_req from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return logout_reqTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new logout_req();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new logout_req(this);
        }
        public void Clear()
        {
            // sessionId
            sessionId_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // sessionId
            totalSize += Yippee.Net.Internal.Size(sessionId_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((logout_req)from);
        }
        public void CopyFrom(logout_req from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((logout_req)from);
        }
        public void MergeFrom(logout_req from)
        {
            if (from == this)
            {
                return;
            }

            // sessionId
            SetSessionId(from.GetSessionId());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // sessionId
            if (Yippee.Net.Internal.Serialize(output, sessionId_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // sessionId
            if (Yippee.Net.Internal.Deserialize(input, out sessionId_) == false)
            {
                return false;
            }

            return true;
        }
        public int GetSessionId()
        {
            return sessionId_;
        }
        public void SetSessionId(int value)
        {
            sessionId_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class logout_ans : Yippee.Net.IObjectBase
    {
        private short result_;
        private static Yippee.Net.TypeInfo logout_ansTypeInfo_ = new Yippee.Net.TypeInfo(0x44BF863, "protocol.logout_ans");

        public logout_ans()
        {
        }
        public logout_ans(logout_ans from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return logout_ansTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new logout_ans();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new logout_ans(this);
        }
        public void Clear()
        {
            // result
            result_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // result
            totalSize += Yippee.Net.Internal.Size(result_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((logout_ans)from);
        }
        public void CopyFrom(logout_ans from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((logout_ans)from);
        }
        public void MergeFrom(logout_ans from)
        {
            if (from == this)
            {
                return;
            }

            // result
            SetResult(from.GetResult());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // result
            if (Yippee.Net.Internal.Serialize(output, result_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // result
            if (Yippee.Net.Internal.Deserialize(input, out result_) == false)
            {
                return false;
            }

            return true;
        }
        public short GetResult()
        {
            return result_;
        }
        public void SetResult(short value)
        {
            result_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class heartbeat : Yippee.Net.IObjectBase
    {
        private static Yippee.Net.TypeInfo heartbeatTypeInfo_ = new Yippee.Net.TypeInfo(0x7B2AE64, "protocol.heartbeat");

        public heartbeat()
        {
        }
        public heartbeat(heartbeat from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return heartbeatTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new heartbeat();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new heartbeat(this);
        }
        public void Clear()
        {
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((heartbeat)from);
        }
        public void CopyFrom(heartbeat from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((heartbeat)from);
        }
        public void MergeFrom(heartbeat from)
        {
            if (from == this)
            {
                return;
            }
        }
        public bool Serialize(Stream stream)
        {
            return true;
        }
        public bool Deserialize(Stream stream)
        {
            return true;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class quit_req : Yippee.Net.IObjectBase
    {
        private static Yippee.Net.TypeInfo quit_reqTypeInfo_ = new Yippee.Net.TypeInfo(0xFFCEBF1, "protocol.quit_req");

        public quit_req()
        {
        }
        public quit_req(quit_req from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return quit_reqTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new quit_req();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new quit_req(this);
        }
        public void Clear()
        {
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((quit_req)from);
        }
        public void CopyFrom(quit_req from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((quit_req)from);
        }
        public void MergeFrom(quit_req from)
        {
            if (from == this)
            {
                return;
            }
        }
        public bool Serialize(Stream stream)
        {
            return true;
        }
        public bool Deserialize(Stream stream)
        {
            return true;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class quit_ans : Yippee.Net.IObjectBase
    {
        private short result_;
        private static Yippee.Net.TypeInfo quit_ansTypeInfo_ = new Yippee.Net.TypeInfo(0xFFCD563, "protocol.quit_ans");

        public quit_ans()
        {
        }
        public quit_ans(quit_ans from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return quit_ansTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new quit_ans();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new quit_ans(this);
        }
        public void Clear()
        {
            // result
            result_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // result
            totalSize += Yippee.Net.Internal.Size(result_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((quit_ans)from);
        }
        public void CopyFrom(quit_ans from)
        {
            if (from == this)
            {
                return;
            }

            Clear();
            MergeFrom(from);
        }
        public void MergeFrom(Yippee.Net.IObjectBase from)
        {
            MergeFrom((quit_ans)from);
        }
        public void MergeFrom(quit_ans from)
        {
            if (from == this)
            {
                return;
            }

            // result
            SetResult(from.GetResult());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // result
            if (Yippee.Net.Internal.Serialize(output, result_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // result
            if (Yippee.Net.Internal.Deserialize(input, out result_) == false)
            {
                return false;
            }

            return true;
        }
        public short GetResult()
        {
            return result_;
        }
        public void SetResult(short value)
        {
            result_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------


}	// namespace protocol