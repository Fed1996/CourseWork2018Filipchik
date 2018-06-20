#pragma once
#include "Journal.h"

#define MAX 5 // кол-во журналов
#define FILE_SAVE "out.txt" // файл для сохранения

class Manager
{
	Journal mas[MAX]; // сами журналы
	bool mas2[MAX]; // то на что мы подписаны

public:
	Manager();
	~Manager();

	void Menu();
	void wait();
	void MenuAdd();
};

