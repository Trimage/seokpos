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
	map <string, int> products; // ��ǰ�� ���̺� (��ǰ��������� ��ǰ��ȣ ����)
	map <int, goods> products_info; // ��ǰ���� ���̺� (��ǰ��ȣ�� �������� ��ǰ��� �ܰ�, ������ ����)

	map<pair<int, string>, receipt> receipt_list;

	unsigned int receiptcnt = 1;
	unsigned int goodscnt = 1;

	while (1) {
		cout << "\n��������������������������������������������������������������������\n";
		cout << "�� ���θ޴�\t\t\t ��\n";
		cout << "�� \t\t\t\t ��\n";
		cout << "�� 1. ��ǰ�Ǹ�\t\t\t ��\n";
		cout << "�� 2. ��ǰ����\t\t\t ��\n";
		cout << "�� 3. ����Ȯ��\t\t\t ��\n";
		cout << "�� 4. ���α׷� ����\t\t ��\n";
		cout << "��������������������������������������������������������������������\n";
		cout << "�޴� ���� : ";
		cin>> menu; // 1:��ǰ�Ǹ� , 2:��ǰ����, 3:����Ȯ��, 4:���α׷� �ݱ�
		if (cin.fail()) {
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
			continue;
		}
		if (menu == 4) break;
		
		switch (menu) { 

		case 1: //�ڸ��θ޴� -> ��ǰ�Ǹ� ����
			while (1) {
				cout << "\n��������������������������������������������������������������������\n";
				cout << "�� ���� -> ��ǰ�Ǹ�\t\t ��\n";
				cout << "�� \t\t\t\t ��\n";
				cout << "�� 1. �Ǹ��ϱ�\t\t\t ��\n";
				cout << "�� 2. ȯ��ó��\t\t\t ��\n";
				cout << "�� 3. �������� ���ư���\t\t ��\n";
				cout << "��������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:�Ǹ��ϱ�, 2:ȯ��ó��, 3.�������� ���ư���

				if (cin.fail()) {
					cout << "�߸� �� ���� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���\n";
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
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
						cout << "�Ǹ��� ��ǰ���� �Է����ּ��� : ";
						getline(cin,sell_goods);
						getline(cin, sell_goods);

						if (products.find(sell_goods) == products.end()) {
							cout << "��ϵ��� ���� ��ǰ�Դϴ�.\n\n";
							continue;
						}
						
						cout << "�Ǹ��� ������ �Է����ּ��� : ";
						cin >> sell_amount;
						
						cout << "\n\n*��������������������������������������*\n";
						cout << "*�Ǹ��� ��ǰ ����\n";
						cout << "*1) ��ǰ�� : " << sell_goods << '\n';
						cout << "*2) ��ǰ���� : " << goods1.price << '\n';
						cout << "*3) ��ǰ��� : " << goods1.amount << '\n';
						cout << "*��������������������������������������*\n";
						cout << "\n�߰��� ��ǰ�� ������ ���� �����մϱ�? (������ 1, Ʋ���� 0) : ";
						cin >> check;
						if (!check) continue;
						
						


		case 2: // �ڸ��θ޴� -> ��ǰ���� ����
			while (1) {
				cout << "\n��������������������������������������������������������������������\n";
				cout << "�� ���� -> ��ǰ����\t\t ��\n";
				cout << "�� \t\t\t\t ��\n";
				cout << "�� 1. ��ǰ�߰�\t\t\t ��\n";
				cout << "�� 2. ��ǰ����\t\t\t ��\n";
				cout << "�� 3. ��ǰ����\t\t\t ��\n";
				cout << "�� 4. ��ǰã��\t\t\t ��\n";
				cout << "�� 5. ��� ��ǰ ����\t\t ��\n";
				cout << "�� 6. �������� ���ư���\t\t ��\n";
				cout << "��������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:��ǰ�߰�, 2:��ǰ����, 3.��ǰ����, 4.��ǰã��, 5.��� ��ǰ ����, 6.�������� ���ư���

				if (cin.fail()) {
					cout << "�߸� �� ���� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���\n";
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
					continue;
				}

				if (menu == 6) break;
				int check = 0;

				switch (menu) {
				case 1:
					while (!check) {
						goods goods1;
						cout << "�߰��� ��ǰ���� �Է��ϼ��� : ";
						getline(cin, goods1.name);
						getline(cin, goods1.name);
						if (products.find(goods1.name) != products.end()) {
							cout << "�ش� ��ǰ�� ����� �Ǿ��ֽ��ϴ�.\n";
							break;
						}
						cout << "�߰��� ��ǰ�� ������ �Է����ּ��� : ";
						cin >> goods1.price;
						cout << "�߰��� ��ǰ�� ����� �Է����ּ��� : ";
						cin >> goods1.amount;

						cout << "\n\n*��������������������������������������*\n";
						cout << "*�߰��� ��ǰ ����\n";
						cout << "*1) ��ǰ�� : " << goods1.name << '\n';
						cout << "*2) ��ǰ���� : " << goods1.price << '\n';
						cout << "*3) ��ǰ��� : " << goods1.amount << '\n';
						cout << "*��������������������������������������*\n";
						cout << "\n�߰��� ��ǰ�� ������ ���� �����մϱ�? (������ 1, Ʋ���� 0) : ";
						cin >> check;
						if (!check) continue;

						products.insert(make_pair(goods1.name, goodscnt));
						products_info.insert(make_pair(goodscnt, goods1));
						goodscnt++;

						cout << "\n**" << goods1.name << " ��ǰ�� ���������� ����� �Ϸ�Ǿ����ϴ�. **\n";
					}
					break;

				case 2:
					while (!check) {
						cout << "������ ��ǰ���� �Է��ϼ��� : ";
						string goods_name;
						getline(cin, goods_name);
						getline(cin, goods_name);

						if (products.find(goods_name) == products.end()) {
							cout << "�ش� ��ǰ�� ��ϵǾ� ���� �ʴ� ��ǰ�Դϴ�.\n";
							break;
						}

						cout << "\n\n*��������������������������������������*\n";
						cout << "*������ ��ǰ ����\n";
						cout << "*1) ��ǰ�� : " << goods_name << '\n';
						cout << "*2) ��ǰ��ȣ : " << products[goods_name] << '\n';
						cout << "*3) ��ǰ���� : " << products_info[products[goods_name]].price << '\n';
						cout << "*4) ��ǰ��� : " << products_info[products[goods_name]].amount << '\n';
						cout << "*��������������������������������������*\n";

						cout << "\n������ ��ǰ�� ������ ���� �����մϱ�? (������ 1, Ʋ���� 0) : ";
						cin >> check;
						if (!check) continue;

						products_info.erase(products[goods_name]);
						products.erase(goods_name);

						cout << "\n**��ǰ�� ���������� ���� �Ǿ����ϴ�. **\n";
					}
					break;

				case 3:
					while (!check) {
						cout << "������ ��ǰ���� �Է��ϼ��� : ";
						string goods_name;
						getline(cin, goods_name);
						getline(cin, goods_name);

						if (products.find(goods_name) == products.end()) {
							cout << "�ش� ��ǰ�� ��ϵǾ� ���� �ʴ� ��ǰ�Դϴ�.\n";
							break;
						}

						cout << "*��������������������������������������*\n";
						cout << "*������ ��ǰ ����\n";
						cout << "*0) ��ǰ��ȣ : " << products[goods_name] << '\n';
						cout << "*1) ��ǰ�� : " << goods_name << '\n';
						cout << "*2) ��ǰ���� : " << products_info[products[goods_name]].price << '\n';
						cout << "*3) ��ǰ��� : " << products_info[products[goods_name]].amount << '\n';
						cout << "*��������������������������������������*\n";

						cout << "������ ��ǰ�� ������ ���� �����մϱ�? (������ 1, Ʋ���� 0) : ";
						cin >> check;
						if (!check) continue;

						check = 0;
						while (!check) {
							cout << "������ ��ǰ�� ������ �������ּ���\n";
							cout << "1:��ǰ��, 2:��ǰ����, 3:��ǰ��� ==> ";
							cin >> menu;

							switch (menu) {

							case 1:
								while (!check) {
									string nextname;
									cout << "������ ��ǰ���� �Է����ּ��� : ";
									getline(cin, nextname);
									getline(cin, nextname);

									cout << "\n\n*��������������������������������������*\n";
									cout << "���� �� : " << goods_name << '\n';
									cout << "���� �� : " << nextname << '\n';
									cout << "*��������������������������������������*\n";
									cout << "\n�� ������ �½��ϱ�? (������ 1, Ʋ���� 0) : ";

									cin >> check;
									if (!check) continue;

									int tmp = products[goods_name];
									products_info[products[goods_name]].name = nextname;
									products.erase(goods_name);
									products.insert(make_pair(nextname, tmp));

									cout << "\n**��ǰ������ ���������� �Ϸ�Ǿ����ϴ�. **\n";
									break;
								}
								break;

							case 2:
								while (!check) {
									int nextprice;
									cout << "���� �� ������ �Է����ּ��� : ";
									cin >> nextprice;

									cout << "\n\n*��������������������������������������*\n";
									cout << "���� �� : " << products_info[products[goods_name]].price << '\n';
									cout << "���� �� : " << nextprice;
									cout << "*��������������������������������������*\n";
									cout << "\n�� ������ �½��ϱ�? (������ 1, Ʋ���� 0) : ";

									cin >> check;
									if (!check) continue;

									products_info[products[goods_name]].price = nextprice;

									cout << "\n**��ǰ������ ���������� �Ϸ�Ǿ����ϴ�. **\n";
									break;
								}
								break;

							case 3:
								while (!check) {
									int nextamount;
									cout << "���� �� ����� �Է����ּ��� : ";
									cin >> nextamount;

									cout << "\n\n*��������������������������������������*\n";
									cout << "���� �� : " << products_info[products[goods_name]].amount << '\n';
									cout << "���� �� : " << nextamount;
									cout << "*��������������������������������������*\n";
									cout << "\n�� ������ �½��ϱ�? (������ 1, Ʋ���� 0) : ";

									cin >> check;
									if (!check) continue;

									products_info[products[goods_name]].amount = nextamount;

									cout << "\n**��ǰ������ ���������� �Ϸ�Ǿ����ϴ�. **\n";
									break;
								}
								break;

							default:
								cout << "���� �ٽ� �Է����ּ���\n\n";
								break;
							}
						}
					}

				case 4:
					while (!check) {
						cout << "1: ��ǰ��ȣ�� ��ȸ, 2:��ǰ������ ��ȸ  ==> ";
						cin >> menu;
						switch (menu) {
						case 1:
							while (!check) {
								int selectnum;
								cout << "\n��ȸ�� ��ǰ��ȣ�� �Է��ϼ��� : ";
								cin >> selectnum;

								if (products_info.find(selectnum) == products_info.end()) {
									cout << "\n�ش� ��ǰ�� ��ϵǾ� ���� �ʴ� ��ǰ�Դϴ�.\n";
									continue;
								}

								cout << "*��������������������������������������*\n";
								cout << "*��ȸ �� ��ǰ ����\n";
								cout << "*0) ��ǰ��ȣ : " << selectnum << '\n';
								cout << "*1) ��ǰ�� : " << products_info[selectnum].name << '\n';
								cout << "*2) ��ǰ���� : " << products_info[selectnum].price << '\n';
								cout << "*3) ��ǰ��� : " << products_info[selectnum].amount << '\n';
								cout << "*��������������������������������������*\n";
								check++;
								break;
							}
							break;
						case 2:
							while (!check) {
								string selectstr;
								cout << "\n��ȸ�� ��ǰ���� �Է��ϼ��� : ";
								cin >> selectstr;

								if (products.find(selectstr) == products.end()) {
									cout << "\n�ش� ��ǰ�� ��ϵǾ� ���� �ʴ� ��ǰ�Դϴ�.\n";
									continue;
								}

								cout << "*��������������������������������������*\n";
								cout << "*��ȸ �� ��ǰ ����\n";
								cout << "*0) ��ǰ��ȣ : " << products[selectstr] << '\n';
								cout << "*1) ��ǰ�� : " << selectstr << '\n';
								cout << "*2) ��ǰ���� : " << products_info[products[selectstr]].price << '\n';
								cout << "*3) ��ǰ��� : " << products_info[products[selectstr]].amount << '\n';
								cout << "*��������������������������������������*\n";
								check++;
							}
							break;

						default:
							cout << "���� �ٽ� �Է����ּ���\n\n";
							break;
						}

					}
					break;

				case 5:
					if (products.empty()) cout << "��ϵ� ��ǰ�� �����ϴ�.\n";
					else {
						cout << "\n\n��ǰ��ȣ\t��ǰ��\t\t��ǰ����\t��ǰ���\n";
						for (auto iter = products.begin();iter != products.end();iter++) {
							cout << iter->second << "\t\t" << products_info[iter->second].name << "\t" << products_info[iter->second].price << "\t\t" << products_info[iter->second].amount << '\n';
						}
					}

					cout << "������������������������������������������������������������������������������������������������������\n\n";
					break;

				default:
					cout << "���� �ٽ� �Է����ּ���\n\n";
					break;
				}
			}

		default:
			cout << "\n���� ��޴��� ������Ʈ ���Դϴ�.\n\n";
			break;
		}
	}
	return 0;
}