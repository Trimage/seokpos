#include "dbbase.h"
#include "base.h"

void RECEIPT::order_receipt(PODBC &podbc,RECEIPT &receipt) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[400]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "SELECT ������, POS��ȣ, ��������ȣ, �����ð�, ��ǰ��, �ܰ�, ����, �ݾ� FROM ���������� WHERE ������ = ";
	str += to_string(receipt.paydate) + " AND POS��ȣ = " + to_string(receipt.posnum) + " AND ��������ȣ = " + to_string(receipt.receiptnum) + "ORDER BY ���� ASC;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �� ���� ��������ȣ�Դϴ�.";

	podbc.db_receipt_viewResult();


	str = "SELECT SUM(�ݾ�) AS '�� ���� �ݾ�' FROM ���������� WHERE ������ = ";
	str += to_string(receipt.paydate) + " AND POS��ȣ = " + to_string(receipt.posnum) + " AND ��������ȣ = " + to_string(receipt.receiptnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "������ �߻��Ͽ����ϴ�.\n";

	podbc.db_receipt_sumResult();

}