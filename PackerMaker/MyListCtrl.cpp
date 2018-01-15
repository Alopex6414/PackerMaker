#include "stdafx.h"
#include "MyListCtrl.h"


CMyListCtrl::CMyListCtrl()
{
}


CMyListCtrl::~CMyListCtrl()
{
}

BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	ON_WM_MOUSEWHEEL()
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()

BOOL CMyListCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	Scroll(CSize(0, -zDelta));
	return CListCtrl::OnMouseWheel(nFlags, zDelta, pt);
}

void CMyListCtrl::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	ModifyStyle(WS_HSCROLL, 0);
	CListCtrl::OnNcCalcSize(bCalcValidRects, lpncsp);
}