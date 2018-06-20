#include "stdafx.h"
#include "edition.h"


edition::edition()
{
	clear();
}

edition::~edition()
{
}

bool edition::operator==(edition &tmp) {
	if (name != tmp.name)
		return false;
	if (issue_topic != tmp.issue_topic)
		return false;
	if (date != tmp.date)
		return false;
	if (number != tmp.number)
		return false;
	if (summary != tmp.summary)
		return false;

	return true;
}

void edition::Read(string NameFile) {
	ifstream file(NameFile + ".txt");
	getline(file, name);
	getline(file, issue_topic);
	getline(file, date);
	getline(file, number);
	getline(file, summary);
}

void edition::Save(ofstream &file) {
	file << name << endl
		<< issue_topic << endl
		<< date << endl
		<< number << endl
		<< summary << endl;
}

edition edition::operator=(edition &tmp) {
	name = tmp.name;
	issue_topic = tmp.issue_topic;
	date = tmp.date;
	number = tmp.number;
	summary = tmp.summary;

	return *this;
}

void edition::clear() {
	name = " ";
	issue_topic = " ";
	date = " ";
	number = " ";
	summary = " ";
}

