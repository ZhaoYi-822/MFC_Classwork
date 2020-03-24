
// 3.24-2View.cpp: CMy3242View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.24-2.h"
#endif

#include "3.24-2Doc.h"
#include "3.24-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3242View

IMPLEMENT_DYNCREATE(CMy3242View, CView)

BEGIN_MESSAGE_MAP(CMy3242View, CView)
END_MESSAGE_MAP()

// CMy3242View 构造/析构

CMy3242View::CMy3242View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP mp;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&mp);
	m_nWidth = mp.bmWidth;
	m_nHeight = mp.bmHeight;
}

CMy3242View::~CMy3242View()
{
}

BOOL CMy3242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3242View 绘图

void CMy3242View::OnDraw(CDC* pDC)
{
	CMy3242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDc;
	MemDc.CreateCompatibleDC(NULL);
	MemDc.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_nWidth,m_nHeight,&MemDc,0,0,SRCCOPY);
}


// CMy3242View 诊断

#ifdef _DEBUG
void CMy3242View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3242Doc* CMy3242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3242Doc)));
	return (CMy3242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3242View 消息处理程序
