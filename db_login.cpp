#include "dbbase.h"

bool PODBC::login() {

	string str; //SQL��ɹ��� ������ ����
	char cstr[500]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	cout << "��ü���� �Է����ּ��� : ";
	cin >> db_name;
	
	cout << "���̵� �Է����ּ��� : ";
	cin >> id;

	cout << "��й�ȣ�� �Է����ּ��� : ";
	cin >> pw;

	AllocateHandles();

	// 32-bit, 64-bit ����
	retcode = SQLConnect(hdbc, (SQLCHAR*)db_name, SQL_NTS, (SQLCHAR*)id, SQL_NTS, (SQLCHAR*)pw, SQL_NTS);

	str = "SELECT ��ǰ�� FROM ��ǰ���� WHERE ��ǰ��ȣ = 0";
	strcpy(cstr, str.c_str());

	if (!ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "\n�α��ο� �����Ͽ����ϴ�.\nȸ���, ���̵�, ��й�ȣ�� ������ �ٽ� Ȯ�����ּ���\n\n";
		return false;
	}

	return true;
}