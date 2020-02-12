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

	cout << "합계금액 : \t\t\t" << paysum;
	cout << "\n----------------------------------------------------------\n";
	int tax = stoi(paysum) / 1.1;
	printf("\t부가세 과세물품가액 : %d\n", tax);
	cout << "\t부가세 : \t\t\t" << stoi(paysum) - (int)tax;
	cout << "\n----------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
