
// 3.30-1View.cpp: CMy3301View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.30-1.h"
#endif

#include "3.30-1Doc.h"
#include "3.30-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3301View

IMPLEMENT_DYNCREATE(CMy3301View, CView)

BEGIN_MESSAGE_MAP(CMy3301View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMy3301View::OnFileOpen)
END_MESSAGE_MAP()

// CMy3301View 构造/析构

CMy3301View::CMy3301View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy3301View::~CMy3301View()
{
}

BOOL CMy3301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3301View 绘图

void CMy3301View::OnDraw(CDC* pDC)
{
	CMy3301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	GetClientRect(&rect);

	if (r == IDOK)
	{
		CImage m_image;
		m_image.Load(filename);
		sx = (rect.Width() - m_image.GetWidth()) / 2;
		sy = (rect.Height() - m_image.GetHeight()) / 2;
		m_image.Draw(pDC->m_hDC, sx, sy, m_image.GetWidth(), m_image.GetHeight());
	}
}


// CMy3301View 诊断

#ifdef _DEBUG
void CMy3301View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3301Doc* CMy3301View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3301Doc)));
	return (CMy3301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3301View 消息处理程序


void CMy3301View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	r = cfd.DoModal();
	filename = cfd.GetPathName();
	Invalidate();
	   
}
