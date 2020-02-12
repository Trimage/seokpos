#include "base.h"
#include "dbbase.h"

void PRODUCT::find(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트
	
	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	int menu;
	bool check = true;
	while (check) {
		cout << "\n\n상품코드로 검색 1 , 상품명으로 검색 2 ==> ";
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "찾을 상품코드를 입력해주세요 : ";
			cin >> product_num;
			str = "SELECT 상품번호,상품명, 단가, 재고 FROM 상품정보 WHERE 상품번호= '";
			str += to_string(product_num) + "'";
			strcpy(cstr, str.c_str());
			check = false;
			break;

		case 2:
			cout << "찾을 상품명을 입력해주세요 : ";
			cin >> name;
			str = "SELECT 상품번호,상품명, 단가, 재고 FROM 상품정보 WHERE 상품명= '";
			str += name + "'";
			strcpy(cstr, str.c_str());
			check = false;
			break;

		default:
			cout << "잘못 된 입력입니다. 다시 입력해주세요";
			break;
		}
	}

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회를 실패하였습니다.";

	if (podbc.db_product_viewResult() == 0)
		cout << "조회결과가 비어있습니다.\n\n";
}