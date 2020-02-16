#include "dbbase.h"

int PODBC::db_product_viewResult() {

	int cnt = 0;

	int product_id;

	char product_name[30];

	int product_price;

	int product_stock;

	SQLLEN pdi, pdn, pdp, pds;


	SQLBindCol(hstmt, 1, SQL_C_LONG, &product_id, sizeof(product_id), &pdi);

	SQLBindCol(hstmt, 2, SQL_C_CHAR, &product_name, sizeof(product_name), &pdn);

	SQLBindCol(hstmt, 3, SQL_C_LONG, &product_price, sizeof(product_price), &pdp);

	SQLBindCol(hstmt, 4, SQL_C_LONG, &product_stock, sizeof(product_stock), &pds);

	retcode = SQLFetch(hstmt);
	if (retcode == SQL_NO_DATA) return cnt;

	cout << "\n--------------------------------------------------------------------------------\n";
	cout << setw(20) << "상품번호" << setw(30) << "상품명" << setw(20) << "단가" << setw(10) << "재고" << '\n';

	while (retcode != SQL_NO_DATA) {
		cout << setw(20) << product_id << setw(30) << product_name << setw(20) << product_price << setw(10) << product_stock << '\n';
		retcode = SQLFetch(hstmt);
		cnt++;
	}
	cout << "--------------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return cnt;
}
