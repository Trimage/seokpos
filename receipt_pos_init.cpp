#include "base.h"

void RECEIPT::pos_init() {

	while (1) {
		cout << "POS��ȣ�� �Է��ϼ��� : ";
		cin >> posnum;

		if (cin.fail()) {
			cout << "���ڸ� �Է����ּ���.\n\n";
			cin.clear(); //������Ʈ���� �ʱ�ȭ
			cin.ignore(256, '\n'); //�Է� ���۸� ����
			continue;
		}

		cout << "\n������ȣ�� " << posnum <<"������ �����Ǿ����ϴ�.\n\n";
		break;
	}
}