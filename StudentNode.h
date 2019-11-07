#pragma once

#include "Stack.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::istream;


class StudentNode {
	friend class List;
public:
	StudentNode(string line);
	int getNumAbsences();
	void add_abs();
	string get_student();
	string get_abs();
	string get_all_abs();
private:
	int recordnum;
	int id;
	string name;
	string mail;
	string units;
	string program;
	string level;

	StudentNode * mNext;
	Stack<string>* absences;
	int absencenum;
};

ostream & operator<<(std::ostream& lhs, StudentNode& rhs);