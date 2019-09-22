#ifndef __K_SB_FILE_PATH_FINDER__
#define __K_SB_FILE_PATH_FINDER__


namespace helper
{
#if defined(WIN32) || defined(_WIN64)

	inline std::string ExtractFileDrive(const std::string &strFileName)
	{
		std::string strDrive = strFileName;
		std::string::size_type nPos = strDrive.rfind(":");
		if (nPos != std::string::npos)
		{
			strDrive.resize(nPos + 1);
			strDrive.append("\\");
			return strDrive;
		}

		return std::string();
	}

	inline std::string ExtractFilePath(const std::string &strFileName)
	{
		std::string strPath = strFileName;
		std::string::size_type nPos = strPath.rfind("\\");
		if (nPos != std::string::npos)
		{
			strPath.resize(nPos + 1);
			return strPath;
		}

		return std::string();
	}

	inline std::string GetAbsPathName(const std::string &strPathName)
	{
		std::string strResult;

		char szBuffer[MAX_PATH];
		if (ExtractFileDrive(strPathName).empty() == false)
		{
			strResult = strPathName;
		}
		else
		{
			GetModuleFileNameA(NULL, szBuffer, MAX_PATH);
			strResult = ExtractFilePath(szBuffer);

			if (strPathName.empty() == false)
			{
				memset(szBuffer, 0, sizeof(char) * MAX_PATH);
				GetFullPathNameA((strResult + strPathName).c_str(), MAX_PATH, szBuffer, NULL);
				strResult = szBuffer;
			}
		}
		return strResult;
	}

#else

	inline std::string GetAbsPathName(const std::string &strPathName)
	{
		return strPathName;
	}

#endif
}

#endif