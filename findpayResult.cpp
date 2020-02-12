#include "dbbase.h"

void PODBC::findpayResult() {

	char repunddate[11]; //결제일

	short repundcnt; //환불 건수

	short repundsum; // 일일 총 환불액

	SQLLEN rd, rc, rs;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &repunddate, sizeof(repunddate), &rd);

	SQLBindCol(hstmt, 2, SQL_C_SHORT, &repundcnt, sizeof(repundcnt), &rc);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &repundsum, sizeof(repundsum), &rs);


	printf("결제일\t환불건수\t\t일일 환불액\t\t");

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		printf("\n%s\t\t%d\t%d", repunddate, repundcnt, repundsum);
		retcode = SQLFetch(hstmt);
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
