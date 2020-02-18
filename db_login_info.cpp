#include "dbbase.h"

void PODBC::db_login_info() {
	
	cout << "\n\n로그인 정보\n";
	cout << "==========================\n";
	cout << "업체명 : " << db_name << '\n';
	cout << "아이디 : " << id << '\n';
	cout << "==========================\n";

}