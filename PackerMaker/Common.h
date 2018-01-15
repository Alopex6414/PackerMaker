//------------------------------------------
// Common.h 公用类头文件
//------------------------------------------
#pragma once

#ifndef __COMMON_H_
#define __COMMON_H_

//Include PlumPack Header File
#include "PlumCipherA.h"
#include "PlumCrypt.h"
#include "PlumPack.h"
#include "PlumThread.h"

//Include PlumPack Static Library
#pragma comment(lib, "PlumPack.lib")
#pragma comment(lib, "PlumThread.lib")

//Macro Definition
#define	USER_WIDTH	640
#define USER_HEIGHT	480

extern CRITICAL_SECTION g_cs;

#endif