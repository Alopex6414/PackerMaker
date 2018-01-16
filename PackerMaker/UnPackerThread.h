#pragma once

#include "PlumThread.h"

class CUnPackerThread : public CPlumThreadBase
{
public:
	CUnPackerThread();
	~CUnPackerThread();
	virtual void WINAPI PlumThreadRun();
};

extern char* g_pUnPackSrcArr;
extern char* g_pUnPackDestArr;
extern int g_nUnPackSize;
extern int g_nUnPackCount;