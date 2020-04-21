
// 4.20.2.2.2.h: 4.20.2.2.2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMy420222App:
// 有关此类的实现，请参阅 4.20.2.2.2.cpp
//

class CMy420222App : public CWinApp
{
public:
	CMy420222App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy420222App theApp;
