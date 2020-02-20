#include "base.h"

void RECEIPT::day_state(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[500]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	cout << "��ǰ�� �Ǹŷ����̸� Ȯ���� ��¥�� �Է����ּ��� ex)20200127 : ";
	cin >> paydate;

	if (to_string(paydate).size() != 8) {
		cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���\n\n";
		day_state(podbc);
		return;
	}

	str = "SELECT ��ǰ��, SUM(����) AS �Ǹż���, (SELECT SUM(����) AS '�� �Ǹż���' FROM ���������� WHERE ������=";
	str += to_string(paydate) + "AND ����>=0) FROM ���������� WHERE ������=" + to_string(paydate) + " AND ����>=0 GROUP BY ��ǰ�� ORDER BY SUM(����) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "��ȸ�� �����Ͽ����ϴ�.";
		return;
	}

	string strdate = to_string(paydate);
	cout << "\n" << strdate.substr(0, 4) << "�� " << strdate.substr(4, 2) << "�� " << strdate.substr(6, 2) << "�� ���� �Ǹŷ� �����Դϴ�. \n";
	podbc.db_receipt_sale_stateResult();
	
}