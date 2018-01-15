
// PackerMakerDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include "ConfigDlg.h"
#include "PackerDlg.h"
#include "UnPackerDlg.h"

// CPackerMakerDlg dialog
class CPackerMakerDlg : public CDialogEx
{
// Construction
public:
	CPackerMakerDlg(CWnd* pParent = NULL);	// standard constructor
	~CPackerMakerDlg();

// ��Ա
private:
	CRect m_cWindowRect;			//��������ߴ�
	CRect m_cTabMainRect;			//ѡ�����ߴ�
	CRect m_cChildRect;				//�Ӵ�������ߴ�

	CConfigDlg m_cConfigDlg;		//���öԻ���
	CPackerDlg m_cPackerDlg;		//����Ի���
	CUnPackerDlg m_cUnPackerDlg;	//����Ի���

public:
	CString m_csArray[16];
	CString m_csCheck;
	int m_nArray[16];
	int m_nCheck;

// ��Ա����
public:
	void ConstructionExtra();		//��ʼ�����캯��
	void InitWindowSharp();			//��ʼ��������״
	void InitWindowLayOut();		//��ʼ�����ڲ���
	void InitWindowItemLayOut();	//��ʼ�����ڿؼ�����
	void InitChildLayOut();			//��ʼ���Ӵ��ڲ���

	void ReadConfigFile();			//��ȡ�����ļ�
	void WriteConfigFile();			//д�������ļ�
	void ArrayCopy(int* pSrc, int* pDest, int nLen);

// Dialog Data
	enum { IDD = IDD_PACKERMAKER_DIALOG };

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
	CTabCtrl m_tabMain;
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnCancel();
};
