
// 3.24-2View.h: CMy3242View 类的接口
//

#pragma once


class CMy3242View : public CView
{
protected: // 仅从序列化创建
	CMy3242View() noexcept;
	DECLARE_DYNCREATE(CMy3242View)

// 特性
public:
	CMy3242Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3242View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3.24-2View.cpp 中的调试版本
inline CMy3242Doc* CMy3242View::GetDocument() const
   { return reinterpret_cast<CMy3242Doc*>(m_pDocument); }
#endif

