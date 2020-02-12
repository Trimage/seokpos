#include "dbbase.h"

void PODBC::db_receipt_sumResult() {

	char paysum[20];

	SQLLEN ps;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &paysum, sizeof(paysum), &ps);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	cout << "�հ�ݾ� : \t\t\t" << paysum;
	cout << "\n----------------------------------------------------------\n";
	int tax = stoi(paysum) / 1.1;
	printf("\t�ΰ��� ������ǰ���� : %d\n", tax);
	cout << "\t�ΰ��� : \t\t\t" << stoi(paysum) - (int)tax;
	cout << "\n----------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
