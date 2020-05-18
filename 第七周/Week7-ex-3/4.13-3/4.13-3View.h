
// 4.13-3View.h: CMy4133View 类的接口
//

#pragma once


class CMy4133View : public CView
{
protected: // 仅从序列化创建
	CMy4133View() noexcept;
	DECLARE_DYNCREATE(CMy4133View)

// 特性
public:
	CMy4133Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	CRect m_rect;
	bool set;
	int x, flag;
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy4133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMovecircle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.13-3View.cpp 中的调试版本
inline CMy4133Doc* CMy4133View::GetDocument() const
   { return reinterpret_cast<CMy4133Doc*>(m_pDocument); }
#endif

