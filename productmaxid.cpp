#include "dbbase.h"

int PODBC::productmaxid() {

	int maxnum = -1;

	short product_max_id; // 상품번호

	SQLLEN pdmi;

	SQLBindCol(hstmt, 1, SQL_C_SHORT, &product_max_id, sizeof(product_max_id), &pdmi);

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		retcode = SQLFetch(hstmt);
		maxnum = maxnum < product_max_id ? product_max_id : maxnum;
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return maxnum;
}
