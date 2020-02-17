#include "dbbase.h"

bool PODBC::db_receipt_listviewResult() {

	char pay_date[10];

	int pos_num;

	int receipt_num;

	char pay_time[30];

	int total_price;

	SQLLEN pdate, psnum, rn, ptime, tp;

	SQLBindCol(hstmt, 1, SQL_C_CHAR, &pay_date, sizeof(pay_date), &pdate);

	SQLBindCol(hstmt, 2, SQL_C_LONG, &pos_num, sizeof(pos_num), &psnum);

	SQLBindCol(hstmt, 3, SQL_C_LONG, &receipt_num, sizeof(receipt_num), &rn);

	SQLBindCol(hstmt, 4, SQL_C_CHAR, &pay_time, sizeof(pay_time), &ptime);

	SQLBindCol(hstmt, 5, SQL_C_LONG, &total_price, sizeof(total_price), &tp);

	retcode = SQLFetch(hstmt);

	if (retcode == SQL_NO_DATA) {
		cout << "�ش��Ͽ� ��ϵ� �ŷ��������� �����ϴ�.\n\n";
		return false;
	}

	string strtime;

	cout << setw(15) << "������" << setw(10) << "POS��ȣ" << setw(15) << "��������ȣ" << setw(15) << "�����ð�" << setw(15) << right << "�� ���� �ݾ�" << '\n';
	cout << "========================================================================\n";

	while (retcode != SQL_NO_DATA) {
		strtime = pay_time;
		cout << setw(15) << left << pay_date << setw(10) << pos_num << setw(15) << receipt_num << setw(15) << strtime.substr(0, 8) << setw(15) << right << total_price << '\n' << left;
		retcode = SQLFetch(hstmt);
	}

	cout << "------------------------------------------------------------------------\n";

	SQLFreeStmt(hstmt, SQL_UNBIND);

	return true;
}
