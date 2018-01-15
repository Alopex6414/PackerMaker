#pragma once

class CMyListCtrl : public CListCtrl
{
private:


public:
	CMyListCtrl();
	~CMyListCtrl();

protected:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	DECLARE_MESSAGE_MAP()
};

