#include "dbbase.h"

void PODBC::findproductResult() {

	char product_name;

	int product_id;

	short product_price;
	
	short product_stock;

	SQLLEN pdtn, pdti, pdtp, pdts;


	SQLBindCol(hstmt, 1, SQL_C_CHAR, &product_name, sizeof(product_name), &pdtn);

	SQLBindCol(hstmt, 2, SQL_C_SHORT, &product_id, sizeof(product_id), &pdti);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &product_price, sizeof(product_price), &pdtp);

	SQLBindCol(hstmt, 4, SQL_C_SHORT, &product_stock, sizeof(product_stock), &pdts);

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		cout << "\n\n*��������������������������������������*\n";
		cout << "*������ ��ǰ ����\n";
		cout << "*1) ��ǰ��ȣ : " << product_id << '\n';
		cout << "*2) ��ǰ�� : " << product_name << '\n';
		cout << "*3) �ܰ� : " << product_price << '\n';
		cout << "*4) ��� : " << product_stock << '\n';
		cout << "*��������������������������������������*\n";
		retcode = SQLFetch(hstmt);
	}
	
	SQLFreeStmt(hstmt, SQL_UNBIND);

}
