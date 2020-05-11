
// UsingDllView.h : CUsingDllView 类的接口
//

#pragma once


class CUsingDllView : public CView
{
protected: // 仅从序列化创建
	CUsingDllView();
	DECLARE_DYNCREATE(CUsingDllView)

// 特性
public:
	CUsingDllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUsingDllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingDllView.cpp 中的调试版本
inline CUsingDllDoc* CUsingDllView::GetDocument() const
   { return reinterpret_cast<CUsingDllDoc*>(m_pDocument); }
#endif

