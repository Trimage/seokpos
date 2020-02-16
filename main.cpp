#include "dbbase.h"
#include "base.h"

using namespace std;

int main() {
	int menu;

	PODBC podbc;
	PRODUCT product;
	RECEIPT receipt;
	PROFIT profit;
		
	while (1) {
		cout << "������������������������������������������������������������\n";
		cout << setw(30) << left << "�� ���θ޴�" << "��\n";
		cout << setw(30) << left << "��" << "��\n";
		cout << setw(30) << left << "�� 1. ��ǰ�Ǹ�" << "��\n";
		cout << setw(30) << left << "�� 2. ��ǰ����" << "��\n";
		cout << setw(30) << left << "�� 3. ������Ȳ" << "��\n";
		cout << setw(30) << left << "�� 4. ���α׷� �ݱ�" << "��\n";
		cout << "������������������������������������������������������������\n";
		cout << "�޴� ���� : ";
		cin >> menu; // 1:��ǰ�Ǹ� , 2:��ǰ����, 3:����Ȯ��, 4:���α׷� �ݱ�
		if (menu == 4) break;

		switch (menu) {
		case 1:
			while (1) {
				cout << "������������������������������������������������������������\n";
				cout << setw(30) << left << "�� ���θ޴� -> ��ǰ�Ǹ�" << "��\n";
				cout << setw(30) << left << "��" << "��\n";
				cout << setw(30) << left << "�� 1. ��ǰ�Ǹ�" << "��\n";
				cout << setw(30) << left << "�� 2. ��������ȸ" << "��\n";
				cout << setw(30) << left << "�� 3. �����޴��� ���ư���" << "��\n";
				cout << "������������������������������������������������������������\n";
				cout << "�޴� ���� : ";
				cin >> menu; // 1:��ǰ�Ǹ�, 2.��������ȸ, 3.�����޴��� ���ư���

				if (menu == 3) break;

				switch (menu) {
				case 1:
					receipt.order(podbc);
					break;
				case 2:
					receipt.receiptview(podbc);
					break;
				default:
					cout << "�ùٸ� ���� �Է����ּ���.\n";
					break;
				}
			}
			break;

		case 2:
			while (1) {
				cout << "������������������������������������������������������������\n";
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
					cout << "�ùٸ� ���� �Է����ּ���.\n";
					break;
				}
			}
			break;

		case 3:
			while (1) {
				cout << "������������������������������������������������������������\n";
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
					cout << "�ùٸ� ���� �Է����ּ���.\n";
					break;
				}
			}
			break;

		default:
			cout << "�ùٸ� ���� �Է����ּ���.\n";
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
