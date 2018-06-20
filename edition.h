#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

class edition
{
public:
	edition();
	~edition();

	string name;
	string	issue_topic;
	string	date;
	string	number;
	string	summary;

	void Read(string NameFile);
	void clear();
	void Save(ofstream &file);

	edition operator=(edition &tmp);
	bool operator==(edition &tmp);
};

