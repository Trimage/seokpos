#include "dbbase.h"


void PODBC::ExecuteStatement() {

	retcode = SQLExecute(hstmt);


	if (retcode == SQL_SUCCESS) {

		printf("Query Execute Success\n");

	}

	else {

		SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, ++rec, state, &native, message, sizeof(message), &length);

		printf("%s : %ld : %ld : %s\n", state, rec, native, message);

	}

}
