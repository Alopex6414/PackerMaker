#pragma once

#include "PlumThread.h"

class CPackerThread : public CPlumThreadBase
{
public:
	CPackerThread();
	~CPackerThread();
	virtual void WINAPI PlumThreadRun();
};

extern CRITICAL_SECTION g_cs;
extern char** g_ppSrcArr;
extern char* g_pDestArr;
extern int g_nSrcSize;
extern DWORD g_dwLuckyArr[4];

extern int g_nPackerCount;