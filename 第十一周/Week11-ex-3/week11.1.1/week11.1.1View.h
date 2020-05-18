
// week11.1.1View.h : Cweek1111View 类的接口
//

#pragma once

class Cweek1111Set;

class Cweek1111View : public CRecordView
{
protected: // 仅从序列化创建
	Cweek1111View();
	DECLARE_DYNCREATE(Cweek1111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK1111_FORM };
#endif
	Cweek1111Set* m_pSet;

// 特性
public:
	Cweek1111Doc* GetDocument() const;

// 操作
public:
	CString path,s;
	int n;
	
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~Cweek1111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString id;
	CString name;
	CString num;
	CString sex;
	CString jprg;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	virtual void OnDraw(CDC* /*pDC*/);
	/*virtual void foo(CString filename);*/
	virtual void drawPicture(CImage&img, int&sx, int&sy, int&w, int&h);
};

#ifndef _DEBUG  // week11.1.1View.cpp 中的调试版本
inline Cweek1111Doc* Cweek1111View::GetDocument() const
   { return reinterpret_cast<Cweek1111Doc*>(m_pDocument); }
#endif

