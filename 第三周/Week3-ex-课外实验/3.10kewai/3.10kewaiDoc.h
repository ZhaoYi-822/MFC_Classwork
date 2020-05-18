
// 3.10kewaiDoc.h: CMy310kewaiDoc 类的接口
//


#pragma once


class CMy310kewaiDoc : public CDocument
{
protected: // 仅从序列化创建
	CMy310kewaiDoc() noexcept;
	DECLARE_DYNCREATE(CMy310kewaiDoc)

// 特性
public:

// 操作
public:
	CRect ca;
	CRect cb;
	CRect cc;
	CRect cd;
	int a, b, c;
	
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy310kewaiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
