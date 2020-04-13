
// 4.13-4View.h: CMy4134View 类的接口
//

#pragma once


class CMy4134View : public CView
{
protected: // 仅从序列化创建
	CMy4134View() noexcept;
	DECLARE_DYNCREATE(CMy4134View)

// 特性
public:
	CMy4134Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy4134View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 4.13-4View.cpp 中的调试版本
inline CMy4134Doc* CMy4134View::GetDocument() const
   { return reinterpret_cast<CMy4134Doc*>(m_pDocument); }
#endif

