
// 4.27.1.1View.cpp: CMy42711View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.27.1.1.h"
#endif

#include "4.27.1.1Doc.h"
#include "4.27.1.1View.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy42711View

IMPLEMENT_DYNCREATE(CMy42711View, CView)

BEGIN_MESSAGE_MAP(CMy42711View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMy42711View::OnFileOpen)
END_MESSAGE_MAP()

// CMy42711View 构造/析构

CMy42711View::CMy42711View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy42711View::~CMy42711View()
{
}

BOOL CMy42711View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy42711View 绘图

void CMy42711View::OnDraw(CDC* /*pDC*/)
{
	CMy42711Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy42711View 诊断

#ifdef _DEBUG
void CMy42711View::AssertValid() const
{
	CView::AssertValid();
}

void CMy42711View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy42711Doc* CMy42711View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy42711Doc)));
	return (CMy42711Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy42711View 消息处理程序


void CMy42711View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString filename;
	string s;
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	if (t == IDOK)
	{
		filename = cfd.GetPathName();
		ifstream ifs(filename);
		CString str = _T("D:/abc.txt");
		CFile file(str, CFile::modeCreate);
		file.Close();
		while (ifs >> s)
		{
			dc.TextOutW(0, 0, _T("已在D盘成功创建abc.txt"));
	}
		ofstream  ofs(str);
		ofs << CT2A(filename);
	}
}
