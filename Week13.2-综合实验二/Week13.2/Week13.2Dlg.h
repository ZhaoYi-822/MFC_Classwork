
// Week13.2Dlg.h : 头文件
//

#pragma once


// CWeek132Dlg 对话框
class CWeek132Dlg : public CDialogEx
{
// 构造
public:
	CString filename;
	CRect rect;
	CWeek132Dlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual void DrawPicture(CString filename);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WEEK132_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
