#pragma once


// Traversal_Dlg 对话框

class Traversal_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Traversal_Dlg)

public:
	Traversal_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Traversal_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Traversal_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	
	CString trav;
};
