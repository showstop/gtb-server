// Generated by the DRCat compiler. DO NOT EDIT!

using System.Collections.Generic;
using System.IO;
using System;


namespace protocol
{

    public enum LoginType
    {
        FACEBOOK = 1,
        GOOGLE = 2,
        GUEST = 98,
    };	// enum LoginType

    public enum TutorialProgress
    {
        INITIALIZE = 0,
        CONTROL_TUTORIAL_BEGIN = 1,
        CONTROL_TUTORIAL_END = 2,
        LOBBY_TUTORIAL_BEGIN = 3,
        LOBBY_TUTORIAL_END = 4,
        ALL_COMPLETE = 5,
    };	// enum TutorialProgress

    public enum GameMode
    {
        QUICK = 1,
        GRANDPRIX = 2,
    };	// enum GameMode

    public enum RewardType
    {
        GOLD = 1,
        DIAMOND = 2,
        QUICK_MATCH_TICKET = 3,
        GRANDPRIX_TICKET = 4,
        VEHICLE_SPECIFIC_CARD = 10,
        VEHICLE_SELECT_CARD = 11,
        VEHICLE_PICK_CARD = 12,
        STUFF = 13,
    };	// enum RewardType

    public enum record_data_key
    {
        LOGIN_COUNT = 101,
        FACEBOOK_POSTING = 102,
        FACEBOOK_LIKE = 103,
        FACEBOOK_FRIEND_INVITE = 104,
        ACHIEVEMENT_COUNT = 105,
        ACQ_GOLD_MEDAL = 1001,
        ACQ_SILVER_MEDAL = 1002,
        ACQ_BRONZE_MEDAL = 1003,
        RUNNING_DISTANCE = 1004,
        ACQ_GAME_MONEY = 1006,
        PLAY_COUNT = 1007,
        USE_ITEM_COUNT = 1008,
        KNOCK_COUNT = 1009,
        OVERWHELM_FIRST = 1010,
        NARROW_SECOND = 1011,
        CONTINUOUS_FIRST = 1012,
        CONTINUOUS_LAST = 1013,
        NO_DEATH_GAME = 1014,
        FRIEND_COUNT = 1015,
        COLLECT_ACHIEVEMENT = 1016,
        BUMP_ATTACK = 1017,
        DEATH = 1018,
        KILL = 1019,
        TOTAL_PLAY_SEC = 1020,
        USE_INGAME_ITEM = 1021,
        ACQ_INGAME_ITEM = 1022,
        QUICK_MATCH_PLAY_COUNT = 1023,
        QUICK_MATCH_PLAY_SEC = 1024,
        GRANDPRIX_PLAY_COUNT = 1025,
        GRANDPRIX_PLAY_SEC = 1026,
        UPGRADE_VEHICLE = 1027,
        PARTS_TUNING = 1028,
        ACQ_NORMAL_STUFF = 1029,
        ACQ_RARE_STUFF = 1030,
        USE_GACHA_COUNT = 1031,
        OPEN_LUCKY_BOX = 1032,
        WATCH_VIDEO_AD_COUNT = 1033,
        DEAL_DAMAGE = 1034,
        TAKE_DAMAGE = 1035,
        DEFENSE_USING_BRAND_NEW = 11101,
        TIME_REWIND = 11102,
        USE_FROST = 11103,
        USE_JACK_BOX = 11104,
        USE_EMERGENCY = 11105,
        USE_ARTISAN_HANDS = 11106,
        USE_SIREN_BOOST = 11107,
        USE_WATER_BOMB = 11108,
        USE_DESTROYER = 11109,
        ONE_SHOT_KILL = 11110,
        USE_BARRICADE = 11111,
        USE_RUN_AWAY = 11112,
        DAMAGE_CHAINING_USING_LIGHTENING_CHAIN = 11113,
        DEFENSE_USING_SPEEDING = 11114,
    };	// enum record_data_key

    // ================================================================================================

    public class match_item_info : Yippee.Net.IObjectBase
    {
        private Dictionary<int, short> infos_ = new Dictionary<int, short>();
        private static Yippee.Net.TypeInfo match_item_infoTypeInfo_ = new Yippee.Net.TypeInfo(0xFA39CBF, "protocol.match_item_info");

        public match_item_info()
        {
        }
        public match_item_info(match_item_info from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return match_item_infoTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new match_item_info();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new match_item_info(this);
        }
        public void Clear()
        {
            // infos
            infos_.Clear();
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // infos
            totalSize += sizeof(uint);
            totalSize += sizeof(int) * infos_.Count;
            totalSize += sizeof(short) * infos_.Count;

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((match_item_info)from);
        }
        public void CopyFrom(match_item_info from)
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
            MergeFrom((match_item_info)from);
        }
        public void MergeFrom(match_item_info from)
        {
            if (from == this)
            {
                return;
            }

            // infos
            foreach (KeyValuePair<int, short> pair in from.GetInfos())
            {
                SetInfos(pair.Key, pair.Value);
            }
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // infos
            uint infosLength = (uint)infos_.Count;
            if (Yippee.Net.Internal.Serialize(output, infosLength) == false)
            {
                return false;
            }
            foreach (KeyValuePair<int, short> pair in infos_)
            {
                if (Yippee.Net.Internal.Serialize(output, pair.Key) == false)
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
            // infos
            uint infosLength = 0;
            if (Yippee.Net.Internal.Deserialize(input, out infosLength) == false)
            {
                return false;
            }
            for (uint i = 0; i < infosLength; ++i)
            {
                int key;
                if (Yippee.Net.Internal.Deserialize(input, out key) == false)
                {
                    return false;
                }
                short value;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                SetInfos(key, value);
            }

            return true;
        }
        public Dictionary<int, short> GetInfos()
        {
            return infos_;
        }
        public bool GetInfos(int key, out short value)
        {
            return infos_.TryGetValue(key, out value);
        }
        public short GetInfos(int key)
        {
            short ret;
            infos_.TryGetValue(key, out ret);
            return ret;
        }
        public void SetInfos(int key, short value)
        {
            infos_[key] = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class reward_info : Yippee.Net.IObjectBase
    {
        private RewardType type_;
        private int specificId_;
        private int quantity_;
        private static Yippee.Net.TypeInfo reward_infoTypeInfo_ = new Yippee.Net.TypeInfo(0xB6766F, "protocol.reward_info");

        public reward_info()
        {
        }
        public reward_info(reward_info from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return reward_infoTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new reward_info();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new reward_info(this);
        }
        public void Clear()
        {
            // type
            type_ = 0;
            // specificId
            specificId_ = 0;
            // quantity
            quantity_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // type
            totalSize += sizeof(int);
            // specificId
            totalSize += Yippee.Net.Internal.Size(specificId_);
            // quantity
            totalSize += Yippee.Net.Internal.Size(quantity_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((reward_info)from);
        }
        public void CopyFrom(reward_info from)
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
            MergeFrom((reward_info)from);
        }
        public void MergeFrom(reward_info from)
        {
            if (from == this)
            {
                return;
            }

            // type
            SetType(from.GetType());
            // specificId
            SetSpecificId(from.GetSpecificId());
            // quantity
            SetQuantity(from.GetQuantity());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // type
            {
                int value = (int)type_;
                if (Yippee.Net.Internal.Serialize(output, value) == false)
                {
                    return false;
                }
            }
            // specificId
            if (Yippee.Net.Internal.Serialize(output, specificId_) == false)
            {
                return false;
            }
            // quantity
            if (Yippee.Net.Internal.Serialize(output, quantity_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // type
            {
                int value = 0;
                if (Yippee.Net.Internal.Deserialize(input, out value) == false)
                {
                    return false;
                }
                type_ = (RewardType)value;
            }
            // specificId
            if (Yippee.Net.Internal.Deserialize(input, out specificId_) == false)
            {
                return false;
            }
            // quantity
            if (Yippee.Net.Internal.Deserialize(input, out quantity_) == false)
            {
                return false;
            }

            return true;
        }
        public RewardType GetType()
        {
            return type_;
        }
        public void SetType(RewardType value)
        {
            type_ = value;
        }
        public int GetSpecificId()
        {
            return specificId_;
        }
        public void SetSpecificId(int value)
        {
            specificId_ = value;
        }
        public int GetQuantity()
        {
            return quantity_;
        }
        public void SetQuantity(int value)
        {
            quantity_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class server_address : Yippee.Net.IObjectBase
    {
        private String domain_ = "";
        private ushort port_;
        private static Yippee.Net.TypeInfo server_addressTypeInfo_ = new Yippee.Net.TypeInfo(0xEC5C9D3, "protocol.server_address");

        public server_address()
        {
        }
        public server_address(server_address from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return server_addressTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new server_address();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new server_address(this);
        }
        public void Clear()
        {
            // domain
            domain_ = "";
            // port
            port_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // domain
            totalSize += Yippee.Net.Internal.SizeUTF8String(domain_);
            // port
            totalSize += Yippee.Net.Internal.Size(port_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((server_address)from);
        }
        public void CopyFrom(server_address from)
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
            MergeFrom((server_address)from);
        }
        public void MergeFrom(server_address from)
        {
            if (from == this)
            {
                return;
            }

            // domain
            SetDomain(from.GetDomain());
            // port
            SetPort(from.GetPort());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // domain
            if (Yippee.Net.Internal.SerializeUTF8String(output, domain_) == false)
            {
                return false;
            }
            // port
            if (Yippee.Net.Internal.Serialize(output, port_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // domain
            if (Yippee.Net.Internal.DeserializeUTF8String(input, out domain_) == false)
            {
                return false;
            }
            // port
            if (Yippee.Net.Internal.Deserialize(input, out port_) == false)
            {
                return false;
            }

            return true;
        }
        public String GetDomain()
        {
            return domain_;
        }
        public void SetDomain(String value)
        {
            domain_ = value;
        }
        public ushort GetPort()
        {
            return port_;
        }
        public void SetPort(ushort value)
        {
            port_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------

    public class asset_info : Yippee.Net.IObjectBase
    {
        private int gold_;
        private int diamond_;
        private short quickTicket_;
        private long quickTimestamp_;
        private short grandprixTicket_;
        private long grandprixTimestamp_;
        private static Yippee.Net.TypeInfo asset_infoTypeInfo_ = new Yippee.Net.TypeInfo(0xE27DBAF, "protocol.asset_info");

        public asset_info()
        {
        }
        public asset_info(asset_info from)
        {
            MergeFrom(from);
        }
        public static Yippee.Net.TypeInfo StaticTypeInfo()
        {
            return asset_infoTypeInfo_;
        }
        public Yippee.Net.TypeInfo RuntimeTypeInfo()
        {
            return StaticTypeInfo();
        }
        public Yippee.Net.IObjectBase NewInstance()
        {
            return new asset_info();
        }
        public Yippee.Net.IObjectBase Clone()
        {
            return new asset_info(this);
        }
        public void Clear()
        {
            // gold
            gold_ = 0;
            // diamond
            diamond_ = 0;
            // quickTicket
            quickTicket_ = 0;
            // quickTimestamp
            quickTimestamp_ = 0;
            // grandprixTicket
            grandprixTicket_ = 0;
            // grandprixTimestamp
            grandprixTimestamp_ = 0;
        }
        public bool Initialized()
        {
            //this call is not implemented yet
            return true;
        }
        public int Size()
        {
            int totalSize = 0;

            // gold
            totalSize += Yippee.Net.Internal.Size(gold_);
            // diamond
            totalSize += Yippee.Net.Internal.Size(diamond_);
            // quickTicket
            totalSize += Yippee.Net.Internal.Size(quickTicket_);
            // quickTimestamp
            totalSize += Yippee.Net.Internal.Size(quickTimestamp_);
            // grandprixTicket
            totalSize += Yippee.Net.Internal.Size(grandprixTicket_);
            // grandprixTimestamp
            totalSize += Yippee.Net.Internal.Size(grandprixTimestamp_);

            return totalSize;
        }
        public void CopyFrom(Yippee.Net.IObjectBase from)
        {
            CopyFrom((asset_info)from);
        }
        public void CopyFrom(asset_info from)
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
            MergeFrom((asset_info)from);
        }
        public void MergeFrom(asset_info from)
        {
            if (from == this)
            {
                return;
            }

            // gold
            SetGold(from.GetGold());
            // diamond
            SetDiamond(from.GetDiamond());
            // quickTicket
            SetQuickTicket(from.GetQuickTicket());
            // quickTimestamp
            SetQuickTimestamp(from.GetQuickTimestamp());
            // grandprixTicket
            SetGrandprixTicket(from.GetGrandprixTicket());
            // grandprixTimestamp
            SetGrandprixTimestamp(from.GetGrandprixTimestamp());
        }
        public bool Serialize(Stream stream)
        {
            BinaryWriter output = new BinaryWriter(stream);
            // gold
            if (Yippee.Net.Internal.Serialize(output, gold_) == false)
            {
                return false;
            }
            // diamond
            if (Yippee.Net.Internal.Serialize(output, diamond_) == false)
            {
                return false;
            }
            // quickTicket
            if (Yippee.Net.Internal.Serialize(output, quickTicket_) == false)
            {
                return false;
            }
            // quickTimestamp
            if (Yippee.Net.Internal.Serialize(output, quickTimestamp_) == false)
            {
                return false;
            }
            // grandprixTicket
            if (Yippee.Net.Internal.Serialize(output, grandprixTicket_) == false)
            {
                return false;
            }
            // grandprixTimestamp
            if (Yippee.Net.Internal.Serialize(output, grandprixTimestamp_) == false)
            {
                return false;
            }

            return true;
        }
        public bool Deserialize(Stream stream)
        {
            BinaryReader input = new BinaryReader(stream);
            // gold
            if (Yippee.Net.Internal.Deserialize(input, out gold_) == false)
            {
                return false;
            }
            // diamond
            if (Yippee.Net.Internal.Deserialize(input, out diamond_) == false)
            {
                return false;
            }
            // quickTicket
            if (Yippee.Net.Internal.Deserialize(input, out quickTicket_) == false)
            {
                return false;
            }
            // quickTimestamp
            if (Yippee.Net.Internal.Deserialize(input, out quickTimestamp_) == false)
            {
                return false;
            }
            // grandprixTicket
            if (Yippee.Net.Internal.Deserialize(input, out grandprixTicket_) == false)
            {
                return false;
            }
            // grandprixTimestamp
            if (Yippee.Net.Internal.Deserialize(input, out grandprixTimestamp_) == false)
            {
                return false;
            }

            return true;
        }
        public int GetGold()
        {
            return gold_;
        }
        public void SetGold(int value)
        {
            gold_ = value;
        }
        public int GetDiamond()
        {
            return diamond_;
        }
        public void SetDiamond(int value)
        {
            diamond_ = value;
        }
        public short GetQuickTicket()
        {
            return quickTicket_;
        }
        public void SetQuickTicket(short value)
        {
            quickTicket_ = value;
        }
        public long GetQuickTimestamp()
        {
            return quickTimestamp_;
        }
        public void SetQuickTimestamp(long value)
        {
            quickTimestamp_ = value;
        }
        public short GetGrandprixTicket()
        {
            return grandprixTicket_;
        }
        public void SetGrandprixTicket(short value)
        {
            grandprixTicket_ = value;
        }
        public long GetGrandprixTimestamp()
        {
            return grandprixTimestamp_;
        }
        public void SetGrandprixTimestamp(long value)
        {
            grandprixTimestamp_ = value;
        }
    }
    // ------------------------------------------------------------------------------------------------


}	// namespace protocol