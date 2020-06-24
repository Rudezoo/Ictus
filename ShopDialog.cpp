

#include "stdafx.h"
#include "Project.h"
#include "ShopDialog.h"
#include "afxdialogex.h"
#include "ProjectView.h"




// CShopDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CShopDialog, CDialog)

CShopDialog::CShopDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOP, pParent)
{
	m_pView = (CProjectView*)AfxGetMainWnd();
	font.CreatePointFont(100,_T("210 ��ȭå L"));
}

CShopDialog::~CShopDialog()
{
}

void CShopDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, fish1);
	DDX_Control(pDX, IDC_BUTTON2, fish2);
	DDX_Control(pDX, IDC_BUTTON3, fish3);
	DDX_Control(pDX, IDC_BUTTON4, fish4);
	DDX_Control(pDX, IDC_BUTTON5, fish5);
	DDX_Control(pDX, IDC_BUTTON6, fish6);
	DDX_Control(pDX, IDC_BUTTON7, fish7);
	DDX_Control(pDX, IDC_BUTTON8, fish8);

	CBitmap bf1, bf2, bf3, bf4, bf5, bf6, bf7, bf8;
	bf1.LoadBitmapW(IDB_FISH_1);
	fish1.SetBitmap(bf1);
	bf2.LoadBitmapW(IDB_FISH_2);
	fish2.SetBitmap(bf2);
	bf3.LoadBitmapW(IDB_FISH_3);
	fish3.SetBitmap(bf3);
	bf4.LoadBitmapW(IDB_FISH_4);
	fish4.SetBitmap(bf4);
	bf5.LoadBitmapW(IDB_FISH_5);
	fish5.SetBitmap(bf5);
	bf6.LoadBitmapW(IDB_FISH_6);
	fish6.SetBitmap(bf6);
	bf7.LoadBitmapW(IDB_FISH_7);
	fish7.SetBitmap(bf7);
	bf8.LoadBitmapW(IDB_FISH_8);
	fish8.SetBitmap(bf8);


	coinnum = m_pView->coin;

	data = _T("");
	have = _T("");

	data = _T("�̸�:�ö���\nƯ¡:�ҽ������� �ξ���� �������� �� �����ַ��� ����ϴ� ���� �����\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	have = _T("���ſϷ�");
	SetDlgItemText(IDC_HAVE, have);

	fish = (LPCTSTR)IDB_FISH_1;
	SetDlgItemText(IDC_DATA, data);
	str.Format(_T("coin: %d"), coinnum);
	SetDlgItemText(IDC_COIN, str);
	SetDlgItemText(IDC_HAVE, have);
	GetDlgItem(IDC_HAVE)->SetFont(&font);
	GetDlgItem(IDC_COIN)->SetFont(&font);
	GetDlgItem(IDC_DATA)->SetFont(&font);
	GetDlgItem(IDC_APPLY)->SetFont(&font);
	GetDlgItem(IDC_CANCLE)->SetFont(&font);
	GetDlgItem(IDC_BUY)->SetFont(&font);
	
	//	f1 = TRUE, f2 = FALSE, f3 = FALSE, f4 = FALSE, f5 = FALSE, f6 = FALSE, f7 = FALSE, f8 = FALSE;
	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	DDX_Control(pDX, IDC_APPLY, m_apply);
	DDX_Control(pDX, IDC_BUY, m_buy);
//	DDX_Control(pDX, IDC_DATA, m_data);
}


BEGIN_MESSAGE_MAP(CShopDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CShopDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShopDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShopDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CShopDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CShopDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CShopDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CShopDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CShopDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUY, &CShopDialog::OnBnClickedBuy)
	ON_BN_CLICKED(IDC_APPLY, &CShopDialog::OnBnClickedApply)
	ON_BN_CLICKED(IDOK, &CShopDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &CShopDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

// CShopDialog �޽��� ó�����Դϴ�.




void CShopDialog::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = TRUE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;


	data = _T("�̸�:�ö���\nƯ¡:�ҽ������� �ξ���� �������� �� �����ַ��� ����ϴ� ���� ������̴�.\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 0) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}
	if (f1 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 0) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}



}


void CShopDialog::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = TRUE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("�̸�:���� �����\nƯ¡: ����ó�� �����𸶵� ���δ�. �̹� �����ڿ��� ���� ���� �������� �������ϰ� �ٽ� ��Ƴ���.\n����:10����");
	SetDlgItemText(IDC_DATA, data);

	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f2 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}

}


void CShopDialog::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = FALSE, bt3 = TRUE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("�̸�:�����̵�\nƯ¡:ũ�γ뽺�� �Ƶ����� ���콺�� ������ �����̵�, �װ� ������� ���¸� ���������� ����̴�.\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f3 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = TRUE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("�̸�:�Ʊ�\nƯ¡:Ư���� ���� ũ�� ������ ����� ������ �ƱͶ�� �Ҹ���. �Ӹ����� �Һ����� ���ø� ����.\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f4 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
	SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = TRUE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("�̸�:���ķ���\nƯ¡:������ ��Ȧ����, ���洨���� �з��ȴ�. �ֿϿ����� ���� �⸣���� ������ �뵵�� �Ŀ��̶�� ��������\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f5 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = TRUE, bt7 = FALSE, bt8 = FALSE;

	data = _T("�̸�:��\nƯ¡: ��ġ �������� �⸣�� ���� �ú��� �Ϳ��� �����, ȣ����� ���� �ٴ�ӿ� �پ�����!\n����:10����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f6 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = TRUE, bt8 = FALSE;

	data = _T("�̸�:�ϸ�\nƯ¡:������ �򵿰���, ���� ������� �Ҹ���. ġ���� �ִ� ���׿��� �������� ä ������ �ٴٸ� ��Ű� �ִ�.\n����:20����");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 20) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f7 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 20) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = TRUE;

	data = _T("�̸�:ũ�������� �����\nƯ¡:ũ���������� ����� �絹�� ������ �� �����, ��Ų�� �����ϸ� Ư���� ���� ��������!\n����:60����");
	SetDlgItemText(IDC_DATA, data);

	if (coinnum >= 60) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}
	if (f8 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 60) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


BOOL CShopDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CShopDialog::OnBnClickedBuy()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (f1 == FALSE&&bt1 == TRUE) {
		f1 = TRUE;
		coinnum -= 0;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f2 == FALSE&&bt2 == TRUE) {
		f2 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f3 == FALSE&&bt3 == TRUE) {
		f3 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f4 == FALSE&&bt4 == TRUE) {
		f4 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f5 == FALSE&&bt5 == TRUE) {
		f5 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f6 == FALSE&&bt6 == TRUE) {
		f6 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f7 == FALSE&&bt7 == TRUE) {
		f7 = TRUE;
		coinnum -= 20;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f8 == FALSE&&bt8 == TRUE) {
		f8 = TRUE;
		coinnum -= 60;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("���ſϷ�");
		SetDlgItemText(IDC_HAVE, have);
	}
	str.Format(_T("coin: %d"), coinnum);
	SetDlgItemText(IDC_COIN, str);
}


void CShopDialog::OnBnClickedApply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (f1 == TRUE&&bt1 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_1;
		fish_S = (LPCTSTR)IDB_FISH1_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f2 == TRUE&&bt2 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_2;
		fish_S = (LPCTSTR)IDB_FISH2_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f3 == TRUE&&bt3 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_3;
		fish_S = (LPCTSTR)IDB_FISH3_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f4 == TRUE&&bt4 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_4;
		fish_S = (LPCTSTR)IDB_FISH4_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f5 == TRUE&&bt5 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_5;
		fish_S = (LPCTSTR)IDB_FISH5_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f6 == TRUE&&bt6 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_6;
		fish_S = (LPCTSTR)IDB_FISH6_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f7 == TRUE&&bt7 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_7;
		fish_S = (LPCTSTR)IDB_FISH7_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f8 == TRUE&&bt8 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_8;
		fish_S = (LPCTSTR)IDB_FISH8_REVERSE;
		m_pView->christmas = TRUE;
	}


	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->fish = fish;
	m_pView->fish2 = fish_S;
	SetDlgItemText(IDC_DATA, data);
}


void CShopDialog::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
	//DestroyWindow();
	CDialog::OnCancel();
}


void CShopDialog::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//m_pView->m_pDlg = NULL;
//	delete this;
	CDialog::PostNcDestroy();
}


void CShopDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
}



void CShopDialog::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
	//DestroyWindow();
	CDialog::OnCancel();
}
