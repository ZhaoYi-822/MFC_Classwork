
// 3.02-2View.h: CMy3022View 类的接口
//

#pragma once


class CMy3022View : public CView
{
protected: // 仅从序列化创建
	CMy3022View() noexcept;
	DECLARE_DYNCREATE(CMy3022View)

// 特性
public:
	CMy3022Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3022View();
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

#ifndef _DEBUG  // 3.02-2View.cpp 中的调试版本
inline CMy3022Doc* CMy3022View::GetDocument() const
   { return reinterpret_cast<CMy3022Doc*>(m_pDocument); }
#endif

