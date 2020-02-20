#include "base.h"

void RECEIPT::current_state(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[500]; // //SQL명령문을 실행하기 위한 캐스트

	struct tm* datetime;

	time_t t;

	t = time(NULL);
	datetime = localtime(&t);
	/*
	printf("%d/%02d/%02d %02d:%02d:%02d", datetime->tm_year + 1900,
		datetime->tm_mon + 1,
		datetime->tm_mday,
		datetime->tm_hour,
		datetime->tm_min,
		datetime->tm_sec
	);
	*/

	string strdate = to_string(datetime->tm_year + 1900);

	if (datetime->tm_mon < 10) strdate += "0";
	strdate += to_string(datetime->tm_mon + 1);

	if (datetime->tm_mday < 10) strdate += "0";
	strdate += to_string(datetime->tm_mday);

	paydate = stoi(strdate);



	str = "SELECT 상품명, SUM(수량) AS 판매수량, (SELECT SUM(수량) AS '총 판매수량' FROM 영수증정보 WHERE 결제일=";
	str += to_string(paydate) + "AND 수량>=0) FROM 영수증정보 WHERE 결제일=" + to_string(paydate) + " AND 수량>=0 GROUP BY 상품명 ORDER BY SUM(수량) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "조회를 실패하였습니다.";
		return;
	}

	cout << "\n" << strdate.substr(0, 4) << "년 " << strdate.substr(4, 2) << "월 " << strdate.substr(6, 2) << "일 오늘 기준 판매량 추이입니다. \n";
	podbc.db_receipt_sale_stateResult();

}