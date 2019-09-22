#ifndef __INIFILECONFIG_H_DA73E23D_3279_451C_AD6C_6F3D58F137B7__
#define __INIFILECONFIG_H_DA73E23D_3279_451C_AD6C_6F3D58F137B7__


#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdint>

// Enumeration Values ----------------------------------------------------------
enum
{
	OPTION_NULL		= 0x00,
	OPTION_LOADED	= 0x01,
	//OPTION_CHANGED	= 0x02,

	//FLAG_NORMAL	= 0,
	//FLAG_UPDATED	= 1,
	//FLAG_DELETED	= 2,
};

/**
 * class IniFileConfig
 */
class IniFileConfig
{
	class Key
	{
		public:
			//Key(uint16_t nFlags = 0x00, const char* pszValue = NULL)
			//	: Flags(nFlags), Value(pszValue)
			Key(const char* pszValue = NULL)
				: Value(pszValue)
				{
				}

			//uint16_t		Flags;
			//std::string	Comment;
			std::string		Value;
	};
	typedef std::map<std::string, Key>		KeyMap;
	typedef std::pair<std::string, Key>		KeyPair;

	class Section
	{
		public:
			//Section(uint16_t nFlags = 0x00)
			//	: Flags(nFlags)
			Section()
			{
			}

			//uint16_t		Flags;
			//std::string	Comment;
			KeyMap			KeyList;
	};
	typedef std::map<std::string, Section>		SectionMap;
	typedef std::pair<std::string, Section>		SectionPair;

public:
	IniFileConfig()
		: m_nOptions(0x00)
		{
		}
	~IniFileConfig()
	{
		Close();
	}

	/*
	 *	pszSectionList
	 *		NULL				.ini ���� ��ü�� �Ľ��Ͽ� m_mapSectionList�� ä���.
	 *		"[Section1] ..."	.ini ���Ͽ��� Ư�� ���Ǹ��� �Ľ��Ͽ� m_mapSectionList�� ä���.
	 */
	bool Open(const char* pszIniFilePath, const char* pszSectionList = NULL);
	/*
	 *	ini ������ ���� ���ڿ��� �м��Ѵ�.
	 *  pszIniString            ini ���ڿ�
	 */
	bool OpenStr(const char* pszIniString, const char* pszSectionList = NULL);
	bool Close(void);

	bool SelectSection(const char* pszSectionName);

	bool GetBoolValue(const char* pszKeyName, bool bDefaultValue/* = false*/) const;
	int16_t GetInt16Value(const char* pszKeyName, int16_t nDefaultValue/* = 0*/) const;
	int32_t GetInt32Value(const char* pszKeyName, int32_t nDefaultValue/* = 0*/) const;
	int64_t GetInt64Value(const char* pszKeyName, int64_t nDefaultValue/* = 0*/) const;
	const char* GetStringValue(const char* pszKeyName, const char* pszDefaultValue = NULL) const;

	bool AssignValue(const char* pszKeyName, bool bValue);
	bool AssignValue(const char* pszKeyName, int16_t nValue);
	bool AssignValue(const char* pszKeyName, int32_t nValue);
	bool AssignValue(const char* pszKeyName, int64_t nValue);
	bool AssignValue(const char* pszKeyName, const char* pszValue);
	bool DeleteKey(const char* pszKeyName);

	bool InsertSection(const char* /* pszSectionName */);
	bool DeleteSection(const char* /* pszSectionName */);

private:
	void _Trim(std::string& rstrData) const;
	bool ParseStream( std::istream& isIniText, const char* pszSectionList = NULL);

protected:
	uint16_t		m_nOptions;
	std::string		m_strIniFilePath,
		m_strSectionName;
	SectionMap		m_mapSectionList;
};

#endif /*__INIFILECONFIG_H_DA73E23D_3279_451C_AD6C_6F3D58F137B7__*/


