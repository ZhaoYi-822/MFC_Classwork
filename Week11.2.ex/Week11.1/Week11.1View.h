
// Week11.1View.h : CWeek111View 类的接口
//

#pragma once

class CWeek111Set;

class CWeek111View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek111View();
	DECLARE_DYNCREATE(CWeek111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK111_FORM };
#endif
	CWeek111Set* m_pSet;

// 特性
public:
	CWeek111Doc* GetDocument() const;

// 操作
public:
	CString path, filename;
	CRect rect;
	int n = 0;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWeek111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	CString number;
	CString sex;
	afx_msg void OnBnClickedButton1();
	virtual void foo(CImage&img, int&sx, int&sy, int&w, int&h);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // Week11.1View.cpp 中的调试版本
inline CWeek111Doc* CWeek111View::GetDocument() const
   { return reinterpret_cast<CWeek111Doc*>(m_pDocument); }
#endif

