#include "dbbase.h"

void PODBC::db_product_viewResult() {

	short product_id;

	char product_name[30];

	short product_price;

	short product_stock;

	SQLLEN pdi, pdn, pdp, pds;


	SQLBindCol(hstmt, 1, SQL_C_SHORT, &product_id, sizeof(product_id), &pdi);

	SQLBindCol(hstmt, 2, SQL_C_CHAR, &product_name, sizeof(product_name), &pdn);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &product_price, sizeof(product_price), &pdp);

	SQLBindCol(hstmt, 4, SQL_C_SHORT, &product_stock, sizeof(product_stock), &pds);

	cout << "\n───────────────────────────────────────────────────────\n";
	printf("상품번호\t상품명\t\t단가\t\t재고");

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		printf("\n%d\t\t%s\t%d\t\t%d", product_id, product_name, product_price, product_stock);
		retcode = SQLFetch(hstmt);
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
