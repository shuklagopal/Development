//Class to connect different databases like access/sql Server
//Link to import ADO objects: http://stackoverflow.com/questions/6552215/c-importing-and-using-ado
//Import help:http://stackoverflow.com/questions/6552215/c-importing-and-using-ado
//To use ADO:http://msdn.microsoft.com/en-us/library/windows/desktop/ms675103%28v=vs.85%29.aspx

#include<afxdb.h>
#import "msado15.dll" rename_namespace("ADO") rename("EOF", "EndOfFile") no_implementation


//class ConnectToDB
//{
//	CDatabase m_Dbconnect; 
//
//public:
//	//ConnectToDB()
//	//{
//	//	m_Dbconnect.Open(_T("MSAccessDSN"));
//
//	//	/*CoInitialize(NULL);
//	//    ADO::_Recordset rd;*/
//	//}
//	bool ConnectDB(); //Connect to database
//	bool ExecuteQry(CString qryStr);
//
//};

const CString GetSQLServerDefaultPath();