#include "base.h"

void PROFIT::year_view(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	string start_date, end_date;
	cout << "������ȸ�� ����ϴ� �⵵�� �Է����ּ��� ex)YYYY : ";
	cin >> start_date;
	start_date = start_date.substr(0, 4);

	end_date = start_date + "9999";
	start_date += "0000";

	paydate = stoi(start_date);

	str = "SELECT SUM(�����ݾ�) '�⺰ �� �����' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << start_date.substr(0, 4) << "�⵵ ���� ���� ��Ȳ�Դϴ�.\n";
	cout << "�� ����� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '�⺰ ���� �����' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �������='����' AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n���� ���� : " << podbc.db_profit_viewResult();



	str = "SELECT SUM(�����ݾ�) '�⺰ ī�� �����' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �������='ī��' AND �����ݾ� >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\nī�� ���� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '�⺰ �� ȯ�Ҿ�' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n\n�� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '�⺰ ���� ȯ�Ҿ�' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �������='����' AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\n���� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) '�⺰ ī�� ȯ�Ҿ�' FROM �������� WHERE ������>=";
	str += start_date + " AND ������ < " + end_date + " AND �������='ī��' AND �����ݾ� <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	cout << "\nī�� ȯ�Ҿ� : " << podbc.db_profit_viewResult();


}