#include "dbbase.h"
#include "base.h"

using namespace std;

int main() {
	int menu;

	PODBC podbc;
	PRODUCT product;
	RECEIPT receipt;
	PROFIT profit;
		
	int cnt = 3;
	while(cnt!=0) {
		if (podbc.login()) break;
		cnt--;
	}
	
	if (cnt == 0) {
		cout << "정보 오류 3회이상 초과로 프로그램이 종료됩니다.\n\n";
		system("pause");
		return 0;
	}
	

	cout << "\n\n로그인이 완료되었습니다.\n\n\n";

	receipt.pos_init();

	cout << "★★SEOK_POS에 오신것을 환영합니다.★★\n\n\n";

	while (1) {
		cout << "\n\n┌────────────────────────────┐\n";
		cout << setw(30) << left << "│ 메인메뉴" << "│\n";
		cout << setw(30) << left << "│" << "│\n";
		cout << setw(30) << left << "│ 1. 상품판매" << "│\n";
		cout << setw(30) << left << "│ 2. 상품관리" << "│\n";
		cout << setw(30) << left << "│ 3. 매출현황" << "│\n";
		cout << setw(30) << left << "│ 4. 환경설정" << "│\n";
		cout << setw(30) << left << "│ 5. 프로그램 닫기" << "│\n";
		cout << "└────────────────────────────┘\n";
		cout << "메뉴 선택 : ";
		cin >> menu; // 1:상품판매 , 2:상품관리, 3:매출확인, 4:환경설정, 5:프로그램 닫기

		if (cin.fail()) {
			cin.clear(); //오류스트림을 초기화
			cin.ignore(256, '\n'); //입력 버퍼를 지움
		}

		if (menu == 5) break;

		switch (menu) {
		case 1:				// 메인메뉴 -> 상품판매 관련메뉴
			while (1) {
				cout << "\n\n┌────────────────────────────┐\n";
				cout << setw(30) << left << "│ 메인메뉴 -> 상품판매" << "│\n";
				cout << setw(30) << left << "│" << "│\n";
				cout << setw(30) << left << "│ 1. 상품판매 및 환불" << "│\n";
				cout << setw(30) << left << "│ 2. 영수증조회" << "│\n";
				cout << setw(30) << left << "│ 3. 일자별 영수증목록 보기" << "│\n";
				cout << setw(30) << left << "│ 4. 이전메뉴로 돌아가기" << "│\n";
				cout << "└────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:상품판매, 2.영수증조회, 3. 일자별 영수증목록 보기, 4.이전메뉴로 돌아가기

				if (cin.fail()) {
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
				}

				if (menu == 4) break;

				switch (menu) {
				case 1:
					receipt.order(podbc);
					break;
				case 2:
					receipt.receiptview(podbc);
					break;
				case 3:
					receipt.listview(podbc);
					break;
				default:
					cout << "\n올바른 값을 입력해주세요.\n\n";
					break;
				}
			}
			break;

		case 2:				// 메인메뉴 -> 상품관리 관련메뉴
			while (1) {
				cout << "\n\n┌────────────────────────────┐\n";
				cout << setw(30) << left << "│ 메인메뉴 -> 상품관리" << "│\n";
				cout << setw(30) << left << "│" << "│\n";
				cout << setw(30) << left << "│ 1. 상품등록" << "│\n";
				cout << setw(30) << left << "│ 2. 상품수정" << "│\n";
				cout << setw(30) << left << "│ 3. 상품제거" << "│\n";
				cout << setw(30) << left << "│ 4. 특정상품 정보조회" << "│\n";
				cout << setw(30) << left << "│ 5. 모든상품 정보조회" << "│\n";
				cout << setw(30) << left << "│ 6. 이전메뉴로 돌아가기" << "│\n";
				cout << "└────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:상품등록, 2.상품수정, 3.상품제거, 4.특정상품조회, 5.모든상품조회, 6.이전메뉴로 돌아가기

				if (cin.fail()) {
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
				}

				if (menu == 6) break;

				switch (menu) {
				case 1:
					product.addition(podbc);
					break;
				case 2:
					product.adjust(podbc);
					break;
				case 3:
					product.del(podbc);
					break;
				case 4:
					product.find(podbc);
					break;
				case 5:
					product.allview(podbc);
					break;
				default:
					cout << "\n올바른 값을 입력해주세요.\n\n";
					break;
				}
			}
			break;

		case 3:				// 메인메뉴 -> 매출현황 관련메뉴
			while (1) {
				cout << "\n\n┌────────────────────────────┐\n";
				cout << setw(30) << left << "│ 메인메뉴 -> 매출현황" << "│\n";
				cout << setw(30) << left << "│" << "│\n";
				cout << setw(30) << left << "│ 1. 금일 매출현황" << "│\n";
				cout << setw(30) << left << "│ 2. 특정일 매출현황" << "│\n";
				cout << setw(30) << left << "│ 3. 월별 매출현황" << "│\n";
				cout << setw(30) << left << "│ 4. 년별 매출현황" << "│\n";
				cout << setw(30) << left << "│ 5. 이전메뉴로 돌아가기" << "│\n";
				cout << "└────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:금일매출현황, 2.특정일 매출현황, 3.월별매출현황, 4.연별매출현황, 5.이전메뉴로 돌아가기

				if (cin.fail()) {
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
				}

				if (menu == 5) break;

				switch (menu) {
				case 1:
					profit.current_view(podbc);
					break;
				case 2:
					profit.day_view(podbc);
					break;
				case 3:
					profit.month_view(podbc);
					break;
				case 4:
					profit.year_view(podbc);
					break;
				default:
					cout << "\n올바른 값을 입력해주세요.\n\n";
					break;
				}
			}
			break;

		case 4:			// 메인메뉴 -> 환경설정
			while (1) {
				cout << "\n\n┌────────────────────────────┐\n";
				cout << setw(30) << left << "│ 메인메뉴 -> 환경설정" << "│\n";
				cout << setw(30) << left << "│" << "│\n";
				cout << setw(30) << left << "│ 1. 포스번호 변경" << "│\n";
				cout << setw(30) << left << "│ 2. 로그인 정보 확인" << "│\n";
				cout << setw(30) << left << "│ 3. 이전메뉴로 돌아가기" << "│\n";
				cout << "└────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:포스번호 변경, 2.로그인 정보 확인, 3.이전메뉴로 돌아가기

				if (cin.fail()) {
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
				}

				if (menu == 3) break;

				switch (menu) {
				case 1:
					receipt.pos_change();
					break;
				case 2:
					podbc.db_login_info();
					break;
				default:
					cout << "\n올바른 값을 입력해주세요.\n\n";
					break;
				}
			}
			break;
		
		default:
			cout << "\n올바른 값을 입력해주세요.\n\n";
			break;
		}
	}

	
	cout << "\n\n※ 프로그램이 종료됩니다 ※\n\n";
	system("pause");
	return 0;


	podbc.DisconnectDataSource();

	system("pause");

	return 0;
}
