#include "dbbase.h"

void PODBC::findpayResult() {

	char repunddate[11]; //������

	short repundcnt; //ȯ�� �Ǽ�

	short repundsum; // ���� �� ȯ�Ҿ�

	SQLLEN rd, rc, rs;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &repunddate, sizeof(repunddate), &rd);

	SQLBindCol(hstmt, 2, SQL_C_SHORT, &repundcnt, sizeof(repundcnt), &rc);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &repundsum, sizeof(repundsum), &rs);


	printf("������\tȯ�ҰǼ�\t\t���� ȯ�Ҿ�\t\t");

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		printf("\n%s\t\t%d\t%d", repunddate, repundcnt, repundsum);
		retcode = SQLFetch(hstmt);
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
