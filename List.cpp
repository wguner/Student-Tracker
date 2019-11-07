#include "List.h"

void List::load_list(std::ifstream& file) {
	delete_list();
	string str;
	getline(file, str);
	while (!file.eof()) {
		getline(file, str);
		if (str != "") {
			StudentNode *pMem = new StudentNode(str);
			insertAtFront(pMem);
		}
	}
}

void List::store_list(std::ofstream& file) {
	StudentNode* pCur = mHead;
	while (pCur != nullptr) {
		file << *pCur << endl;
		pCur = pCur->mNext;
	}
}

void List::insertAtFront(StudentNode* pNew) {
	StudentNode* pTemp = mHead;
	mHead = pNew;
	mHead->mNext = pTemp;

}


void List::delete_list(StudentNode * const pMem) {//deletefromBack
	if (pMem != nullptr) {
		delete_list(pMem->mNext);
		delete pMem;
	}
}

void List::delete_list() {
	delete_list(mHead);
	mHead = nullptr;
}

List::~List() {
	delete_list();
}

void List::set_absences() {
	StudentNode* pCur = mHead;
	string input = "";
	while (pCur != nullptr) {
		cout << "Student:" << pCur->name << " was in class today? Y/N\n";
		cin >> input;
		if (tolower(input.at(0)) == 'n')
		{
			pCur->add_abs();
		}
		pCur = pCur->mNext;
	}
}

void List::allAbsences(int min) {
	string output = " ";
	StudentNode* pCur = mHead;
	while (pCur != nullptr) {
		if (pCur->absencenum >= min)
			output = pCur->get_student();
		output += pCur->get_all_abs();
		pCur = pCur->mNext;
		cout << output << endl;
	}
}

void List::mostRecentAbsence() {
	string output = " ";
	StudentNode* pCur = mHead;
	while (pCur != nullptr) {
		output = pCur->get_student();
		output += ',' + pCur->get_abs() + '\n';
		cout << output;
		pCur = pCur->mNext;
	}
}

