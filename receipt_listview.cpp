#include "base.h"
#include "dbbase.h"

void RECEIPT::listview(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[400]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "영수증 목록을 확인하려는 결제일을 입력해주세요 (ex 20200127 : ";
	cin >> paydate;

	cout << "\n\n\n";
	str = "SELECT 결제일, POS번호, 영수증번호, 결제시간, SUM(금액) AS '총 결제 금액' FROM 영수증정보 WHERE 결제일 = ";
	str += to_string(paydate) + " GROUP BY 결제일, POS번호, 영수증번호, 결제시간 ORDER BY POS번호 ASC";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "오류가 발생하였습니다.";

	if (!podbc.db_receipt_listviewResult()) return;

}