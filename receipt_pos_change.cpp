#include "base.h"

void RECEIPT::pos_change() {
	
	while (1) {
		cout << "������ ������ȣ�� �Է����ּ��� : ";
		cin >> posnum;

		if (cin.fail()) {
			cout << "���ڸ� �Է����ּ���.\n\n";
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
			continue;
		}
		
		cout << "\n������ȣ�� " << posnum << "������ ����Ǿ����ϴ�.\n\n";
		break;
		
	}
}