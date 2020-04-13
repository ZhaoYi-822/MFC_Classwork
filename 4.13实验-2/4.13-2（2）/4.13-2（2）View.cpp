
// 4.13-2（2）View.cpp: CMy41322View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.13-2（2）.h"
#endif

#include"MyDlg2.h"
#include "4.13-2（2）Doc.h"
#include "4.13-2（2）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41322View

IMPLEMENT_DYNCREATE(CMy41322View, CView)

BEGIN_MESSAGE_MAP(CMy41322View, CView)
	ON_COMMAND(ID_Plus, &CMy41322View::OnPlus)
END_MESSAGE_MAP()

// CMy41322View 构造/析构

CMy41322View::CMy41322View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy41322View::~CMy41322View()
{
}

BOOL CMy41322View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy41322View 绘图

void CMy41322View::OnDraw(CDC* /*pDC*/)
{
	CMy41322Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy41322View 诊断

#ifdef _DEBUG
void CMy41322View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41322View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41322Doc* CMy41322View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41322Doc)));
	return (CMy41322Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41322View 消息处理程序


void CMy41322View::OnPlus()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
