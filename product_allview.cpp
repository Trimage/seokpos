#include "base.h"
#include "dbbase.h"

void PRODUCT::allview(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "SELECT * FROM ��ǰ����";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �����Ͽ����ϴ�.";
	
	if (podbc.db_product_viewResult() == 0)
		cout << "��ǰ�� ��ϵǾ����� �ʽ��ϴ�. ��ǰ�� ������ּ���.\n\n";;
}