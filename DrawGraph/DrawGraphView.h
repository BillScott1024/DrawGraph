
// DrawGraphView.h : CDrawGraphView 类的接口
//

#pragma once


class CDrawGraphView : public CScrollView
{
protected: // 仅从序列化创建
	CDrawGraphView();
	DECLARE_DYNCREATE(CDrawGraphView)

// 特性
public:
	CDrawGraphDoc* GetDocument() const;

// 操作
public:
	CPoint m_begin,m_end;
	int m_type;
	COLORREF pencolor,brushcolor;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnGraphLine();
	afx_msg void OnGraphRectangel();
	afx_msg void OnGraphEllipse();
	afx_msg void OnUpdateGraphLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGraphRectangel(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGraphEllipse(CCmdUI *pCmdUI);
	afx_msg void OnColorBrush();
	afx_msg void OnColorPen();
};

#ifndef _DEBUG  // DrawGraphView.cpp 中的调试版本
inline CDrawGraphDoc* CDrawGraphView::GetDocument() const
   { return reinterpret_cast<CDrawGraphDoc*>(m_pDocument); }
#endif

