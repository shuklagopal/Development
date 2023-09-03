
// TestAppMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestAppMFC.h"
#include "TestAppMFCDlg.h"
#include "afxdialogex.h"
#include "DatabaseConnect.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestAppMFCDlg dialog




CTestAppMFCDlg::CTestAppMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestAppMFCDlg::IDD, pParent)
	, m_strPath1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestAppMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestAppMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ConnectDB, &CTestAppMFCDlg::OnBnClickedConnectdb)
END_MESSAGE_MAP()


// CTestAppMFCDlg message handlers

BOOL CTestAppMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestAppMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestAppMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestAppMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestAppMFCDlg::OnBnClickedConnectdb()
{
	try
	{
	 // TODO: Add your control notification handler code here
	  //CString Path = GetSQLServerDefaultPath();

	  /*CInternetSession abc(L"MyProgram");
	  abc.GetHttpConnection(L"http://www.bovada.com/");
	  CStdioFile* File= abc.OpenURL(L"http://msdn.microsoft.com/en-us/library/59kzsz14.aspx");*/



		

		   typedef bool (*ptrtoFun)(char* );
		   HMODULE hModule = LoadLibraryA("MessagesDLL");
		   DWORD dw = GetLastError(); 
		   ptrtoFun FunCall = (ptrtoFun) GetProcAddress(hModule, "WDC_ProcessHardwareID");
		   CStringA ptrID ="111-222-333";
		   FunCall(ptrID.GetBuffer());
		
		   typedef bool(*ptrtoFunAdd)(int);
		   ptrtoFunAdd FunCallAdd = (ptrtoFunAdd)GetProcAddress(hModule, "Add");
		   FunCallAdd(23);
		   

	  //
	    CInternetSession nsMySession( L"My Program" ); 
        CHttpFile *pFile ;
		TCHAR pBuffer[200]; 

        CString sNewInput, sHttpFile = _T( "" ) ; 
        nsMySession.EnableStatusCallback() ; 
        /*pFile = nsMySession.OpenURL(L"http://www.google.com/", 
                NULL, INTERNET_FLAG_RELOAD ) ; */

		pFile = (CHttpFile*)nsMySession.OpenURL(L"http://www.bovada.com/",1,INTERNET_FLAG_TRANSFER_ASCII) ; 

        if ( pFile != NULL ) 
        { 
               //while ( pFile->ReadString( sNewInput ) ) 
			    while ( pFile->ReadString( pBuffer,200 ) ) 
                { 
                        sHttpFile += (LPSTR)pBuffer ; 
                        sHttpFile += _T( "\r\n" ) ; 
                } 
                //m_site.SetWindowText( sHttpFile ) ; 
                pFile->Close() ; 
        } 
        else 
        { 
                //AfxMessageBox( "Not parsed correctly", MB_OK|MB_ICONINFORMATION ); 
        } 
        //delete pFile ; 
        nsMySession.Close() ; 
	  //
  
	}
	catch(...)
	{}
}
