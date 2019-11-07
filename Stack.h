#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack {
public:
	Stack(int newSize = 0);
	~Stack();
	bool isEmpty();
	bool push(T &pNew);
	bool pop(T &poppedItem);
	bool peek(T &item);
private:
	int mSize;
	int mMaxSize;
	T *mTop;
};
