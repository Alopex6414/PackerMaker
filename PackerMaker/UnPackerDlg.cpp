// UnPackerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "UnPackerDlg.h"
#include "afxdialogex.h"

// CUnPackerDlg 对话框

IMPLEMENT_DYNAMIC(CUnPackerDlg, CDialogEx)

CUnPackerDlg::CUnPackerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUnPackerDlg::IDD, pParent)
{
	ConstructionExtra();
}

CUnPackerDlg::~CUnPackerDlg()
{
	if (m_pPlumUnPackerThread)
	{
		m_pPlumUnPackerThread->PlumThreadExit();
		delete m_pPlumUnPackerThread;
		m_pPlumUnPackerThread = NULL;
	}

	m_Brush.DeleteObject();
}

void CUnPackerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_CONFIG, m_gbxUnPackConfig);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_PROCESS, m_gbxUnPackerProgress);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_ORIGINFILEPATH, m_sticOriginFilePath);
	DDX_Control(pDX, IDC_EDIT_UNPACKER_ORIGINFILEPATH, m_edtOriginFilePath);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_UNPACKERFILEPATH, m_sticUnPackerFilePath);
	DDX_Control(pDX, IDC_EDIT_UNPACKER_UNPACKERFILEPATH, m_edtUnPackerFilePath);
	DDX_Control(pDX, IDC_BUTTON_UNPACKER_ORIGINFILEPATH, m_btnImport);
	DDX_Control(pDX, IDC_BUTTON_UNPACKER_UNPACKERFILEPATH, m_btnExport);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_CONVERTSTATE, m_sticConvertState);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_CONVERTMARK, m_sticConvertMark);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_PROGRESSTIP, m_sticUnPackerProgressTip);
	DDX_Control(pDX, IDC_PROGRESS_UNPACKER, m_prgUnPacker);
	DDX_Control(pDX, IDC_BUTTON_UNPACKER_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_UNPACKER_OK, m_btnOk);
	DDX_Control(pDX, IDC_STATIC_UNPACKER_PACKERSTATE, m_sticUnPackerState);
}


BEGIN_MESSAGE_MAP(CUnPackerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_UNPACKER_ORIGINFILEPATH, &CUnPackerDlg::OnBnClickedButtonUnpackerOriginfilepath)
	ON_BN_CLICKED(IDC_BUTTON_UNPACKER_UNPACKERFILEPATH, &CUnPackerDlg::OnBnClickedButtonUnpackerUnpackerfilepath)
	ON_BN_CLICKED(IDC_BUTTON_UNPACKER_CANCEL, &CUnPackerDlg::OnBnClickedButtonUnpackerCancel)
	ON_BN_CLICKED(IDC_BUTTON_UNPACKER_OK, &CUnPackerDlg::OnBnClickedButtonUnpackerOk)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CUnPackerDlg 消息处理程序


BOOL CUnPackerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CUnPackerDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	RePaintWindow(dc);
}


HBRUSH CUnPackerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(255, 255, 255));
		return m_Brush;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


//------------------------------------------
// CUnPackerDlg ~用户定义函数
//------------------------------------------

// CUnPackerDlg ~构造函数
void CUnPackerDlg::ConstructionExtra()
{
	m_csImport = L"";
	m_csExport = L"";

	m_nCheck = 0;
	memset(m_nArray, 0, 16);

	m_pPlumUnPackerThread = NULL;

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

	m_Brush.CreateSolidBrush(RGB(255, 255, 255));
}

// CUnPackerDlg ~初始化窗口形状
void CUnPackerDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CUnPackerDlg ~设置窗口数据
void CUnPackerDlg::SetWindowData(int* pArray, int nCheck)
{
	m_nCheck = nCheck;
	for (int i = 0; i < 16; ++i)
	{
		m_nArray[i] = *(pArray + i);
	}
}

// CUnPackerDlg ~初始化窗口布局
void CUnPackerDlg::InitWindowLayOut()
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
	m_gbxUnPackConfig.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	TempX = X;
	TempY = Y;

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticOriginFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticOriginFilePath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtOriginFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtOriginFilePath.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 0;
	m_btnImport.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnImport.GetWindowRect(&Rect);

	X = TempX;
	Y = TempY;

	X += 20;
	Y += nHeight / 8 - 5 + Rect.Height() + 50;
	m_sticUnPackerFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticUnPackerFilePath.GetWindowRect(&Rect);

	X += 0;
	Y += Rect.Height() + 10;
	m_edtUnPackerFilePath.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtUnPackerFilePath.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 0;
	m_btnExport.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnExport.GetWindowRect(&Rect);

	X = TempX;
	Y = TempY;

	X += 20;
	Y += nHeight / 8 - 5 + (Rect.Height() + 50) * 2;
	m_sticConvertState.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticConvertState.GetWindowRect(&Rect);

	X += 20;
	Y += Rect.Height() + 20;
	m_sticConvertMark.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticConvertMark.GetWindowRect(&Rect);

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top + m_cWindowRect.Height() * 2 / 3;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() / 4;
	m_gbxUnPackerProgress.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	X += 20;
	Y += nHeight / 3 - 5;
	m_sticUnPackerProgressTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticUnPackerProgressTip.GetWindowRect(&Rect);
	m_sticUnPackerState.SetWindowPos(NULL, X + 400, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);

	X += 0;
	Y += Rect.Height() + 10;
	m_prgUnPacker.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_prgUnPacker.GetWindowRect(&Rect);

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

// CUnPackerDlg ~初始化窗口控件布局
void CUnPackerDlg::InitWindowItemLayOut()
{
	// 关于Status
	m_sticConvertMark.SetWindowText(L"Ready!");

	// 关于ProgressBar
	m_gbxUnPackerProgress.ShowWindow(SW_HIDE);
	m_sticUnPackerProgressTip.ShowWindow(SW_HIDE);
	m_sticUnPackerState.ShowWindow(SW_HIDE);
	m_prgUnPacker.ShowWindow(SW_HIDE);
}

// CUnPackerDlg ~重绘窗口
void CUnPackerDlg::RePaintWindow(CDC& dc)
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

//------------------------------------------
// CUnPackerDlg ~控件响应函数
//------------------------------------------

// CUnPackerDlg ~导入路径
void CUnPackerDlg::OnBnClickedButtonUnpackerOriginfilepath()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = TRUE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	csDefaultDir = L"C:\\";
	csFileName = L"";
	csFileFilter = L"文件|||";

	CString csCryptType = L"udf";

	CString csDefaultPath;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_HIDEREADONLY | OFN_READONLY | OFN_NOCHANGEDIR, csFileFilter, NULL);
	INT_PTR nResult;

	if (m_csImport == L"")
	{
		GetModuleFileName(AfxGetInstanceHandle(), csDefaultPath.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
		csDefaultPath = csDefaultPath.Left(csDefaultPath.ReverseFind('\\'));
	}
	else
	{
		csDefaultPath = m_csImport;
	}

	FileDlg.GetOFN().lpstrInitialDir = csDefaultPath;
	nResult = FileDlg.DoModal();
	if (nResult == IDOK)
	{
		csDefaultPath = FileDlg.GetPathName();
		m_csImport = csDefaultPath;
		m_edtOriginFilePath.SetWindowText(csDefaultPath);

		CString csExportDefaultPath;
		int nPos;

		nPos = csDefaultPath.ReverseFind('\\');
		csExportDefaultPath = csDefaultPath.Left(nPos);
		m_csExport = csExportDefaultPath;
		m_edtUnPackerFilePath.SetWindowText(csExportDefaultPath);
	}

}

// CUnPackerDlg ~导出路径
void CUnPackerDlg::OnBnClickedButtonUnpackerUnpackerfilepath()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bIsOpen = FALSE;
	CString csDefaultDir;
	CString csFileName;
	CString csFileFilter;

	CString csImportPath;
	int nLen;
	int nPos;

	m_edtOriginFilePath.GetWindowText(csImportPath);
	if (csImportPath == L"")
	{
		MessageBox(L"Please Select Import File Path!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	nLen = csImportPath.GetLength();
	nPos = csImportPath.ReverseFind('\\');
	csImportPath = csImportPath.Right(nLen - nPos - 1);
	nPos = csImportPath.ReverseFind('.');
	csFileName = csImportPath.Left(nPos);

	csDefaultDir = L"udf";
	csFileFilter = L"文件 (*.udf)|*.udf||";

	CString csCryptType = L"";

	CString csDefaultPath;
	CFileDialog FileDlg(bIsOpen, csDefaultDir, csFileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, csFileFilter, NULL);
	INT_PTR nResult;

	if (m_csExport == L"")
	{
		GetModuleFileName(AfxGetInstanceHandle(), csDefaultPath.GetBufferSetLength(_MAX_PATH + 1), _MAX_PATH);
		csDefaultPath = csDefaultPath.Left(csDefaultPath.ReverseFind('\\'));
	}
	else
	{
		csDefaultPath = m_csExport;
	}

	FileDlg.GetOFN().lpstrInitialDir = csDefaultPath;
	nResult = FileDlg.DoModal();
	if (nResult == IDOK)
	{
		csDefaultPath = FileDlg.GetPathName();
		csDefaultPath = csDefaultPath.Left(csDefaultPath.ReverseFind('\\'));
		m_csExport = csDefaultPath;
		m_edtUnPackerFilePath.SetWindowText(csDefaultPath);
	}

}

// CUnPackerDlg ~取消
void CUnPackerDlg::OnBnClickedButtonUnpackerCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	GetParent()->SendMessage(WM_CLOSE);
	OnCancel();
}

// CUnPackerDlg ~确定
void CUnPackerDlg::OnBnClickedButtonUnpackerOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString csOriginFilePath;
	CString csUnPackerFilePath;

	m_edtOriginFilePath.GetWindowText(csOriginFilePath);
	m_edtUnPackerFilePath.GetWindowText(csUnPackerFilePath);

	if (csOriginFilePath == L"")
	{
		MessageBox(L"Please Select Import File Path!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	if (csUnPackerFilePath == L"")
	{
		MessageBox(L"Please Select Export File Path!", L"Warning", MB_OK | MB_ICONWARNING);
		return;
	}

	csUnPackerFilePath = csUnPackerFilePath + L"\\";

	m_sticConvertMark.SetWindowText(L"Please Wait...");

	m_gbxUnPackerProgress.ShowWindow(SW_SHOW);
	m_sticUnPackerProgressTip.ShowWindow(SW_SHOW);
	m_sticUnPackerState.ShowWindow(SW_SHOW);
	m_prgUnPacker.ShowWindow(SW_SHOW);

	int nLen;

	nLen = WideCharToMultiByte(CP_ACP, 0, csOriginFilePath, -1, NULL, 0, NULL, NULL);
	g_pUnPackSrcArr = (char*)malloc((nLen + 1)*sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, csOriginFilePath, -1, g_pUnPackSrcArr, nLen, NULL, NULL);

	nLen = WideCharToMultiByte(CP_ACP, 0, csUnPackerFilePath, -1, NULL, 0, NULL, NULL);
	g_pUnPackDestArr = (char*)malloc((nLen + 1)*sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, csUnPackerFilePath, -1, g_pUnPackDestArr, nLen, NULL, NULL);

	if (m_pPlumUnPackerThread)
	{
		m_pPlumUnPackerThread->PlumThreadExit();
		delete m_pPlumUnPackerThread;
		m_pPlumUnPackerThread = NULL;
	}

	m_pPlumUnPackerThread = new CPlumThread(&m_UnPackerThread);
	m_pPlumUnPackerThread->PlumThreadInit();

	KillTimer(1);
	SetTimer(1, 10, NULL);

	KillTimer(0);
	SetTimer(0, 100, NULL);
}

// CUnPackerDlg ~定时器
void CUnPackerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString csConvertCount;
	CString csAllCount;

	switch (nIDEvent)
	{
	case 0:
		csConvertCount.Format(L"%d", g_nUnPackCount);
		csAllCount.Format(L"%d", g_nUnPackSize);

		m_prgUnPacker.SetPos(g_nUnPackCount);
		m_sticUnPackerState.SetWindowText(csConvertCount + L" Completed, " + csAllCount + L" In Total.");
		if (g_nUnPackCount == g_nUnPackSize)
		{
			m_sticUnPackerState.SetWindowText(L"Finish!");
			m_btnOk.EnableWindow(TRUE);
			KillTimer(0);
		}

		break;
	case 1:
		if (g_nUnPackSize != 0)
		{
			m_prgUnPacker.SetRange(0, g_nUnPackSize);
			m_prgUnPacker.SetStep(1);
			m_prgUnPacker.SetPos(0);
			m_btnOk.EnableWindow(FALSE);
			KillTimer(1);
		}
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
