#include "dbbase.h"

string PODBC::db_receipt_order_productname() {

	string product_name;

	char productname[30];

	SQLLEN ptn;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &productname, sizeof(productname), &ptn);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return 0;
	}

	product_name = productname;

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return product_name;
}
