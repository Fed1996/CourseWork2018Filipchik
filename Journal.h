#pragma once
#include "edition.h"

#define Max 300 // максимальное кол-во выпусков

class Journal
{
	edition mas[Max]; // выпуски журнала
	int max;
public:
	string name; // название журнала

	Journal();
	~Journal();

	void refresh();
	void save(ofstream &file);
};

