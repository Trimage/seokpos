#include "base.h"

void RECEIPT::year_state(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[500]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	string start_date, end_date;
	cout << "��ǰ�� �Ǹŷ����̸� Ȯ���� �⵵�� �Է����ּ��� ex)YYYY : ";
	cin >> start_date;

	if (start_date.size() != 4) {
		cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���\n\n";
		month_state(podbc);
		return;
	}

	end_date = start_date + "1231"; //20201231
	start_date += "0101";			//20200101

	paydate = stoi(start_date);

	str = "SELECT ��ǰ��, SUM(����) AS �Ǹż���, (SELECT SUM(����) AS '�� �Ǹż���' FROM ���������� WHERE ������>=";
	str += start_date + " AND ������<=" + end_date + " AND ����>=0) FROM ���������� WHERE ������ >=" + start_date + " AND ������<=" + end_date + " AND ����>=0 GROUP BY ��ǰ�� ORDER BY SUM(����) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �����Ͽ����ϴ�.\n";

	cout << start_date.substr(0, 4) << "�� ���� �Ǹŷ� �����Դϴ�.\n";
	podbc.db_receipt_sale_stateResult();

}