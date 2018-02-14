#pragma once
#include "afxwin.h"


// CConfigDlg 对话框

class CConfigDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigDlg();

// 成员
private:
	CRect m_cWindowRect;

	CBrush m_Brush;

public:
	CString m_csArray[16];
	CString m_csCheck;
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

	bool AnalysisText(CString cs, int* pCount);

// 对话框数据
	enum { IDD = IDD_DIALOG_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CStatic m_gbxPackerType;
	CStatic m_gbxLuckyNumber;
	CStatic m_sticPackerTypeTip;
	CStatic m_sticLuckyNumberTip;
	CStatic m_sticArray1;
	CStatic m_sticArray2;
	CStatic m_sticArray3;
	CStatic m_sticArray4;
	CStatic m_sticLink1;
	CStatic m_sticLink2;
	CStatic m_sticLink3;
	CStatic m_sticLink4;
	CStatic m_sticLink5;
	CStatic m_sticLink6;
	CStatic m_sticLink7;
	CStatic m_sticLink8;
	CStatic m_sticLink9;
	CStatic m_sticLink10;
	CStatic m_sticLink11;
	CStatic m_sticLink12;
	CEdit m_edtLucky1;
	CEdit m_edtLucky2;
	CEdit m_edtLucky3;
	CEdit m_edtLucky4;
	CEdit m_edtLucky5;
	CEdit m_edtLucky6;
	CEdit m_edtLucky7;
	CEdit m_edtLucky8;
	CEdit m_edtLucky9;
	CEdit m_edtLucky10;
	CEdit m_edtLucky11;
	CEdit m_edtLucky12;
	CEdit m_edtLucky13;
	CEdit m_edtLucky14;
	CEdit m_edtLucky15;
	CEdit m_edtLucky16;
	CButton m_btnDefault;
	CButton m_btnSave;
	afx_msg void OnBnClickedButtonConfigCancel();
	afx_msg void OnBnClickedButtonConfigOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
