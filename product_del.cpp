#include "base.h"
#include "dbbase.h"

void PRODUCT::del(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	allview(podbc);

	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	

	cout << "������ ��ǰ�ڵ带 �Է����ּ��� : ";
	cin >> product_num;
	
	str = "SELECT * FROM ��ǰ���� WHERE ��ǰ��ȣ=";
	str += to_string(product_num);
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "��ϵ��� ���� ��ǰ�Դϴ�.";
		return;
	}

	if (podbc.db_product_viewResult() == 0) {
		cout << "��ȸ����� ����ֽ��ϴ�.\n\n";
		return;
	}

	int menu;
	cout << "���� �� ��ǰ�� �� ��ǰ�� �½��ϱ�? (������ 1, �ƴϸ� 2) : ";
	cin >> menu;

	if (menu == 2) {
		cout << "\n��ǰ���Ű� ��ҵǾ����ϴ�. \n";
		return;
	}

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "DELETE FROM ��ǰ���� WHERE ��ǰ��ȣ=";
	str += to_string(product_num);
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ ó�� ���� �ʾҽ��ϴ�.\n\n";
	else cout << "������ �Ϸ�Ǿ����ϴ�.\n\n";
	

}