/*=============================================================================== 
	底層需依賴第三方 : JSON for Modern C++ / single_include https://github.com/nlohmann/json

	
 -  jsonfunc.read("xxx.json")  可以回傳 json 物件
 -  jsonfunc.dict<T,S>(j) 可以回傳 key = T , value = S 的 unordered_map
 -  jsonfunc.list<T>(j)  value = T 的 list
=================================================================================*/



#ifndef __JSONFUNC_HPP__
#define __JSONFUNC_HPP__

namespace cxxuseful{
	using json = nlohmann::json;
	using namespace std;
	class JsonFunc{
		public:
			json read(string jsonfile){
				ifstream i(jsonfile);
				json j;
				i >> j;
				return j;
			}//endread
			template<typename T,typename S> unordered_map<T,S> dict(json &j){
				unordered_map<T,S> d = j;
				return d;
			}
			template<typename T> vector<T> list(json &j){
				vector<T> v = j;
				return j;
			}



	} jsonfc;


};





#endif






