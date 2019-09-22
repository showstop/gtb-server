// Generated by the DRCat compiler. DO NOT EDIT!

using System.Collections.Generic;
using System.IO;
using System;


namespace protocol
{

    public enum HardwareResourceKey
    {
        CPU_USAGE = 1,
        MEM_USAGE = 2,
        DISK_USAGE = 3,
    };	// enum HardwareResourceKey

    public enum GameResourceKey
    {
        USER_COUNT = 1,
        ROOM_COUNT = 2,
        PLAY_COUNT = 3,
    };	// enum GameResourceKey

    // ================================================================================================

    public class game_monitor_data : Yippee.Net.IObjectBase
    {
        private String machineName_ = "";
        private Dictionary<HardwareResourceKey, int> machineResourceInfo_ = new Dictionary<HardwareResourceKey, int>();
        private Dictionary<GameResourceKey, int> gameResourceInfo_ = new Dictionary<GameResourceKey, int>();
        private static Yippee.Net.TypeInfo game_monitor_dataTypeInfo_ = new Yippee.Net.TypeInfo(0x86124E1, "protocol.game_monitor_data");

        public game_monitor_data()
        {
        }
        public game_monitor_data(game_monitor_data from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return game_monitor_dataTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new game_monitor_data();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new game_monitor_data(this);
        }
        public void Clear()
        {
            // machineName
            machineName_ = "";
            // machineResourceInfo
            machineResourceInfo_.Clear();
            // gameResourceInfo
            gameResourceInfo_.Clear();
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // machineName
            totalSize += Yippee.Net.Internal.SizeUTF8String(machineName_);
            // machineResourceInfo
            totalSize += sizeof(uint);
            totalSize += sizeof(HardwareResourceKey) * machineResourceInfo_.Count;
            totalSize += sizeof(int) * machineResourceInfo_.Count;
            // gameResourceInfo
            totalSize += sizeof(uint);
            totalSize += sizeof(GameResourceKey) * gameResourceInfo_.Count;
            totalSize += sizeof(int) * gameResourceInfo_.Count;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((game_monitor_data)from);
        }
        public void CopyFrom(game_monitor_data from)
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
            MergeFrom((game_monitor_data)from);
        }
        public void MergeFrom(game_monitor_data from)
        {
            if (from == this)
            {
                return;
            }

            // machineName
            SetMachineName(from.GetMachineName());
            // machineResourceInfo
            foreach (KeyValuePair<HardwareResourceKey, int> pair in from.GetMachineResourceInfo())
            {
                SetMachineResourceInfo(pair.Key, pair.Value);
            }
            // gameResourceInfo
            foreach (KeyValuePair<GameResourceKey, int> pair in from.GetGameResourceInfo())
            {
                SetGameResourceInfo(pair.Key, pair.Value);
            }
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // machineName
            if (Yippee.Net.Internal.SerializeUTF8String(output, machineName_) == false)
            {
                return false;
            }
            // machineResourceInfo
            uint machineResourceInfoLength = (uint)machineResourceInfo_.Count;
            if (Yippee.Net.Internal.Serialize(output, machineResourceInfoLength) == false)
            {
                return false;
            }
            foreach (KeyValuePair<HardwareResourceKey, int> pair in machineResourceInfo_)
            {
                int key = (int)pair.Key;
                if (Yippee.Net.Internal.Serialize(output, key) == false)
                {
                    return false;
                }
                if (Yippee.Net.Internal.Serialize(output, pair.Value) == false)
                {
                    return false;
                }
            }
            // gameResourceInfo
            uint gameResourceInfoLength = (uint)gameResourceInfo_.Count;
            if (Yippee.Net.Internal.Serialize(output, gameResourceInfoLength) == false)
            {
                return false;
            }
            foreach (KeyValuePair<GameResourceKey, int> pair in gameResourceInfo_)
            {
                int key = (int)pair.Key;
                if (Yippee.Net.Internal.Serialize(output, key) == false)
                {
                    return false;
                }
                if (Yippee.Net.Internal.Serialize(output, pair.Value) == false)
                {
                    return false;
                }
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // machineName
            if (Yippee.Net.Internal.DeserializeUTF8String(input, out machineName_) == false)
            {
                return false;
            }
            // machineResourceInfo
            uint machineResourceInfoLength = 0;
            if (Yippee.Net.Internal.Deserialize(input, out machineResourceInfoLength) == false)
            {
                return false;
            }
            for (uint i = 0; i < machineResourceInfoLength; ++i)
            {
                int key;
                if (Yippee.Net.Internal.Deserialize(input, out key) == false)
                {
                    return false;
                }
                int value;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                SetMachineResourceInfo((HardwareResourceKey)key, value);
            }
            // gameResourceInfo
            uint gameResourceInfoLength = 0;
            if (Yippee.Net.Internal.Deserialize(input, out gameResourceInfoLength) == false)
            {
                return false;
            }
            for (uint i = 0; i < gameResourceInfoLength; ++i)
            {
                int key;
                if (Yippee.Net.Internal.Deserialize(input, out key) == false)
                {
                    return false;
                }
                int value;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                SetGameResourceInfo((GameResourceKey)key, value);
            }

            return true;
        }
        public String GetMachineName()
        {
            return machineName_;
        }
        public void SetMachineName(String value)
        {
            machineName_ = value;
        }
        public Dictionary<HardwareResourceKey, int> GetMachineResourceInfo()
        {
            return machineResourceInfo_;
        }
        public bool GetMachineResourceInfo(HardwareResourceKey key, out int value)
        {
            return machineResourceInfo_.TryGetValue(key, out value);
        }
        public int GetMachineResourceInfo(HardwareResourceKey key)
        {
            int ret;
            machineResourceInfo_.TryGetValue(key, out ret);
            return ret;
        }
        public void SetMachineResourceInfo(HardwareResourceKey key, int value)
        {
            machineResourceInfo_[key] = value;
        }
        public Dictionary<GameResourceKey, int> GetGameResourceInfo()
        {
            return gameResourceInfo_;
        }
        public bool GetGameResourceInfo(GameResourceKey key, out int value)
        {
            return gameResourceInfo_.TryGetValue(key, out value);
        }
        public int GetGameResourceInfo(GameResourceKey key)
        {
            int ret;
            gameResourceInfo_.TryGetValue(key, out ret);
            return ret;
        }
        public void SetGameResourceInfo(GameResourceKey key, int value)
        {
            gameResourceInfo_[key] = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class monitor_data_req : Yippee.Net.IObjectBase
    {
        private static Yippee.Net.TypeInfo monitor_data_reqTypeInfo_ = new Yippee.Net.TypeInfo(0xA949CA1, "protocol.monitor_data_req");

        public monitor_data_req()
        {
        }
        public monitor_data_req(monitor_data_req from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return monitor_data_reqTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new monitor_data_req();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new monitor_data_req(this);
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
            CopyFrom((monitor_data_req)from);
        }
        public void CopyFrom(monitor_data_req from)
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
            MergeFrom((monitor_data_req)from);
        }
        public void MergeFrom(monitor_data_req from)
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

    public class monitor_data_ans : Yippee.Net.IObjectBase
    {
        private short result_;
        private game_monitor_data data_ = new game_monitor_data();
        private static Yippee.Net.TypeInfo monitor_data_ansTypeInfo_ = new Yippee.Net.TypeInfo(0xA94A433, "protocol.monitor_data_ans");

        public monitor_data_ans()
        {
        }
        public monitor_data_ans(monitor_data_ans from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return monitor_data_ansTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new monitor_data_ans();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new monitor_data_ans(this);
        }
        public void Clear()
        {
            // result
            result_ = 0;
            // data
            data_.Clear();
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
            // data
            totalSize += Yippee.Net.Internal.Size(data_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((monitor_data_ans)from);
        }
        public void CopyFrom(monitor_data_ans from)
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
            MergeFrom((monitor_data_ans)from);
        }
        public void MergeFrom(monitor_data_ans from)
        {
            if (from == this)
            {
                return;
            }

            // result
            SetResult(from.GetResult());
            // data
            SetData(from.GetData());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // result
            if (Yippee.Net.Internal.Serialize(output, result_) == false)
            {
                return false;
            }
            // data
            if (data_.Serialize(stream) == false)
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
            // data
            if (data_.Deserialize(stream) == false)
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
        public game_monitor_data GetData()
        {
            return data_;
        }
        public void SetData(game_monitor_data value)
        {
            data_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------


}	// namespace protocol