#include "base.h"

void RECEIPT::pos_init() {

	while (1) {
		cout << "POS번호를 입력하세요 : ";
		cin >> posnum;

		if (cin.fail()) {
			cout << "숫자만 입력해주세요.\n\n";
			cin.clear(); //오류스트림을 초기화
			cin.ignore(256, '\n'); //입력 버퍼를 지움
			continue;
		}

		cout << "\n포스번호가 " << posnum <<"번으로 설정되었습니다.\n\n";
		break;
	}
}