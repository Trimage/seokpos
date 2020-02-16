#include "base.h"
#include "dbbase.h"

int PROFIT::insert(int total, int cnt, RECEIPT &receipt, PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	int menu; // ���� ��� �����ϸ鼭 ���


	paydate = receipt.info_paydate_output();
	posnum = receipt.info_posnum_output();
	receiptnum = receipt.info_receiptnum_output();
	
	while (1) {
		cout << "���� ����� �������ּ��� (1:����, 2:ī��, 3:�ܻ�) : ";
		cin >> menu;

		if (menu == 1 || menu == 2 || menu==3) break;
		cout << "�ùٸ� ���� �Է����ּ���.\n\n";
	}
	if (menu == 1) pay_type = "����";
	else if (menu == 2) pay_type = "ī��";
	else if (menu == 3) pay_type = "�ܻ�";
	
	while (1) {
		cout << "���� �� �ݾ��� �Է����ּ��� : ";
		cin >> paymoney;

		if (paymoney > total) cout << "������ �ݾ׺��� ���� Ů�ϴ�.\n�ٽ� �Է����ּ���.\n\n";
		else break;
	}

	str = "INSERT INTO ��������(������,POS��ȣ,��������ȣ,�������,�����ݾ�,����) VALUES(";
	str += to_string(paydate) + ", " + to_string(posnum) + ", " + to_string(receiptnum) + ", '" + pay_type + "', " + to_string(paymoney) + ", " + to_string(cnt) + ");" ;
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "����� �� �����ϴ�.";
	else cout << pay_type << "������ �Ϸ� �Ǿ����ϴ�.\n";

	return total - paymoney;
}