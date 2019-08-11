/*
	這是主要引入函式庫

*/
#ifndef __CXXUSEFUL_HPP__
#define __CXXUSEFUL_HPP__

// STL_Library
#include <iostream>
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
#include "boost_includes.hpp"
using namespace std;
// =============================================================================
namespace cxxuseful{
	template<typename T> T type(const BoostAny &val){
		return boost::any_cast<T>(val);
	}//endif
};//end_namespace
//==============================================================================
// typefunc project files 
#include "cmdcolor.hpp"
#include "printfunc.hpp"
#include "todictfunc.hpp"
#include "makestrfunc.hpp"
#include "randomfunc.hpp"
#include "timer.hpp"

//==============================================================================

#endif 