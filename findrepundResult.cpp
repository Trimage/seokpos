#include "dbbase.h"

void PODBC::findrepundResult() {

	short goods_id;

	char goods_name[20];

	short goods_price;

	short goods_stock;

	SQLLEN gid, gna, gpc, gst;


	SQLBindCol(hstmt, 1, SQL_C_SHORT, &goods_id, sizeof(goods_id), &gid);

	SQLBindCol(hstmt, 2, SQL_C_CHAR, &goods_name, sizeof(goods_name), &gna);

	SQLBindCol(hstmt, 3, SQL_C_SHORT, &goods_price, sizeof(goods_price), &gpc);

	SQLBindCol(hstmt, 4, SQL_C_SHORT, &goods_stock, sizeof(goods_stock), &gst);


	printf("상품번호\t상품명\t\t단가\t\t재고");

	retcode = SQLFetch(hstmt);

	while (retcode != SQL_NO_DATA) {
		printf("\n%d\t\t%s\t%d\t\t%d", goods_id, goods_name, goods_price, goods_stock);
		retcode = SQLFetch(hstmt);
	}

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
