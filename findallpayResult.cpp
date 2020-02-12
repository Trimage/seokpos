#include "dbbase.h"

void PODBC::findallpayResult() {

	char paydate[11]; //결제일

	short paycnt; //총 결제 건수

	short paysum; // 일일 총 결재액

	SQLLEN apd, apc, aps;


	SQLBindCol(hstmt, 1, SQL_C_CHAR, &paydate, sizeof(paydate), &apd);

	SQLBindCol(hstmt, 2, SQL_C_SHORT, &paycnt, sizeof(paycnt), &apc);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &paysum, sizeof(paysum), &aps);


	printf("결제일\t총 결제 건수\t\t일일 총 결재액");

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		printf("\n%s\t%d\t%d", paydate, paycnt, paysum);
		retcode = SQLFetch(hstmt);
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
