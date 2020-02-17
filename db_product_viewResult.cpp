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

	cout << "--------------------------------------------------------------------------------------------\n";
	cout << setw(20) << "상품번호" << setw(30) << "상품명" << setw(25) <<  right << "단가"  << setw(15) << "재고" << '\n';
	cout << "--------------------------------------------------------------------------------------------\n";

	while (retcode != SQL_NO_DATA) {
		cout << setw(20) << left << product_id << setw(30) << product_name << setw(25) << right << product_price << setw(15) << product_stock << left << '\n';
		retcode = SQLFetch(hstmt);
		cnt++;
	}
	cout << "--------------------------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return cnt;
}
