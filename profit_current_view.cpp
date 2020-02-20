#include "base.h"

void PROFIT::current_view(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

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


	str = "SELECT SUM(�����ݾ�) '���� �� �����' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n" << strdate.substr(0, 4) << "�� " << strdate.substr(4, 2) << "�� " << strdate.substr(6, 2) << "�� ���� ���� �Ǹŷ� �����Դϴ�. \n";
	cout << "�� ����� : " << podbc.db_profit_viewResult();
	

	str = "SELECT SUM(�����ݾ�) '���� ���� �����' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �������='����' AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n���� ���� : " << podbc.db_profit_viewResult();



	str = "SELECT SUM(�����ݾ�) '���� ī�� �����' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �������='ī��' AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\nī�� ���� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '���� �� ȯ�Ҿ�' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n\n�� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '���� ���� ȯ�Ҿ�' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �������='����' AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n���� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '���� ī�� ȯ�Ҿ�' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �������='ī��' AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\nī�� ȯ�Ҿ� : " << podbc.db_profit_viewResult() << "\n\n";


}