#include "base.h"
#include "dbbase.h"

void PRODUCT::addition(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	bool check = false; //��ǰ �´��� ���� Ȯ��
	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	
	
	while (!check) {
		cout << "�߰��� ��ǰ ���� �Է����ּ��� : ";
		getline(cin, name);
		getline(cin, name);

		cout << "�ܰ��� �Է����ּ��� : ";
		cin >> unit_price;

		cout << "��� �Է����ּ��� : ";
		cin >> stock;

		cout << "----------------------------------------------------------";
		cout << "\n��ǰ�� : " << name << "\n�ܰ� : " << unit_price << "\n��� : " << stock << '\n';
		cout << "----------------------------------------------------------";
		cout << "\n����� ��ǰ�� �� ��ǰ�� �½��ϱ� (������1, �ٸ��� 0) : ";
		cin >> check;

		if (!check) cout << "**����� ��ǰ�� �ٽ� �Է����ּ���\n\n";
	}

	str = "SELECT MAX(��ǰ��ȣ)+1 FROM ��ǰ����";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.";
		return;
	}

	product_num = podbc.db_product_numResult();


	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "INSERT INTO ��ǰ����(��ǰ��ȣ,��ǰ��, �ܰ�, ���) VALUES(";
	str += to_string(product_num) + ", '" + name + "', " + to_string(unit_price) + ", " + to_string(stock) + ");";
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "�̹� ��ϵ� ��ǰ��ȣ�Դϴ�.";
	else cout << "\n\n�ڵ���� �Ϸ� �Ǿ����ϴ�.��\n";

}