
// 4.20.1.1View.h: CMy42011View 类的接口
//

#pragma once


class CMy42011View : public CView
{
protected: // 仅从序列化创建
	CMy42011View() noexcept;
	DECLARE_DYNCREATE(CMy42011View)

// 特性
public:
	CMy42011Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	CPoint point;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy42011View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.20.1.1View.cpp 中的调试版本
inline CMy42011Doc* CMy42011View::GetDocument() const
   { return reinterpret_cast<CMy42011Doc*>(m_pDocument); }
#endif

