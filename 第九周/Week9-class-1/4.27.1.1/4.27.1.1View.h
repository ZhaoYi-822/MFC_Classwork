
// 4.27.1.1View.h: CMy42711View 类的接口
//

#pragma once


class CMy42711View : public CView
{
protected: // 仅从序列化创建
	CMy42711View() noexcept;
	DECLARE_DYNCREATE(CMy42711View)

// 特性
public:
	CMy42711Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy42711View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 4.27.1.1View.cpp 中的调试版本
inline CMy42711Doc* CMy42711View::GetDocument() const
   { return reinterpret_cast<CMy42711Doc*>(m_pDocument); }
#endif

