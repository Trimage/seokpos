#include "dbbase.h"
#include "base.h"

using namespace std;

int main() {
	int menu;

	PODBC podbc;
	PRODUCT product;
	RECEIPT receipt;

	receipt.order(podbc);
	
	/*
	while (1) {
		cout << "\n��������������������������������������������������������������������\n";
		cout << "�� ���θ޴�\t\t\t ��\n";
		cout << "�� \t\t\t\t ��\n";
		cout << "�� 1. ��ǰ�Ǹ�\t\t\t ��\n";
		cout << "�� 2. ��ǰ����\t\t\t ��\n";
		cout << "�� 3. ����Ȯ��\t\t\t ��\n";
		cout << "�� 4. ���α׷� �ݱ�\t\t ��\n";
		cout << "��������������������������������������������������������������������\n";
		cout << "�޴� ���� : ";
		cin >> menu; // 1:��ǰ�Ǹ� , 2:��ǰ����, 3:����Ȯ��, 4:���α׷� �ݱ�
		if (menu == 4) break;

		switch (menu) {
		case 1:
		case 2:
		case 3:
		default:
		}
	}
	
	cout << "\n\n�� ���α׷��� ����˴ϴ� ��";
	system("pause");
	return 0;


	*/

	/* 
	==> ��ǰ���� podbc.ExecuteStatementDirect((SQLCHAR*)"INSERT INTO ��ǰ���� (��ǰ��ȣ,��ǰ��,�ܰ�,���) VALUES (7,'�Ƹ������ũ',3000,10)");
	==> ��ǰ���� podbc.ExecuteStatementDirect((SQLCHAR*)"DELETE FROM ��ǰ���� WHERE ��ǰ��='�Ƹ޸�ī��'");
	==> ��ǰ���� 
	==> ��ǰã�� podbc.ExecuteStatementDirect((SQLCHAR*)"select * FROM ��ǰ���� WHERE ��ǰ��='�Ƹ޸�ī��'");
	
	==> ��������ȸ podbc.ExecuteStatementDirect((SQLCHAR*)"SELECT ����, ��ǰ����.��ǰ��, ��ǰ����.�ܰ�, ����, ��ǰ�ݾ� FROM �ֹ�����,��ǰ���� WHERE ������ = '2020/02/07' AND ��ǥ��ȣ=3 AND �ֹ�����.��ǰ��ȣ=��ǰ����.��ǰ��ȣ ORDER BY ���� ASC");

	==> �Ϻ� ���� �Ǽ� �� �ݾ�, �Ϻ� ȯ�� �Ǽ� �� �ݾ�, �Ϻ� ���� �Ǽ� �� �ݾ�
		SELECT ������, COUNT(������)AS ����Ǽ�, SUM(�Ѱ����ݾ�) AS '���� �����' FROM ���������� WHERE ��������='����' GROUP BY ������
		SELECT ������, COUNT(������)AS ȯ�ҰǼ�, SUM(�Ѱ����ݾ�) AS '���� ȯ�Ҿ�' FROM ���������� WHERE ��������='ȯ��' GROUP BY ������
		SELECT ������, COUNT(������)AS '�� ���� �Ǽ�', SUM(�Ѱ����ݾ�) AS '���� �� ������' FROM ���������� GROUP BY ������

	*/

	/*
	podbc.RetrieveResult();
	*/

	podbc.DisconnectDataSource();

	system("pause");

	return 0;
}
