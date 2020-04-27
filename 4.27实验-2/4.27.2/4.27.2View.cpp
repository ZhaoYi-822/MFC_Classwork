
// 4.27.2View.cpp: CMy4272View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.27.2.h"
#endif

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#include "4.27.2Doc.h"
#include "4.27.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4272View

IMPLEMENT_DYNCREATE(CMy4272View, CView)

BEGIN_MESSAGE_MAP(CMy4272View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMy4272View::OnFileOpen)
END_MESSAGE_MAP()

// CMy4272View 构造/析构

CMy4272View::CMy4272View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy4272View::~CMy4272View()
{
}

BOOL CMy4272View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4272View 绘图

void CMy4272View::OnDraw(CDC* /*pDC*/)
{
	CMy4272Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy4272View 诊断

#ifdef _DEBUG
void CMy4272View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4272View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4272Doc* CMy4272View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4272Doc)));
	return (CMy4272Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4272View 消息处理程序
void CMy4272View::foo(CImage &img,int &sx,int &sy,int &w,int &h)
{
	CRect rect;
	GetClientRect(&rect);
	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}

void CMy4272View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	CImage img;
	CClientDC dc(this);
	int t = cfd.DoModal();
	if (t == IDOK)
	{
		CString s1;
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		int sx, sy, w, h;
		int x = 10, y = 10;
		while (ifs >> s)
		{
			  s1 = s.c_str();
	         img.Load(s1); 
			 
		}
             foo(img, sx, sy, w, h);
		     img.Draw(dc.m_hDC, sx,sy,w,h);
	}
}
