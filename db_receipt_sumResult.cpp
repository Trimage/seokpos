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

	int tax = stoi(paysum) / 1.1;

	cout << setw(30) << left << "�ΰ��� ���� ��ǰ���� : ";
	cout << setw(35) << right << tax << '\n';

	cout << setw(30) << left << "��       ��       �� : ";
	cout << setw(35) << right << stoi(paysum) - tax << '\n';
	cout << "-------------------------------------------------------------------\n";

	cout << setw(30) << left << "�հ�ݾ� : ";
	cout << setw(35) << right << paysum << '\n';
	cout << "-------------------------------------------------------------------\n";

	cout << left;

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
