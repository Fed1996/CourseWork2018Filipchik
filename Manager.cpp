#include "stdafx.h"
#include "Manager.h"


Manager::Manager()
{
	for (int i = 0; i < MAX; ++i) {
		mas2[i] = false;
	}
	mas[0].name = "NationalGeographic";
	mas[1].name = "People";
	mas[2].name = "BussinesWeek";
	mas[3].name = "PROCport";
	mas[4].name = "Forbes";
}


Manager::~Manager()
{
}

void Manager::Menu() {
	setlocale(LC_ALL, "Russian");
	int i = 0;

	while (1) {
		system("cls");
		cout << "1.Subscribe to magazines\n2.Wait for logs to be released\n0. Exit\n";
		cin >> i;

		switch (i) {
		case 0:
			return;
		case 1:
			MenuAdd();
			break;
		case 2:
			wait();
			break;
		}

		i = 0;
	}

	return;
}

void Manager::MenuAdd() {
	int i = 0;

	while (1) {
		i = 0;
		system("cls");

		cout << "You are subscribed to\n";

		for (int j = 0; j < MAX; ++j)
			if (mas2[j]) cout << mas[j].name << endl;

		cout << endl;

		cout << "1.National Geographic\n2.People\n3.Bussines Week\n4.PROCport\n5.Forbes\n0. Exit\n";
		cin >> i;

		if (i == 0)
			return;
		if (i > 5)
			continue;

		mas2[i - 1] = !mas2[i - 1];
	}

	return;
}

void Manager::wait() {
	ofstream file(FILE_SAVE);
	system("cls");
	while (1) {
		file.open(FILE_SAVE);
		for (int i = 0; i < MAX; ++i) {
			if (mas2[i]) {
				mas[i].refresh();
				mas[i].save(file);
			}
		}

		file.close();

		//Sleep(30000);
		Sleep(500);
	}
}
