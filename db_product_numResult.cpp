#include "dbbase.h"

int PODBC::db_product_numResult() {

	int getnum;

	int product_num;

	SQLLEN pdn;

	SQLBindCol(hstmt, 1, SQL_C_LONG, &product_num, sizeof(product_num), &pdn);

	retcode = SQLFetch(hstmt);

	if (product_num>=0) getnum= product_num;
	else getnum = 0;

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return getnum;

}