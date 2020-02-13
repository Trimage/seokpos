#include "dbbase.h"
#include "base.h"

void RECEIPT::order(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[500]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ
	string menu; //��ǰ��ȣ�� �ƴ� "����" || "���" �Է½� �׿� ���� ó���ϱ�
	int menu2; //�Ѱ����ݾ� ��� �� ���� ���� ����� 1 ��Ҵ� 2

	int total_pay = 0; //�� ���� �ݾ� ��¿�

	cout << "POS��ȣ�� �Է��ϼ��� : ";
	cin >> posnum;

	vector<RECEIPT> order_list;
	PRODUCT product1;

	while (1) {
		cout << "\n\n================���� ��ٱ��� ��� ���================\n";
		cout << "��ǰ��\t\t�ܰ�\t\t����\t�ݾ�\n";
		for (int i = 0;i < order_list.size();i++) {
			cout << order_list[i].product_name;
			printf("\t%d\t\t%d\t%d\n", order_list[i].unit_price, order_list[i].amount, order_list[i].payprice);
		}
		cout << "=======================================================\n";

		product1.allview(podbc);
		cout << "\n\n�Ǹ��� ��ǰ��ȣ�� �Է����ּ��� (�������� �� \"����\", �Ǹ���� �� \"���\" : ";
		cin >> menu;
		if (menu == "���") return;
		else if (menu == "����") break;
		else product_num = stoi(menu);

		str = "SELECT * FROM ��ǰ���� WHERE ��ǰ��ȣ=";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "��ȸ�� �����Ͽ����ϴ�.";

		if (podbc.db_product_viewResult() == 0) {
			cout << "��ϵ��� ���� ��ǰ�Դϴ�.";
			continue;
		}


		str = "SELECT ��ǰ�� FROM ��ǰ���� WHERE ��ǰ��ȣ = ";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "��ȸ�� �����Ͽ����ϴ�.";

		product_name = podbc.db_receipt_order_productname();



		str = "SELECT �ܰ� FROM ��ǰ���� WHERE ��ǰ��ȣ = ";
		str += to_string(product_num);
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << "��ȸ�� �����Ͽ����ϴ�.";

		unit_price = podbc.db_receipt_order_unitprice();

		cout << "��ǰ�� ������ �Է����ּ��� : ";
		cin >> amount;

		payprice = unit_price * amount;

		order_list.push_back(*this);

		total_pay += payprice;
	}

	while (1) {
		cout << "�� ���� �Ͻ� �ݾ��� " << total_pay << "�� �Դϴ�.\n";
		cout << "������ ����Ͻʴϱ�? (����:1, ���2) : ";
		cin >> menu2;

		if (menu2 == 1) break;
		else if (menu2 == 2) {
			cout << "������ ��ҵ˴ϴ�. \n";
			return;
		}
		else cout << "�ùٸ� ���� �Է����ּ���.\n";
	}
	
	struct tm* datetime;

	time_t t;

	t = time(NULL);
	datetime = localtime(&t);
	/*
	printf("%d/%02d/%02d %02d:%02d:%02d", datetime->tm_year + 1900,
		datetime->tm_mon + 1,
		datetime->tm_mday,
		datetime->tm_hour,
		datetime->tm_min,
		datetime->tm_sec
	);
	*/
	
	string strdate=to_string(datetime->tm_year + 1900);
	
	if (datetime->tm_mon < 10) strdate += "0";
	strdate += to_string(datetime->tm_mon + 1);
	
	if (datetime->tm_mday < 10) strdate += "0";
	strdate+= to_string(datetime->tm_mday);

	paydate = stoi(strdate);

	str = "SELECT MAX(��������ȣ)+1 FROM ���������� WHERE ������= ";
	str += to_string(paydate) + "AND POS��ȣ = " + to_string(posnum) + ";";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
		cout << "��ȸ�� �����Ͽ����ϴ�.";
	receiptnum = podbc.db_receipt_order_receiptnum();

	paytime= to_string(datetime->tm_hour) + ":" + to_string(datetime->tm_min) + ":" + to_string(datetime->tm_sec);

	PROFIT profit;
	int cnt = 1;
	while (total_pay) {
		total_pay = profit.insert(total_pay, cnt, *this, podbc);
	}
	

	for (int i = 0;i < order_list.size();i++) {
		str = "INSERT INTO ����������(������,POS��ȣ,��������ȣ,�����ð�,����,��ǰ��ȣ,��ǰ��,�ܰ�,����,�ݾ�) VALUES (";
		str += to_string(paydate) + ", " + to_string(order_list[i].posnum) + ", " + to_string(receiptnum) + ", '";
		str += paytime + "', ";
		str += to_string(i + 1) + ", " + to_string(order_list[i].product_num) + ", '" + order_list[i].product_name + "', ";
		str += to_string(order_list[i].unit_price) + ", " + to_string(order_list[i].amount) + ", " + to_string(order_list[i].payprice) + ");";
		strcpy(cstr, str.c_str());

		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << order_list[i].product_num << "�� ������ �����Ͽ����ϴ�.";


		str = "UPDATE ��ǰ���� SET ���=(SELECT ��� FROM ��ǰ���� WHERE ��ǰ��ȣ=";
		str += to_string(order_list[i].product_num) + ") - " + to_string(order_list[i].amount) + " WHERE ��ǰ��ȣ = " + to_string(order_list[i].product_num) + ";";
		strcpy(cstr, str.c_str());
		podbc.AllocateHandles();
		podbc.ConnectDataSource();

		if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr))
			cout << order_list[i].product_num << "��� ������Ʈ�� �����Ͽ����ϴ�.";
	}

	cout << "\n\n ������ �Ϸ�Ǿ����ϴ�.";
}