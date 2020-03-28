
// 3.17-3View.h: CMy3173View 类的接口
//

#pragma once


class CMy3173View : public CView
{
protected: // 仅从序列化创建
	CMy3173View() noexcept;
	DECLARE_DYNCREATE(CMy3173View)

// 特性
public:
	CMy3173Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray <CRect, CRect> ca;
	bool set;
	CRect c;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3173View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 3.17-3View.cpp 中的调试版本
inline CMy3173Doc* CMy3173View::GetDocument() const
   { return reinterpret_cast<CMy3173Doc*>(m_pDocument); }
#endif

