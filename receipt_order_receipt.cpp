#include "dbbase.h"
#include "base.h"

void RECEIPT::order_receipt(PODBC &podbc,RECEIPT &receipt) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[400]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	/*
	SELECT ������, POS��ȣ, ��������ȣ, �����ð�, ��ǰ��, �ܰ�, ����, �ݾ� FROM ���������� WHERE ������ = 20200207 AND POS��ȣ = 1 AND ��������ȣ = 2
	SELECT SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = 20200207 AND POS��ȣ = 1 AND ��������ȣ = 2
		*/


	str = "SELECT ������, POS��ȣ, ��������ȣ, �����ð�, ��ǰ��, �ܰ�, ����, �ݾ� FROM ���������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + "ORDER BY ���� ASC;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �� ���� ��������ȣ�Դϴ�.";

	if (!podbc.db_receipt_viewResult(receipt.posnum)) return;


	str = "SELECT SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	podbc.db_receipt_sumResult();



	str = "SELECT SUM(�����ݾ�) AS '�� ���� �ݾ�' FROM �������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + " AND ������� = '����';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << setw(30) << left << "���� ���� �ݾ� : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';




	str = "SELECT SUM(�����ݾ�) AS '�� ���� �ݾ�' FROM �������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + " AND ������� = 'ī��';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << setw(30) << left << "ī�� ���� �ݾ� : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';




	str = "SELECT SUM(�����ݾ�) AS '�� ���� �ݾ�' FROM �������� WHERE ������ = ";
	str += to_string(paydate) + " AND POS��ȣ = " + to_string(posnum) + " AND ��������ȣ = " + to_string(receiptnum) + " AND ������� = '�ܻ�';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << setw(30) << left << "�ܻ� ���� �ݾ� : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';

	cout << "------------------------------------------------------------------------\n";

}