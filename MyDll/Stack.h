#pragma once
template <class T>
class Stack
{
	T* mem;
	int MaxSize;
	int ind;
public:
	Stack(int _MaxSize = 10);
	~Stack();
	bool IsEmpty();
	bool IsFull();
	void push(T val);
	T pop();
};
template <class T>
Stack<T>::Stack(int _MaxSize) :MaxSize(_MaxSize) {
	mem = new T[MaxSize];
	ind = -1;
}
template <class T>
Stack<T>::~Stack() {
	delete[] mem;
}
template <class T>
bool Stack<T>::IsEmpty() {
	return ind < 0;
}
template <class T>
bool Stack<T>::IsFull() {
	return ind >= MaxSize - 1;
}
template <class T>
void Stack<T>::push(T val) {
	if (IsFull()) throw - 1;
	ind = ind + 1;
	mem[ind] = val;
}
template <class T>
T Stack<T>::pop() {
	if (IsEmpty()) throw - 2;
	T val = mem[ind];
	ind--;
	return val;
}