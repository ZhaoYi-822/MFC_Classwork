
// 4.20.2.4View.h: CMy42024View 类的接口
//

#pragma once


class CMy42024View : public CView
{
protected: // 仅从序列化创建
	CMy42024View() noexcept;
	DECLARE_DYNCREATE(CMy42024View)

// 特性
public:
	CMy42024Doc* GetDocument() const;

// 操作
public:
	int R, G, B;
	bool flag;
	CRect rect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy42024View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBrush();
};

#ifndef _DEBUG  // 4.20.2.4View.cpp 中的调试版本
inline CMy42024Doc* CMy42024View::GetDocument() const
   { return reinterpret_cast<CMy42024Doc*>(m_pDocument); }
#endif

