
// 3.30-1View.h: CMy3301View 类的接口
//

#pragma once


class CMy3301View : public CView
{
protected: // 仅从序列化创建
	CMy3301View() noexcept;
	DECLARE_DYNCREATE(CMy3301View)

// 特性
public:
	CMy3301Doc* GetDocument() const;

// 操作
public:
	int r, sx, sy;
	CString filename;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy3301View();
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

#ifndef _DEBUG  // 3.30-1View.cpp 中的调试版本
inline CMy3301Doc* CMy3301View::GetDocument() const
   { return reinterpret_cast<CMy3301Doc*>(m_pDocument); }
#endif

