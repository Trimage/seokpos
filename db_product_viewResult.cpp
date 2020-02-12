#include "dbbase.h"

int PODBC::db_product_viewResult() {

	int cnt = 0;

	short product_id;

	char product_name[30];

	short product_price;

	short product_stock;

	SQLLEN pdi, pdn, pdp, pds;


	SQLBindCol(hstmt, 1, SQL_C_SHORT, &product_id, sizeof(product_id), &pdi);

	SQLBindCol(hstmt, 2, SQL_C_CHAR, &product_name, sizeof(product_name), &pdn);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &product_price, sizeof(product_price), &pdp);

	SQLBindCol(hstmt, 4, SQL_C_SHORT, &product_stock, sizeof(product_stock), &pds);

	retcode = SQLFetch(hstmt);
	if (retcode == SQL_NO_DATA) return cnt;

	cout << "\n----------------------------------------------------------------------------\n";
	printf("��ǰ��ȣ\t��ǰ��\t\t�ܰ�\t\t���");

	while (retcode != SQL_NO_DATA) {
		printf("\n%d\t\t%s\t%d\t\t%d", product_id, product_name, product_price, product_stock);
		retcode = SQLFetch(hstmt);
		cnt++;
	}
	cout << "\n----------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return cnt;
}
