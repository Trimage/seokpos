#include "dbbase.h"
#include "base.h"

void RECEIPT::order(PODBC &podbc) {
	string str; //SQL명령문을 저장할 공간
	char cstr[500]; // //SQL명령문을 실행하기 위한 캐스트
	string menu; //상품번호가 아닌 "결제" || "취소" 입력시 그에 대한 처리하기
	int menu2; //총결제금액 출력 후 최종 결제 진행시 1 취소는 2

	int total_pay = 0; //총 결제 금액 출력용

	cout << "POS번호를 입력하세요 : ";
	cin >> posnum;
	
	if (cin.fail()) {
		cin.clear(); //오류스트림을 초기화
		cin.ignore(256, '\n'); //입력 버퍼를 지움
		order(podbc);
		return;
	}

	cout << "\n**환불에 경우 수량에서 -숫자 형식으로 진행해주세요 ex)수량 : -10\n\n";

	map<int,RECEIPT> order_list;
	PRODUCT product1;

	while (1) {
		cout << "\n등록된 상품정보\n";
		product1.allview(podbc);
		cout << "\n\n(선택을 마치고 결제를 할 경우 \"결제\", 판매취소 시 \"취소\")\n판매할 상품번호를 입력해주세요 : ";
		cin >> menu;
		if (menu == "취소") return;
		else if (menu == "결제") break;
		else product_num = stoi(menu);

		str = "SELECT * FROM 상품정보 WHERE 상품번호=";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "조회를 실패하였습니다.";

		if (podbc.db_product_viewResult() == 0) {
			cout << "등록되지 않은 상품입니다.\n\n";
			continue;
		}


		str = "SELECT 상품명 FROM 상품정보 WHERE 상품번호 = ";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "조회를 실패하였습니다.";

		product_name = podbc.db_receipt_order_productname();



		str = "SELECT 단가 FROM 상품정보 WHERE 상품번호 = ";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "조회를 실패하였습니다.";

		unit_price = podbc.db_receipt_order_unitprice();

		cout << "상품의 수량을 입력해주세요 : ";
		cin >> amount;

		payprice = unit_price * amount;

		order_list[product_num] = *this;


		cout << "\n\n******************************현재 장바구니 담긴 목록******************************\n";
		cout << setw(30) << "상품명" << right << setw(20) << "단가" << setw(10) << "수량" << setw(20) << "금액" << '\n';
		for (auto iter = order_list.begin(); iter != order_list.end();iter++) {
			cout << setw(30) << left << iter->second.product_name << setw(20) << right << iter->second.unit_price << setw(10) << iter->second.amount << setw(20) << iter->second.payprice << left << '\n';
		}
		cout << "***********************************************************************************\n";
	}

	for (auto iter = order_list.begin(); iter != order_list.end();iter++) total_pay += iter->second.payprice;

	while (1) {
		cout << "\n총 결제 하실 금액은 " << total_pay << "원 입니다.\n";
		cout << "결제를 희망하십니까? (진행:1, 취소2) : ";
		cin >> menu2;

		if (menu2 == 1) break;
		else if (menu2 == 2) {
			cout << "결제가 취소됩니다. \n";
			return;
		}
		else cout << "올바른 값을 입력해주세요.\n";
	}
	
	struct tm* datetime;

	time_t t;

	t = time(NULL);
	datetime = localtime(&t);
	/*
	printf("%d/%02d/%02d %02d:%02d:%02d", datetime->tm_year + 1900,
		datetime->tm_mon + 1,
		datetime->tm_mday,
		datetime->tm_hour,
		datetime->tm_min,
		datetime->tm_sec
	);
	*/
	
	string strdate=to_string(datetime->tm_year + 1900);
	
	if (datetime->tm_mon < 10) strdate += "0";
	strdate += to_string(datetime->tm_mon + 1);
	
	if (datetime->tm_mday < 10) strdate += "0";
	strdate+= to_string(datetime->tm_mday);

	paydate = stoi(strdate);

	str = "SELECT MAX(영수증번호)+1 FROM 영수증정보 WHERE 결제일= ";
	str += to_string(paydate) + "AND POS번호 = " + to_string(posnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "조회를 실패하였습니다.";
	receiptnum = podbc.db_receipt_order_receiptnum();

	paytime= to_string(datetime->tm_hour) + ":" + to_string(datetime->tm_min) + ":" + to_string(datetime->tm_sec);

	PROFIT profit;
	int cnt = 1;
	while (total_pay) {
		total_pay = profit.insert(total_pay, cnt, *this, podbc);
		cnt++;
		
		if (total_pay > 0) cout << "남은 결제 금액은 " << total_pay << "입니다.\n\n";
	}
	
	cnt = 1;
	for (auto iter = order_list.begin(); iter != order_list.end();iter++) {
		str = "INSERT INTO 영수증정보(결제일,POS번호,영수증번호,결제시간,순번,상품번호,상품명,단가,수량,금액) VALUES (";
		str += to_string(paydate) + ", " + to_string(iter->second.posnum) + ", " + to_string(receiptnum) + ", '";
		str += paytime + "', ";
		str += to_string(cnt) + ", " + to_string(iter->second.product_num) + ", '" + iter->second.product_name + "', ";
		str += to_string(iter->second.unit_price) + ", " + to_string(iter->second.amount) + ", " + to_string(iter->second.payprice) + ");";
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << iter->second.product_num << "는 결제를 실패하였습니다.";


		str = "UPDATE 상품정보 SET 재고=(SELECT 재고 FROM 상품정보 WHERE 상품번호=";
		str += to_string(iter->second.product_num) + ") - " + to_string(iter->second.amount) + " WHERE 상품번호 = " + to_string(iter->second.product_num) + ";";
		strcpy(cstr, str.c_str());
		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << iter->second.product_num << "재고 업데이트를 실패하였습니다.";

		cnt++;
	}

	cout << "\n****결제가 완료되었습니다.****\n\n";

	this->order_receipt(podbc,*this);
}