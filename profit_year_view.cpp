#include "base.h"
#define TAB 11

void PROFIT::year_view(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	int total_price, cash, card;		// 총 금액, 현금 금액, 카드 금액
	float total_percent, cash_percent, card_percent;	// 총 결제율, 현금 결제율, 카드 결제율
	int tab_size;	// 출력문 정렬을 위한 사이즈 조정

	string start_date, end_date;
	cout << "매출조회를 희망하는 년도를 입력해주세요 ex)YYYY : ";
	cin >> start_date;

	if (start_date.size() != 4) {
		cout << "잘못된 값입니다. 다시 입력해주세요\n\n";
		year_view(podbc);
		return;
	}

	end_date = start_date + "1231";	//202001231
	start_date += "0101";				//20200101

	paydate = stoi(start_date);

	str = "SELECT SUM(결제금액) AS '금일 총 매출액' FROM 매출정보 WHERE 결제금액>=0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	cout << start_date.substr(0, 4) << "년도 기준 매출현황 입니다.\n";
	total_price = podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) AS '현금 매출액' FROM 매출정보 WHERE 결제방식='현금' AND 결제금액 >=0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	cash = podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) AS '카드 매출액' FROM 매출정보 WHERE 결제방식='카드' AND 결제금액 >=0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	card = podbc.db_profit_viewResult();


	cout << setw(31) << "\n종류" << "금액\n";
	cout << "========================================================================================================\n";

	if (total_price != 0) total_percent = 100;
	else total_percent = 0;
	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;
	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;

	if (card != 0) card_percent = (float)card / total_price * 100;
	else card_percent = 0;

	string chart_bar = "━";
	int cnt = 2;

	for (int i = 3;i <= total_percent / 2; i++) {
		chart_bar += "━";
		cnt++;
	}

	cout << setw(30) << "총 매출액" << chart_bar;
	cout << "  " << total_price << "원 ";
	printf("(%.2f", total_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(total_price).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = total_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";

	chart_bar = "━";
	cnt = 2;
	for (int i = 3;i <= cash_percent / 2; i++) {
		chart_bar += "━";
		cnt++;
	}

	cout << setw(30) << "현금 결제액" << chart_bar;
	cout << "  " << cash << "원 ";
	printf("(%.2f", cash_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";



	chart_bar = "━";
	cnt = 2;
	for (int i = 3;i <= card_percent / 2; i++) {
		chart_bar += "━";
		cnt++;
	}

	cout << setw(30) << "카드 결제액" << chart_bar;
	cout << "  " << card << "원 ";
	printf("(%.2f", card_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(card).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = card_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";		// 

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";



	str = "SELECT SUM(결제금액) AS '해당일 총 환불액' FROM 매출정보 WHERE 결제금액<0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	total_price = podbc.db_profit_viewResult() * -1;



	str = "SELECT SUM(결제금액) AS '해당 일 총 현금 환불액' FROM 매출정보 WHERE 결제금액<0 AND 결제방식='현금' AND 결제금액 <0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	cash = podbc.db_profit_viewResult() * -1;


	str = "SELECT SUM(결제금액) AS '해당 일 총 카드 환불액' FROM 매출정보 WHERE 결제금액<0 AND 결제방식='카드' AND 결제금액 <0 AND 결제일>=";
	str += start_date + " AND 결제일 <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.\n";
		return;
	}

	card = podbc.db_profit_viewResult() * -1;

	if (total_price != 0) total_percent = 100;
	else total_percent = 0;

	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;

	if (card != 0) card_percent = (float)card / total_price * 100;
	else card_percent = 0;

	chart_bar = "━";
	cnt = 2;
	if (total_price != 0) {
		for (int i = 3;i <= total_percent / 2; i++) {
			chart_bar += "━";
			cnt++;
		}
	}

	cout << setw(30) << "총 환불액" << chart_bar;
	cout << "  " << total_price << "원 ";
	printf("(%.2f", total_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";


	chart_bar = "━";
	cnt = 2;
	for (int i = 3;i <= cash_percent / 2; i++) {
		chart_bar += "━";
		cnt++;
	}

	cout << setw(30) << "현금 환불액" << chart_bar;
	cout << "  " << cash << "원 ";
	printf("(%.2f", cash_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";		// 

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";


	chart_bar = "━";
	cnt = 2;
	for (int i = 3;i <= card_percent / 2; i++) {
		chart_bar += "━";
		cnt++;
	}

	cout << setw(30) << "카드 취소액" << chart_bar;
	cout << "  " << card << "원 ";
	printf("(%.2f", card_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(card).size() + 3;		// tab_size = ━개수 + " 12개".size() + " (".size()
	tab_size = card_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10이면 +6, 아니면 +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "│\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";		// 

	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";


	cout << setw(29) << "" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << setw(TAB) << "│" << "│\n";
	cout << setw(29) << "" << setw(TAB) << "│ 0%" << setw(TAB) << "│ 20%" << setw(TAB) << "│ 40%" << setw(TAB) << "│ 60%" << setw(TAB) << "│ 80%" << "│ 100%\n";
	cout << "--------------------------------------------------------------------------------------------------------\n";

}