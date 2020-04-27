
// 4.27.1View.cpp: CMy4271View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.27.1.h"
#endif

#include "4.27.1Doc.h"
#include "4.27.1View.h"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4271View

IMPLEMENT_DYNCREATE(CMy4271View, CView)

BEGIN_MESSAGE_MAP(CMy4271View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMy4271View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMy4271View::OnFileSaveAs)
END_MESSAGE_MAP()

// CMy4271View 构造/析构

CMy4271View::CMy4271View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy4271View::~CMy4271View()
{
}

BOOL CMy4271View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4271View 绘图

void CMy4271View::OnDraw(CDC* /*pDC*/)
{
	CMy4271Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy4271View 诊断

#ifdef _DEBUG
void CMy4271View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4271View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4271Doc* CMy4271View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4271Doc)));
	return (CMy4271Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4271View 消息处理程序


void CMy4271View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	if (t == IDOK)
	{
		filename = cfd.GetPathName();
		ifstream ifs(filename);	
	}
}


void CMy4271View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CFileDialog cfd(false);
	int t = cfd.DoModal();
	if (t == IDOK)
	{
		ofstream  ofs(cfd.GetPathName());
		ofs << CT2A(filename);
	}
}
