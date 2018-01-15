#pragma once

#include "PlumThread.h"

class CUnPackerThread : public CPlumThreadBase
{
public:
	CUnPackerThread();
	~CUnPackerThread();
	virtual void WINAPI PlumThreadRun();
};

