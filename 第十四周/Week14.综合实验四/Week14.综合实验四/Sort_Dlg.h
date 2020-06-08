#pragma once


// Sort_Dlg 对话框

class Sort_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Sort_Dlg)

public:
	Sort_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Sort_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Sort_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sort;
};
