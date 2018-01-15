// MoreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "MoreDlg.h"
#include "afxdialogex.h"


// CMoreDlg �Ի���

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


// CMoreDlg ��Ϣ�������

BOOL CMoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

// CMoreDlg ~���캯��
void CMoreDlg::ConstructionExtra()
{

}

// CMoreDlg ~��ʼ������
void CMoreDlg::SetWindowData(CString& csFileType, CString& csFileName, CString& csExport)
{
	m_csFileType = csFileType;
	m_csFileName = csFileName;
	m_csExport = csExport;
}


// CMoreDlg ~��ʼ�����ڿؼ�
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	csFileFilter = L"�ļ� (*." + csPackerType + L")|*." + csPackerType + L"||";

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}


void CMoreDlg::OnBnClickedButtonMoreOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
