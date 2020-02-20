#include "base.h"

void RECEIPT::day_state(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[500]; // //SQL명령문을 실행하기 위한 캐스트

	cout << "상품의 판매량추이를 확인할 날짜를 입력해주세요 ex)20200127 : ";
	cin >> paydate;

	if (to_string(paydate).size() != 8) {
		cout << "잘못된 값입니다. 다시 입력해주세요\n\n";
		day_state(podbc);
		return;
	}

	str = "SELECT 상품명, SUM(수량) AS 판매수량, (SELECT SUM(수량) AS '총 판매수량' FROM 영수증정보 WHERE 결제일=";
	str += to_string(paydate) + "AND 수량>=0) FROM 영수증정보 WHERE 결제일=" + to_string(paydate) + " AND 수량>=0 GROUP BY 상품명 ORDER BY SUM(수량) DESC;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "조회를 실패하였습니다.";
		return;
	}

	string strdate = to_string(paydate);
	cout << "\n" << strdate.substr(0, 4) << "년 " << strdate.substr(4, 2) << "월 " << strdate.substr(6, 2) << "일 기준 판매량 추이입니다. \n";
	podbc.db_receipt_sale_stateResult();
	
}