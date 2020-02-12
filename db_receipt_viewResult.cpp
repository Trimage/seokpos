#include "dbbase.h"

void PODBC::db_receipt_viewResult() {

	char pay_date[20];

	short receipt_num;

	char pay_time[30];

	char pay_option[5];

	short payprice;

	char product_name[30];

	short unit_price;

	short amount;

	short price;

	SQLLEN pdate, rn, ptime, po, pp, pn, up, at, pr;


	SQLBindCol(hstmt, 1, SQL_C_CHAR, &pay_date, sizeof(pay_date), &pdate);

	SQLBindCol(hstmt, 2, SQL_C_SHORT, &receipt_num, sizeof(receipt_num), &rn);

	SQLBindCol(hstmt, 3, SQL_C_CHAR, &pay_time, sizeof(pay_time), &ptime);

	SQLBindCol(hstmt, 4, SQL_C_CHAR, &pay_option, sizeof(pay_option), &po);

	SQLBindCol(hstmt, 5, SQL_C_SHORT, &payprice, sizeof(payprice), &pp);

	SQLBindCol(hstmt, 6, SQL_C_CHAR, &product_name, sizeof(product_name), &pn);

	SQLBindCol(hstmt, 7, SQL_C_SHORT, &unit_price, sizeof(unit_price), &up);

	SQLBindCol(hstmt, 8, SQL_C_SHORT, &amount, sizeof(amount), &at);

	SQLBindCol(hstmt, 9, SQL_C_SHORT, &price, sizeof(price), &pr);
	

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n등록되지 않은 영수증입니다.\n";
		return;
	}

	cout << "영수증번호 : " << receipt_num << '\n';
	cout << "결제일 : " << pay_date << '\t' << pay_time;
	cout << "\n결제방식 : " << pay_option;
	cout << "\n==========================================================\n";
	printf("상품명\t\t단가\t\t수량\t금액");
	cout << "\n==========================================================\n";

	short totalpay = payprice;
	
	while (retcode != SQL_NO_DATA) {
		printf("%s\t%d\t\t%d\t%d\n", product_name, unit_price, amount, price);
		retcode = SQLFetch(hstmt);
	}

	cout << "\n---------------------------------------------------------------------\n";
	cout << "총 결제 금액\t\t\t\t" << totalpay << '\n';

	SQLFreeStmt(hstmt, SQL_UNBIND);

}
