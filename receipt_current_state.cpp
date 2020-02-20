#include "base.h"

void RECEIPT::current_state(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[500]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	struct tm* datetime;

	time_t t;

	t = time(NULL);
	datetime = localtime(&t);
	/*
	printf("%d/%02d/%02d %02d:%02d:%02d", datetime->tm_year + 1900,
		datetime->tm_mon + 1,
		datetime->tm_mday,
		datetime->tm_hour,
		datetime->tm_min,
		datetime->tm_sec
	);
	*/

	string strdate = to_string(datetime->tm_year + 1900);

	if (datetime->tm_mon < 10) strdate += "0";
	strdate += to_string(datetime->tm_mon + 1);

	if (datetime->tm_mday < 10) strdate += "0";
	strdate += to_string(datetime->tm_mday);

	paydate = stoi(strdate);



	str = "SELECT ��ǰ��, SUM(����) AS �Ǹż���, (SELECT SUM(����) AS '�� �Ǹż���' FROM ���������� WHERE ������=";
	str += to_string(paydate) + "AND ����>=0) FROM ���������� WHERE ������=" + to_string(paydate) + " AND ����>=0 GROUP BY ��ǰ�� ORDER BY SUM(����) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "��ȸ�� �����Ͽ����ϴ�.";
		return;
	}

	cout << "\n" << strdate.substr(0, 4) << "�� " << strdate.substr(4, 2) << "�� " << strdate.substr(6, 2) << "�� ���� ���� �Ǹŷ� �����Դϴ�. \n";
	podbc.db_receipt_sale_stateResult();

}