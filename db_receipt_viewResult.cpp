#include "dbbase.h"

bool PODBC::db_receipt_viewResult(int posnum) {

	char pay_date[10];

	int pos_num;

	int receipt_num;

	char pay_time[30];

	char product_name[50];

	int unit_price;

	int amount;

	int price;

	SQLLEN pdate, psnum, rn, ptime, pn, up, at, pr;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &pay_date, sizeof(pay_date), &pdate);

	SQLBindCol(hstmt, 2, SQL_C_LONG, &pos_num, sizeof(pos_num), &psnum);

	SQLBindCol(hstmt, 3, SQL_C_LONG, &receipt_num, sizeof(receipt_num), &rn);

	SQLBindCol(hstmt, 4, SQL_C_CHAR, &pay_time, sizeof(pay_time), &ptime);

	SQLBindCol(hstmt, 5, SQL_C_CHAR, &product_name, sizeof(product_name), &pn);

	SQLBindCol(hstmt, 6, SQL_C_LONG, &unit_price, sizeof(unit_price), &up);

	SQLBindCol(hstmt, 7, SQL_C_LONG, &amount, sizeof(amount), &at);

	SQLBindCol(hstmt, 8, SQL_C_LONG, &price, sizeof(price), &pr);
	

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "\n��ϵ��� ���� �������Դϴ�.\n";
		return false;
	}

	string strtime = pay_time;

	cout << "������ : " << setw(20) << pay_date << "�����ð� : " << strtime.substr(0,8) << '\n';
	cout << "POS��ȣ : " << setw(10) << posnum << "��������ȣ : " << receipt_num << '\n';
	cout << "========================================================================\n";
	cout << setw(30) << "��ǰ��" << right << setw(10) << "�ܰ�" << setw(10) << "����" << setw(20) << "�ݾ�" << '\n';
	cout << "------------------------------------------------------------------------\n";
	
	while (retcode != SQL_NO_DATA) {
		cout << setw(30) << left << product_name << setw(10) << right << unit_price << setw(10) << amount << setw(20) << price << left << '\n';
		retcode = SQLFetch(hstmt);
	}

	cout << "------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return true;
}
