#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct goods {
	string name;
	unsigned int price;
	unsigned int amount;
}goods;

typedef struct receipt {
	string date;
	unsigned int goodsnum;
	string name;
	unsigned int amount;
	unsigned int price;
	string payment;
	unsigned int extended_price;
}receipt;


int main() {
	int menu;
	map <string, int> products; // 상품명 테이블 (상품명기준으로 상품번호 대입)
	map <int, goods> products_info; // 상품정보 테이블 (상품번호를 기준으로 상품명과 단가, 수량을 대입)

	map<pair<int, string>, receipt> receipt_list;

	unsigned int receiptcnt = 1;
	unsigned int goodscnt = 1;

	while (1) {
		cout << "\n┌────────────────────────────────┐\n";
		cout << "│ 메인메뉴\t\t\t │\n";
		cout << "│ \t\t\t\t │\n";
		cout << "│ 1. 상품판매\t\t\t │\n";
		cout << "│ 2. 상품관리\t\t\t │\n";
		cout << "│ 3. 매출확인\t\t\t │\n";
		cout << "│ 4. 프로그램 종료\t\t │\n";
		cout << "└────────────────────────────────┘\n";
		cout << "메뉴 선택 : ";
		cin>> menu; // 1:상품판매 , 2:상품관리, 3:매출확인, 4:프로그램 닫기
		if (cin.fail()) {
			cin.clear(); //오류스트림을 초기화
			cin.ignore(256, '\n'); //입력 버퍼를 지움
			continue;
		}
		if (menu == 4) break;
		
		switch (menu) { 

		case 1: //★메인메뉴 -> 상품판매 관련
			while (1) {
				cout << "\n┌────────────────────────────────┐\n";
				cout << "│ 메인 -> 상품판매\t\t │\n";
				cout << "│ \t\t\t\t │\n";
				cout << "│ 1. 판매하기\t\t\t │\n";
				cout << "│ 2. 환불처리\t\t\t │\n";
				cout << "│ 3. 이전으로 돌아가기\t\t │\n";
				cout << "└────────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:판매하기, 2:환불처리, 3.이전으로 돌아가기

				if (cin.fail()) {
					cout << "잘못 된 값을 입력하였습니다. 다시 입력해주세요\n";
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
					continue;
				}

				if (menu == 3) break;
				int check = 0;

				switch(menu) {
				case 1:
					while (1) {
						string sell_goods;
						int sell_amount;
						int paysum=0;
						cout << "판매할 상품명을 입력해주세요 : ";
						getline(cin,sell_goods);
						getline(cin, sell_goods);

						if (products.find(sell_goods) == products.end()) {
							cout << "등록되지 않은 상품입니다.\n\n";
							continue;
						}
						
						cout << "판매할 수량을 입력해주세요 : ";
						cin >> sell_amount;
						
						cout << "\n\n*───────────────────*\n";
						cout << "*판매할 상품 정보\n";
						cout << "*1) 상품명 : " << sell_goods << '\n';
						cout << "*2) 상품가격 : " << goods1.price << '\n';
						cout << "*3) 상품재고 : " << goods1.amount << '\n';
						cout << "*───────────────────*\n";
						cout << "\n추가할 상품의 정보가 위와 동일합니까? (맞으면 1, 틀리면 0) : ";
						cin >> check;
						if (!check) continue;
						
						


		case 2: // ★메인메뉴 -> 상품관리 관련
			while (1) {
				cout << "\n┌────────────────────────────────┐\n";
				cout << "│ 메인 -> 상품관리\t\t │\n";
				cout << "│ \t\t\t\t │\n";
				cout << "│ 1. 상품추가\t\t\t │\n";
				cout << "│ 2. 상품제거\t\t\t │\n";
				cout << "│ 3. 상품수정\t\t\t │\n";
				cout << "│ 4. 상품찾기\t\t\t │\n";
				cout << "│ 5. 모든 상품 보기\t\t │\n";
				cout << "│ 6. 이전으로 돌아가기\t\t │\n";
				cout << "└────────────────────────────────┘\n";
				cout << "메뉴 선택 : ";
				cin >> menu; // 1:상품추가, 2:상품제거, 3.상품수정, 4.상품찾기, 5.모든 상품 보기, 6.이전으로 돌아가기

				if (cin.fail()) {
					cout << "잘못 된 값을 입력하였습니다. 다시 입력해주세요\n";
					cin.clear(); //오류스트림을 초기화
					cin.ignore(256, '\n'); //입력 버퍼를 지움
					continue;
				}

				if (menu == 6) break;
				int check = 0;

				switch (menu) {
				case 1:
					while (!check) {
						goods goods1;
						cout << "추가할 상품명을 입력하세요 : ";
						getline(cin, goods1.name);
						getline(cin, goods1.name);
						if (products.find(goods1.name) != products.end()) {
							cout << "해당 상품은 등록이 되어있습니다.\n";
							break;
						}
						cout << "추가할 상품의 가격을 입력해주세요 : ";
						cin >> goods1.price;
						cout << "추가할 상품의 재고량을 입력해주세요 : ";
						cin >> goods1.amount;

						cout << "\n\n*───────────────────*\n";
						cout << "*추가할 상품 정보\n";
						cout << "*1) 상품명 : " << goods1.name << '\n';
						cout << "*2) 상품가격 : " << goods1.price << '\n';
						cout << "*3) 상품재고 : " << goods1.amount << '\n';
						cout << "*───────────────────*\n";
						cout << "\n추가할 상품의 정보가 위와 동일합니까? (맞으면 1, 틀리면 0) : ";
						cin >> check;
						if (!check) continue;

						products.insert(make_pair(goods1.name, goodscnt));
						products_info.insert(make_pair(goodscnt, goods1));
						goodscnt++;

						cout << "\n**" << goods1.name << " 상품이 정상적으로 등록이 완료되었습니다. **\n";
					}
					break;

				case 2:
					while (!check) {
						cout << "제거할 상품명을 입력하세요 : ";
						string goods_name;
						getline(cin, goods_name);
						getline(cin, goods_name);

						if (products.find(goods_name) == products.end()) {
							cout << "해당 상품은 등록되어 있지 않는 상품입니다.\n";
							break;
						}

						cout << "\n\n*───────────────────*\n";
						cout << "*제거할 상품 정보\n";
						cout << "*1) 상품명 : " << goods_name << '\n';
						cout << "*2) 상품번호 : " << products[goods_name] << '\n';
						cout << "*3) 상품가격 : " << products_info[products[goods_name]].price << '\n';
						cout << "*4) 상품재고 : " << products_info[products[goods_name]].amount << '\n';
						cout << "*───────────────────*\n";

						cout << "\n제거할 상품의 정보가 위와 동일합니까? (맞으면 1, 틀리면 0) : ";
						cin >> check;
						if (!check) continue;

						products_info.erase(products[goods_name]);
						products.erase(goods_name);

						cout << "\n**상품이 정상적으로 삭제 되었습니다. **\n";
					}
					break;

				case 3:
					while (!check) {
						cout << "수정할 상품명을 입력하세요 : ";
						string goods_name;
						getline(cin, goods_name);
						getline(cin, goods_name);

						if (products.find(goods_name) == products.end()) {
							cout << "해당 상품은 등록되어 있지 않는 상품입니다.\n";
							break;
						}

						cout << "*───────────────────*\n";
						cout << "*수정할 상품 정보\n";
						cout << "*0) 상품번호 : " << products[goods_name] << '\n';
						cout << "*1) 상품명 : " << goods_name << '\n';
						cout << "*2) 상품가격 : " << products_info[products[goods_name]].price << '\n';
						cout << "*3) 상품재고량 : " << products_info[products[goods_name]].amount << '\n';
						cout << "*───────────────────*\n";

						cout << "수정할 상품의 정보가 위와 동일합니까? (맞으면 1, 틀리면 0) : ";
						cin >> check;
						if (!check) continue;

						check = 0;
						while (!check) {
							cout << "수정할 상품의 정보를 선택해주세요\n";
							cout << "1:상품명, 2:상품가격, 3:상품재고량 ==> ";
							cin >> menu;

							switch (menu) {

							case 1:
								while (!check) {
									string nextname;
									cout << "수정할 상품명을 입력해주세요 : ";
									getline(cin, nextname);
									getline(cin, nextname);

									cout << "\n\n*───────────────────*\n";
									cout << "수정 전 : " << goods_name << '\n';
									cout << "수정 후 : " << nextname << '\n';
									cout << "*───────────────────*\n";
									cout << "\n위 정보가 맞습니까? (맞으면 1, 틀리면 0) : ";

									cin >> check;
									if (!check) continue;

									int tmp = products[goods_name];
									products_info[products[goods_name]].name = nextname;
									products.erase(goods_name);
									products.insert(make_pair(nextname, tmp));

									cout << "\n**상품수정이 정상적으로 완료되었습니다. **\n";
									break;
								}
								break;

							case 2:
								while (!check) {
									int nextprice;
									cout << "수정 할 가격을 입력해주세요 : ";
									cin >> nextprice;

									cout << "\n\n*───────────────────*\n";
									cout << "수정 전 : " << products_info[products[goods_name]].price << '\n';
									cout << "수정 후 : " << nextprice;
									cout << "*───────────────────*\n";
									cout << "\n위 정보가 맞습니까? (맞으면 1, 틀리면 0) : ";

									cin >> check;
									if (!check) continue;

									products_info[products[goods_name]].price = nextprice;

									cout << "\n**상품수정이 정상적으로 완료되었습니다. **\n";
									break;
								}
								break;

							case 3:
								while (!check) {
									int nextamount;
									cout << "수정 할 재고량을 입력해주세요 : ";
									cin >> nextamount;

									cout << "\n\n*───────────────────*\n";
									cout << "수정 전 : " << products_info[products[goods_name]].amount << '\n';
									cout << "수정 후 : " << nextamount;
									cout << "*───────────────────*\n";
									cout << "\n위 정보가 맞습니까? (맞으면 1, 틀리면 0) : ";

									cin >> check;
									if (!check) continue;

									products_info[products[goods_name]].amount = nextamount;

									cout << "\n**상품수정이 정상적으로 완료되었습니다. **\n";
									break;
								}
								break;

							default:
								cout << "값을 다시 입력해주세요\n\n";
								break;
							}
						}
					}

				case 4:
					while (!check) {
						cout << "1: 상품번호로 조회, 2:상품명으로 조회  ==> ";
						cin >> menu;
						switch (menu) {
						case 1:
							while (!check) {
								int selectnum;
								cout << "\n조회할 상품번호를 입력하세요 : ";
								cin >> selectnum;

								if (products_info.find(selectnum) == products_info.end()) {
									cout << "\n해당 상품은 등록되어 있지 않는 상품입니다.\n";
									continue;
								}

								cout << "*───────────────────*\n";
								cout << "*조회 된 상품 정보\n";
								cout << "*0) 상품번호 : " << selectnum << '\n';
								cout << "*1) 상품명 : " << products_info[selectnum].name << '\n';
								cout << "*2) 상품가격 : " << products_info[selectnum].price << '\n';
								cout << "*3) 상품재고량 : " << products_info[selectnum].amount << '\n';
								cout << "*───────────────────*\n";
								check++;
								break;
							}
							break;
						case 2:
							while (!check) {
								string selectstr;
								cout << "\n조회할 상품명을 입력하세요 : ";
								cin >> selectstr;

								if (products.find(selectstr) == products.end()) {
									cout << "\n해당 상품은 등록되어 있지 않는 상품입니다.\n";
									continue;
								}

								cout << "*───────────────────*\n";
								cout << "*조회 된 상품 정보\n";
								cout << "*0) 상품번호 : " << products[selectstr] << '\n';
								cout << "*1) 상품명 : " << selectstr << '\n';
								cout << "*2) 상품가격 : " << products_info[products[selectstr]].price << '\n';
								cout << "*3) 상품재고량 : " << products_info[products[selectstr]].amount << '\n';
								cout << "*───────────────────*\n";
								check++;
							}
							break;

						default:
							cout << "값을 다시 입력해주세요\n\n";
							break;
						}

					}
					break;

				case 5:
					if (products.empty()) cout << "등록된 상품이 없습니다.\n";
					else {
						cout << "\n\n상품번호\t상품명\t\t상품가격\t상품재고량\n";
						for (auto iter = products.begin();iter != products.end();iter++) {
							cout << iter->second << "\t\t" << products_info[iter->second].name << "\t" << products_info[iter->second].price << "\t\t" << products_info[iter->second].amount << '\n';
						}
					}

					cout << "───────────────────────────────────────────────────\n\n";
					break;

				default:
					cout << "값을 다시 입력해주세요\n\n";
					break;
				}
			}

		default:
			cout << "\n현재 대메뉴를 업데이트 중입니다.\n\n";
			break;
		}
	}
	return 0;
}