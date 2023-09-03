
// TestAppMFCDlg.h : header file
//

#pragma once
#include "DatabaseConnect.h"
#include "afxwin.h"

// CTestAppMFCDlg dialog
class CTestAppMFCDlg : public CDialogEx
{
// Construction
public:
	CTestAppMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTAPPMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConnectdb();

private:
	//ConnectToDB m_ObjConnectDB;
public:
	CStatic m_strPath;
	CString m_strPath1;
};
