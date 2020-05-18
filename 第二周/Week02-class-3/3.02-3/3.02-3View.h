
// 3.02-3View.h: CMy3023View 类的接口
//

#pragma once


class CMy3023View : public CView
{
protected: // 仅从序列化创建
	CMy3023View() noexcept;
	DECLARE_DYNCREATE(CMy3023View)

// 特性
public:
	CMy3023Doc* GetDocument() const;

// 操作
public:
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3023View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3.02-3View.cpp 中的调试版本
inline CMy3023Doc* CMy3023View::GetDocument() const
   { return reinterpret_cast<CMy3023Doc*>(m_pDocument); }
#endif

