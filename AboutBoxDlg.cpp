// AboutBoxDlg.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "XMLTools.h"
#include "AboutBoxDlg.h"
#include "afxdialogex.h"

#include "Report.h"
#include <libxml/xmlversion.h>
#include <libxslt/xsltconfig.h>

// Bo�te de dialogue CAboutBoxDlg

IMPLEMENT_DYNAMIC(CAboutBoxDlg, CDialogEx)

CAboutBoxDlg::CAboutBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutBoxDlg::IDD, pParent)
{

}

CAboutBoxDlg::~CAboutBoxDlg()
{
}

void CAboutBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_ABOUTURL, m_wndExtURL);
}


BEGIN_MESSAGE_MAP(CAboutBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutBoxDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// Gestionnaires de messages de CAboutBoxDlg

BOOL CAboutBoxDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  #ifdef _DEBUG
    SetDlgItemTextW(IDC_ABOUTTEXT, Report::str_format(L"XML Tools Plugin\r\nversion %s unicode (debug)\r\n \r\nlibXML %s \r\nlibXSTL %s",
          XMLTOOLS_VERSION_NUMBER, TEXT(LIBXML_DOTTED_VERSION), TEXT(LIBXSLT_DOTTED_VERSION)).c_str());
  #else
    SetDlgItemTextW(IDC_ABOUTTEXT, Report::str_format(L"XML Tools Plugin\r\nversion %s unicode\r\n \r\nlibXML %s \r\nlibXSTL %s",
        XMLTOOLS_VERSION_NUMBER, TEXT(LIBXML_DOTTED_VERSION), TEXT(LIBXSLT_DOTTED_VERSION)).c_str());
  #endif

  m_wndExtURL.SetURL(PAYPAL_URL);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION�: les pages de propri�t�s OCX devraient retourner FALSE
}