#include "dbbase.h"

void PODBC::db_receipt_sumResult() {

	int paysum;

	SQLLEN ps;

	SQLBindCol(hstmt, 1, SQL_C_LONG, &paysum, sizeof(paysum), &ps);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return;
	}

	int tax = paysum / 1.1;

	cout << setw(30) << left << "부가세 과세 물품가액 : ";
	cout << setw(40) << right << tax << '\n';

	cout << setw(30) << left << "부       가       세 : ";
	cout << setw(40) << right << paysum - tax << '\n';
	cout << "------------------------------------------------------------------------\n";

	cout << setw(30) << left << "합계금액 : ";
	cout << setw(40) << right << paysum << '\n';
	cout << "------------------------------------------------------------------------\n";

	cout << left;

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
