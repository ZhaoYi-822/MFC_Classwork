
// Week6-ex1View.h: CWeek6ex1View 类的接口
//

#pragma once


class CWeek6ex1View : public CView
{
protected: // 仅从序列化创建
	CWeek6ex1View() noexcept;
	DECLARE_DYNCREATE(CWeek6ex1View)

// 特性
public:
	CWeek6ex1Doc* GetDocument() const;

// 操作
public:
	int i = 1;
	CString s,str;
	int pos,flag,x,y;
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek6ex1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Week6-ex1View.cpp 中的调试版本
inline CWeek6ex1Doc* CWeek6ex1View::GetDocument() const
   { return reinterpret_cast<CWeek6ex1Doc*>(m_pDocument); }
#endif

