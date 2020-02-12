#ifndef __BASE_H__
#define __BASE_H__

#include "dbbase.h"
#include <string>
#include <iostream>

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

class RECEIPT {
	int paydate;		// ������
	int posnum;			// POS�� ��ȣ
	int receiptnum;		// ��������ȣ
	string paytime;		// �����ð�
	int no;				// ����
	string pruduct_name; // ��ǰ��
	int unit_price;		//��ǰ�ܰ�
	int amount;			// ��ǰ����
	int payprice;		// �ݾ�

public :
	void receiptview(PODBC &podbc);	//��������ȸ
};

#endif