#pragma once
#include "edition.h"

#define Max 300 // ������������ ���-�� ��������

class Journal
{
	edition mas[Max]; // ������� �������
	int max;
public:
	string name; // �������� �������

	Journal();
	~Journal();

	void refresh();
	void save(ofstream &file);
};

