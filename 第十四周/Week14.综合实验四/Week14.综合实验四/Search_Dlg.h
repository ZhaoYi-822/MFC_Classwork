#pragma once


// Search_Dlg 对话框

class Search_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Search_Dlg)

public:
	Search_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Search_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Search_DlG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString search;
};
