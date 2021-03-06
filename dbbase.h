#ifndef __DBBASE_H__
#define	__DBBASE_H__

#include <windows.h>
#include <sqlext.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

class PODBC {

	char db_name[20];

	char id[20];
	
	char pw[20];

	SQLHENV henv;

	SQLHDBC hdbc;

	SQLHSTMT hstmt;

	SQLRETURN retcode;

	// For specific error

	SQLSMALLINT length;

	SQLINTEGER rec = 0, native;

	SQLCHAR state[7], message[256];

public:

	void AllocateHandles();

	void ConnectDataSource();

	bool login();

	bool ExecuteStatementDirect(SQLCHAR* sql);
	
	void PrepareStatement(SQLCHAR* sql);

	void ExecuteStatement();

	void RetrieveResult();

	void findproductResult();
	int db_product_viewResult();
	int db_product_numResult();
	bool db_receipt_viewResult(int posnum);
	void db_receipt_sumResult();
	int db_profit_viewResult();
	int db_receipt_order_receiptnum();
	int db_receipt_order_unitprice();
	string db_receipt_order_productname();

	void db_receipt_sale_stateResult();

	bool db_receipt_listviewResult();

	void db_login_info();

	void DisconnectDataSource();

};

#endif