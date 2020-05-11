
// Week10View.h : CWeek10View 类的接口
//

#pragma once


class CWeek10View : public CView
{
protected: // 仅从序列化创建
	CWeek10View();
	DECLARE_DYNCREATE(CWeek10View)

// 特性
public:
	CWeek10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Week10View.cpp 中的调试版本
inline CWeek10Doc* CWeek10View::GetDocument() const
   { return reinterpret_cast<CWeek10Doc*>(m_pDocument); }
#endif

