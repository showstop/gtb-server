#include "IniFileConfig.h"
#include <strstream>
#include <cstring>

using namespace std;

bool IniFileConfig::Open(const char* pszIniFilePath, const char* pszSectionList)
{
	ifstream	ifsIniFile; 

	ifsIniFile.open(pszIniFilePath);
	if (ifsIniFile.is_open() == false)
		return false;

	return ParseStream( ifsIniFile, pszSectionList );
}


bool IniFileConfig::OpenStr( const char* pszIniString, const char* pszSectionList /*= NULL*/ )
{
	istrstream	isIniText(pszIniString); 

	return ParseStream( isIniText, pszSectionList );
}

bool IniFileConfig::ParseStream( istream& isIniText, const char* pszSectionList /*= NULL*/ )
{
	string		strLineData, strSection;
	bool		bParseSection = false;

	do
	{
		std::getline(isIniText, strLineData);

		_Trim(strLineData);
		if (!strLineData.empty())
		{
			// comment
			if (strLineData[0] == ';' || strLineData[0] == '#')
			{
				/* do nothing */
			}

			// section
			else if (strLineData[0] == '[')
			{
				// 특정 Section만 파싱
				if (pszSectionList != NULL)					
				{
					string strSectionListTemp = pszSectionList;
					transform(strSectionListTemp.begin(), strSectionListTemp.end(), strSectionListTemp.begin(), (int (*)(int))toupper);
					string strLineDataTemp = strLineData;
					transform(strLineDataTemp.begin(), strLineDataTemp.end(), strLineDataTemp.begin(), (int (*)(int))toupper);

					if( strstr(strSectionListTemp.c_str(), strLineDataTemp.c_str()) == NULL )
					{
						bParseSection = false;
						continue;
					}					
				}
				else
					bParseSection = true;

				// ...
				pair<SectionMap::iterator, bool>	result;

				strSection = strLineData.substr(1, strLineData.find(']') - 1);
				transform(strSection.begin(), strSection.end(), strSection.begin(), (int (*)(int))toupper);

				//result = m_mapSectionList.insert(SectionMap::value_type(strSection, Section(FLAG_NORMAL)));
				result = m_mapSectionList.insert(SectionMap::value_type(strSection, Section()));
				if (!result.second)
					strSection.erase();
			}

			// key
			else if (strLineData.find('=') != string::npos)
			{
				if (bParseSection && !strSection.empty())
				{
					string	strKeyName, strKeyValue;
					size_t	nPos = strLineData.find('=');

					strKeyName	= strLineData.substr(0, nPos);
					transform(strKeyName.begin(), strKeyName.end(), strKeyName.begin(), (int (*)(int))toupper);
					strKeyValue	= strLineData.substr(nPos + 1);
					_Trim(strKeyName);
					_Trim(strKeyValue);

					// ...
					KeyMap	&roKeyList = (m_mapSectionList.find(strSection)->second).KeyList;

					//roKeyList.insert(KeyMap::value_type(strKeyName, Key(FLAG_NORMAL, strKeyValue.c_str())));
					roKeyList.insert(KeyMap::value_type(strKeyName, Key(strKeyValue.c_str())));
				}
			}
		}
	}
	while (isIniText.eof() == false);

	m_nOptions = OPTION_LOADED;
	return true;
}

bool IniFileConfig::Close(void)
{
	//dolduri-개발: 수정된 사항을 파일에 저장...
	//if (m_nOptions & OPTION_CHANGED)
	//{
	//ofstream outFile (FileName.c_str());									// Create an output filestream
	//if (!outFile.is_open()) return false;									// If the output file doesn't open, then return

	//for (int i=0;i<(int)content.size();i++)									// Loop through each vector
	//{
	//	outFile << content[i].Comments;										// Write out the comments
	//	if(content[i].Key == "")											// Is this a section?
	//		outFile << content[i].Commented << "[" 
	//		<< content[i].Section << "]" << endl;							// Then format the section
	//	else
	//		outFile << content[i].Commented << content[i].Key  
	//		<< "=" << content[i].Value << endl;								// Else format a key/value
	//}

	//outFile.close();														// Close the file
	//}

	m_mapSectionList.clear();
	return true;
}

bool IniFileConfig::SelectSection(const char* pszSectionName)
{
	if (m_nOptions & OPTION_LOADED)
	{
		string						strSectionName = pszSectionName;
		transform(strSectionName.begin(), strSectionName.end(), strSectionName.begin(), (int (*)(int))toupper);

		SectionMap::const_iterator	it;

		if ((it = m_mapSectionList.find(strSectionName)) != m_mapSectionList.end())
		{
			m_strSectionName = strSectionName;
			return true;
		}

		m_strSectionName.clear();
	}

	return false;
}

bool IniFileConfig::GetBoolValue(const char* pszKeyName, bool bDefaultValue/* = false*/) const
{
	const char	*pszKeyValue;

	if ((pszKeyValue = GetStringValue(pszKeyName)) != NULL)
	{
		int (*pfTolower)(int) = tolower; 
		string	strKeyValue;

		strKeyValue.reserve(strlen(pszKeyValue) + 2);
		strKeyValue  = '(';
		strKeyValue += pszKeyValue;
		strKeyValue += ')';
		transform(strKeyValue.begin(), strKeyValue.end(), strKeyValue.begin(), pfTolower);

		return (strstr("(true)(yes)(on)(1)(-1)", strKeyValue.c_str()) != NULL);
	}

	return bDefaultValue;
}

int16_t IniFileConfig::GetInt16Value(const char* pszKeyName, int16_t nDefaultValue/* = 0*/) const
{
	const char	*pszKeyValue;

	if ((pszKeyValue = GetStringValue(pszKeyName)) != NULL)
	{
		char	*pEndPtr;

		return (int16_t) strtol(pszKeyValue, &pEndPtr, 10);
	}

	return nDefaultValue;
}

int32_t IniFileConfig::GetInt32Value(const char* pszKeyName, int32_t nDefaultValue/* = 0*/) const
{
	const char	*pszKeyValue;

	if ((pszKeyValue = GetStringValue(pszKeyName)) != NULL)
	{
		char	*pEndPtr;

		return strtol(pszKeyValue, &pEndPtr, 10);
	}

	return nDefaultValue;
}

int64_t IniFileConfig::GetInt64Value(const char* pszKeyName, int64_t nDefaultValue/* = 0*/) const
{
	const char	*pszKeyValue;

	if ((pszKeyValue = GetStringValue(pszKeyName)) != NULL)
	{
		char	*pEndPtr;

#if defined(_WIN32) || defined(_WIN64)
		return (int64_t) _strtoui64(pszKeyValue, &pEndPtr, 10);
#else
		return strtoll(pszKeyValue, &pEndPtr, 10);
#endif
	}

	return nDefaultValue;
}

const char* IniFileConfig::GetStringValue(const char* pszKeyName, const char* pszDefaultValue) const
{
	if (!m_strSectionName.empty())
	{
		string					strKeyName = pszKeyName;
		transform(strKeyName.begin(), strKeyName.end(), strKeyName.begin(), (int (*)(int))toupper);

		const KeyMap			&roKeyList = (m_mapSectionList.find(m_strSectionName)->second).KeyList;
		KeyMap::const_iterator	it;

		if ((it = roKeyList.find(strKeyName)) != roKeyList.end())
			return (it->second).Value.c_str();
	}

	return pszDefaultValue;
}

bool IniFileConfig::AssignValue(const char* pszKeyName, bool bValue)
{
	char	szKeyValue[6];	// "True" / "False"

	sprintf(szKeyValue, "%s", (bValue) ? "True" : "False");
	return AssignValue(pszKeyName, szKeyValue);
}

bool IniFileConfig::AssignValue(const char* pszKeyName, int16_t nValue)
{
	char	szKeyValue[7];	// "-32768" ~ "32767"

	sprintf(szKeyValue, "%d", (int) nValue);
	return AssignValue(pszKeyName, szKeyValue);
}

bool IniFileConfig::AssignValue(const char* pszKeyName, int32_t nValue)
{
	char	szKeyValue[12];	// "-2147483648" ~ "2147483647"

	sprintf(szKeyValue, "%ld", (long) nValue);
	return AssignValue(pszKeyName, szKeyValue);
}

bool IniFileConfig::AssignValue(const char* pszKeyName, int64_t nValue)
{
	char	szKeyValue[21];	// "-9223372036854775808" ~ "9223372036854775807"

#if defined(_WIN32) || defined(_WIN64)
	sprintf(szKeyValue, "%I64d", nValue);
#else
	sprintf(szKeyValue, "%lld", nValue);
#endif
	return AssignValue(pszKeyName, szKeyValue);
}

bool IniFileConfig::AssignValue(const char* pszKeyName, const char* pszValue)
{
	if (!m_strSectionName.empty())
	{
		string							strKeyName = pszKeyName;
		transform(strKeyName.begin(), strKeyName.end(), strKeyName.begin(), (int (*)(int))toupper);

		KeyMap							&roKeyList = (m_mapSectionList.find(m_strSectionName)->second).KeyList;
		pair<KeyMap::iterator, bool>	result;

		//result = roKeyList.insert(KeyMap::value_type(strKeyName, Key(FLAG_UPDATED, pszValue)));
		result = roKeyList.insert(KeyMap::value_type(strKeyName, Key(pszValue)));
		if (!result.second)
		{
			Key		&roKey = (result.first)->second;

			//roKey.Flags	= FLAG_UPDATED;
			roKey.Value		= pszValue;
		}

		//m_nOptions |= OPTION_CHANGED;
		return true;
	}

	return false;
}

bool IniFileConfig::DeleteKey(const char* pszKeyName)
{
	if (!m_strSectionName.empty())
	{
		string				strKeyName = pszKeyName;
		transform(strKeyName.begin(), strKeyName.end(), strKeyName.begin(), (int (*)(int))toupper);

		KeyMap				&roKeyList = (m_mapSectionList.find(m_strSectionName)->second).KeyList;
		KeyMap::iterator	it;

		if ((it = roKeyList.find(strKeyName)) != roKeyList.end())
		{
			//(it->second).Flags = FLAG_DELETED;

			//m_nOptions |= OPTION_CHANGED;
			return true;
		}
	}

	return false;
}

bool IniFileConfig::InsertSection(const char* /* pszSectionName */)
{
	//dolduri-개발: 
	return false;
}

bool IniFileConfig::DeleteSection(const char* /* pszSectionName */)
{
	//dolduri-개발: 
	return false;
}

void IniFileConfig::_Trim(std::string& rstrData) const
{
	size_t	nPos;

	// left
	nPos = rstrData.find_first_not_of("\x09\x0A\x0B\x0C\x0D\x20");
	if (nPos == std::string::npos)
	{
		rstrData.erase();
		return;
	}
	else if (nPos > 0)
		rstrData.erase(0, nPos);

	// right
	nPos = rstrData.find_last_not_of("\x09\x0A\x0B\x0C\x0D\x20");
	if (++ nPos < rstrData.size())
		rstrData.erase(nPos);
}
