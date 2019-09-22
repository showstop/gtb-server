#if defined(_WIN32) || defined(_WIN64)
#pragma once
#include <vector>
#include <map>
#include <string>

class WmiImpl;

/**
	@brief WQL를 통해 쿼리를 실행한다.
	@author kkkkkkman
	@data 2008-09-09

	@remark 현재는 Query를 실행하고 정보를 가져 오는 것까지만 구현되어 잇다.
	       해당 클래스의 메소드를 호출하려면 좀 더 구현이 필요하다.
			( testMethod 의 소스를 참고 한다. )

	@code
		// 접속 처리
		Wmi wmi;
		wmi.connect();
		Wmi::RowSet rs1;

		// 핑을 날림
		wmi.runWql( L"SELECT * FROM Win32_PingStatus WHERE Address=\"119.196.12.37\"", rs1 );
		for( size_t i=0;i<rs1.size();++i )
		{
			Wmi::Row r = rs1[i];
			for( Wmi::Row::iterator it = r.begin(); it != r.end(); ++it )
			{
				std::wcout << (*it).first << ": " << (*it).second << std::endl;
			}
		}
	@endcode
 */
class Wmi
{
	WmiImpl*			m_impl;
public:
	/// @brief Row 쿼리를 실행한 결과 Row
	typedef std::map< std::wstring, std::wstring >	Row;
	/// @brief Row의 Set( 여러개의 Row 가 존재하는 경우가 있다. )
	typedef std::vector< Row >						RowSet;

	/// @brief 생성자
						Wmi();
	/// @brief 소멸자
						~Wmi();
	/** 
		@brief 로컬 WMI에 연결한다.
		@return 성공할 경우 true
		@remark 현재 로컬에만 연결이 되도록 되어 있다. 구현 클래스를 보면 리모트 연결을 하도록 해뒀다. ( 하지만 동작하지 않더라, 테스트 되지 않았음 )
	 */	
	bool				connect(void);
	/**
		@brief 연결을 종료한다.
	 */ 
	void				close();
	/**
		@brief WQL 쿼리를 실행한다. 쿼리 실행 결과는 RS로 리턴된다.
		@param query 실행한 쿼리 
		@param rs 실행 결과
		@return 성공시 true
	 */
	bool				runWql( const wchar_t* query, Wmi::RowSet& rs );
	/**
		@brief WMI class의 속성치를 전부 가져 온다.
		@param wmiClass WMI Class 명
		@param rs 결과셋
		@return 성공 했으면 true
	 */
	bool				getClassProperties( const wchar_t * wmiClass, Wmi::RowSet& rs );
	/** 
		@brief 메소드 실행 테스트
	 */
	bool				testMethod( const wchar_t* wmiClass, const wchar_t* methodName );

};
#endif