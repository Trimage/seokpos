#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class PRODUCT //상품정보
{
	string name;	//상품명
	int product_num; //상품번호
	int unit_price;	// 단가
	int stock;	//재고

public :
	void addition(PODBC &podbc); // 상품등록
	void del(PODBC &podbc);		// 상품제거
	void adjust(PODBC &podbc);	// 상품수정
	void find(PODBC &podbc);	// 상품찾기
	void allview(PODBC &podbc);	// 모든 상품 보기
};

class RECEIPT {		//영수증정보
	int paydate;		// 결제일
	int posnum;			// POS기 번호
	int receiptnum;		// 영수증번호
	string paytime;		// 결제시간
	int no;				// 순번
	int product_num;	// 상품번호
	string product_name; // 상품명
	int unit_price;		//상품단가
	int amount;			// 상품수량
	int payprice;		// 금액

public :
	void order_receipt(PODBC &podbc,RECEIPT &receipt);	//판매 후 영수증출력
	void receiptview(PODBC &podbc);	//영수증조회
	void order(PODBC &podbc);		// 상품판매
	int info_paydate_output();		//결제일 출력
	int info_posnum_output();		//POS기 번호 출력
	int info_receiptnum_output();		//영수증번호 출력
	void listview(PODBC &podbc); //영수증 목록 보기

	void pos_init();			// POS번호 초기설정
	void pos_change();			// POS번호 변경

	void current_state(PODBC &podbc);			// 금일 판매량 조회
	void day_state(PODBC &podbc);			// 일별 판매량 조회
	void month_state(PODBC &podbc);			// 월별 판매량 조회
	void year_state(PODBC &podbc);			// 년별 판매량 조회
};

class PROFIT {		//매출정보
	int paydate;		// 결제일
	int posnum;			// POS기 번호
	int receiptnum;		// 영수증번호
	string pay_type;	// 결제방식
	int paymoney;			//결제금액

public :
	int insert(int total, int cnt, RECEIPT &receipt, PODBC &podbc);	// 매출정보등록
	void current_view(PODBC &podbc); // 금일 매출 조회
	void day_view(PODBC &podbc);	// 일별 매출 조회
	void month_view(PODBC &podbc);	// 월별 매출 조회
	void year_view(PODBC &podbc);	// 년별 매출 조회
};

#endif