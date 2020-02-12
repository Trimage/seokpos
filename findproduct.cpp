#include "dbbase.h"

int PODBC::findproduct() {

	int cnt = 0;

	short product_id; // ��ǰ��ȣ

	char product_name; // ��ǰ��

	short product_price; // �ܰ�

	short product_stock; // ���

	short product_active; //Ȱ��ȭ����
	
	SQLLEN pdi, pdn, pdp, pds, pda;

	SQLBindCol(hstmt, 1, SQL_C_SHORT, &product_id, sizeof(product_id), &pdi);

	SQLBindCol(hstmt, 2, SQL_C_CHAR, &product_name, sizeof(product_name), &pdn);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &product_price, sizeof(product_price), &pdp);

	SQLBindCol(hstmt, 4, SQL_C_SHORT, &product_stock, sizeof(product_stock), &pds);

	SQLBindCol(hstmt, 5, SQL_C_SHORT, &product_active, sizeof(product_active), &pda);

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		retcode = SQLFetch(hstmt);
		cnt++;
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return cnt;
}
