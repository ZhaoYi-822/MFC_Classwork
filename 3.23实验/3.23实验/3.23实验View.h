
// 3.23实验View.h: CMy323实验View 类的接口
//

#pragma once


class CMy323实验View : public CView
{
protected: // 仅从序列化创建
	CMy323实验View() noexcept;
	DECLARE_DYNCREATE(CMy323实验View)

// 特性
public:
	CMy323实验Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray<CRect, CRect> ca;
	bool set;
	CRect m_window;
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy323实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircles();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 3.23实验View.cpp 中的调试版本
inline CMy323实验Doc* CMy323实验View::GetDocument() const
   { return reinterpret_cast<CMy323实验Doc*>(m_pDocument); }
#endif

