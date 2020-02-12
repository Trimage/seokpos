#include "base.h"
#include "dbbase.h"

void PRODUCT::find(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	int menu;
	bool check = true;
	while (check) {
		cout << "\n\n��ǰ�ڵ�� �˻� 1 , ��ǰ������ �˻� 2 ==> ";
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "ã�� ��ǰ�ڵ带 �Է����ּ��� : ";
			cin >> product_num;
			str = "SELECT ��ǰ��ȣ,��ǰ��, �ܰ�, ��� FROM ��ǰ���� WHERE ��ǰ��ȣ= '";
			str += to_string(product_num) + "'";
			strcpy(cstr, str.c_str());
			check = false;
			break;

		case 2:
			cout << "ã�� ��ǰ���� �Է����ּ��� : ";
			cin >> name;
			str = "SELECT ��ǰ��ȣ,��ǰ��, �ܰ�, ��� FROM ��ǰ���� WHERE ��ǰ��= '";
			str += name + "'";
			strcpy(cstr, str.c_str());
			check = false;
			break;

		default:
			cout << "�߸� �� �Է��Դϴ�. �ٽ� �Է����ּ���";
			break;
		}
	}

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �����Ͽ����ϴ�.";

	if (podbc.db_product_viewResult() == 0)
		cout << "��ȸ����� ����ֽ��ϴ�.\n\n";
}