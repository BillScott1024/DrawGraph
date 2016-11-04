
// DrawGraphView.cpp : CDrawGraphView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DrawGraph.h"
#endif

#include "DrawGraphDoc.h"
#include "DrawGraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawGraphView

IMPLEMENT_DYNCREATE(CDrawGraphView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawGraphView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawGraphView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_GRAPH_LINE, &CDrawGraphView::OnGraphLine)
	ON_COMMAND(ID_GRAPH_RECTANGEL, &CDrawGraphView::OnGraphRectangel)
	ON_COMMAND(ID_GRAPH_ELLIPSE, &CDrawGraphView::OnGraphEllipse)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_LINE, &CDrawGraphView::OnUpdateGraphLine)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_RECTANGEL, &CDrawGraphView::OnUpdateGraphRectangel)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_ELLIPSE, &CDrawGraphView::OnUpdateGraphEllipse)
	ON_COMMAND(ID_COLOR_BRUSH, &CDrawGraphView::OnColorBrush)
	ON_COMMAND(ID_COLOR_PEN, &CDrawGraphView::OnColorPen)
END_MESSAGE_MAP()

// CDrawGraphView ����/����

CDrawGraphView::CDrawGraphView()
{
	// TODO: �ڴ˴���ӹ������
	m_begin.x = 0;
	m_begin.y = 0;
	m_end.x = 0;
	m_end.y = 0;
	m_type = 0;
	pencolor = RGB(255,0,0);
	brushcolor = RGB(0,255,0);

}

CDrawGraphView::~CDrawGraphView()
{
}

BOOL CDrawGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CDrawGraphView ����

void CDrawGraphView::OnDraw(CDC* pDC)
{
	CDrawGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPen newpen;
	CPen* oldpen;
	newpen.CreatePen(PS_SOLID ,8,pencolor);
	oldpen = pDC->SelectObject(&newpen);
	CBrush brush;
	brush.CreateSolidBrush(brushcolor);
//	CBitmap bmp;
//	bmp.LoadBitmap(IDB_BITMAP1);
//	brush.CreatePatternBrush(&bmp);
	pDC->SelectObject(&brush);
	switch(m_type)
	{
	case 0:
		pDC->MoveTo(m_begin);
		pDC->LineTo(m_end);
		break;
	case 1:
		pDC->Rectangle(m_begin.x,m_begin.y,m_end.x,m_end.y);
		break;
	case 2:
		pDC->Ellipse(m_begin.x,m_begin.y,m_end.x,m_end.y);
		break;

	}
	
	pDC->SelectObject(&oldpen);
}

void CDrawGraphView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 3000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawGraphView ��ӡ


void CDrawGraphView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CDrawGraphView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawGraphView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawGraphView ���

#ifdef _DEBUG
void CDrawGraphView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawGraphView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawGraphDoc* CDrawGraphView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawGraphDoc)));
	return (CDrawGraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawGraphView ��Ϣ�������


void CDrawGraphView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_begin = point;

	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawGraphView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//CDC* pDC = GetDC();
	/*
	pDC->MoveTo(m_begin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/
	/*CWindowDC dc(GetParent());
	dc.MoveTo(m_begin);
	dc.LineTo(point);*/

	m_end = point;
	Invalidate();

	CScrollView::OnLButtonUp(nFlags, point);
}


void CDrawGraphView::OnGraphLine()
{
	// TODO: Add your command handler code here
	m_type = 0;
}


void CDrawGraphView::OnGraphRectangel()
{
	// TODO: Add your command handler code here
	m_type = 1;
}


void CDrawGraphView::OnGraphEllipse()
{
	// TODO: Add your command handler code here
	m_type = 2;
}


void CDrawGraphView::OnUpdateGraphLine(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type == 0);
}


void CDrawGraphView::OnUpdateGraphRectangel(CCmdUI *pCmdUI)
{
pCmdUI->SetCheck(m_type == 1);
	// TODO: Add your command update UI handler code here
}


void CDrawGraphView::OnUpdateGraphEllipse(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type == 2);
}


void CDrawGraphView::OnColorBrush()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		brushcolor = dlg.GetColor();
	}
}


void CDrawGraphView::OnColorPen()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		pencolor = dlg.GetColor();
	}
}
