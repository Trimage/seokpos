#include "base.h"
#include "dbbase.h"

void PRODUCT::addition(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트
	bool check = false; //상품 맞는지 여부 확인
	podbc.AllocateHandles();
	podbc.ConnectDataSource();
	
	
	while (!check) {
		cout << "추가할 상품 명을 입력해주세요 : ";
		getline(cin, name);
		getline(cin, name);

		cout << "단가를 입력해주세요 : ";
		cin >> unit_price;

		cout << "재고를 입력해주세요 : ";
		cin >> stock;

		cout << "----------------------------------------------------------";
		cout << "\n상품명 : " << name << "\n단가 : " << unit_price << "\n재고 : " << stock << '\n';
		cout << "----------------------------------------------------------";
		cout << "\n등록한 상품이 위 상품이 맞습니까 (맞으면1, 다르면 0) : ";
		cin >> check;

		if (!check) cout << "**등록할 상품을 다시 입력해주세요\n\n";
	}

	str = "SELECT MAX(상품번호)+1 FROM 상품정보";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "오류가 발생하였습니다.";
		return;
	}

	product_num = podbc.db_product_numResult();


	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "INSERT INTO 상품정보(상품번호,상품명, 단가, 재고) VALUES(";
	str += to_string(product_num) + ", '" + name + "', " + to_string(unit_price) + ", " + to_string(stock) + ");";
	strcpy(cstr, str.c_str());
	
	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "이미 등록된 상품번호입니다.";
	else cout << "\n\n★등록이 완료 되었습니다.★\n";

}