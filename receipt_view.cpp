#include "base.h"
#include "dbbase.h"

void RECEIPT::receiptview(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[400]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	
	/*
	SELECT ������, POS��ȣ, ��������ȣ, �����ð�, ��ǰ��, �ܰ�, ����, �ݾ� FROM ���������� WHERE ������ = 20200207 AND POS��ȣ = 1 AND ��������ȣ = 2
	SELECT SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = 20200207 AND POS��ȣ = 1 AND ��������ȣ = 2
		*/

	cout << "�������� �Է����ּ��� ( ex 20200127 : ";
	cin >> paydate;

	cout << "POS�� ��ȣ�� �Է����ּ��� : ";
	cin >> posnum;

	cout << "��������ȣ�� �Է����ּ��� : ";
	cin >> receiptnum;

	str = "SELECT ������, POS��ȣ, ��������ȣ, �����ð�, ��ǰ��, �ܰ�, ����, �ݾ� FROM ���������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + "ORDER BY ���� ASC;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �� ���� ��������ȣ�Դϴ�.";

	podbc.db_receipt_viewResult();


	str = "SELECT SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	podbc.db_receipt_sumResult();
	
}