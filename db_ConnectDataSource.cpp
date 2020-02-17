#include "dbbase.h"

void PODBC::ConnectDataSource() {

	// 32-bit, 64-bit ¡÷¿«

	retcode = SQLConnect(hdbc, (SQLCHAR*) db_name, SQL_NTS, (SQLCHAR*)id, SQL_NTS, (SQLCHAR*)pw, SQL_NTS);
}