#include "dbbase.h"

void PODBC::AllocateHandles() {

	// ȯ�� �ڵ鷯 �Ҵ�

	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);


	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

		// ODBC ����̹� ���� ���

		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

			// ���� �ڵ鷯 �Ҵ�

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