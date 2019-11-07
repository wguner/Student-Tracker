#include "Stack.h"

template <class T>
Stack<T>::Stack(int newSize) {
	mSize = newSize;
	mMaxSize = 180;
	mTop = new T[180];
}


template <class T>
Stack<T>::~Stack() { //this weird code took me awhile understand
	delete[] mTop;
}

template <class T>
bool Stack<T>::isEmpty() {
		return mSize == 0;
}

template <class T>
bool Stack<T>::push(T &pNew) {
	if (mSize < mMaxSize) {
		mSize++;
		mTop++;
		*mTop = pNew;
	}
	return false;
}

template <class T>
bool Stack<T>::pop(T &pNew) {
	if (!isEmpty()) {
		pNew = *mTop;
		mTop--;
		mSize--;
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::peek(T &item) {
	if (isEmpty()) {
		return false;
	}
	item = mTop[mSize - 1];
	return true;
}

