
// Week11.classView.h : CWeek11classView 类的接口
//

#pragma once

class CWeek11classSet;

class CWeek11classView : public CRecordView
{
protected: // 仅从序列化创建
	CWeek11classView();
	DECLARE_DYNCREATE(CWeek11classView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK11CLASS_FORM };
#endif
	CWeek11classSet* m_pSet;

// 特性
public:
	CWeek11classDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CWeek11classView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString num;
	CString age;
	CString tel;
};

#ifndef _DEBUG  // Week11.classView.cpp 中的调试版本
inline CWeek11classDoc* CWeek11classView::GetDocument() const
   { return reinterpret_cast<CWeek11classDoc*>(m_pDocument); }
#endif

