#include "base.h"
#include "dbbase.h"

void PRODUCT::del(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	allview(podbc);

	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	

	cout << "제거할 상품코드를 입력해주세요 : ";
	cin >> product_num;
	
	str = "SELECT * FROM 상품정보 WHERE 상품번호=";
	str += to_string(product_num);
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "등록되지 않은 상품입니다.";
		return;
	}

	if (podbc.db_product_viewResult() == 0) {
		cout << "조회결과가 비어있습니다.\n\n";
		return;
	}

	int menu;
	cout << "제거 할 상품이 위 상품이 맞습니까? (맞으면 1, 아니면 2) : ";
	cin >> menu;

	if (menu == 2) {
		cout << "\n상품제거가 취소되었습니다. \n";
		return;
	}

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "DELETE FROM 상품정보 WHERE 상품번호=";
	str += to_string(product_num);
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "삭제가 처리 되지 않았습니다.\n\n";
	else cout << "삭제가 완료되었습니다.\n\n";
	

}