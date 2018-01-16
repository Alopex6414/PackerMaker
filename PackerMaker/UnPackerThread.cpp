#include "stdafx.h"
#include "UnPackerThread.h"

#include "Common.h"

char* g_pUnPackSrcArr = NULL;
char* g_pUnPackDestArr = NULL;
int g_nUnPackSize = 0;
int g_nUnPackCount = 0;

CUnPackerThread::CUnPackerThread()
{
}


CUnPackerThread::~CUnPackerThread()
{
}

void WINAPI CUnPackerThread::PlumThreadRun()
{
	EnterCriticalSection(&g_cs);

	CPlumPack* pUnPacker = new CPlumPack;

	g_nUnPackSize = 0;
	g_nUnPackCount = 0;

	pUnPacker->PlumUnPackFilePackerA((const char*)g_pUnPackSrcArr, (const char*)g_pUnPackDestArr, &g_nUnPackSize, &g_nUnPackCount);

	free(g_pUnPackSrcArr);
	g_pUnPackSrcArr = NULL;
	free(g_pUnPackDestArr);
	g_pUnPackDestArr = NULL;

	delete pUnPacker;

	LeaveCriticalSection(&g_cs);
}
