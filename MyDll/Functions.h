#pragma once
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Table.h"
#include <string>
using namespace std;
class Functions
{
	Table t;
public:
	bool CheckBracket(string S) {
		int size = S.size();
		int check = 1;
		Stack<int> ST(size);
		for (int i = 0; i < size; i++) {
			if (S[i] == '(') {
				ST.push(i);
			}
			if (S[i] == ')') {
				if (ST.IsEmpty()) {
					//cout << ") in" << i + 1 << " symbol isn't paired (" << endl;
					check = 0;
				}
				else ST.pop();
			}

		}

		while (!ST.IsEmpty()) {
			//cout << "( in " << ST.pop() + 1 << "symbol isn't paired" << endl;
			check = 0;
		}
		if ((ST.IsEmpty()) && (check == 1)) {
			//cout << "No errors" << endl;
			return true;
		}
		else { return false; }
	}
	Queue<pair<string, int>> Lexical_view(string S) {
		Queue<pair<string, int>> q(100);
		string str = S;
		str += " ";
		string t;
		string op = "()+-*/";
		int state = 0;
		int size = str.size();
		for (int i = 0; i < size; i++) {
			int IsOp = op.find(str[i]);
			if (state == 0)
			{
				if (IsOp >= 0)
				{
					if (IsOp == 1)
						q.push({ string(1, str[i]), 4 });
					if (IsOp == 0)
						q.push({ string(1, str[i]), 1 });
					if ((IsOp == 2) || (IsOp == 3))
						q.push({ string(1, str[i]), 2 });
					if ((IsOp == 4) || (IsOp == 5))
						q.push({ string(1, str[i]), 3 });
				}
				else {
					if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.') || ((str[i] >= 'a') && (str[i] <= 'z'))) {
						t = str[i];
						state = 1;
					}
				}
			}


			else {
				if (state == 1) {
					if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.') || ((str[i] >= 'a') && (str[i] <= 'z'))) {
						t += str[i];
					}
					else
						if (IsOp >= 0)
						{
							q.push({ t,0 });
							if (IsOp == 1)
								q.push({ string(1, str[i]), 4 });
							if (IsOp == 0)
								q.push({ string(1, str[i]), 1 });
							if ((IsOp == 2) || (IsOp == 3))
								q.push({ string(1, str[i]), 2 });
							if ((IsOp == 4) || (IsOp == 5))
								q.push({ string(1, str[i]), 3 });
							state = 0;
						}
						else {
							q.push({ t,0 });
							state = 0;
						}


				}
			}
		}
		return q;
	}
	void print_Lex_view(Queue<pair<string, int>> q) {
		while (!q.IsEmpty()) {
			pair<string, int> val = q.pop();
			cout << val.first << "[" << val.second << "]" << " ";
		}
		cout << endl;
	}
	void addParameter(string p, string val) {
		t.Set(p, val);
	}
	void Match_table(Queue<pair<string, int>> q) {
		while (!q.IsEmpty()) {
			pair<string, int> val = q.pop();
			if ((val.first[0] >= 'a') && (val.first[0] <= 'z')) {
				string c = val.first;
				t.Set(c, "0");
			}
			cout << endl;
		}
	}
	string Reverse_Polish_notation(Queue<pair<string, int>> q) {
		string res;
		Stack < pair < string, int>> ST(100);
		pair<string, int> op, val;
		while (!q.IsEmpty()) {
			val = q.pop();
			if (val.second == 0) {
				res += val.first;
				res += " ";
			}
			else {
				if (val.first == "(") {
					ST.push(val);
				}
				if (val.first == ")") {
					while (true) {
						op = ST.pop();
						if (op.first == "(") break;
						res += op.first;
						res += " ";

					}
				}
				if ((val.first == "*") || (val.first == "/") || (val.first == "+") || (val.first == "-")) {
					while (!ST.IsEmpty()) {
						op = ST.pop();
						if (val.second <= op.second) {
							res += op.first;
							res += " ";
						}
						else {
							ST.push(op);
							break;
						}
					}
					ST.push(val);
				}

			}

		}
		while (!ST.IsEmpty()) {
			pair<string, int> val3 = ST.pop();
			res += val3.first;
			res += " ";
		}
		return res;
	}
	string RPN_translate(string rpn) {
		string res;
		for (int i = 0; i < rpn.size(); i++) {
			if ((rpn[i] >= 'a') && (rpn[i] <= 'z')) {
				res += t.GetVal(to_string(rpn[i]));
				continue;
			}
			res += rpn[i];

		}
	}
	double Result(Queue<pair<string, int>> qp) {
		double res = 0.0, operand1 = 0.0, operand2 = 0.0;
		Stack<double> ST;
		pair<string, int> val;
		while (!qp.IsEmpty()) {
			val = qp.pop();
			if (val.second == 0) {
				double value = stod(val.first);
				ST.push(value);
			}
			else {
				if (val.first == "*") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand1 * operand2;
					ST.push(res);
				}
				if (val.first == "/") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand2 / operand1;
					ST.push(res);
				}
				if (val.first == "+") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand1 + operand2;
					ST.push(res);
				}
				if (val.first == "-") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand2 - operand1;
					ST.push(res);
				}
			}


		}
		res = ST.pop();
		return res;
	}
	string Double_To_String(double d) {
		string s = to_string(d);
		return s;
	}
	string Char_To_String(char c) {
		string s = to_string(c);
		return s;
	}
	void SetVal(string key, string val) {
		t.Set(key, val);
	}
};

