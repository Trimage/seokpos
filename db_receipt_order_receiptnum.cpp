#include "dbbase.h"

int PODBC::db_receipt_order_receiptnum() {
	
	int getnum;

	int receiptnum;

	SQLLEN ren;

	SQLBindCol(hstmt, 1, SQL_C_LONG, &receiptnum, sizeof(receiptnum), &ren);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return 0;
	}

	if (receiptnum > 0) getnum = receiptnum;
	else getnum = 1;

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return getnum;
}