#include "stdafx.h"
#include"DatabaseConnect.h"

//Link to import ADO objects: http://stackoverflow.com/questions/6552215/c-importing-and-using-ado
//Import help:http://stackoverflow.com/questions/6552215/c-importing-and-using-ado
//To use ADO:http://msdn.microsoft.com/en-us/library/windows/desktop/ms675103%28v=vs.85%29.aspx
//ADO example codes vc++:http://msdn.microsoft.com/en-us/library/windows/desktop/ms677563(v=vs.85).aspx

#import "msado15.dll" rename_namespace("ADO") rename("EOF", "EndOfFile") implementation_only

//bool ConnectToDB::ConnectDB()
//{
//   //Connect to database
//	try
//	{
//		//m_Dbconnect.Open(_T("MSAccessDSN"));
//	return true;
//	}
//	catch(...)
//	{
//	   
//	}
//
//}
//
//bool ConnectToDB::ExecuteQry(CString qryStr)
//{
//   //Connect to database
//	try
//	{
//		
//	   return true;
//	}
//	catch(...)
//	{
//	   
//	}
//
//}

const CString GetSQLServerDefaultPath()
{
   //Step1.Connect to sql server
   //Step2.fire query
   //Step3.return result

   CoInitialize(NULL);
   try 
   {
      ADO::_RecordsetPtr pRs("ADODB.Recordset");
      ADO::_ConnectionPtr pCn("ADODB.Connection");
	  variant_t recordsCount; 
	  _variant_t vtDefaultDataPath;
	   CString DafaultPath("Path");
     
      pCn->Provider = "sqloledb";
      pCn->Open("Data Source='abc-pc';Initial Catalog='master';Integrated Security=SSPI", "", "", ADO::adConnectUnspecified);
     
	  //Note: Execute query
	  _bstr_t qryString= "SELECT SERVERPROPERTY('INSTANCEDEFAULTDATAPATH') as [Default_data_path], SERVERPROPERTY('INSTANCEDEFAULTLOGPATH') as [Default_log_path]";
	  pRs = pCn->Execute(qryString,&recordsCount,ADO::adOptionUnspecified ); 
	  pRs->MoveFirst();

      // Note: Get a field.
      vtDefaultDataPath = pRs->Fields->GetItem((long)0)->GetValue();
	  DafaultPath = vtDefaultDataPath.bstrVal; 
      // Note : Close objects
      pRs->Close();
      pCn->Close();

	  return DafaultPath;
   }
   catch (_com_error &e) {
      printf("Error:\n");
      printf("Code = %08lx\n", e.Error());
      printf("Code meaning = %s\n", (char*) e.ErrorMessage());
      printf("Source = %s\n", (char*) e.Source());
      printf("Description = %s\n", (char*) e.Description());
   }
   CoUninitialize();


}

