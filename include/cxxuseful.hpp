/*
	這是主要引入函式庫  STL + Boost + json ....

*/
#ifndef __CXXUSEFUL_HPP__
#define __CXXUSEFUL_HPP__

// STL_Library
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
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
#include <chrono>
#include <random>
// ===============================================================================
// third_party 第三方好用函式庫
#include "boost_includes.hpp"
// JSON for Modern C++ / single_include https://github.com/nlohmann/json
#include "json.hpp"
// =============================================================================
// 全域函式
namespace cxxuseful{
	template<typename T> T type(const BoostAny &val){
		return boost::any_cast<T>(val);
	}//endif


};//end_namespace

//==============================================================================


// DIY 開發 HPP 

// typefunc project files 
#include "cmdcolor.hpp"
#include "printfunc.hpp"
#include "makedictfunc.hpp"
#include "randomfunc.hpp"
#include "timer.hpp"
#include "jsonfunc.hpp"
#include "strhandler.hpp"
#include "utf8str.hpp"
#include "otherfunc.hpp"

//==============================================================================

#endif 