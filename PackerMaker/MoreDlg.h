#pragma once
#include "afxwin.h"


// CMoreDlg 对话框

class CMoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMoreDlg)

public:
	CMoreDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMoreDlg();

// 成员
private:

public:
	CString m_csFileType;
	CString m_csFileName;
	CString m_csExport;

// 成员函数
public:
	void ConstructionExtra();
	void SetWindowData(CString& csFileType, CString& csFileName, CString& csExport);
	void InitWindowItemLayOut();

// 对话框数据
	enum { IDD = IDD_DIALOG_MORE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_gbxMoreOption;
	CStatic m_sticConvertTypeTip;
	CEdit m_edtConvertType;
	CStatic m_sticConvertName;
	CEdit m_edtConvertName;
	CStatic m_sticPackerFilePath;
	CEdit m_edtPackerFileType;
	CButton m_btnExport;
	CButton m_btnCancel;
	CButton m_btnOk;
	afx_msg void OnBnClickedButtonMoreExport();
	afx_msg void OnBnClickedButtonMoreCancel();
	afx_msg void OnBnClickedButtonMoreOk();
};
