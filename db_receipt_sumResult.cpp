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

	cout.setf(ios::left);

	cout << setw(15) << "�հ�ݾ� : ";
	cout.setf(ios::right); 
	cout << setw(15) << paysum << '\n';

	cout << "----------------------------------------------------------\n";
	int tax = stoi(paysum) / 1.1;

	cout.setf(ios::left);
	cout << setw(15) << "�ΰ��� ������ǰ���� : ";
	cout.setf(ios::right);
	cout << setw(15) << tax << '\n';

	cout.setf(ios::left);
	cout << setw(15) << "�ΰ��� : ";
	cout.setf(ios::right);
	cout << setw(15) << stoi(paysum) - tax << '\n';
	cout << "----------------------------------------------------------\n";

	cout.setf(ios::left);

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
