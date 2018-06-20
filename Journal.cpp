#include "stdafx.h"
#include "Journal.h"


Journal::Journal()
{
	max = 0;
	refresh();
}


Journal::~Journal()
{
}

void Journal::refresh() {
	ifstream file(name + ".txt");

	if (!file.is_open())
		return;

	int maxT;
	string temp;
	getline(file, temp);
	if ((maxT = atoi(temp.c_str())) == 0) {
		max = maxT;
		return;
	}

	edition* tmp = new edition[maxT];

	for (int i = 0; i < maxT; ++i) {
		getline(file, temp);
		tmp[i].Read(temp);
	}

	bool flag = true;

	for (int i = 0; i < maxT; ++i) {
		flag = true;
		for (int j = 0; j < max; ++j) {
			if (tmp[i] == mas[j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Journal: " << name << " edition: " << tmp[i].name << endl;
	} 

	for (int i = 0; i < max; ++i)
		mas[i].clear();

	max = maxT;

	for (int i = 0; i < max; ++i) {
		mas[i] = tmp[i];
	}

	return;
}

void Journal::save(ofstream &file) {
	file << name << endl;

	for (int i = 0; i < max; ++i) {
		mas[i].Save(file);
	}

	return;
}

