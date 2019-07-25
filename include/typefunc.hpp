/*
	其他類別請使用 typefunc 包住
	需要繼承 Base 類別
	
	繼承後物件 
		private:
			共同演算法介面
		public:
			不同型別執行介面



*/
#ifndef __TYPEFUNC_HPP__
#define __TYPEFUNC_HPP__

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
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
// =============================================================================
namespace typefunc{	
	template<typename T> T type(BoostAny val){
		return boost::any_cast<T>(val);
	}//endif
};//end_namespace
//==============================================================================
// typefunc project files 
#include "printfunc.hpp"
#include "todictfunc.hpp"


//==============================================================================

#endif 