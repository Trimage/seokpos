#include "dbbase.h"
#include "base.h"

void RECEIPT::order_receipt(PODBC &podbc,RECEIPT &receipt) {
	string str; //SQL명령문을 저장할 공간
	char cstr[400]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	/*
	SELECT 결제일, POS번호, 영수증번호, 결제시간, 상품명, 단가, 수량, 금액 FROM 영수증정보 WHERE 결제일 = 20200207 AND POS번호 = 1 AND 영수증번호 = 2
	SELECT SUM(금액) AS '총 결제 금액' FROM 영수증정보 WHERE 결제일 = 20200207 AND POS번호 = 1 AND 영수증번호 = 2
		*/


	str = "SELECT 결제일, POS번호, 영수증번호, 결제시간, 상품명, 단가, 수량, 금액 FROM 영수증정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + "ORDER BY 순번 ASC;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회할 수 없는 영수증번호입니다.";

	if (!podbc.db_receipt_viewResult(receipt.posnum)) return;


	str = "SELECT SUM(금액) AS '총 결제 금액' FROM 영수증정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	podbc.db_receipt_sumResult();



	str = "SELECT SUM(결제금액) AS '총 결제 금액' FROM 매출정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + " AND 결제방식 = '현금';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << setw(30) << left << "현금 결제 금액 : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';




	str = "SELECT SUM(결제금액) AS '총 결제 금액' FROM 매출정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + " AND 결제방식 = '카드';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << setw(30) << left << "카드 결제 금액 : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';




	str = "SELECT SUM(결제금액) AS '총 결제 금액' FROM 매출정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + " AND 결제방식 = '외상';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	cout << setw(30) << left << "외상 결제 금액 : ";
	cout << setw(40) << right << podbc.db_profit_viewResult() << '\n';

	cout << "------------------------------------------------------------------------\n";

}