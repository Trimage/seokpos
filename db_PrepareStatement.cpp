#include "dbbase.h"

void PODBC::PrepareStatement(SQLCHAR* sql) {

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		printf("Connect Success\n");

	}

	else {

		SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, ++rec, state, &native, message, sizeof(message), &length);

		printf("%s : %ld : %ld : %s\n", state, rec, native, message);

	}


	retcode = SQLPrepare(hstmt, sql, SQL_NTS);


	if (retcode == SQL_SUCCESS) {

		printf("\nQuery Prepare Success\n");

	}

	else {

		SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, ++rec, state, &native, message, sizeof(message), &length);

		printf("\n%s : %ld : %ld : %s\n", state, rec, native, message);

	}

}
