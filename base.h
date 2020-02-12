#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>
#include <vector>

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

class ORDER
{
	string receiptnum;	//��������ȣ
	int product_num;	//��ǰ��ȣ
	int turn;	//����
	int amount;	//����
	int price;	//��ǰ�ݾ�

public :
	void sell(PODBC &podbc);	// ��ǰ�Ǹ�
	void refund();	// ��ǰȯ��
};

class RECEIPT {
	string paydate;		// ������
	int receiptnum;	// ��������ȣ
	string pay_or_refund; //��������
	int product_num;	// ��ǰ��ȣ
	int paytime;		// �����ð�
	string payoption;		// �������
	int payprice;		// �Ѱ����ݾ�

public :
	void receiptview(PODBC &podbc);	//��������ȸ
};

#endif