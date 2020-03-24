
// 3.24View.h: CMy324View 类的接口
//

#pragma once


class CMy324View : public CView
{
protected: // 仅从序列化创建
	CMy324View() noexcept;
	DECLARE_DYNCREATE(CMy324View)

// 特性
public:
	CMy324Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy324View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnName();
};

#ifndef _DEBUG  // 3.24View.cpp 中的调试版本
inline CMy324Doc* CMy324View::GetDocument() const
   { return reinterpret_cast<CMy324Doc*>(m_pDocument); }
#endif

