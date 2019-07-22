/*---------------------------------------------
	更新日期 : 2019.7



-----------------------------------------------*/



#ifndef __BOOST_INCLUDES_HPP__
#define __BOOST_INCLUDES_HPP__

//------------------------------------------------------------------
// multiprecision : handle BigNumbers , note need iomanip::setprecision to cout output 
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

typedef boost::multiprecision::cpp_int BoostInt;
typedef boost::multiprecision::cpp_dec_float_100 BoostFloat;


#include <boost/algorithm/string.hpp>
/* ----------- string algorithms ---------
	切割 tokens 
	boost::split(vector<string> tokens,string input,boost::is_any_of(string) MARK)
	boost::join(vector<string> tokens,string MARK)
	boost::trim(string)   , return void !!
	boost::trim_left(string)  // python strip()
	boost::trim_right(string) // python strip()
-------------------------------------------*/ 

#include <boost/format.hpp>
/*----------------------------------------
	字串格式化輸出 :
	boost.format("%1%,%2%") % [變數1] % [變數2] ;
	.str() 可回傳 string   
------------------------------------------*/
#include <boost/foreach.hpp>
/*---------------------------------------
BOOST_FOREACH(T i ,vector<T> &vec){
	
}  // 取代 (iterator::it=vec.begin();it!=vec.end();++it)

--------------------------------------------*/
#include <boost/range/algorithm.hpp>
/*-------------------------------------
計算字串數目
boost::count(string,ch)
boost::count_if(string,bool(ch))
---------------------------------------*/







#endif