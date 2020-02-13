#include "base.h"

void PROFIT::day_view(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	string strdate;
	cout << "매출조회를 희망하는 날짜를 입력해주세요 ex)YYYYMMDD : ";
	cin >> strdate;
	strdate = strdate.substr(0, 8);

	paydate = stoi(strdate);

	str = "SELECT SUM(결제금액) '금일 총 매출액' FROM 매출정보 WHERE 결제일=";
	str += to_string(paydate) + " AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << strdate.substr(0,4) << "년 " << strdate.substr(4,2) << "월 " << strdate.substr(6,2) << "일 기준 매출 현황입니다.\n";
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

	cout << "\n카드 환불액 : " << podbc.db_profit_viewResult();


}