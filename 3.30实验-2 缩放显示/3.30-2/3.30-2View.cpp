
// 3.30-2View.cpp: CMy3302View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.30-2.h"
#endif

#include "3.30-2Doc.h"
#include "3.30-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3302View

IMPLEMENT_DYNCREATE(CMy3302View, CView)

BEGIN_MESSAGE_MAP(CMy3302View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMy3302View::OnFileOpen)
END_MESSAGE_MAP()

// CMy3302View 构造/析构

CMy3302View::CMy3302View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy3302View::~CMy3302View()
{
}

BOOL CMy3302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3302View 绘图

void CMy3302View::OnDraw(CDC* pDC)
{
	CMy3302Doc* pDoc = GetDocument();
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
		rect_radio = 1.0*rect.Width() / rect.Height();
		image_radio = 1.0 * m_image.GetWidth() / m_image.GetHeight();

		if (rect_radio > image_radio)
		{
			h = rect.Height();
			w =image_radio * h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else {
			w = rect.Width();
			h = w / image_radio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		m_image.Draw(pDC->m_hDC, sx, sy, w, h);
	}
	
}


// CMy3302View 诊断

#ifdef _DEBUG
void CMy3302View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3302Doc* CMy3302View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3302Doc)));
	return (CMy3302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3302View 消息处理程序


void CMy3302View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	r= cfd.DoModal();
	filename= cfd.GetPathName();
	Invalidate();
}
