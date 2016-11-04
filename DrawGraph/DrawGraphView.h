
// DrawGraphView.h : CDrawGraphView ��Ľӿ�
//

#pragma once


class CDrawGraphView : public CScrollView
{
protected: // �������л�����
	CDrawGraphView();
	DECLARE_DYNCREATE(CDrawGraphView)

// ����
public:
	CDrawGraphDoc* GetDocument() const;

// ����
public:
	CPoint m_begin,m_end;
	int m_type;
	COLORREF pencolor,brushcolor;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // DrawGraphView.cpp �еĵ��԰汾
inline CDrawGraphDoc* CDrawGraphView::GetDocument() const
   { return reinterpret_cast<CDrawGraphDoc*>(m_pDocument); }
#endif

