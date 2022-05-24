#pragma once
template <class T>
class Queue
{
	T* mem;
	int N;
	int start;
	int end;
	int next(int ind) {
		return(ind + 1) % N;
	}
public:
	Queue(int _N = 11);
	bool IsEmpty();
	bool IsFull();
	void push(T val);
	T pop();

};
template <class T>
Queue<T>::Queue(int _N) :N(_N + 1) {
	mem = new T[N];
	end = N - 1;
	start = next(end);
}

template <class T>
bool Queue<T>::IsEmpty() {
	return start == next(end);
}
template <class T>
bool Queue<T>::IsFull() {
	return start == next(next(end));
}
template <class T>
void Queue<T>::push(T val) {
	if (IsFull()) {
		throw - 1;
	}
	end = next(end);
	mem[end] = val;
}
template <class T>
T Queue<T>::pop() {
	if (IsEmpty())throw - 2;
	T val = mem[start];
	start = next(start);
	return val;
}