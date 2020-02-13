#include "dbbase.h"

int PODBC::db_receipt_order_unitprice() {
	
	int order_price;

	int unit_price;

	SQLLEN up;

	SQLBindCol(hstmt, 1, SQL_C_LONG, &unit_price, sizeof(unit_price), &up);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return 0;
	}

	order_price = unit_price;

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return order_price;
}
