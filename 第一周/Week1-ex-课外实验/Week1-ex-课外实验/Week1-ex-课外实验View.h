
// Week1-ex-课外实验View.h : CWeek1ex课外实验View 类的接口
//

#pragma once


class CWeek1ex课外实验View : public CView
{
protected: // 仅从序列化创建
	CWeek1ex课外实验View();
	DECLARE_DYNCREATE(CWeek1ex课外实验View)

// 特性
public:
	CWeek1ex课外实验Doc* GetDocument() const;

// 操作
public:
	CString name2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek1ex课外实验View();
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
};

#ifndef _DEBUG  // Week1-ex-课外实验View.cpp 中的调试版本
inline CWeek1ex课外实验Doc* CWeek1ex课外实验View::GetDocument() const
   { return reinterpret_cast<CWeek1ex课外实验Doc*>(m_pDocument); }
#endif

