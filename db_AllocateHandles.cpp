#include "dbbase.h"

void PODBC::AllocateHandles() {

	// 환경 핸들러 할당

	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);


	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

		// ODBC 드라이버 버전 명시

		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

			// 연결 핸들러 할당

			retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);


			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

				printf("Allocate Success\n");

			}

			else {

				SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, ++rec, state, &native, message, sizeof(message), &length);

				printf("%s : %ld : %ld : %s\n", state, rec, native, message);

			}

		}

		else {

			SQLGetDiagRec(SQL_HANDLE_ENV, henv, ++rec, state, &native, message, sizeof(message), &length);

			printf("%s : %ld : %ld : %s\n", state, rec, native, message);

		}

	}

	else {

		SQLGetDiagRec(SQL_HANDLE_ENV, henv, rec, state, &native, message, sizeof(message), &length);

		printf("%s : %ld : %ld : %s\n", state, rec, native, message);

	}

}