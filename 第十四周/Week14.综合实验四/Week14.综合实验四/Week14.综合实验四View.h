
// Week14.综合实验四View.h : CWeek14综合实验四View 类的接口
//

#pragma once

class CWeek14综合实验四Set;

class CWeek14综合实验四View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek14综合实验四View();
	DECLARE_DYNCREATE(CWeek14综合实验四View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK14_FORM };
#endif
	CWeek14综合实验四Set* m_pSet;

// 特性
public:
	CWeek14综合实验四Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWeek14综合实验四View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString num;
	CString major;
	CString sex;
	double birth;
	CString tel;
	CString home;
	CString pic;
	afx_msg void OnSort();
	afx_msg void OnSearch();
	afx_msg void OnTraversal();
};

#ifndef _DEBUG  // Week14.综合实验四View.cpp 中的调试版本
inline CWeek14综合实验四Doc* CWeek14综合实验四View::GetDocument() const
   { return reinterpret_cast<CWeek14综合实验四Doc*>(m_pDocument); }
#endif

