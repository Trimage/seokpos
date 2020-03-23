#include "dbbase.h"
#include "base.h"
#include "menu.h"



using namespace std;

int main() {
	int menu;

	PODBC podbc;
	PRODUCT product;
	RECEIPT receipt;
	PROFIT profit;
		
	int cnt = 0;
	while(cnt!=3) {
		if (podbc.login()) break;

		cnt++;
	}
	
	if (cnt == 3) {
		cout << "�α��� ���� 3ȸ �̻����� ���� ���α׷��� ����˴ϴ�.\n\n";
		system("pause");
		return 0;
	}
	

	cout << "\n\n�α����� �Ϸ�Ǿ����ϴ�.\n\n\n";

	receipt.pos_init();

	cout << "�ڡ�SEOK_POS�� ���Ű��� ȯ���մϴ�.�ڡ�\n\n\n";

	while (1) {
		menu = main_menu();

		if (cin.fail()) {
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
		}

		if (menu == 5) break;

		switch (menu) {
		case 1:				// ���θ޴� -> �����ϱ� ���ø޴�
			while (1) {
				menu = sell_menu();

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
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
					cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
					break;
				}
			}
			break;

		case 2:				// ���θ޴� -> ��ǰ���� ���ø޴�
			while (1) {
				menu = product_menu();

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
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
					cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
					break;
				}
			}
			break;

		case 3:				// ���θ޴� -> ������� ���ø޴�
			while (1) {
				menu = statistics_menu();

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
				}

				if (menu == 3) break;

				switch (menu) {
				case 1:			// ���θ޴� -> ������� -> ������� ���ø޴�
					while (1) {
						menu = statistics_sell_menu();

						if (cin.fail()) {
							cin.clear(); //������Ʈ���� �ʱ�ȭ
							cin.ignore(256, '\n'); //�Է� ���۸� ����
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
							cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
							break;
						}
					}
					break;

				case 2:			// ���θ޴� -> ������� -> �Ǹŷ� ��� ���ø޴�
					while (1) {
						menu = statistics_product_menu();

						if (cin.fail()) {
							cin.clear(); //������Ʈ���� �ʱ�ȭ
							cin.ignore(256, '\n'); //�Է� ���۸� ����
						}

						if (menu == 5) break;

						switch (menu) {
						case 1:
							receipt.current_state(podbc);
							break;
						case 2:
							receipt.day_state(podbc);
							break;
						case 3:
							receipt.month_state(podbc);
							break;
						case 4:
							receipt.year_state(podbc);
							break;
						default:
							cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
							break;
						}
					}
					break;

				default:
					cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
					break;
				}
			}
			break;

		case 4:			// ���θ޴� -> ȯ�漳��
			while (1) {
				menu = configuration_menu();

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
				}

				if (menu == 4) break;

				switch (menu) {
				case 1:
					receipt.pos_change();
					break;
				case 2:
					podbc.db_login_info();
					break;
				case 3:
				{
					PODBC account_tmp;
					if (account_tmp.login()) {
						podbc = account_tmp;
						podbc.db_login_info();
						cout << "\n�� �α��������� ������ ����Ǿ����ϴ�.\n\n";
					}
					else cout << "���� ������ �����Ͽ����ϴ�. ���� �������� �α����� �����մϴ�.\n";
					break;
				}

				default:
					cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
					break;
				}
			}
			break;
		
		default:
			cout << "\n�ùٸ� ���� �Է����ּ���.\n\n";
			break;
		}
	}

	
	cout << "\n\n�� ���α׷��� ����˴ϴ� ��\n\n";
	system("pause");
	return 0;


	podbc.DisconnectDataSource();

	system("pause");

	return 0;
}
