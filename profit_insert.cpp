#include "base.h"
#include "dbbase.h"

int PROFIT::insert(int total, int cnt, RECEIPT &receipt, PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	int menu; // 결제 방식 선택하면서 사용


	paydate = receipt.info_paydate_output();
	posnum = receipt.info_posnum_output();
	receiptnum = receipt.info_receiptnum_output();
	
	while (1) {
		cout << "결제 방식을 선택해주세요 (1:현금, 2:카드, 3:외상) : ";
		cin >> menu;

		if (menu == 1 || menu == 2 || menu==3) break;
		cout << "올바른 값을 입력해주세요.\n\n";
	}
	if (menu == 1) pay_type = "현금";
	else if (menu == 2) pay_type = "카드";
	else if (menu == 3) pay_type = "외상";
	
	while (1) {
		cout << "결제 할 금액을 입력해주세요 : ";
		cin >> paymoney;

		if (paymoney > total) cout << "결제할 금액보다 값이 큽니다.\n다시 입력해주세요.\n\n";
		else break;
	}

	str = "INSERT INTO 매출정보(결제일,POS번호,영수증번호,결제방식,결제금액,순번) VALUES(";
	str += to_string(paydate) + ", " + to_string(posnum) + ", " + to_string(receiptnum) + ", '" + pay_type + "', " + to_string(paymoney) + ", " + to_string(cnt) + ");" ;
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "등록할 수 없습니다.";
	else cout << pay_type << "결제가 완료 되었습니다.\n";

	return total - paymoney;
}