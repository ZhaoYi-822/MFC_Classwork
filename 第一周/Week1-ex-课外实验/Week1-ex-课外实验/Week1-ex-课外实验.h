
// Week1-ex-课外实验.h : Week1-ex-课外实验 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CWeek1ex课外实验App:
// 有关此类的实现，请参阅 Week1-ex-课外实验.cpp
//

class CWeek1ex课外实验App : public CWinAppEx
{
public:
	CWeek1ex课外实验App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWeek1ex课外实验App theApp;
