#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class PRODUCT //��ǰ����
{
	string name;	//��ǰ��
	int product_num; //��ǰ��ȣ
	int unit_price;	// �ܰ�
	int stock;	//���

public :
	void addition(PODBC &podbc); // ��ǰ���
	void del(PODBC &podbc);		// ��ǰ����
	void adjust(PODBC &podbc);	// ��ǰ����
	void find(PODBC &podbc);	// ��ǰã��
	void allview(PODBC &podbc);	// ��� ��ǰ ����
};

class RECEIPT {		//����������
	int paydate;		// ������
	int posnum;			// POS�� ��ȣ
	int receiptnum;		// ��������ȣ
	string paytime;		// �����ð�
	int no;				// ����
	int product_num;	// ��ǰ��ȣ
	string product_name; // ��ǰ��
	int unit_price;		//��ǰ�ܰ�
	int amount;			// ��ǰ����
	int payprice;		// �ݾ�

public :
	void order_receipt(PODBC &podbc,RECEIPT &receipt);	//�Ǹ� �� ���������
	void receiptview(PODBC &podbc);	//��������ȸ
	void order(PODBC &podbc);		// ��ǰ�Ǹ�
	int info_paydate_output();		//������ ���
	int info_posnum_output();		//POS�� ��ȣ ���
	int info_receiptnum_output();		//��������ȣ ���
};

class PROFIT {		//��������
	int paydate;		// ������
	int posnum;			// POS�� ��ȣ
	int receiptnum;		// ��������ȣ
	string pay_type;	// �������
	int paymoney;			//�����ݾ�

public :
	int insert(int total, int cnt, RECEIPT &receipt, PODBC &podbc);	// �����������
	void current_view(PODBC &podbc); // ���ϸ�����ȸ
	void day_view(PODBC &podbc);	// �Ϻ�������ȸ
	void month_view(PODBC &podbc);	// ����������ȸ
	void year_view(PODBC &podbc);	// �⺰������ȸ
};

#endif