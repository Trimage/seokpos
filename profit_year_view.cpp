#include "base.h"
#define TAB 11

void PROFIT::year_view(PODBC &podbc) {
	string str; //SQL��ɹ��� ������ ����
	char cstr[200]; // //SQL��ɹ��� �����ϱ� ���� ĳ��Ʈ

	int total_price, cash, card;		// �� �ݾ�, ���� �ݾ�, ī�� �ݾ�
	float total_percent, cash_percent, card_percent;	// �� ������, ���� ������, ī�� ������
	int tab_size;	// ��¹� ������ ���� ������ ����

	string start_date, end_date;
	cout << "������ȸ�� ����ϴ� �⵵�� �Է����ּ��� ex)YYYY : ";
	cin >> start_date;

	if (start_date.size() != 4) {
		cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���\n\n";
		year_view(podbc);
		return;
	}

	end_date = start_date + "1231";	//202001231
	start_date += "0101";				//20200101

	paydate = stoi(start_date);

	str = "SELECT SUM(�����ݾ�) AS '���� �� �����' FROM �������� WHERE �����ݾ�>=0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	cout << start_date.substr(0, 4) << "�⵵ ���� ������Ȳ �Դϴ�.\n";
	total_price = podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) AS '���� �����' FROM �������� WHERE �������='����' AND �����ݾ� >=0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	cash = podbc.db_profit_viewResult();


	str = "SELECT SUM(�����ݾ�) AS 'ī�� �����' FROM �������� WHERE �������='ī��' AND �����ݾ� >=0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	card = podbc.db_profit_viewResult();


	cout << setw(31) << "\n����" << "�ݾ�\n";
	cout << "========================================================================================================\n";

	if (total_price != 0) total_percent = 100;
	else total_percent = 0;
	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;
	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;

	if (card != 0) card_percent = (float)card / total_price * 100;
	else card_percent = 0;

	string chart_bar = "��";
	int cnt = 2;

	for (int i = 3;i <= total_percent / 2; i++) {
		chart_bar += "��";
		cnt++;
	}

	cout << setw(30) << "�� �����" << chart_bar;
	cout << "  " << total_price << "�� ";
	printf("(%.2f", total_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(total_price).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = total_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";

	chart_bar = "��";
	cnt = 2;
	for (int i = 3;i <= cash_percent / 2; i++) {
		chart_bar += "��";
		cnt++;
	}

	cout << setw(30) << "���� ������" << chart_bar;
	cout << "  " << cash << "�� ";
	printf("(%.2f", cash_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";



	chart_bar = "��";
	cnt = 2;
	for (int i = 3;i <= card_percent / 2; i++) {
		chart_bar += "��";
		cnt++;
	}

	cout << setw(30) << "ī�� ������" << chart_bar;
	cout << "  " << card << "�� ";
	printf("(%.2f", card_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(card).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = card_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";		// 

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";



	str = "SELECT SUM(�����ݾ�) AS '�ش��� �� ȯ�Ҿ�' FROM �������� WHERE �����ݾ�<0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	total_price = podbc.db_profit_viewResult() * -1;



	str = "SELECT SUM(�����ݾ�) AS '�ش� �� �� ���� ȯ�Ҿ�' FROM �������� WHERE �����ݾ�<0 AND �������='����' AND �����ݾ� <0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	cash = podbc.db_profit_viewResult() * -1;


	str = "SELECT SUM(�����ݾ�) AS '�ش� �� �� ī�� ȯ�Ҿ�' FROM �������� WHERE �����ݾ�<0 AND �������='ī��' AND �����ݾ� <0 AND ������>=";
	str += start_date + " AND ������ <=" + end_date + " ;";
	strcpy(cstr, str.c_str());

	podbc.AllocateHandles();
	podbc.ConnectDataSource();

	if (!podbc.ExecuteStatementDirect((SQLCHAR*)cstr)) {
		cout << "������ �߻��Ͽ����ϴ�.\n";
		return;
	}

	card = podbc.db_profit_viewResult() * -1;

	if (total_price != 0) total_percent = 100;
	else total_percent = 0;

	if (cash != 0)	cash_percent = (float)cash / total_price * 100;
	else cash_percent = 0;

	if (card != 0) card_percent = (float)card / total_price * 100;
	else card_percent = 0;

	chart_bar = "��";
	cnt = 2;
	if (total_price != 0) {
		for (int i = 3;i <= total_percent / 2; i++) {
			chart_bar += "��";
			cnt++;
		}
	}

	cout << setw(30) << "�� ȯ�Ҿ�" << chart_bar;
	cout << "  " << total_price << "�� ";
	printf("(%.2f", total_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";


	chart_bar = "��";
	cnt = 2;
	for (int i = 3;i <= cash_percent / 2; i++) {
		chart_bar += "��";
		cnt++;
	}

	cout << setw(30) << "���� ȯ�Ҿ�" << chart_bar;
	cout << "  " << cash << "�� ";
	printf("(%.2f", cash_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(cash).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = cash_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";		// 

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";


	chart_bar = "��";
	cnt = 2;
	for (int i = 3;i <= card_percent / 2; i++) {
		chart_bar += "��";
		cnt++;
	}

	cout << setw(30) << "ī�� ��Ҿ�" << chart_bar;
	cout << "  " << card << "�� ";
	printf("(%.2f", card_percent);
	cout << "%)";

	tab_size = cnt + 1 + to_string(card).size() + 3;		// tab_size = ������ + " 12��".size() + " (".size()
	tab_size = card_percent < 10 ? tab_size += 6 : tab_size += 7;	// tab_size = percent <10�̸� +6, �ƴϸ� +7

	if (tab_size > 49) cout << "\n";
	else if (tab_size >= 39 && tab_size <= 48) cout << setw(48 - tab_size) << "" << "��\n";
	else if (tab_size >= 29 && tab_size <= 38) cout << setw(38 - tab_size) << "" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 19 && tab_size <= 28) cout << setw(28 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else if (tab_size >= 8 && tab_size <= 18) cout << setw(18 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	else cout << setw(8 - tab_size) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";		// 

	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";


	cout << setw(29) << "" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << setw(TAB) << "��" << "��\n";
	cout << setw(29) << "" << setw(TAB) << "�� 0%" << setw(TAB) << "�� 20%" << setw(TAB) << "�� 40%" << setw(TAB) << "�� 60%" << setw(TAB) << "�� 80%" << "�� 100%\n";
	cout << "--------------------------------------------------------------------------------------------------------\n";

}