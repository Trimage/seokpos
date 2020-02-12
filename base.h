#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>
#include <vector>

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

class ORDER
{
	string receiptnum;	//영수증번호
	int product_num;	//상품번호
	int turn;	//순번
	int amount;	//수량
	int price;	//상품금액

public :
	void sell(PODBC &podbc);	// 상품판매
	void refund();	// 상품환불
};

class RECEIPT {
	string paydate;		// 결제일
	int receiptnum;	// 영수증번호
	string pay_or_refund; //매출유무
	int product_num;	// 상품번호
	int paytime;		// 결제시간
	string payoption;		// 결제방식
	int payprice;		// 총결제금액

public :
	void receiptview(PODBC &podbc);	//영수증조회
};

#endif