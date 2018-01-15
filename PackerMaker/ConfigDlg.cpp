// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PackerMaker.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"


// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialogEx)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfigDlg::IDD, pParent)
{
	ConstructionExtra();
}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_CONFIG_PACKERTYPE, m_gbxPackerType);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LUCKYNUMBER, m_gbxLuckyNumber);
	DDX_Control(pDX, IDC_STATIC_CONFIG_PACKERTYPETIP, m_sticPackerTypeTip);
	DDX_Control(pDX, IDC_STATIC_LUCKYNUMBER, m_sticLuckyNumberTip);
	DDX_Control(pDX, IDC_STATIC_ARRAY1, m_sticArray1);
	DDX_Control(pDX, IDC_STATIC_ARRAY2, m_sticArray2);
	DDX_Control(pDX, IDC_STATIC_ARRAY3, m_sticArray3);
	DDX_Control(pDX, IDC_STATIC_ARRAY4, m_sticArray4);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK1, m_sticLink1);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK2, m_sticLink2);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK3, m_sticLink3);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK4, m_sticLink4);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK5, m_sticLink5);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK6, m_sticLink6);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK7, m_sticLink7);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK8, m_sticLink8);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK9, m_sticLink9);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK10, m_sticLink10);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK11, m_sticLink11);
	DDX_Control(pDX, IDC_STATIC_CONFIG_LINK12, m_sticLink12);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY1, m_edtLucky1);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY2, m_edtLucky2);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY3, m_edtLucky3);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY4, m_edtLucky4);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY5, m_edtLucky5);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY6, m_edtLucky6);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY7, m_edtLucky7);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY8, m_edtLucky8);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY9, m_edtLucky9);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY10, m_edtLucky10);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY11, m_edtLucky11);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY12, m_edtLucky12);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY13, m_edtLucky13);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY14, m_edtLucky14);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY15, m_edtLucky15);
	DDX_Control(pDX, IDC_EDIT_CONFIG_LUCKY16, m_edtLucky16);
	DDX_Control(pDX, IDC_BUTTON_CONFIG_CANCEL, m_btnDefault);
	DDX_Control(pDX, IDC_BUTTON_CONFIG_OK, m_btnSave);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_CONFIG_CANCEL, &CConfigDlg::OnBnClickedButtonConfigCancel)
	ON_BN_CLICKED(IDC_BUTTON_CONFIG_OK, &CConfigDlg::OnBnClickedButtonConfigOk)
END_MESSAGE_MAP()


// CConfigDlg 消息处理程序


BOOL CConfigDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitWindowSharp();
	InitWindowLayOut();
	InitWindowItemLayOut();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CConfigDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	RePaintWindow(dc);
}


//------------------------------------------
// CConfigDlg ~用户定义函数
//------------------------------------------

// CConfigDlg ~构造函数
void CConfigDlg::ConstructionExtra()
{
	m_csCheck = L"";

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

// CConfigDlg ~初始化窗口形状
void CConfigDlg::InitWindowSharp()
{
	SetWindowPos(NULL, m_cWindowRect.left, m_cWindowRect.top, m_cWindowRect.Width(), m_cWindowRect.Height(), SWP_NOACTIVATE | SWP_SHOWWINDOW);
	GetClientRect(&m_cWindowRect);
}

// CConfigDlg ~设置窗口数据
void CConfigDlg::SetWindowData(int* pArray, int nCheck)
{
	m_nCheck = nCheck;
	for (int i = 0; i < 16; ++i)
	{
		m_nArray[i] = *(pArray + i);
	}
}

// CConfigDlg ~初始化窗口布局
void CConfigDlg::InitWindowLayOut()
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
	nHeight = m_cWindowRect.Height() / 6;
	m_gbxPackerType.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	m_sticPackerTypeTip.ShowWindow(SW_HIDE);

	X += 50;
	Y += nHeight / 2 - 5;
	GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN)->SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN)->GetWindowRect(&Rect);

	X += Rect.Width() + 250;
	Y += 0;
	GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE)->SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE)->GetWindowRect(&Rect);

	X = m_cWindowRect.left;
	Y = m_cWindowRect.top + m_cWindowRect.Height() / 6 + 5;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height() * 2 / 3;
	m_gbxLuckyNumber.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW);

	TempX = X;
	TempY = Y;

	X += 20;
	Y += nHeight / 8 - 5;
	m_sticLuckyNumberTip.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLuckyNumberTip.GetWindowRect(&Rect);

	TempX = X;
	TempY = Y;

	//Array1
	X += 30;
	Y += Rect.Height() + 20;
	m_sticArray1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray1.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky1.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink1.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink1.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky2.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink2.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky3.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink3.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky4.GetWindowRect(&Rect);

	//Array2
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 2 - 10;
	m_sticArray2.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray2.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky5.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky5.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink4.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky6.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky6.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink5.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink5.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky7.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky7.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink6.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink6.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky8.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky8.GetWindowRect(&Rect);

	//Array3
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 3 - 10;
	m_sticArray3.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray3.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky9.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky9.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink7.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink7.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky10.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky10.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink8.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink8.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky11.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky11.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink9.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink9.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky12.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky12.GetWindowRect(&Rect);

	//Array3
	X = TempX;
	Y = TempY;

	X += 30;
	Y += (Rect.Height() + 20) * 4 - 10;
	m_sticArray4.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticArray4.GetWindowRect(&Rect);

	X += Rect.Width() + 15;
	Y += -3;
	m_edtLucky13.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky13.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink10.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink10.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky14.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky14.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink11.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink11.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky15.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky15.GetWindowRect(&Rect);

	X += Rect.Width() + 10;
	Y += 3;
	m_sticLink12.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_sticLink12.GetWindowRect(&Rect);

	X += Rect.Width() + 5;
	Y += -3;
	m_edtLucky16.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_edtLucky16.GetWindowRect(&Rect);

	X = m_cWindowRect.right - 75;
	Y = m_cWindowRect.bottom - 24;
	nWidth = m_cWindowRect.Width();
	nHeight = m_cWindowRect.Height();
	m_btnSave.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnSave.GetWindowRect(&Rect);

	X += -Rect.Width() - 20;
	Y += 0;
	m_btnDefault.SetWindowPos(NULL, X, Y, nWidth, nHeight, SWP_NOACTIVATE | SWP_SHOWWINDOW | SWP_NOSIZE);
	m_btnDefault.GetWindowRect(&Rect);
}

// CConfigDlg ~初始化窗口控件布局
void CConfigDlg::InitWindowItemLayOut()
{
	// 关于CheckBox
	if (m_nCheck == 0)
	{
		((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE))->SetCheck(TRUE);
	}

	// 关于Edit
	m_edtLucky1.LimitText(2);
	m_edtLucky2.LimitText(2);
	m_edtLucky3.LimitText(2);
	m_edtLucky4.LimitText(2);
	m_edtLucky5.LimitText(2);
	m_edtLucky6.LimitText(2);
	m_edtLucky7.LimitText(2);
	m_edtLucky8.LimitText(2);
	m_edtLucky9.LimitText(2);
	m_edtLucky10.LimitText(2);
	m_edtLucky11.LimitText(2);
	m_edtLucky12.LimitText(2);
	m_edtLucky13.LimitText(2);
	m_edtLucky14.LimitText(2);
	m_edtLucky15.LimitText(2);
	m_edtLucky16.LimitText(2);

	for (int i = 0; i < 16; ++i)
	{
		m_csArray[i].Format(L"%x", m_nArray[i]);
	}

	m_edtLucky1.SetWindowText(m_csArray[0]);
	m_edtLucky2.SetWindowText(m_csArray[1]);
	m_edtLucky3.SetWindowText(m_csArray[2]);
	m_edtLucky4.SetWindowText(m_csArray[3]);

	m_edtLucky5.SetWindowText(m_csArray[4]);
	m_edtLucky6.SetWindowText(m_csArray[5]);
	m_edtLucky7.SetWindowText(m_csArray[6]);
	m_edtLucky8.SetWindowText(m_csArray[7]);

	m_edtLucky9.SetWindowText(m_csArray[8]);
	m_edtLucky10.SetWindowText(m_csArray[9]);
	m_edtLucky11.SetWindowText(m_csArray[10]);
	m_edtLucky12.SetWindowText(m_csArray[11]);

	m_edtLucky13.SetWindowText(m_csArray[12]);
	m_edtLucky14.SetWindowText(m_csArray[13]);
	m_edtLucky15.SetWindowText(m_csArray[14]);
	m_edtLucky16.SetWindowText(m_csArray[15]);
}

// CConfigDlg ~重绘窗口
void CConfigDlg::RePaintWindow(CDC& dc)
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
// CConfigDlg ~控件响应函数
//------------------------------------------

// CConfigDlg ~默认
void CConfigDlg::OnBnClickedButtonConfigCancel()
{
	// TODO:  在此添加控件通知处理程序代码

	// 关于CheckBox
	((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE))->SetCheck(TRUE);

	// 关于Edit
	m_edtLucky1.LimitText(2);
	m_edtLucky2.LimitText(2);
	m_edtLucky3.LimitText(2);
	m_edtLucky4.LimitText(2);
	m_edtLucky5.LimitText(2);
	m_edtLucky6.LimitText(2);
	m_edtLucky7.LimitText(2);
	m_edtLucky8.LimitText(2);
	m_edtLucky9.LimitText(2);
	m_edtLucky10.LimitText(2);
	m_edtLucky11.LimitText(2);
	m_edtLucky12.LimitText(2);
	m_edtLucky13.LimitText(2);
	m_edtLucky14.LimitText(2);
	m_edtLucky15.LimitText(2);
	m_edtLucky16.LimitText(2);

	m_edtLucky1.SetWindowText(L"AA");
	m_edtLucky2.SetWindowText(L"BB");
	m_edtLucky3.SetWindowText(L"CC");
	m_edtLucky4.SetWindowText(L"DD");

	m_edtLucky5.SetWindowText(L"12");
	m_edtLucky6.SetWindowText(L"48");
	m_edtLucky7.SetWindowText(L"84");
	m_edtLucky8.SetWindowText(L"21");

	m_edtLucky9.SetWindowText(L"12");
	m_edtLucky10.SetWindowText(L"34");
	m_edtLucky11.SetWindowText(L"56");
	m_edtLucky12.SetWindowText(L"78");

	m_edtLucky13.SetWindowText(L"FF");
	m_edtLucky14.SetWindowText(L"FF");
	m_edtLucky15.SetWindowText(L"FF");
	m_edtLucky16.SetWindowText(L"FF");

	Invalidate(FALSE);
	UpdateWindow();
}


void CConfigDlg::OnBnClickedButtonConfigOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString csTextArray[16];

	m_edtLucky1.GetWindowText(csTextArray[0]);
	m_edtLucky2.GetWindowText(csTextArray[1]);
	m_edtLucky3.GetWindowText(csTextArray[2]);
	m_edtLucky4.GetWindowText(csTextArray[3]);
	m_edtLucky5.GetWindowText(csTextArray[4]);
	m_edtLucky6.GetWindowText(csTextArray[5]);
	m_edtLucky7.GetWindowText(csTextArray[6]);
	m_edtLucky8.GetWindowText(csTextArray[7]);
	m_edtLucky9.GetWindowText(csTextArray[8]);
	m_edtLucky10.GetWindowText(csTextArray[9]);
	m_edtLucky11.GetWindowText(csTextArray[10]);
	m_edtLucky12.GetWindowText(csTextArray[11]);
	m_edtLucky13.GetWindowText(csTextArray[12]);
	m_edtLucky14.GetWindowText(csTextArray[13]);
	m_edtLucky15.GetWindowText(csTextArray[14]);
	m_edtLucky16.GetWindowText(csTextArray[15]);

	for (int i = 0; i < 16; ++i)
	{
		bool btrue;
		btrue = AnalysisText(csTextArray[i], &m_nArray[i]);
		if (!btrue)
		{
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

			m_edtLucky1.SetWindowText(L"AA");
			m_edtLucky2.SetWindowText(L"BB");
			m_edtLucky3.SetWindowText(L"CC");
			m_edtLucky4.SetWindowText(L"DD");

			m_edtLucky5.SetWindowText(L"12");
			m_edtLucky6.SetWindowText(L"48");
			m_edtLucky7.SetWindowText(L"84");
			m_edtLucky8.SetWindowText(L"21");

			m_edtLucky9.SetWindowText(L"12");
			m_edtLucky10.SetWindowText(L"34");
			m_edtLucky11.SetWindowText(L"56");
			m_edtLucky12.SetWindowText(L"78");

			m_edtLucky13.SetWindowText(L"FF");
			m_edtLucky14.SetWindowText(L"FF");
			m_edtLucky15.SetWindowText(L"FF");
			m_edtLucky16.SetWindowText(L"FF");

			Invalidate(FALSE);
			UpdateWindow();

			return;
		}
	}

	if (((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERORIGIN))->GetCheck())
	{
		m_nCheck = 0;
	}

	if (((CButton*)GetDlgItem(IDC_RADIO_CONFIG_PACKERCRYPTFILE))->GetCheck())
	{
		m_nCheck = 1;
	}

	MessageBox(L"Save Succeed!", L"Asterisk", MB_OK | MB_ICONASTERISK);
}

// CConfigDlg ~数据分析
bool CConfigDlg::AnalysisText(CString cs, int* pCount)
{
	char* pArray;
	int nLen;
	int nTextCount;
	int nConvert;

	nTextCount = cs.GetLength();

	if (!nTextCount)
	{
		MessageBox(L"Array Can not Be Empty!", L"Warning", MB_OK | MB_ICONWARNING);
		return false;
	}

	if (nTextCount != 2)
	{
		MessageBox(L"Array Should have 2 Bit!", L"Warning", MB_OK | MB_ICONWARNING);
		return false;
	}

	nLen = WideCharToMultiByte(CP_ACP, 0, cs, -1, NULL, 0, NULL, NULL);
	pArray = new char[nLen + 1];
	WideCharToMultiByte(CP_ACP, 0, cs, -1, pArray, nLen, NULL, NULL);

	nLen = strlen(pArray);
	nConvert = 0;
	for (int i = 0; i < nLen; ++i)
	{
		int Bit;

		if (!((*(pArray + i) >= 'A' && *(pArray + i) <= 'F') || (*(pArray + i) >= '0' && *(pArray + i) <= '9')))
		{
			MessageBox(L"Array Number Should in 0~9 or A~F!", L"Warning", MB_OK | MB_ICONWARNING);
			delete[] pArray;
			return false;
		}

		switch (*(pArray + i))
		{
		case '0':
			Bit = 0;
			break;
		case '1':
			Bit = 1;
			break;
		case '2':
			Bit = 2;
			break;
		case '3':
			Bit = 3;
			break;
		case '4':
			Bit = 4;
			break;
		case '5':
			Bit = 5;
			break;
		case '6':
			Bit = 6;
			break;
		case '7':
			Bit = 7;
			break;
		case '8':
			Bit = 8;
			break;
		case '9':
			Bit = 9;
			break;
		case 'A':
			Bit = 10;
			break;
		case 'B':
			Bit = 11;
			break;
		case 'C':
			Bit = 12;
			break;
		case 'D':
			Bit = 13;
			break;
		case 'E':
			Bit = 14;
			break;
		case 'F':
			Bit = 15;
			break;
		default:
			return false;
			break;
		}

		nConvert += Bit * (1 << (4 * (1 - i)));
	}

	*pCount = nConvert;

	delete[] pArray;

	return true;
}