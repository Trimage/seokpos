#include "base.h"
#include "dbbase.h"

void RECEIPT::receiptview(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[10000]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "�������� �Է����ּ��� (ex 2020-01-01) : ";
	getline(cin, paydate);
	
	cout << "��������ȣ�� �Է����ּ��� : ";
	cin >> receiptnum;

	str = "SELECT ����������.������, ����������.��ǥ��ȣ, �����ð�, �������,�Ѱ����ݾ�, ��ǰ����.��ǰ��, ��ǰ����.�ܰ�, ����, ��ǰ�ݾ� FROM ����������,�ֹ�����,��ǰ���� WHERE ����������.������ = '";
	str+=paydate + "' AND ����������.��ǥ��ȣ=" + to_string(receiptnum) + " AND ����������.������=�ֹ�����.������ AND ����������.��ǥ��ȣ=�ֹ�����.��ǥ��ȣ AND ����������.��ǰ��ȣ=�ֹ�����.��ǰ��ȣ AND �ֹ�����.��ǰ��ȣ=��ǰ����.��ǰ��ȣ ORDER BY ���� ASC";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �� ���� ��������ȣ�Դϴ�.";

	podbc.db_receipt_viewResult();
}