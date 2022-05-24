#pragma once
#include "Functions.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
namespace MyDLL {
	public ref class Csh_Func {
		Functions* obj;
	public:
		Csh_Func() {
			obj = new Functions();
		}
		String^ setExpression(String^ s) {
			std::string res = msclr::interop::marshal_as<std::string>(s);
			if (obj->CheckBracket(res) != true)
				throw - 1;
			Queue<pair<string, int>> q = obj->Lexical_view(res);
			obj->Match_table(q);
			res = obj->Reverse_Polish_notation(q);
			String^ Res = gcnew String(res.c_str());
			return Res;
		}
		void Match_Val(String^ Key, String^ Val) {
			std::string key = msclr::interop::marshal_as<std::string>(Key);
			std::string val = msclr::interop::marshal_as<std::string>(Val);
			obj->SetVal(key, val);
		}

	};
}