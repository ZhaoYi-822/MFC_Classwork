
// 4.7-2View.h: CMy472View 类的接口
//

#pragma once


class CMy472View : public CView
{
protected: // 仅从序列化创建
	CMy472View() noexcept;
	DECLARE_DYNCREATE(CMy472View)

// 特性
public:
	CMy472Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy472View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnExstring();
};

#ifndef _DEBUG  // 4.7-2View.cpp 中的调试版本
inline CMy472Doc* CMy472View::GetDocument() const
   { return reinterpret_cast<CMy472Doc*>(m_pDocument); }
#endif

