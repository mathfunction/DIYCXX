/*
	其他類別請使用 typefunc 包住
	需要繼承 Base 類別


*/
#ifndef __TYPEFUNC_HPP__
#define __TYPEFUNC_HPP__

#include <iostream>
// STL library
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <queue>
#include <stack>
#include <utility>
#include "boost_includes.hpp"
#include "cxxcolor.hpp"

using namespace std;
using namespace cxxcolor;

namespace typefunc{

	template<typename T> T to_type(Any val){
		return boost::any_cast<T>(val);
	}//endif
	//==================================================================================
	class Base{
		public:
			virtual BoostAny operator[](BoostInt v){return v;}
			virtual BoostAny operator[](BoostFloat v){return v;}
			virtual BoostAny operator[](double v){return v;}
			virtual BoostAny operator[](int v){return v;}
			virtual BoostAny operator[](string v){return v;}
			virtual BoostAny operator[](basic_string<int> &v){return v;}
			virtual BoostAny operator[](basic_string<double> &v){return v;}
			virtual BoostAny operator[](unordered_map<string,string> &v){return v;}
			virtual BoostAny operator[](unordered_map<string,int> &v){return v;}
			virtual BoostAny operator[](unordered_map<string,double> &v){return v;}
			virtual BoostAny operator[]();
	};
	//=================================================================================
	/*
	class PrintFunc{
		








	} print;
	*/










};//end_namespace 



#endif 