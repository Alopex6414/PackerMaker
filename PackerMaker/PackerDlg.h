#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "MoreDlg.h"
#include "MyListCtrl.h"
#include <vector>

#include "PlumThread.h"
#include "PackerThread.h"

using namespace std;

// CPackerDlg �Ի���

class CPackerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPackerDlg)

public:
	CPackerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPackerDlg();

// ��Ա
private:
	CRect m_cWindowRect;
	
	vector<CString> m_vecFilePath;
	CString m_csPackerFileType;
	CString m_csPackerFileName;
	CString m_csExport;

	CPackerThread m_PackerThread;
	CPlumThread* m_pPlumPackerThread;

public:
	int m_nArray[16];
	int m_nCheck;

// ��Ա����
public:
	void ConstructionExtra();

	const void SetWindowRect(CRect& Rect) { m_cWindowRect = Rect; }
	void SetWindowData(int* pArray, int nCheck);
	void InitWindowSharp();
	void InitWindowLayOut();
	void InitWindowItemLayOut();

	void RePaintWindow(CDC& dc);

	void UpdateListCtrl(vector<CString>& vecFilePath);

// �Ի�������
	enum { IDD = IDD_DIALOG_PACKER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CStatic m_gbxPackerConfig;
	CStatic m_gbxPackerProgress;
	CStatic m_sticPackerConfigTip;
	CStatic m_sticPackerProgressTip;
	CStatic m_sticConvertStateTip;
	CButton m_btnAdd;
	CButton m_btnModify;
	CButton m_btnDelete;
	CButton m_btnCancel;
	CButton m_btnOk;
	CMyListCtrl m_lstPackerList;
	CProgressCtrl m_prgPackerProgress;
	afx_msg void OnBnClickedButtonPackerAdd();
	afx_msg void OnBnClickedButtonPackerModify();
	afx_msg void OnBnClickedButtonPackerDelete();
	afx_msg void OnBnClickedButtonPackerCancel();
	afx_msg void OnBnClickedButtonPackerOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
