#include "base.h"
#include "dbbase.h"

void RECEIPT::receiptview(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[10000]; // //SQL명령문을 실행하기 위한 캐스트
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "결제일을 입력해주세요 (ex 2020-01-01) : ";
	getline(cin, paydate);
	
	cout << "영수증번호를 입력해주세요 : ";
	cin >> receiptnum;

	str = "SELECT 영수증정보.결제일, 영수증정보.전표번호, 결제시간, 결제방식,총결제금액, 상품정보.상품명, 상품정보.단가, 수량, 상품금액 FROM 영수증정보,주문내역,상품정보 WHERE 영수증정보.결제일 = '";
	str+=paydate + "' AND 영수증정보.전표번호=" + to_string(receiptnum) + " AND 영수증정보.결제일=주문내역.결제일 AND 영수증정보.전표번호=주문내역.전표번호 AND 영수증정보.상품번호=주문내역.상품번호 AND 주문내역.상품번호=상품정보.상품번호 ORDER BY 순번 ASC";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회할 수 없는 영수증번호입니다.";

	podbc.db_receipt_viewResult();
}