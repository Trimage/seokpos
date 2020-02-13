#include "base.h"
#include "dbbase.h"

void PRODUCT::adjust(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	
	allview(podbc);

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "\n\n���� �� ��ǰ��ȣ�� �Է����ּ��� : ";
	cin >> product_num;

	int menu = 1;

	while (menu) {
		cout << "\n\n���� �� ������ �Է����ּ���\n1:��ǰ��, 2:�ܰ�, 3:��� 4:��� ���� / 0:���==> ";
		cin >> menu;

		if (menu == 0) return;

		switch (menu) {
		case 1:
			cout << "���� �� ��ǰ���� �Է����ּ��� : ";
			getline(cin, name);
			getline(cin, name);

			str = "UPDATE ��ǰ���� SET ��ǰ�� = '";
			str += name + "' WHERE ��ǰ��ȣ=" + to_string(product_num);
			
			menu = 0;
			break;

		case 2:
			cout << "���� �� �ܰ��� �Է����ּ��� : ";
			cin >> unit_price;

			str = "UPDATE ��ǰ���� SET �ܰ� = ";
			str += to_string(unit_price) + " WHERE ��ǰ��ȣ=" + to_string(product_num);

			menu = 0;
			break;

		case 3:
			cout << "���� �� ��� �Է����ּ��� : ";
			cin >> stock;

			str = "UPDATE ��ǰ���� SET ��� = ";
			str += to_string(stock) + " WHERE ��ǰ��ȣ=" + to_string(product_num);

			menu = 0;
			break;

		case 4:
			cout << "���� �� ��ǰ���� �Է����ּ��� : ";
			getline(cin, name);
			getline(cin, name);

			cout << "���� �� �ܰ��� �Է����ּ��� : ";
			cin >> unit_price;

			cout << "���� �� ��� �Է����ּ��� : ";
			cin >> stock;

			str = "UPDATE ��ǰ���� SET ��ǰ�� = '";
			str += name + "', �ܰ� = " + to_string(unit_price) + ", ���=" + to_string(stock) + " WHERE ��ǰ��ȣ=" + to_string(product_num);

			menu = 0;
			break;

		default :
			cout << "\n�ٽ� �Է����ּ���\n";
			break;
		}
	}

	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �Ϸ� �Ǿ����ϴ�.";
}