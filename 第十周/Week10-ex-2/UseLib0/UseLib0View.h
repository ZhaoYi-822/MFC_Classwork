
// UseLib0View.h : CUseLib0View 类的接口
//

#pragma once


class CUseLib0View : public CView
{
protected: // 仅从序列化创建
	CUseLib0View();
	DECLARE_DYNCREATE(CUseLib0View)

// 特性
public:
	CUseLib0Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUseLib0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UseLib0View.cpp 中的调试版本
inline CUseLib0Doc* CUseLib0View::GetDocument() const
   { return reinterpret_cast<CUseLib0Doc*>(m_pDocument); }
#endif

