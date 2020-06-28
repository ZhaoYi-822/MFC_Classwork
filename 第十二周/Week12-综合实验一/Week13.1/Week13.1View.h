
// Week13.1View.h : CWeek131View 类的接口
//

#pragma once

class CWeek131Set;

class CWeek131View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek131View();
	DECLARE_DYNCREATE(CWeek131View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK131_FORM };
#endif
	CWeek131Set* m_pSet;

// 特性
public:
	CWeek131Doc* GetDocument() const;

// 操作
public:
	CString path, s,file;
	
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWeek131View();
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
	CString num;
	CString major;
	CString sex;
	CString birth;
	CString tel;
	CString home;
	CString jpeg;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	virtual void drawPicture(CString filename);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // Week13.1View.cpp 中的调试版本
inline CWeek131Doc* CWeek131View::GetDocument() const
   { return reinterpret_cast<CWeek131Doc*>(m_pDocument); }
#endif

