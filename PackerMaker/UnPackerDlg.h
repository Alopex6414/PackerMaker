#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "PlumThread.h"
#include "UnPackerThread.h"

// CUnPackerDlg 对话框

class CUnPackerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUnPackerDlg)

public:
	CUnPackerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUnPackerDlg();

// 成员
private:
	CRect m_cWindowRect;

	CString m_csImport;
	CString m_csExport;

	CBrush m_Brush;

	CUnPackerThread m_UnPackerThread;
	CPlumThread* m_pPlumUnPackerThread;

public:
	int m_nArray[16];
	int m_nCheck;

// 成员函数
public:
	void ConstructionExtra();

	const void SetWindowRect(CRect& Rect) { m_cWindowRect = Rect; }
	void SetWindowData(int* pArray, int nCheck);
	void InitWindowSharp();
	void InitWindowLayOut();
	void InitWindowItemLayOut();

	void RePaintWindow(CDC& dc);

// 对话框数据
	enum { IDD = IDD_DIALOG_UNPACKER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CStatic m_gbxUnPackConfig;
	CStatic m_gbxUnPackerProgress;
	CStatic m_sticOriginFilePath;
	CEdit m_edtOriginFilePath;
	CStatic m_sticUnPackerFilePath;
	CEdit m_edtUnPackerFilePath;
	CButton m_btnImport;
	CButton m_btnExport;
	CStatic m_sticConvertState;
	CStatic m_sticConvertMark;
	CStatic m_sticUnPackerProgressTip;
	CStatic m_sticUnPackerState;
	CProgressCtrl m_prgUnPacker;
	CButton m_btnCancel;
	CButton m_btnOk;
	afx_msg void OnBnClickedButtonUnpackerOriginfilepath();
	afx_msg void OnBnClickedButtonUnpackerUnpackerfilepath();
	afx_msg void OnBnClickedButtonUnpackerCancel();
	afx_msg void OnBnClickedButtonUnpackerOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
