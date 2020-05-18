
// 4.13.1View.h: CMy4131View 类的接口
//

#pragma once


class CMy4131View : public CView
{
protected: // 仅从序列化创建
	CMy4131View() noexcept;
	DECLARE_DYNCREATE(CMy4131View)

// 特性
public:
	CMy4131Doc* GetDocument() const;

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
	virtual ~CMy4131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.13.1View.cpp 中的调试版本
inline CMy4131Doc* CMy4131View::GetDocument() const
   { return reinterpret_cast<CMy4131Doc*>(m_pDocument); }
#endif

