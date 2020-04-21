
// 4.20.2.2.2View.h: CMy420222View 类的接口
//

#pragma once


class CMy420222View : public CView
{
protected: // 仅从序列化创建
	CMy420222View() noexcept;
	DECLARE_DYNCREATE(CMy420222View)

// 特性
public:
	CMy420222Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy420222View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // 4.20.2.2.2View.cpp 中的调试版本
inline CMy420222Doc* CMy420222View::GetDocument() const
   { return reinterpret_cast<CMy420222Doc*>(m_pDocument); }
#endif

