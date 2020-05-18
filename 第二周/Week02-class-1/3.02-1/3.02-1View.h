
// 3.02-1View.h: CMy3021View 类的接口
//

#pragma once


class CMy3021View : public CView
{
protected: // 仅从序列化创建
	CMy3021View() noexcept;
	DECLARE_DYNCREATE(CMy3021View)

// 特性
public:
	CMy3021Doc* GetDocument() const;

// 操作
public:
	CPoint m_point;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3021View();
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

#ifndef _DEBUG  // 3.02-1View.cpp 中的调试版本
inline CMy3021Doc* CMy3021View::GetDocument() const
   { return reinterpret_cast<CMy3021Doc*>(m_pDocument); }
#endif

