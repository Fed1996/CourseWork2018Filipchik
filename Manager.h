#pragma once
#include "Journal.h"

#define MAX 5 // ���-�� ��������
#define FILE_SAVE "out.txt" // ���� ��� ����������

class Manager
{
	Journal mas[MAX]; // ���� �������
	bool mas2[MAX]; // �� �� ��� �� ���������

public:
	Manager();
	~Manager();

	void Menu();
	void wait();
	void MenuAdd();
};

