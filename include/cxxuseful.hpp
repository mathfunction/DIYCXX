/*
	這是主要引入函式庫  STL + Boost + json ....

*/
#ifndef __CXXUSEFUL_HPP__
#define __CXXUSEFUL_HPP__

// STL_Library
#include <iostream>
#include <array>
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
#include <cmath>
//#include <string_view>
#include <tuple>
#include <queue>
#include <stack>
#include <utility>
#include <chrono>
#include <random>
#include <functional>
#include <initializer_list>
//==============================================================================
// windows 指令集
#if defined _WIN32 || defined _WIN64
	#include<windows.h>
#endif

// ===============================================================================
// third_party 第三方好用函式庫
#include "boost_includes.hpp"
// JSON for Modern C++ / single_include https://github.com/nlohmann/json
#ifndef __NVCC__	
	#include "json.hpp"
#endif
// =============================================================================
// 全域函式
namespace cxxuseful{
	template<typename T> T type(const BoostAny &val){
		return boost::any_cast<T>(val);
	}//endif

};//end_namespace

//==============================================================================


// DIY 開發 HPP 
#include "utf8str.hpp"
#include "cmdcolor.hpp"
#ifndef __NVCC__
	#include "printfunc.hpp"
#endif
#include "makedictfunc.hpp"
#ifndef __NVCC__
	#include "timer.hpp" 
	#include "randomfunc.hpp"
	#include "jsonfunc.hpp"
	#include "dataframe.hpp"
#endif
#include "strhandler.hpp"
#include "otherfunc.hpp"
#include "setfunc.hpp"
#include "filepath.hpp"
#include "checkinfunc.hpp"
#include "cxxtensor.hpp"
#include "simd.hpp"
#include "threads_piplines.hpp"
//#include "socketio.hpp"
//==============================================================================

#endif 