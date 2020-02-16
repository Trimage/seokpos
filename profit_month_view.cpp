#include "base.h"

void PROFIT::month_view(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	string start_date,end_date;
	cout << "매출조회를 희망하는 날짜를 입력해주세요 ex)YYYYMM : ";
	cin >> start_date;
	start_date = start_date.substr(0, 6);

	end_date = start_date + "31";
	start_date += "00";

	paydate = stoi(start_date);

	str = "SELECT SUM(결제금액) '총 매출액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << start_date.substr(0, 4) << "년 " << start_date.substr(4, 2) << "월 기준 매출 현황입니다.\n";
	cout << "총 매출액 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '현금 매출액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제방식='현금' AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n현금 매출 : " << podbc.db_profit_viewResult();



	str = "SELECT SUM(결제금액) '카드 매출액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제방식='카드' AND 결제금액 >=0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n카드 매출 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '총 환불액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";
	
	cout << "\n\n총 환불액 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '현금 환불액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제방식='현금' AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n현금 환불액 : " << podbc.db_profit_viewResult();


	str = "SELECT SUM(결제금액) '카드 환불액' FROM 매출정보 WHERE 결제일>=";
	str += start_date + " AND 결제일 < " + end_date + " AND 결제방식='카드' AND 결제금액 <0;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << "\n카드 환불액 : " << podbc.db_profit_viewResult() << "\n\n";


}