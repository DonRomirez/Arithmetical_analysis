#pragma once
struct Pair {
	string key;
	string val;
};
class Table {
	Pair** mem;
	int size;
	int max;
public:
	Table(int _max=10) :max(_max) {
		mem = new Pair * [max];
		size = 0;
	}
	~Table() {
		delete [] mem;
	}
	Pair* Search(string key) {
		Pair *tmp = nullptr;
		for (int i = 0; i < size; i++) {
			if (mem[i]->key == key)
				tmp = mem[i];
		}
		return tmp;
	}
	string GetVal(string key) {
		Pair* p = Search(key);
		if (p == nullptr)
			throw - 1;
		else
			return p->val;
	}
	void Set(string key, string val) {
		Pair* p = Search(key);
		if (p != nullptr)
			p->val = val;
		else {
			p = new Pair;
			p->key = key;
			p->val = val;
		}
		mem[size] = p;
		size++;
	}


};