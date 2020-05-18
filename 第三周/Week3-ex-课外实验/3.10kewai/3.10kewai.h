
// 3.10kewai.h: 3.10kewai 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMy310kewaiApp:
// 有关此类的实现，请参阅 3.10kewai.cpp
//

class CMy310kewaiApp : public CWinApp
{
public:
	CMy310kewaiApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy310kewaiApp theApp;
