#include "dbbase.h"
#include "base.h"

using namespace std;

int main() {
	int menu;

	PODBC podbc;
	PRODUCT product;
	RECEIPT receipt;

	receipt.order(podbc);
	
	/*
	while (1) {
		cout << "\n┌────────────────────────────────┐\n";
		cout << "│ 메인메뉴\t\t\t │\n";
		cout << "│ \t\t\t\t │\n";
		cout << "│ 1. 상품판매\t\t\t │\n";
		cout << "│ 2. 상품관리\t\t\t │\n";
		cout << "│ 3. 매출확인\t\t\t │\n";
		cout << "│ 4. 프로그램 닫기\t\t │\n";
		cout << "└────────────────────────────────┘\n";
		cout << "메뉴 선택 : ";
		cin >> menu; // 1:상품판매 , 2:상품관리, 3:매출확인, 4:프로그램 닫기
		if (menu == 4) break;

		switch (menu) {
		case 1:
		case 2:
		case 3:
		default:
		}
	}
	
	cout << "\n\n※ 프로그램이 종료됩니다 ※";
	system("pause");
	return 0;


	*/

	/* 
	==> 상품삽입 podbc.ExecuteStatementDirect((SQLCHAR*)"INSERT INTO 상품정보 (상품번호,상품명,단가,재고) VALUES (7,'아몬드케이크',3000,10)");
	==> 상품제거 podbc.ExecuteStatementDirect((SQLCHAR*)"DELETE FROM 상품정보 WHERE 상품명='아메리카노'");
	==> 상품수정 
	==> 상품찾기 podbc.ExecuteStatementDirect((SQLCHAR*)"select * FROM 상품정보 WHERE 상품명='아메리카노'");
	
	==> 영수증조회 podbc.ExecuteStatementDirect((SQLCHAR*)"SELECT 순번, 상품정보.상품명, 상품정보.단가, 수량, 상품금액 FROM 주문내역,상품정보 WHERE 결제일 = '2020/02/07' AND 전표번호=3 AND 주문내역.상품번호=상품정보.상품번호 ORDER BY 순번 ASC");

	==> 일별 매출 건수 및 금액, 일별 환불 건수 및 금액, 일별 결제 건수 및 금액
		SELECT 결제일, COUNT(결제일)AS 매출건수, SUM(총결제금액) AS '일일 매출액' FROM 영수증정보 WHERE 매출유무='매출' GROUP BY 결제일
		SELECT 결제일, COUNT(결제일)AS 환불건수, SUM(총결제금액) AS '일일 환불액' FROM 영수증정보 WHERE 매출유무='환불' GROUP BY 결제일
		SELECT 결제일, COUNT(결제일)AS '총 결제 건수', SUM(총결제금액) AS '일일 총 결제액' FROM 영수증정보 GROUP BY 결제일

	*/

	/*
	podbc.RetrieveResult();
	*/

	podbc.DisconnectDataSource();

	system("pause");

	return 0;
}
