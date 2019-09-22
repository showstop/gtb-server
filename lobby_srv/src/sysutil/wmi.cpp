#if defined(_WIN32) || defined(_WIN64)
#include "wmi.hpp"

#ifndef _WIN32_DCOM
#define _WIN32_DCOM
#endif

#pragma comment( lib, "wbemuuid.lib" )
#pragma comment( lib, "comsupp.lib" )

#include <comdef.h>
#include <wbemidl.h>

//-----------------------------------------------------------------------------
// class WmiImpl 
//-----------------------------------------------------------------------------

/**
	@brief WQL�� ���� Wmi Provider�� ������ �����Ѵ�. ( ���� )
	@author kkkkkkman
	@data 2008-09-09
 */
class WmiImpl
{
	/// @brief IWbemServices�� ������
	IWbemServices*		m_svc;
	/// @brief IWbemLocator�� ������
	IWbemLocator*		m_loc;
	/// @brief �ʱ�ȭ ����
	bool				m_init;
public:
	
	/**
		@brief ������
	 */
						WmiImpl() : m_svc(NULL), m_loc(NULL), m_init(false) 
	{}
	
	/**
		@brief �Ҹ���
	 */
						~WmiImpl()
	{
		close();
	}

	/** 
		@brief ���� WMI�� �����Ѵ�.
		@return ������ ��� true
	 */	
	bool				connect(const wchar_t *host, const wchar_t* pszName, const wchar_t* pszPwd)
	{
		close();

		HRESULT            result;
		// COM ���̺귯���� �ʱ�ȭ �Ѵ�. (initializes the COM library)
		result = CoInitializeEx( 0, COINIT_MULTITHREADED );
		if( FAILED( result ) ) {
			return false;
		}
		// ���� ���ؽ�Ʈ�� �ʱ�ȭ (setup process-wide security context)
		result = CoInitializeSecurity( NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL ); 
        if (RPC_E_TOO_LATE != result && S_OK != result){
		//if( FAILED( result ) ) {
			CoUninitialize();
			return false;
		}

		// connect to WMI
		result = CoCreateInstance( CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, ( LPVOID * )&m_loc );
        if( FAILED( result ) ) {
			CoUninitialize();
			return false;
		}

		if(  host == NULL || pszPwd == NULL || pszPwd == NULL )
		{
			result = m_loc->ConnectServer( _bstr_t( L"ROOT\\CIMV2" ), NULL, NULL, 0, NULL, 0, 0, &m_svc );
			if( FAILED( result ) ) {
				CoUninitialize();
				return false;
			}
		}
		else
		{
			wchar_t buffer[100];
            
            // For security
			swprintf_s( buffer, L"\\\\%s\\ROOT\\CIMV2", host );            
            //FUNC_SWPRINTF_SAFE( buffer, L"\\\\%s\\ROOT\\CIMV2", host );
			
            result = m_loc->ConnectServer( _bstr_t( buffer ), _bstr_t(pszName), _bstr_t(pszPwd), 0, NULL, 0, 0, &m_svc );
			if( FAILED( result ) ) {
				CoUninitialize();
				return false;
			}
		}

		result = CoSetProxyBlanket( m_svc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE );
		if( FAILED( result ) ) {
			CoUninitialize();
			return false;
		}

		m_init = true;

		return true;
	}

	/**
		@brief ������ �����Ѵ�.
	 */ 
	void close() 
	{
		if( !m_init )
			return ;

		if( m_svc ) {
			m_svc->Release();
			m_svc = NULL;
		}

		if( m_loc ) {
            m_loc->Release();
			m_loc = NULL;
		}
		// closes the OLE Component Object Model (COM) library
		CoUninitialize();
	}

	/**
		@brief WQL ������ �����Ѵ�. ���� ���� ����� RS�� ���ϵȴ�.
		@param query ������ ���� 
		@param rs ���� ���
		@return ������ true
	 */
	bool runWql( const wchar_t* query, Wmi::RowSet& rs )
	{
		if( !m_init ) {
			return false;
		}
		rs.clear();
		HRESULT                 ret;
		IEnumWbemClassObject *  pEnumerator = NULL;
		// ������ �����Ѵ�. ( execute a query )
		ret = m_svc->ExecQuery( L"WQL", _bstr_t(query), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator );
		if( FAILED( ret ) ) {
			return false;
		}
		if( pEnumerator )
		{
			IWbemClassObject *      clsObj[32];
			ULONG                   uReturn = 0;
			// enumeration ���� ���� ClassObject �ν��Ͻ��� �����´�. ( �ִ� 32�� ) 
			ret = pEnumerator->Next( /*WBEM_INFINITE*/2000, 32, clsObj, &uReturn );
			if( uReturn > 0 ) 
			{
				rs.resize( uReturn );
				for( ULONG i=0;i<uReturn;++i )
				{
					//-----------------------------------------------------------------------------
					// classobj�� ��� Properties�� enumerating �ؼ� ���� Map���� �����Ѵ�. 
					//-----------------------------------------------------------------------------
					Wmi::Row& r = rs[i];
					VARIANT vtProp;
					VariantInit( &vtProp );
					
					ret = clsObj[i]->BeginEnumeration( WBEM_FLAG_NONSYSTEM_ONLY );
					if( FAILED( ret ) )
					{
						clsObj[i]->Release();
						continue;
					}
					CIMTYPE	pvtType; VARIANT pVal; BSTR pstrName;
					// ������ Property���� Map�� �Ҵ��Ѵ�.
					while( clsObj[i]->Next( 0, &pstrName, &pVal, &pvtType, NULL ) == WBEM_S_NO_ERROR ) 
					{
						// ����&�迭 ���� ����
						if( (pVal.vt & 0xf000) == 0 )
						{
							if( pVal.vt != VT_NULL ) {
								_bstr_t str = pVal;
								r[ pstrName ] = str;
							}
							else
							{
								r[ pstrName ] = L"";
							}
						}
						else
						{
							r[ pstrName ] = L"";
						}
						SysFreeString( pstrName );
						VariantClear( &pVal );
					}
					clsObj[i]->Release();
				}
			}
			else
			{
                char tmp[255]={0, };
                wcstombs(tmp, query, wcslen(query));
			}
			pEnumerator->Release();
			if( uReturn == 0 )
				return false;
		}        
		return true;
	}

	/**
		@brief WMI class�� �Ӽ�ġ�� ���� ���� �´�.
		@param wmiClass WMI Class ��
		@param rs �����
		@return ���� ������ true
	 */
	bool getClassProperties( const wchar_t * wmiClass, Wmi::RowSet& rs )
	{
		std::wstring wquery;

		wquery += L"SELECT * FROM ";
		wquery += wmiClass;

		return runWql( wquery.c_str(), rs );
	}

	bool testMethod( const wchar_t* wmiClass, const wchar_t* methodName )
	{
		HRESULT ret;
		// set up to call the Win32_Process::Create method
		BSTR MethodName = SysAllocString(L"Create");
		BSTR ClassName = SysAllocString(L"Win32_Process");

		IWbemClassObject* pClass = NULL;
        IWbemClassObject* pInParamsDefinition = NULL;
        IWbemClassObject* pClassInstance = NULL;
        IWbemClassObject* pOutParams = NULL;

		ret = m_svc->GetObject(ClassName, 0, NULL, &pClass, NULL);
		if( FAILED( ret ) ) {
			goto emError;
		}

        if (NULL == pClass)
        {
            goto emError;
        }

		ret = pClass->GetMethod(MethodName, 0, &pInParamsDefinition, NULL);
		if( FAILED( ret ) ) {
			goto emError;
		}

        if (NULL == pInParamsDefinition)
        {
            goto emError;
        }

		ret = pInParamsDefinition->SpawnInstance(0, &pClassInstance);
		if( FAILED( ret ) ) {
			goto emError;
		}

        if (NULL == pClassInstance)
        {
            goto emError;
        }

		// Create the values for the in parameters
		VARIANT varCommand;
		varCommand.vt = VT_BSTR;
		varCommand.bstrVal = L"notepad.exe";

		// Store the value for the in parameters
		ret = pClassInstance->Put(L"CommandLine", 0, &varCommand, 0);

		// Execute Method
		ret = m_svc->ExecMethod(ClassName, MethodName, 0, NULL, pClassInstance, &pOutParams, NULL);
		if( FAILED( ret ) ) {
			goto emError;
		}
        if (NULL == pOutParams)
        {
            goto emError;
        }
		SysFreeString( MethodName );
		SysFreeString( ClassName );

		if(pOutParams)
			pOutParams->Release();
		if(pClassInstance)
			pClassInstance->Release();
		if( pInParamsDefinition )
			pInParamsDefinition->Release();
		if( pClass )
			pClass->Release();

		return true;

emError:

		SysFreeString( MethodName );
		SysFreeString( ClassName );

		if(NULL != pOutParams)
			pOutParams->Release();
		if(NULL != pClassInstance)
			pClassInstance->Release();
		if(NULL != pInParamsDefinition )
			pInParamsDefinition->Release();
		if(NULL != pClass )
			pClass->Release();

		return true;
	}
};


//-----------------------------------------------------------------------------
// class Wmi 
//-----------------------------------------------------------------------------
Wmi::Wmi()
{
	m_impl = new WmiImpl;
}

Wmi::~Wmi()
{
    if (NULL != m_impl)
    {
	delete m_impl;
        m_impl = NULL;
    }	
}

void Wmi::close()
{
	m_impl->close();
}

bool Wmi::runWql( const wchar_t* query, Wmi::RowSet& rs )
{
	return m_impl->runWql( query, rs );
}
bool Wmi::connect(void)
{
	return m_impl->connect(0,0,0);
}

bool Wmi::getClassProperties( const wchar_t * wmiClass, Wmi::RowSet& rs )
{
	return m_impl->getClassProperties( wmiClass, rs );
}

bool Wmi::testMethod( const wchar_t* wmiClass, const wchar_t* methodName )
{
    return m_impl->testMethod( wmiClass, methodName );
}

#endif
