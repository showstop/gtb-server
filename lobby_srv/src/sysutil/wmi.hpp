#if defined(_WIN32) || defined(_WIN64)
#pragma once
#include <vector>
#include <map>
#include <string>

class WmiImpl;

/**
	@brief WQL�� ���� ������ �����Ѵ�.
	@author kkkkkkman
	@data 2008-09-09

	@remark ����� Query�� �����ϰ� ������ ���� ���� �ͱ����� �����Ǿ� �մ�.
	       �ش� Ŭ������ �޼ҵ带 ȣ���Ϸ��� �� �� ������ �ʿ��ϴ�.
			( testMethod �� �ҽ��� ���� �Ѵ�. )

	@code
		// ���� ó��
		Wmi wmi;
		wmi.connect();
		Wmi::RowSet rs1;

		// ���� ����
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
	/// @brief Row ������ ������ ��� Row
	typedef std::map< std::wstring, std::wstring >	Row;
	/// @brief Row�� Set( �������� Row �� �����ϴ� ��찡 �ִ�. )
	typedef std::vector< Row >						RowSet;

	/// @brief ������
						Wmi();
	/// @brief �Ҹ���
						~Wmi();
	/** 
		@brief ���� WMI�� �����Ѵ�.
		@return ������ ��� true
		@remark ���� ���ÿ��� ������ �ǵ��� �Ǿ� �ִ�. ���� Ŭ������ ���� ����Ʈ ������ �ϵ��� �ص״�. ( ������ �������� �ʴ���, �׽�Ʈ ���� �ʾ��� )
	 */	
	bool				connect(void);
	/**
		@brief ������ �����Ѵ�.
	 */ 
	void				close();
	/**
		@brief WQL ������ �����Ѵ�. ���� ���� ����� RS�� ���ϵȴ�.
		@param query ������ ���� 
		@param rs ���� ���
		@return ������ true
	 */
	bool				runWql( const wchar_t* query, Wmi::RowSet& rs );
	/**
		@brief WMI class�� �Ӽ�ġ�� ���� ���� �´�.
		@param wmiClass WMI Class ��
		@param rs �����
		@return ���� ������ true
	 */
	bool				getClassProperties( const wchar_t * wmiClass, Wmi::RowSet& rs );
	/** 
		@brief �޼ҵ� ���� �׽�Ʈ
	 */
	bool				testMethod( const wchar_t* wmiClass, const wchar_t* methodName );

};
#endif