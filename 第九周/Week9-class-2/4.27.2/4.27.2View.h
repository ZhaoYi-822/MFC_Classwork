
// 4.27.2View.h: CMy4272View 类的接口
//

#pragma once


class CMy4272View : public CView
{
protected: // 仅从序列化创建
	CMy4272View() noexcept;
	DECLARE_DYNCREATE(CMy4272View)

// 特性
public:
	CMy4272Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy4272View();
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
};

#ifndef _DEBUG  // 4.27.2View.cpp 中的调试版本
inline CMy4272Doc* CMy4272View::GetDocument() const
   { return reinterpret_cast<CMy4272Doc*>(m_pDocument); }
#endif

