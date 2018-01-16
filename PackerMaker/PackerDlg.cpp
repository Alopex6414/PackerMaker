// PackerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "PackerDlg.h"
#include "afxdialogex.h"

#include "Common.h"
#include "PackerThread.h"

// CPackerDlg 对话框

IMPLEMENT_DYNAMIC(CPackerDlg, CDialogEx)

CPackerDlg::CPackerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPackerDlg::IDD, pParent)
{
	ConstructionExtra();
}

CPackerDlg::~CPackerDlg()
{
	if (m_pPlumPackerThread)
	{
		m_pPlumPackerThread->PlumThreadExit();
		delete m_pPlumPackerThread;
		m_pPlumPackerThread = NULL;
	}
}

void CPackerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PACKER_LIST, m_gbxPackerConfig);
	DDX_Control(pDX, IDC_STATIC_PACKER_PROCESS, m_gbxPackerProgress);
	DDX_Control(pDX, IDC_STATIC_PACKER_CONFIGTIP, m_sticPackerConfigTip);
	DDX_Control(pDX, IDC_STATIC_PACKER_PROGRESSTIP, m_sticPackerProgressTip);
	DDX_Control(pDX, IDC_BUTTON_PACKER_ADD, m_btnAdd);
	DDX_Control(pDX, IDC_BUTTON_PACKER_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_PACKER_DELETE, m_btnDelete);
	DDX_Control(pDX, IDC_BUTTON_PACKER_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_PACKER_OK, m_btnOk);
	DDX_Control(pDX, IDC_LIST_PACKER, m_lstPackerList);
	DDX_Control(pDX, IDC_PROGRESS_PACKER, m_prgPackerProgress);
	DDX_Control(pDX, IDC_STATIC_PACKER_PACKERSTATE, m_sticConvertStateTip);
}


BEGIN_MESSAGE_MAP(CPackerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_PACKER_ADD, &CPackerDlg::OnBnClickedButtonPackerAdd)
	ON_BN_CLICKED(IDC_BUTTON_PACKER_MODIFY, &CPackerDlg::OnBnClickedButtonPackerModify)
	ON_BN_CLICKED(IDC_BUTTON_PACKER_DELETE, &CPackerDlg::OnBnClickedButtonPackerDelete)
	ON_BN_CLICKED(IDC_BUTTON_PACKER_CANCEL, &CPackerDlg::OnBnClickedButtonPackerCancel)
	ON_BN_CLICKED(IDC_BUTTON_PACKER_OK, &CPackerDlg::OnBnClickedButtonPackerOk)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPackerDlg 消息处理程序


BOOL CPackerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CPackerDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	RePaintWindow(dc);
}


//------------------------------------------
// CPackerDlg ~用户定义函数
//------------------------------------------

// CPackerDlg ~构造函数
void CPackerDlg::ConstructionExtra()
{
	m_vecFilePath.clear();
	m_csPackerFileType = L"pak";
	m_csPackerFileName = L"MyPack";
	m_csExport = L"C:\\MyPack.pak";

	m_pPlumPackerThread = NULL;

	m_nCheck = 0;
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

// CPackerDlg ~初始化窗口形状
void CPackerDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CPackerDlg ~设置窗口数据
void CPackerDlg::SetWindowData(int* pArray, int nCheck)
{
	m_nCheck = nCheck;
	for (int i = 0; i < 16; ++i)
	{
		m_nArray[i] = *(pArray + i);
	}
}

// CPackerDlg ~初始化窗口布局
void CPackerDlg::InitWindowLayOut()
{
	int X = 0;
	int Y = 0;
	int nWidth = 0;
	int nHeight = 0;
	int TempX = 0;
	int TempY = 0;
	CRect Rect;

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() * 2 / 3;
	m_gbxPackerConfig.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticPackerConfigTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticPackerConfigTip.GetWindowRect(&Rect);

	X += 310;
	Y += 20;
	m_btnAdd.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnAdd.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 0;
	m_btnDelete.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnDelete.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 0;
	m_btnModify.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnModify.GetWindowRect(&Rect);

	X = m_cWindowRect.left + 10;
	Y += Rect.Height() + 10;
	nWidth = m_cWindowRect.Width() - 20;
	nHeight = m_cWindowRect.Height() * 2 / 3 - Y - 10;
	m_lstPackerList.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);
	m_lstPackerList.GetWindowRect(&Rect);

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top + m_cWindowRect.Height() * 2 / 3;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() / 4;
	m_gbxPackerProgress.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	X += 20;
	Y += nHeight / 3 - 5;
	m_sticPackerProgressTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticPackerProgressTip.GetWindowRect(&Rect);
	m_sticConvertStateTip.SetWindowPos(NULL, X + 400, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);

	X += 0;
	Y += Rect.Height() + 10;
	m_prgPackerProgress.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_prgPackerProgress.GetWindowRect(&Rect);

	X = m_cWindowRect.right - 75;
	Y = m_cWindowRect.bottom - 24;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height();
	m_btnOk.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnOk.GetWindowRect(&Rect);

	X += -Rect.Width() - 20;
	Y += 0;
	m_btnCancel.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnCancel.GetWindowRect(&Rect);
}

// CPackerDlg ~初始化窗口控件布局
void CPackerDlg::InitWindowItemLayOut()
{
	// 关于ListCtrl
	m_lstPackerList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lstPackerList.InsertColumn(0, L"", LVCFMT_CENTER, 0);
	m_lstPackerList.InsertColumn(1, L"Serial", LVCFMT_CENTER, 50);
	m_lstPackerList.InsertColumn(2, L"File Name", LVCFMT_CENTER, 150);
	m_lstPackerList.InsertColumn(3, L"File Path", LVCFMT_CENTER, m_cWindowRect.Width() - 220);

	// 关于ProgressBar
	m_gbxPackerProgress.ShowWindow(SW_HIDE);
	m_sticPackerProgressTip.ShowWindow(SW_HIDE);
	m_prgPackerProgress.ShowWindow(SW_HIDE);
	m_sticConvertStateTip.ShowWindow(SW_HIDE);
}

// CPackerDlg ~重绘窗口
void CPackerDlg::RePaintWindow(CDC& dc)
{
	CDC MemDC;
	CBitmap MemBitmap;
	CRect MemRect;

	GetClientRect(&MemRect);

	MemDC.CreateCompatibleDC(&dc);
	MemBitmap.CreateCompatibleBitmap(&dc, MemRect.Width(), MemRect.Height());

	MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(&MemRect, RGB(255, 255, 255)); // RGB(110, 142, 199)

	dc.BitBlt(m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), &MemDC, MemRect.left, MemRect.top, SRCCOPY);

	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}

// CPackerDlg ~刷新列表
void CPackerDlg::UpdateListCtrl(vector<CString>& vecFilePath)
{
	int nCount;

	m_lstPackerList.DeleteAllItems();
	nCount = vecFilePath.size();

	for (int i = 0; i < nCount; ++i)
	{
		CString csTemp;
		CString csFileName;

		csTemp.Format(L"%d", i + 1);

		csFileName = vecFilePath[i];
		csFileName = csFileName.Right(csFileName.GetLength() - csFileName.ReverseFind('\\') - 1);

		m_lstPackerList.InsertItem(i, L"");
		m_lstPackerList.SetItemText(i, 1, csTemp);
		m_lstPackerList.SetItemText(i, 2, csFileName);
		m_lstPackerList.SetItemText(i, 3, vecFilePath[i]);
	}
}

//------------------------------------------
// CPackerDlg ~控件响应函数
//------------------------------------------

// CPackerDlg ~添加封包文件
void CPackerDlg::OnBnClickedButtonPackerAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = TRUE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"C:\\";
	csFileName = L"";
	csFileFilter = L"文件|||";

	DWORD dwFileNumbers = 1000;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY, csFileFilter, NULL);
	INT_PTR nResult;

	POSITION pos = 0;
	CString strFile;
	TCHAR *pBufOld = FileDlg.m_ofn.lpstrFile;
	DWORD dwMaxOld = FileDlg.m_ofn.nMaxFile;

	FileDlg.m_ofn.lpstrFile = new TCHAR[dwFileNumbers * MAX_PATH];
	ZeroMemory(FileDlg.m_ofn.lpstrFile, sizeof(TCHAR) * dwFileNumbers * MAX_PATH);
	FileDlg.m_ofn.nMaxFile = dwFileNumbers * MAX_PATH;
	
	nResult = FileDlg.DoModal();

	if (nResult != IDOK)
	{
		delete[](FileDlg.m_ofn.lpstrFile);
		FileDlg.m_ofn.lpstrFile = pBufOld;
		FileDlg.m_ofn.nMaxFile = dwMaxOld;
		return;
	}

	m_vecFilePath.clear();
	pos = FileDlg.GetStartPosition();
	while (pos)
	{
		strFile = FileDlg.GetNextPathName(pos);
		m_vecFilePath.push_back(strFile);
	}

	UpdateListCtrl(m_vecFilePath);

	delete[](FileDlg.m_ofn.lpstrFile);
	FileDlg.m_ofn.lpstrFile = pBufOld;
	FileDlg.m_ofn.nMaxFile = dwMaxOld;
}

// CPackerDlg ~修改封包文件
void CPackerDlg::OnBnClickedButtonPackerModify()
{
	// TODO:  在此添加控件通知处理程序代码
	CMoreDlg dlg;
	INT_PTR nResult;
	dlg.SetWindowData(m_csPackerFileType, m_csPackerFileName, m_csExport);
	nResult = dlg.DoModal();
	if (nResult == IDOK)
	{
		m_csPackerFileType = dlg.m_csFileType;
		m_csPackerFileName = dlg.m_csFileName;
		m_csExport = dlg.m_csExport;
	}

}

// CPackerDlg ~删除封包文件
void CPackerDlg::OnBnClickedButtonPackerDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	int nCount = m_lstPackerList.GetItemCount();

	for (int i = m_lstPackerList.GetItemCount() - 1; i > 0; --i)
	{
		if (m_lstPackerList.GetItemState(i, LVNI_SELECTED) == LVIS_SELECTED)
		{
			m_lstPackerList.DeleteItem(i);
			m_vecFilePath.erase(m_vecFilePath.begin() + i);
		}
	}

	if (m_lstPackerList.GetItemState(0, LVNI_SELECTED) == LVIS_SELECTED)
	{
		m_lstPackerList.DeleteItem(0);
		m_vecFilePath.erase(m_vecFilePath.begin());
	}

	UpdateListCtrl(m_vecFilePath);
}

// CPackerDlg ~取消
void CPackerDlg::OnBnClickedButtonPackerCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	GetParent()->SendMessage(WM_CLOSE);
	OnCancel();
}

// CPackerDlg ~确定
void CPackerDlg::OnBnClickedButtonPackerOk()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_vecFilePath.empty())
	{
		MessageBox(L"Please Select at least One to Packer!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	if (m_csExport == L"")
	{
		return;
	}

	m_gbxPackerProgress.ShowWindow(SW_SHOW);
	m_sticPackerProgressTip.ShowWindow(SW_SHOW);
	m_prgPackerProgress.ShowWindow(SW_SHOW);
	m_sticConvertStateTip.ShowWindow(SW_SHOW);

	m_prgPackerProgress.SetRange(0, m_vecFilePath.size());
	m_prgPackerProgress.SetStep(1);
	m_prgPackerProgress.SetPos(0);
	m_btnOk.EnableWindow(FALSE);

	KillTimer(0);
	SetTimer(0, 100, NULL);

	DWORD dwLuckyNumberArr[4] =
	{
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
	};

	for (int i = 0; i < 4; ++i)
	{
		dwLuckyNumberArr[i] = m_nArray[4 * i + 0] * (1 << 24)
			+ m_nArray[4 * i + 1] * (1 << 16)
			+ m_nArray[4 * i + 2] * (1 << 8)
			+ m_nArray[4 * i + 3] * (1 << 0);
	}

	for (int i = 0; i < 4; ++i)
	{
		g_dwLuckyArr[i] = dwLuckyNumberArr[i];
	}

	int nSize;
	int nLen;

	nSize = m_vecFilePath.size();
	g_nSrcSize = m_vecFilePath.size();
	g_ppSrcArr = (char**)malloc(nSize*sizeof(char*));
	for (int i = 0; i < nSize; ++i)
	{
		nLen = WideCharToMultiByte(CP_ACP, 0, m_vecFilePath[i], -1, NULL, 0, NULL, NULL);
		*(g_ppSrcArr + i) = (char*)malloc((nLen + 1)*sizeof(char));
		WideCharToMultiByte(CP_ACP, 0, m_vecFilePath[i], -1, *(g_ppSrcArr + i), nLen, NULL, NULL);
	}

	nLen = WideCharToMultiByte(CP_ACP, 0, m_csExport, -1, NULL, 0, NULL, NULL);
	g_pDestArr = (char*)malloc((nLen + 1)*sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, m_csExport, -1, g_pDestArr, nLen, NULL, NULL);

	if (m_pPlumPackerThread)
	{
		m_pPlumPackerThread->PlumThreadExit();
		delete m_pPlumPackerThread;
		m_pPlumPackerThread = NULL;
	}

	g_nPackerCheck = m_nCheck;

	m_pPlumPackerThread = new CPlumThread(&m_PackerThread);
	m_pPlumPackerThread->PlumThreadInit();

}


void CPackerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString csConvertCount;
	CString csAllCount;

	switch (nIDEvent)
	{
	case 0:
		//EnterCriticalSection(&g_cs);

		csConvertCount.Format(L"%d", g_nPackerCount);
		csAllCount.Format(L"%d", m_vecFilePath.size());

		m_prgPackerProgress.SetPos(g_nPackerCount);
		m_sticConvertStateTip.SetWindowText(csConvertCount + L" Completed, " + csAllCount + L" In Total.");
		if (g_nPackerCount == m_vecFilePath.size())
		{
			m_sticConvertStateTip.SetWindowText(L"Finish!");
			m_btnOk.EnableWindow(TRUE);
			KillTimer(0);
		}
		
		//LeaveCriticalSection(&g_cs);
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
