#include "base.h"
#include "dbbase.h"

void PRODUCT::allview(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[200]; // //SQL명령문을 실행하기 위한 캐스트

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	str = "SELECT * FROM 상품정보";
	strcpy(cstr, str.c_str());

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회를 실패하였습니다.";
	
	podbc.db_product_viewResult();
}