#include "dbbase.h"
#include "base.h"
#define TAB 40

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
		cout << "\n\n��������������������������������������������������������������������������������\n";
		cout << setw(TAB) << left << "�� ���θ޴�" << "��\n";
		cout << setw(TAB) << left << "��" << "��\n";
		cout << setw(TAB) << left << "�� 1. �����ϱ�" << "��\n";
		cout << setw(TAB) << left << "�� 2. ��ǰ����" << "��\n";
		cout << setw(TAB) << left << "�� 3. �������" << "��\n";
		cout << setw(TAB) << left << "�� 4. ȯ�漳��" << "��\n";
		cout << setw(TAB) << left << "�� 5. ���α׷� �ݱ�" << "��\n";
		cout << "��������������������������������������������������������������������������������\n";
		cout << "�޴� ���� : ";
		cin >> menu; // 1:�����ϱ� , 2:��ǰ����, 3:�������, 4:ȯ�漳��, 5:���α׷� �ݱ�

		if (cin.fail()) {
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
		}

		if (menu == 5) break;

		switch (menu) {
		case 1:				// ���θ޴� -> �����ϱ� ���ø޴�
			while (1) {
				cout << "\n\n��������������������������������������������������������������������������������\n";
				cout << setw(TAB) << left << "�� ���θ޴� -> �����ϱ�" << "��\n";
				cout << setw(TAB) << left << "��" << "��\n";
				cout << setw(TAB) << left << "�� 1. ��ǰ�Ǹ� �� ȯ��" << "��\n";
				cout << setw(TAB) << left << "�� 2. ��������ȸ" << "��\n";
				cout << setw(TAB) << left << "�� 3. ���ں� ��������� ����" << "��\n";
				cout << setw(TAB) << left << "�� 4. �����޴��� ���ư���" << "��\n";
				cout << "��������������������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:��ǰ�Ǹ�, 2.��������ȸ, 3. ���ں� ��������� ����, 4.�����޴��� ���ư���

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
				cout << "\n\n��������������������������������������������������������������������������������\n";
				cout << setw(TAB) << left << "�� ���θ޴� -> ��ǰ����" << "��\n";
				cout << setw(TAB) << left << "��" << "��\n";
				cout << setw(TAB) << left << "�� 1. ��ǰ���" << "��\n";
				cout << setw(TAB) << left << "�� 2. ��ǰ����" << "��\n";
				cout << setw(TAB) << left << "�� 3. ��ǰ����" << "��\n";
				cout << setw(TAB) << left << "�� 4. Ư����ǰ ������ȸ" << "��\n";
				cout << setw(TAB) << left << "�� 5. ����ǰ ������ȸ" << "��\n";
				cout << setw(TAB) << left << "�� 6. �����޴��� ���ư���" << "��\n";
				cout << "��������������������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:��ǰ���, 2.��ǰ����, 3.��ǰ����, 4.Ư����ǰ��ȸ, 5.����ǰ��ȸ, 6.�����޴��� ���ư���

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
				cout << "\n\n��������������������������������������������������������������������������������\n";
				cout << setw(TAB) << left << "�� ���θ޴� -> �������" << "��\n";
				cout << setw(TAB) << left << "��" << "��\n";
				cout << setw(TAB) << left << "�� 1. ���� ���" << "��\n";
				cout << setw(TAB) << left << "�� 2. �Ǹŷ� ���" << "��\n";
				cout << setw(TAB) << left << "�� 3. �����޴��� ���ư���" << "��\n";
				cout << "��������������������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:���� ���, 2.�Ǹŷ� ���, 3.�����޴��� ���ư���

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
				}

				if (menu == 3) break;

				switch (menu) {
				case 1:			// ���θ޴� -> ������� -> ������� ���ø޴�
					while (1) {
						cout << "\n\n��������������������������������������������������������������������������������\n";
						cout << setw(TAB) << left << "�� ���θ޴� -> ������� -> �������" << "��\n";
						cout << setw(TAB) << left << "��" << "��\n";
						cout << setw(TAB) << left << "�� 1. ���� ������Ȳ" << "��\n";
						cout << setw(TAB) << left << "�� 2. Ư���� ������Ȳ" << "��\n";
						cout << setw(TAB) << left << "�� 3. ���� ������Ȳ" << "��\n";
						cout << setw(TAB) << left << "�� 4. �⺰ ������Ȳ" << "��\n";
						cout << setw(TAB) << left << "�� 5. �����޴��� ���ư���" << "��\n";
						cout << "��������������������������������������������������������������������������������\n";
						cout << "�޴� ���� : ";
						cin >> menu; // 1:���ϸ�����Ȳ, 2.Ư���� ������Ȳ, 3.����������Ȳ, 4.����������Ȳ, 5.�����޴��� ���ư���

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
						cout << "\n\n��������������������������������������������������������������������������������\n";
						cout << setw(TAB) << left << "�� ���θ޴� -> ������� -> �Ǹŷ� ���" << "��\n";
						cout << setw(TAB) << left << "��" << "��\n";
						cout << setw(TAB) << left << "�� 1. ���� �Ǹŷ� ����" << "��\n";
						cout << setw(TAB) << left << "�� 2. Ư���� �Ǹŷ� ����" << "��\n";
						cout << setw(TAB) << left << "�� 3. ���� �Ǹŷ� ����" << "��\n";
						cout << setw(TAB) << left << "�� 4. �⺰ �Ǹŷ� ����" << "��\n";
						cout << setw(TAB) << left << "�� 5. �����޴��� ���ư���" << "��\n";
						cout << "��������������������������������������������������������������������������������\n";
						cout << "�޴� ���� : ";
						cin >> menu; // 1:���� �Ǹŷ� ����, 2:Ư���� �Ǹŷ� ����, 3:���� �Ǹŷ� ����, 4:�⺰ �Ǹŷ� ����, 5.�����޴��� ���ư���

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
				cout << "\n\n��������������������������������������������������������������������������������\n";
				cout << setw(TAB) << left << "�� ���θ޴� -> ȯ�漳��" << "��\n";
				cout << setw(TAB) << left << "��" << "��\n";
				cout << setw(TAB) << left << "�� 1. ������ȣ ����" << "��\n";
				cout << setw(TAB) << left << "�� 2. �α��� ���� Ȯ��" << "��\n";
				cout << setw(TAB) << left << "�� 3. �ٸ� �������� �α����ϱ�" << "��\n";
				cout << setw(TAB) << left << "�� 4. �����޴��� ���ư���" << "��\n";
				cout << "��������������������������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:������ȣ ����, 2.�α��� ���� Ȯ��, 3.�ٸ� �������� �α����ϱ�, 4.�����޴��� ���ư���

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
						system("cls");
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
