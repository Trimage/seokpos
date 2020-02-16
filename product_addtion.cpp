#include "base.h"
#include "dbbase.h"

void PRODUCT::addition(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "추가할 상품 명을 입력해주세요 : ";
	getline(cin, name);
	getline(cin, name);

	cout << "단가를 입력해주세요 : ";
	cin >> unit_price;

	cout << "재고를 입력해주세요 : ";
	cin >> stock;

	str = "INSERT INTO 상품정보(상품번호,상품명, 단가, 재고) VALUES((SELECT MAX(상품번호)+1 FROM 상품정보), '";
	str += name + "', " + to_string(unit_price) + ", " + to_string(stock) + ");";
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "이미 등록된 상품번호입니다.";
	else cout << "등록이 완료 되었습니다.\n";

}