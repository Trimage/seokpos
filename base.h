#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>

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

class RECEIPT {
	int paydate;		// 결제일
	int posnum;			// POS기 번호
	int receiptnum;		// 영수증번호
	string paytime;		// 결제시간
	int no;				// 순번
	string pruduct_name; // 상품명
	int unit_price;		//상품단가
	int amount;			// 상품수량
	int payprice;		// 금액

public :
	void receiptview(PODBC &podbc);	//영수증조회
};

#endif