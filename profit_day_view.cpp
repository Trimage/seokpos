#include "base.h"

void PROFIT::day_view(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	string strdate;
	cout << "������ȸ�� ����ϴ� ��¥�� �Է����ּ��� ex)YYYYMMDD : ";
	cin >> strdate;
	strdate = strdate.substr(0, 8);

	paydate = stoi(strdate);

	str = "SELECT SUM(�����ݾ�) '���� �� �����' FROM �������� WHERE ������=";
	str += to_string(paydate) + " AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << strdate.substr(0,4) << "�� " << strdate.substr(4,2) << "�� " << strdate.substr(6,2) << "�� ���� ���� ��Ȳ�Դϴ�.\n";
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

	cout << "\nī�� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


}