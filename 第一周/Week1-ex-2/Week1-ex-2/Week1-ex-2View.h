
// Week1-ex-2View.h : CWeek1ex2View 类的接口
//

#pragma once


class CWeek1ex2View : public CView
{
protected: // 仅从序列化创建
	CWeek1ex2View();
	DECLARE_DYNCREATE(CWeek1ex2View)

// 特性
public:
	CWeek1ex2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek1ex2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Week1-ex-2View.cpp 中的调试版本
inline CWeek1ex2Doc* CWeek1ex2View::GetDocument() const
   { return reinterpret_cast<CWeek1ex2Doc*>(m_pDocument); }
#endif

