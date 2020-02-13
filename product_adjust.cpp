#include "base.h"
#include "dbbase.h"

void PRODUCT::adjust(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트
	
	allview(podbc);

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	cout << "\n\n수정 할 상품번호를 입력해주세요 : ";
	cin >> product_num;

	int menu = 1;

	while (menu) {
		cout << "\n\n수정 할 내역을 입력해주세요\n1:상품명, 2:단가, 3:재고 4:모두 수정 / 0:취소==> ";
		cin >> menu;

		if (menu == 0) return;

		switch (menu) {
		case 1:
			cout << "변경 할 상품명을 입력해주세요 : ";
			getline(cin, name);
			getline(cin, name);

			str = "UPDATE 상품정보 SET 상품명 = '";
			str += name + "' WHERE 상품번호=" + to_string(product_num);
			
			menu = 0;
			break;

		case 2:
			cout << "수정 할 단가를 입력해주세요 : ";
			cin >> unit_price;

			str = "UPDATE 상품정보 SET 단가 = ";
			str += to_string(unit_price) + " WHERE 상품번호=" + to_string(product_num);

			menu = 0;
			break;

		case 3:
			cout << "수정 할 재고를 입력해주세요 : ";
			cin >> stock;

			str = "UPDATE 상품정보 SET 재고 = ";
			str += to_string(stock) + " WHERE 상품번호=" + to_string(product_num);

			menu = 0;
			break;

		case 4:
			cout << "변경 할 상품명을 입력해주세요 : ";
			getline(cin, name);
			getline(cin, name);

			cout << "수정 할 단가를 입력해주세요 : ";
			cin >> unit_price;

			cout << "수정 할 재고를 입력해주세요 : ";
			cin >> stock;

			str = "UPDATE 상품정보 SET 상품명 = '";
			str += name + "', 단가 = " + to_string(unit_price) + ", 재고=" + to_string(stock) + " WHERE 상품번호=" + to_string(product_num);

			menu = 0;
			break;

		default :
			cout << "\n다시 입력해주세요\n";
			break;
		}
	}

	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "수정이 완료 되었습니다.";
}