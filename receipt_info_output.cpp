#include "base.h"

int RECEIPT::info_paydate_output() {		//결제일 출력
	return paydate;
}
int RECEIPT::info_posnum_output() {		//POS기 번호 출력
	return posnum;
}

int RECEIPT::info_receiptnum_output() {		//영수증번호 출력
	return receiptnum;
}