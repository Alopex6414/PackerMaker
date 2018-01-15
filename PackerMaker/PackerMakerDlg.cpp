
// PackerMakerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "PackerMakerDlg.h"
#include "afxdialogex.h"

#include "Common.h"
#include "PackerThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRITICAL_SECTION g_cs;

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


// CPackerMakerDlg dialog



CPackerMakerDlg::CPackerMakerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPackerMakerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	InitializeCriticalSection(&g_cs);
}

CPackerMakerDlg::~CPackerMakerDlg()
{
	DeleteCriticalSection(&g_cs);
}

void CPackerMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);
}

BEGIN_MESSAGE_MAP(CPackerMakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CPackerMakerDlg::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// CPackerMakerDlg message handlers

BOOL CPackerMakerDlg::OnInitDialog()
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
	ConstructionExtra();
	ReadConfigFile();
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();
	InitChildLayOut();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPackerMakerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPackerMakerDlg::OnPaint()
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
HCURSOR CPackerMakerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//------------------------------------------
// CPackerMakerDlg ~用户定义函数
//------------------------------------------

// CPackerMakerDlg ~初始化构造函数
void CPackerMakerDlg::ConstructionExtra()
{
	m_nCheck = 0;
	m_csCheck = L"";
	memset(m_nArray, 0, 16);

	m_nArray[0] = 170;
	m_nArray[1] = 187;
	m_nArray[2] = 204;
	m_nArray[3] = 221;

	m_nArray[4] = 18;
	m_nArray[5] = 72;
	m_nArray[6] = 132;
	m_nArray[7] = 33;

	m_nArray[8] = 18;
	m_nArray[9] = 52;
	m_nArray[10] = 86;
	m_nArray[11] = 120;

	m_nArray[12] = 255;
	m_nArray[13] = 255;
	m_nArray[14] = 255;
	m_nArray[15] = 255;
}

// CPackerMakerDlg ~初始化窗口形状
void CPackerMakerDlg::InitWindowSharp()
{
	int X = 0;
	int Y = 0;
	int nScreenWidth = 0;
	int nScreenHeight = 0;

	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (nScreenWidth >= USER_WIDTH && nScreenHeight >= USER_HEIGHT)
	{
		X = (nScreenWidth - USER_WIDTH) >> 1;
		Y = (nScreenHeight - USER_HEIGHT) >> 1;
	}

	m_cWindowRect.left = X;
	m_cWindowRect.top = Y;
	m_cWindowRect.right = m_cWindowRect.left + USER_WIDTH;
	m_cWindowRect.bottom = m_cWindowRect.top + USER_HEIGHT;

	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_SHOWWINDOW);
}

// CPackerMakerDlg ~初始化窗口布局
void CPackerMakerDlg::InitWindowLayOut()
{
	CRect Rect;

	GetClientRect(&Rect);

	m_cTabMainRect.left = Rect.left + 10;
	m_cTabMainRect.top = Rect.top + 10;
	m_cTabMainRect.right = Rect.right - 10;
	m_cTabMainRect.bottom = Rect.bottom - 10;

	m_tabMain.SetWindowPos(NULL, m_cTabMainRect.left, m_cTabMainRect.top, m_cTabMainRect.Width(), m_cTabMainRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

// CPackerMakerDlg ~初始化窗口控件布局
void CPackerMakerDlg::InitWindowItemLayOut()
{
	m_tabMain.InsertItem(0, L"Packer");		//封包
	m_tabMain.InsertItem(1, L"UnPacker");	//解包
	m_tabMain.InsertItem(2, L"Config");		//设置

	m_tabMain.SetCurSel(0);
}

// CPackerMakerDlg ~初始化子窗口布局
void CPackerMakerDlg::InitChildLayOut()
{
	m_cChildRect = m_cTabMainRect;
	m_cChildRect.left += 10;
	m_cChildRect.top += 24;
	m_cChildRect.right -= 10;
	m_cChildRect.bottom -= 5;

	m_cPackerDlg.SetWindowRect(m_cChildRect);
	m_cPackerDlg.SetWindowData(m_nArray, m_nCheck);
	m_cPackerDlg.Create(IDD_DIALOG_PACKER, this);
	m_cPackerDlg.ShowWindow(SW_SHOW);

	m_cUnPackerDlg.SetWindowRect(m_cChildRect);
	m_cUnPackerDlg.SetWindowData(m_nArray, m_nCheck);
	m_cUnPackerDlg.Create(IDD_DIALOG_UNPACKER, this);
	m_cUnPackerDlg.ShowWindow(SW_HIDE);

	m_cConfigDlg.SetWindowRect(m_cChildRect);
	m_cConfigDlg.SetWindowData(m_nArray, m_nCheck);
	m_cConfigDlg.Create(IDD_DIALOG_CONFIG, this);
	m_cConfigDlg.ShowWindow(SW_HIDE);

	m_cPackerDlg.m_nCheck = m_cConfigDlg.m_nCheck;
	ArrayCopy(m_cConfigDlg.m_nArray, m_cPackerDlg.m_nArray, 16);

	m_cUnPackerDlg.m_nCheck = m_cConfigDlg.m_nCheck;
	ArrayCopy(m_cConfigDlg.m_nArray, m_cUnPackerDlg.m_nArray, 16);
}

// CPackerMakerDlg ~读取配置文件
void CPackerMakerDlg::ReadConfigFile()
{
	CFileFind File;
	CString FileName;
	BOOL IsFileExist;

	GetModuleFileName(AfxGetInstanceHandle(), FileName.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
	FileName = FileName.Left(FileName.ReverseFind('\\'));
	FileName += L"\\Config.ini";

	IsFileExist = File.FindFile(FileName);
	if (!IsFileExist)
	{
		return;
	}

	GetPrivateProfileString(L"PackerMaker Checked", L"Check", L"Can not Read Check Infomation!", m_csCheck.GetBuffer(MAX_PATH), MAX_PATH, FileName);
	m_csCheck.ReleaseBuffer();

	for (int i = 0; i < 16; ++i)
	{
		CString csNumber;
		csNumber.Format(L"%d", i);
		GetPrivateProfileString(L"PackerMaker Array", L"Lucky" + csNumber, L"Can not Read Array Infomation!", m_csArray[i].GetBuffer(MAX_PATH), MAX_PATH, FileName);
		m_csArray[i].ReleaseBuffer();
	}

	m_nCheck = _ttoi(m_csCheck);
	for (int i = 0; i < 16; ++i)
	{
		m_nArray[i] = _ttoi(m_csArray[i]);
	}

}

// CPackerMakerDlg ~写入配置文件
void CPackerMakerDlg::WriteConfigFile()
{
	CString FileName;
	CString csValue;

	m_nCheck = m_cConfigDlg.m_nCheck;
	ArrayCopy(m_cConfigDlg.m_nArray, m_nArray, 16);

	GetModuleFileName(AfxGetInstanceHandle(), FileName.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
	FileName = FileName.Left(FileName.ReverseFind('\\'));
	FileName += L"\\Config.ini";

	csValue.Format(L"%d", m_nCheck);
	WritePrivateProfileString(L"PackerMaker Checked", L"Check", csValue, FileName);
	for (int i = 0; i < 16; ++i)
	{
		CString csNumber;
		CString csValue;
		csNumber.Format(L"%d", i);
		csValue.Format(L"%d", m_nArray[i]);
		WritePrivateProfileString(L"PackerMaker Array", L"Lucky" + csNumber, csValue, FileName);
	}

}

// CPackerMakerDlg ~数组复制
void CPackerMakerDlg::ArrayCopy(int* pSrc, int* pDest, int nLen)
{
	for (int i = 0; i < nLen; ++i)
	{
		*(pDest + i) = *(pSrc + i);
	}
}

//------------------------------------------
// CPackerMakerDlg ~控件响应函数
//------------------------------------------

void CPackerMakerDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int nCurSel;

	nCurSel = m_tabMain.GetCurSel();
	switch (nCurSel)
	{
	case 0:
		m_cPackerDlg.m_nCheck = m_cConfigDlg.m_nCheck;
		ArrayCopy(m_cConfigDlg.m_nArray, m_cPackerDlg.m_nArray, 16);

		m_cPackerDlg.ShowWindow(SW_SHOW);
		m_cUnPackerDlg.ShowWindow(SW_HIDE);
		m_cConfigDlg.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_cUnPackerDlg.m_nCheck = m_cConfigDlg.m_nCheck;
		ArrayCopy(m_cConfigDlg.m_nArray, m_cUnPackerDlg.m_nArray, 16);

		m_cPackerDlg.ShowWindow(SW_HIDE);
		m_cUnPackerDlg.ShowWindow(SW_SHOW);
		m_cConfigDlg.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_cPackerDlg.ShowWindow(SW_HIDE);
		m_cUnPackerDlg.ShowWindow(SW_HIDE);
		m_cConfigDlg.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}

	*pResult = 0;
}


void CPackerMakerDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	WriteConfigFile();

	CDialogEx::OnCancel();
}
