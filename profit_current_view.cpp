#include "base.h"

void PROFIT::current_view(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

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


	str = "SELECT SUM(결제금액) '금일 총 매출액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n" << strdate.substr(0, 4) << "년 " << strdate.substr(4, 2) << "월 " << strdate.substr(6, 2) << "일 오늘 기준 판매량 추이입니다. \n";
	cout << "총 매출액 : " << podbc.db_profit_viewResult();
	

	str = "SELECT SUM(결제금액) '금일 현금 매출액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제방식='현금' AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n현금 매출 : " << podbc.db_profit_viewResult();



	str = "SELECT SUM(결제금액) '금일 카드 매출액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제방식='카드' AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n카드 매출 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '금일 총 환불액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n\n총 환불액 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '금일 현금 환불액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제방식='현금' AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n현금 환불액 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '금일 카드 환불액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제방식='카드' AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n카드 환불액 : " << podbc.db_profit_viewResult() << "\n\n";


}