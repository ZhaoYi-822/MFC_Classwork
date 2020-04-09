
// 4.7-1View.h: CMy471View 类的接口
//

#pragma once


class CMy471View : public CView
{
protected: // 仅从序列化创建
	CMy471View() noexcept;
	DECLARE_DYNCREATE(CMy471View)

// 特性
public:
	CMy471Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy471View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // 4.7-1View.cpp 中的调试版本
inline CMy471Doc* CMy471View::GetDocument() const
   { return reinterpret_cast<CMy471Doc*>(m_pDocument); }
#endif

