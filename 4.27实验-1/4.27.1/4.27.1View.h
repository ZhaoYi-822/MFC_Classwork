
// 4.27.1View.h: CMy4271View 类的接口
//

#pragma once


class CMy4271View : public CView
{
protected: // 仅从序列化创建
	CMy4271View() noexcept;
	DECLARE_DYNCREATE(CMy4271View)

// 特性
public:
	CMy4271Doc* GetDocument() const;

// 操作
public:
	CString filename;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy4271View();
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
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // 4.27.1View.cpp 中的调试版本
inline CMy4271Doc* CMy4271View::GetDocument() const
   { return reinterpret_cast<CMy4271Doc*>(m_pDocument); }
#endif

