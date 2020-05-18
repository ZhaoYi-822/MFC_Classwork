
// 3.30-2View.h: CMy3302View 类的接口
//

#pragma once


class CMy3302View : public CView
{
protected: // 仅从序列化创建
	CMy3302View() noexcept;
	DECLARE_DYNCREATE(CMy3302View)

// 特性
public:
	CMy3302Doc* GetDocument() const;

// 操作
public:
	int r, w,h, sx, sy;
	CString filename;
	float rect_radio, image_radio;
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3302View();
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

#ifndef _DEBUG  // 3.30-2View.cpp 中的调试版本
inline CMy3302Doc* CMy3302View::GetDocument() const
   { return reinterpret_cast<CMy3302Doc*>(m_pDocument); }
#endif

