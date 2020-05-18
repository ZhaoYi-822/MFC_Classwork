
// 3.10View.h: CMy310View 类的接口
//

#pragma once


class CMy310View : public CView
{
protected: // 仅从序列化创建
	CMy310View() noexcept;
	DECLARE_DYNCREATE(CMy310View)

// 特性
public:
	CMy310Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy310View();
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

#ifndef _DEBUG  // 3.10View.cpp 中的调试版本
inline CMy310Doc* CMy310View::GetDocument() const
   { return reinterpret_cast<CMy310Doc*>(m_pDocument); }
#endif

