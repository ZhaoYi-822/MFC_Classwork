
// 4.20.2.3View.h: CMy42023View 类的接口
//

#pragma once


class CMy42023View : public CView
{
protected: // 仅从序列化创建
	CMy42023View() noexcept;
	DECLARE_DYNCREATE(CMy42023View)

// 特性
public:
	CMy42023Doc* GetDocument() const;

// 操作
public:
	CRect rect,rect1;
	CPoint point;
	int x1, x2, y1, y2,flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy42023View();
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

#ifndef _DEBUG  // 4.20.2.3View.cpp 中的调试版本
inline CMy42023Doc* CMy42023View::GetDocument() const
   { return reinterpret_cast<CMy42023Doc*>(m_pDocument); }
#endif

