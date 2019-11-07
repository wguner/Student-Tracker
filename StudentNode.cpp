#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "StudentNode.h"

StudentNode::StudentNode(string line) {
	string str = " ";
	std::stringstream stream(line);
	getline(stream, str, ',');
	recordnum = stoi(str);

	getline(stream, str, ',');
	id = stoi(str);

	getline(stream, name, '"');
	getline(stream, name, '"');
	name = "\"" + name + "\"";
	stream.ignore();

	getline(stream, mail, ',');
	getline(stream, units, ',');
	getline(stream, program, ',');
	getline(stream, level, ',');
	absences = new Stack<string>;
	absencenum = 0;

	while (!stream.eof()) {
		getline(stream, str, ',');
		absences->push(str);
		absencenum++;
	}
}

void StudentNode::add_abs() {
	std::stringstream stream;
	string date;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	stream << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday;
	date = stream.str();
	absences->push(date);
	absencenum++;
}

string StudentNode::get_student() {
	std::stringstream stream;
	stream << (recordnum) << ',' << id << ',' << name << ',' << mail << ',' << units << ',' << program << ',' << level;
	string temp = stream.str();
	return temp;
}

int StudentNode::getNumAbsences() {
	return absencenum;
}

string StudentNode::get_abs() {
	string abs = " ";
	absences->peek(abs);
	return abs;
}

string StudentNode::get_all_abs() {
	string temp;
	std::stringstream stream;
	Stack<string>* stack = new Stack<string>; //i hate this line
	while (!absences->isEmpty()) {
		absences->pop(temp);
		stream << ',' << temp;
		stack->push(temp);
	}
	while (!stack->isEmpty()) {
		stack->pop(temp);
		absences->push(temp);
	}
	string abs = stream.str();
	delete(stack);
	return abs;
}



ostream & operator <<(ostream& lhs, StudentNode& rhs) {
	return lhs << rhs.get_student() << rhs.get_all_abs();
}