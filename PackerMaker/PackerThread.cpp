#include "stdafx.h"
#include "PackerThread.h"

#include "Common.h"

char** g_ppSrcArr = NULL;
char* g_pDestArr = NULL;
int g_nSrcSize = 0;
DWORD g_dwLuckyArr[4] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

int g_nPackerCount = 0;

CPackerThread::CPackerThread()
{
}


CPackerThread::~CPackerThread()
{
}

void WINAPI CPackerThread::PlumThreadRun()
{
	EnterCriticalSection(&g_cs);

	CPlumPack* pPacker = new CPlumPack;

	g_nPackerCount = 0;

	pPacker->PlumPackFilePackerA((const char**)g_ppSrcArr, g_nSrcSize, (const char*)g_pDestArr, g_dwLuckyArr, &g_nPackerCount);

	free(g_pDestArr);
	g_pDestArr = NULL;

	for (int i = 0; i < g_nSrcSize; ++i)
	{
		free(*(g_ppSrcArr + i));
		*(g_ppSrcArr + i) = NULL;
	}

	free(g_ppSrcArr);
	g_ppSrcArr = NULL;

	g_nSrcSize = 0;

	delete pPacker;

	LeaveCriticalSection(&g_cs);
}
