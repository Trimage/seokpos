#include "dbbase.h"

void PODBC::DisconnectDataSource() {

	if (hstmt) {

		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

		hstmt = NULL;

	}

	SQLDisconnect(hdbc);

	if (hdbc) {

		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

		hdbc = NULL;

	}

	if (henv) {

		SQLFreeHandle(SQL_HANDLE_ENV, henv);

		henv = NULL;

	}

}
