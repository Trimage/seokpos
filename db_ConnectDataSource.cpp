#include "dbbase.h"

void PODBC::ConnectDataSource() {

	// 32-bit, 64-bit ¡÷¿«

	retcode = SQLConnect(hdbc, (SQLCHAR*)"seokposdb", SQL_NTS, (SQLCHAR*)"seok", SQL_NTS, (SQLCHAR*)"1234", SQL_NTS);
}