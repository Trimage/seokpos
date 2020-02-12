#ifndef __DBBASE_H__
#define	__DBBASE_H__

#include <windows.h>
#include <sqlext.h>
#include <iostream>

using namespace std;

class PODBC {
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

	bool ExecuteStatementDirect(SQLCHAR* sql);
	
	void PrepareStatement(SQLCHAR* sql);

	void ExecuteStatement();

	void RetrieveResult();

	void findproductResult();
	void db_product_viewResult();
	void db_receipt_viewResult();
	void findpayResult();
	void findrepundResult();
	void findallpayResult();

	void DisconnectDataSource();

};

#endif