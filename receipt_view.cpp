#include "base.h"
#include "dbbase.h"

void RECEIPT::receiptview(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[400]; // //SQL명령문을 실행하기 위한 캐스트
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	
	/*
	SELECT 결제일, POS번호, 영수증번호, 결제시간, 상품명, 단가, 수량, 금액 FROM 영수증정보 WHERE 결제일 = 20200207 AND POS번호 = 1 AND 영수증번호 = 2
	SELECT SUM(금액) AS '총 결제 금액' FROM 영수증정보 WHERE 결제일 = 20200207 AND POS번호 = 1 AND 영수증번호 = 2
		*/

	cout << "결제일을 입력해주세요 ( ex 20200127 : ";
	cin >> paydate;

	cout << "POS기 번호를 입력해주세요 : ";
	cin >> posnum;

	cout << "영수증번호를 입력해주세요 : ";
	cin >> receiptnum;
	
	cout << "\n\n\n";
	str = "SELECT 결제일, POS번호, 영수증번호, 결제시간, 상품명, 단가, 수량, 금액 FROM 영수증정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + "ORDER BY 순번 ASC;";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회할 수 없는 영수증번호입니다.";

	if (!podbc.db_receipt_viewResult(this->posnum)) return;


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

	payprice = podbc.db_profit_viewResult();
	if (payprice != 0) {
		cout << setw(30) << left << "현금 결제 금액 : ";
		cout << setw(40) << right << payprice << '\n';
	}

	str = "SELECT SUM(결제금액) AS '총 결제 금액' FROM 매출정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + " AND 결제방식 = '카드';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	payprice = podbc.db_profit_viewResult();
	if (payprice != 0) {
		cout << setw(30) << left << "카드 결제 금액 : ";
		cout << setw(40) << right << payprice << '\n';
	}



	str = "SELECT SUM(결제금액) AS '총 결제 금액' FROM 매출정보 WHERE 결제일 = ";
	str += to_string(paydate) + " AND POS번호 = " + to_string(posnum) + " AND 영수증번호 = " + to_string(receiptnum) + " AND 결제방식 = '외상';";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.\n";

	payprice = podbc.db_profit_viewResult();
	if (payprice != 0) {
		cout << setw(30) << left << "외상 결제 금액 : ";
		cout << setw(40) << right << payprice << '\n';
	}

	cout << "------------------------------------------------------------------------\n";

}