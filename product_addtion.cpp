#include "base.h"
#include "dbbase.h"

void PRODUCT::addition(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "�߰��� ��ǰ ���� �Է����ּ��� : ";
	getline(cin, name);

	cout << "�ܰ��� �Է����ּ��� : ";
	cin >> unit_price;

	cout << "��� �Է����ּ��� : ";
	cin >> stock;

	str = "INSERT INTO ��ǰ����(��ǰ��ȣ,��ǰ��, �ܰ�, ���, Ȱ��ȭ����) VALUES((SELECT MAX(��ǰ��ȣ)+1 FROM ��ǰ����), '";
	str += name + "', " + to_string(unit_price) + ", " + to_string(stock) + ", 1);";
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "�̹� ��ϵ� ��ǰ��ȣ�Դϴ�.";

}