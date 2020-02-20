#include "dbbase.h"
#define TAB 11

void PODBC::db_receipt_sale_stateResult() {

	char product_name[50];

	int amount;

	int total_amount;

	SQLLEN pdn, amt, tamt;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &product_name, sizeof(product_name), &pdn);

	SQLBindCol(hstmt, 2, SQL_C_LONG, &amount, sizeof(amount), &amt);

	SQLBindCol(hstmt, 3, SQL_C_LONG, &total_amount, sizeof(total_amount), &tamt);


	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA || amount==0) {
		cout << "\n조회되는 내역이 없습니다.\n";
		return;
	}
	
	cout << setw(31) << "\n상품명" << "판매량\n";
	cout << "=======================================================================================\n";

	while (retcode != SQL_NO_DATA) {
		float percent = (float)amount / total_amount * 100;
		string chart_bar="━";
		int cnt = 2;
		for (int i = 3;i <= percent / 2; i++) {
			chart_bar += "━";
			cnt++;
		}

		cout << setw(30) << product_name << chart_bar;
		cout << "  " << amount << "개 ";
		printf("(%.2f", percent);
		cout << "%)";
		
		int tab_size = cnt + 1 + to_string(amount).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
		tab_size = percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

		if (tab_size > 49) cout << "\n";
		else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
		else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";	
		else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
		else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
		else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";		// 

		cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";

		retcode = SQLFetch(hstmt);
	}

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	cout << setw(29) << "" << setw(TAB) << "│ 0%" << setw(TAB) << "│ 20%" << setw(TAB) << "│ 40%" << setw(TAB) << "│ 60%" << setw(TAB) << "│ 80%" << "│ 100%\n";
	cout << "---------------------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return;
}
