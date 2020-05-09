
// Week8.class1View.h: CWeek8class1View 类的接口
//

#pragma once


class CWeek8class1View : public CView
{
protected: // 仅从序列化创建
	CWeek8class1View() noexcept;
	DECLARE_DYNCREATE(CWeek8class1View)

// 特性
public:
	CWeek8class1Doc* GetDocument() const;
	CString filename;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek8class1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShow();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Week8.class1View.cpp 中的调试版本
inline CWeek8class1Doc* CWeek8class1View::GetDocument() const
   { return reinterpret_cast<CWeek8class1Doc*>(m_pDocument); }
#endif

