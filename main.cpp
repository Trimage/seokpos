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
		cout << "���� ���� 3ȸ�̻� �ʰ��� ���α׷��� ����˴ϴ�.\n\n";
		system("pause");
		return 0;
	}
	

	cout << "\n\n�α����� �Ϸ�Ǿ����ϴ�.\n\n\n";

	receipt.pos_init();

	cout << "�ڡ�SEOK_POS�� ���Ű��� ȯ���մϴ�.�ڡ�\n\n\n";

	while (1) {
		cout << "\n\n������������������������������������������������������������\n";
		cout << setw(30) << left << "�� ���θ޴�" << "��\n";
		cout << setw(30) << left << "��" << "��\n";
		cout << setw(30) << left << "�� 1. ��ǰ�Ǹ�" << "��\n";
		cout << setw(30) << left << "�� 2. ��ǰ����" << "��\n";
		cout << setw(30) << left << "�� 3. ������Ȳ" << "��\n";
		cout << setw(30) << left << "�� 4. ȯ�漳��" << "��\n";
		cout << setw(30) << left << "�� 5. ���α׷� �ݱ�" << "��\n";
		cout << "������������������������������������������������������������\n";
		cout << "�޴� ���� : ";
		cin >> menu; // 1:��ǰ�Ǹ� , 2:��ǰ����, 3:����Ȯ��, 4:ȯ�漳��, 5:���α׷� �ݱ�

		if (cin.fail()) {
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
		}

		if (menu == 5) break;

		switch (menu) {
		case 1:				// ���θ޴� -> ��ǰ�Ǹ� ���ø޴�
			while (1) {
				cout << "\n\n������������������������������������������������������������\n";
				cout << setw(30) << left << "�� ���θ޴� -> ��ǰ�Ǹ�" << "��\n";
				cout << setw(30) << left << "��" << "��\n";
				cout << setw(30) << left << "�� 1. ��ǰ�Ǹ� �� ȯ��" << "��\n";
				cout << setw(30) << left << "�� 2. ��������ȸ" << "��\n";
				cout << setw(30) << left << "�� 3. ���ں� ��������� ����" << "��\n";
				cout << setw(30) << left << "�� 4. �����޴��� ���ư���" << "��\n";
				cout << "������������������������������������������������������������\n";
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
				cout << "\n\n������������������������������������������������������������\n";
				cout << setw(30) << left << "�� ���θ޴� -> ��ǰ����" << "��\n";
				cout << setw(30) << left << "��" << "��\n";
				cout << setw(30) << left << "�� 1. ��ǰ���" << "��\n";
				cout << setw(30) << left << "�� 2. ��ǰ����" << "��\n";
				cout << setw(30) << left << "�� 3. ��ǰ����" << "��\n";
				cout << setw(30) << left << "�� 4. Ư����ǰ ������ȸ" << "��\n";
				cout << setw(30) << left << "�� 5. ����ǰ ������ȸ" << "��\n";
				cout << setw(30) << left << "�� 6. �����޴��� ���ư���" << "��\n";
				cout << "������������������������������������������������������������\n";
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

		case 3:				// ���θ޴� -> ������Ȳ ���ø޴�
			while (1) {
				cout << "\n\n������������������������������������������������������������\n";
				cout << setw(30) << left << "�� ���θ޴� -> ������Ȳ" << "��\n";
				cout << setw(30) << left << "��" << "��\n";
				cout << setw(30) << left << "�� 1. ���� ������Ȳ" << "��\n";
				cout << setw(30) << left << "�� 2. Ư���� ������Ȳ" << "��\n";
				cout << setw(30) << left << "�� 3. ���� ������Ȳ" << "��\n";
				cout << setw(30) << left << "�� 4. �⺰ ������Ȳ" << "��\n";
				cout << setw(30) << left << "�� 5. �����޴��� ���ư���" << "��\n";
				cout << "������������������������������������������������������������\n";
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

		case 4:			// ���θ޴� -> ȯ�漳��
			while (1) {
				cout << "\n\n������������������������������������������������������������\n";
				cout << setw(30) << left << "�� ���θ޴� -> ȯ�漳��" << "��\n";
				cout << setw(30) << left << "��" << "��\n";
				cout << setw(30) << left << "�� 1. ������ȣ ����" << "��\n";
				cout << setw(30) << left << "�� 2. �α��� ���� Ȯ��" << "��\n";
				cout << setw(30) << left << "�� 3. �����޴��� ���ư���" << "��\n";
				cout << "������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:������ȣ ����, 2.�α��� ���� Ȯ��, 3.�����޴��� ���ư���

				if (cin.fail()) {
					cin.clear(); //������Ʈ���� �ʱ�ȭ
					cin.ignore(256, '\n'); //�Է� ���۸� ����
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
