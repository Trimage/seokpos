#include "base.h"

void RECEIPT::month_state(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[500]; // //SQL명령문을 실행하기 위한 캐스트

	string start_date, end_date;
	cout << "상품의 판매량추이를 확인할 날짜를 입력해주세요 ex)YYYYMM : ";
	cin >> start_date;

	if (start_date.size() != 6) {
		cout << "잘못된 값입니다. 다시 입력해주세요\n\n";
		month_state(podbc);
		return;
	}

	end_date = start_date + "31";	//20200431
	start_date += "01";				//20200400

	paydate = stoi(start_date);
	
	str = "SELECT 상품명, SUM(수량) AS 판매수량, (SELECT SUM(수량) AS '총 판매수량' FROM 영수증정보 WHERE 결제일>=";
	str += start_date + " AND 결제일<=" + end_date + " AND 수량>=0) FROM 영수증정보 WHERE 결제일 >=" + start_date + " AND 결제일<=" + end_date + " AND 수량>=0 GROUP BY 상품명 ORDER BY SUM(수량) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회를 실패하였습니다.\n";

	cout << start_date.substr(0, 4) << "년 " << start_date.substr(4, 2) << "월 기준 판매량 추이입니다.\n";
	podbc.db_receipt_sale_stateResult();

}