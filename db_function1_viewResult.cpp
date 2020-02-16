#include "dbbase.h"

int PODBC::db_function1_viewResult() {

	int getnum;

	int profitsum;

	SQLLEN pfs;

	SQLBindCol(hstmt, 1, SQL_C_LONG, &profitsum, sizeof(profitsum), &pfs);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n오류가 발생하였습니다.\n";
		return 0;
	}
	
	if (profitsum==-858993460) getnum=0;
	else getnum = profitsum;
	

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return getnum;
}
