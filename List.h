#pragma once
#include "StudentNode.h" 
#include <iostream>
#include <fstream>

class List
{
public:
	~List();
	void load_list(std::ifstream& file);
	void store_list(std::ofstream& file);
	void insertAtFront(StudentNode* pNew);
	void delete_list();
	void set_absences();
	void allAbsences(int min);
	void mostRecentAbsence();
private:
	void delete_list(StudentNode* const pMem);
	StudentNode* mHead;
};