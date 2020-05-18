
// 3.10kewaiView.h: CMy310kewaiView 类的接口
//

#pragma once


class CMy310kewaiView : public CView
{
protected: // 仅从序列化创建
	CMy310kewaiView() noexcept;
	DECLARE_DYNCREATE(CMy310kewaiView)

// 特性
public:
	CMy310kewaiDoc* GetDocument() const;

// 操作
public:
	int cout = 0;
	CString s, s1, s2, s3;
	int x ;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy310kewaiView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.10kewaiView.cpp 中的调试版本
inline CMy310kewaiDoc* CMy310kewaiView::GetDocument() const
   { return reinterpret_cast<CMy310kewaiDoc*>(m_pDocument); }
#endif

