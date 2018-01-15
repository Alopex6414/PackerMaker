// MoreDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "MoreDlg.h"
#include "afxdialogex.h"


// CMoreDlg 对话框

IMPLEMENT_DYNAMIC(CMoreDlg, CDialogEx)

CMoreDlg::CMoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMoreDlg::IDD, pParent)
{
	ConstructionExtra();
}

CMoreDlg::~CMoreDlg()
{

}

void CMoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MORE_OPTIONS, m_gbxMoreOption);
	DDX_Control(pDX, IDC_STATIC_CONVERTTYPETIP, m_sticConvertTypeTip);
	DDX_Control(pDX, IDC_EDIT_MORE_CONVERTTYPE, m_edtConvertType);
	DDX_Control(pDX, IDC_STATIC_MORE_OPTIONTIP, m_sticPackerFilePath);
	DDX_Control(pDX, IDC_EDIT_MORE_OPTION, m_edtPackerFileType);
	DDX_Control(pDX, IDC_BUTTON_MORE_EXPORT, m_btnExport);
	DDX_Control(pDX, IDC_BUTTON_MORE_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_MORE_OK, m_btnOk);
	DDX_Control(pDX, IDC_STATIC_CONVERTNAME, m_sticConvertName);
	DDX_Control(pDX, IDC_EDIT_MORE_CONVERTNAME, m_edtConvertName);
}


BEGIN_MESSAGE_MAP(CMoreDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_MORE_EXPORT, &CMoreDlg::OnBnClickedButtonMoreExport)
	ON_BN_CLICKED(IDC_BUTTON_MORE_CANCEL, &CMoreDlg::OnBnClickedButtonMoreCancel)
	ON_BN_CLICKED(IDC_BUTTON_MORE_OK, &CMoreDlg::OnBnClickedButtonMoreOk)
END_MESSAGE_MAP()


// CMoreDlg 消息处理程序

BOOL CMoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

// CMoreDlg ~构造函数
void CMoreDlg::ConstructionExtra()
{

}

// CMoreDlg ~初始化数据
void CMoreDlg::SetWindowData(CString& csFileType, CString& csFileName, CString& csExport)
{
	m_csFileType = csFileType;
	m_csFileName = csFileName;
	m_csExport = csExport;
}


// CMoreDlg ~初始化窗口控件
void CMoreDlg::InitWindowItemLayOut()
{
	m_edtConvertType.LimitText(3);
	m_edtConvertName.LimitText(32);

	m_edtConvertType.SetWindowText(m_csFileType);
	m_edtConvertName.SetWindowText(m_csFileName);
	m_edtPackerFileType.SetWindowText(m_csExport);
}


void CMoreDlg::OnBnClickedButtonMoreExport()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = FALSE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"C:\\";
	csFileName = L"";

	m_edtConvertName.GetWindowText(csFileName);
	if (csFileName == L"")
	{
		MessageBox(L"Packer File Name Can not be Empty!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	CString csPackerType = L"";
	m_edtConvertType.GetWindowText(csPackerType);
	if (csPackerType == L"")
	{
		MessageBox(L"Packer File Type Can not be Empty!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}
	else if (csPackerType.Find('.') != -1)
	{
		MessageBox(L"Packer File Type Can not have '.'!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	csFileFilter = L"文件 (*." + csPackerType + L")|*." + csPackerType + L"||";

	CString csDefaultPath;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, csFileFilter, NULL);
	INT_PTR nResult;

	FileDlg.GetOFN().lpstrInitialDir = csDefaultPath;
	nResult = FileDlg.DoModal();
	if (nResult == IDOK)
	{
		csDefaultPath = FileDlg.GetPathName();
		m_csExport = csDefaultPath;
		m_edtConvertType.GetWindowText(m_csFileType);
		m_edtConvertName.GetWindowText(m_csFileName);
		m_edtPackerFileType.SetWindowText(csDefaultPath);
	}
}


void CMoreDlg::OnBnClickedButtonMoreCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
}


void CMoreDlg::OnBnClickedButtonMoreOk()
{
	// TODO:  在此添加控件通知处理程序代码
	OnOK();
}
