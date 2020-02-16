#include "dbbase.h"

void PODBC::db_receipt_sumResult() {

	char paysum[20];

	SQLLEN ps;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &paysum, sizeof(paysum), &ps);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return;
	}

	cout.setf(ios::left);

	cout << setw(15) << "합계금액 : ";
	cout.setf(ios::right); 
	cout << setw(15) << paysum << '\n';

	cout << "----------------------------------------------------------\n";
	int tax = stoi(paysum) / 1.1;

	cout.setf(ios::left);
	cout << setw(15) << "부가세 과세물품가액 : ";
	cout.setf(ios::right);
	cout << setw(15) << tax << '\n';

	cout.setf(ios::left);
	cout << setw(15) << "부가세 : ";
	cout.setf(ios::right);
	cout << setw(15) << stoi(paysum) - tax << '\n';
	cout << "----------------------------------------------------------\n";

	cout.setf(ios::left);

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
