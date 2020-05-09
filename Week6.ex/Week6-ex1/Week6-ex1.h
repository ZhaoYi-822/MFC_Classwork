
// Week6-ex1.h: Week6-ex1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CWeek6ex1App:
// 有关此类的实现，请参阅 Week6-ex1.cpp
//

class CWeek6ex1App : public CWinApp
{
public:
	CWeek6ex1App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWeek6ex1App theApp;
