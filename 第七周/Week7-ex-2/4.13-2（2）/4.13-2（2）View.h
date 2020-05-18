
// 4.13-2（2）View.h: CMy41322View 类的接口
//

#pragma once


class CMy41322View : public CView
{
protected: // 仅从序列化创建
	CMy41322View() noexcept;
	DECLARE_DYNCREATE(CMy41322View)

// 特性
public:
	CMy41322Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy41322View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPlus();
};

#ifndef _DEBUG  // 4.13-2（2）View.cpp 中的调试版本
inline CMy41322Doc* CMy41322View::GetDocument() const
   { return reinterpret_cast<CMy41322Doc*>(m_pDocument); }
#endif

