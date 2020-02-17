#include "base.h"
#include "dbbase.h"

void RECEIPT::listview(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[400]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "������ ����� Ȯ���Ϸ��� �������� �Է����ּ��� (ex 20200127 : ";
	cin >> paydate;

	cout << "\n\n\n";
	str = "SELECT ������, POS��ȣ, ��������ȣ, �����ð�, SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = ";
	str += to_string(paydate) + " GROUP BY ������, POS��ȣ, ��������ȣ, �����ð� ORDER BY POS��ȣ ASC";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.";

	if (!podbc.db_receipt_listviewResult()) return;

}