#include "dbbase.h"

bool PODBC::login() {

	string str; //SQL명령문을 저장할 공간
	char cstr[500]; // //SQL명령문을 실행하기 위한 캐스트

	cout << "업체명을 입력해주세요 : ";
	cin >> db_name;
	
	cout << "아이디를 입력해주세요 : ";
	cin >> id;

	cout << "비밀번호를 입력해주세요 : ";
	cin >> pw;

	AllocateHandles();

	// 32-bit, 64-bit 주의
	retcode = SQLConnect(hdbc, (SQLCHAR*)db_name, SQL_NTS, (SQLCHAR*)id, SQL_NTS, (SQLCHAR*)pw, SQL_NTS);

	str = "SELECT 상품명 FROM 상품정보 WHERE 상품번호 = 0";
	strcpy(cstr, str.c_str());

	if (!ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "\n로그인에 실패하였습니다.\n회사명, 아이디, 비밀번호의 정보를 다시 확인해주세요\n\n";
		return false;
	}

	return true;
}