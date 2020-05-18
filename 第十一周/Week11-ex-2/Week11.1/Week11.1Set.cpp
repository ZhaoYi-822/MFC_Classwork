
// Week11.1Set.cpp : CWeek111Set 类的实现
//

#include "stdafx.h"
#include "Week11.1.h"
#include "Week11.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek111Set 实现

// 代码生成在 2020年5月17日, 13:06

IMPLEMENT_DYNAMIC(CWeek111Set, CRecordset)

CWeek111Set::CWeek111Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CWeek111Set::GetDefaultConnect()
{
	return _T("DSN=p_student;DBQ=D:\\MFC\\S_Picture.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CWeek111Set::GetDefaultSQL()
{
	return _T("[s_student]");
}

void CWeek111Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Long(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);
	RFX_Text(pFX, _T("[字段4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CWeek111Set 诊断

#ifdef _DEBUG
void CWeek111Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWeek111Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

