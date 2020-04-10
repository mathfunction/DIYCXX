/*=============================================================================== 
	底層需依賴第三方 : JSON for Modern C++ / single_include https://github.com/nlohmann/json

	
 -  jsonfunc.read("xxx.json")  可以回傳 json 物件
 -  jsonfunc.todict<T,S>(j) 可以回傳 key = T , value = S 的 unordered_map
=================================================================================*/



#ifndef __JSONFUNC_HPP__
#define __JSONFUNC_HPP__

namespace cxxuseful{
	
	
	class JsonFunc{
		public:
			json read(string jsonfile){
				ifstream i(jsonfile);
				json j;
				i >> j;
				return j;
			}//endread
			template<typename T,typename S> unordered_map<T,S> todict(json &j){
				unordered_map<T,S> d = j;
				return d;
			} 

	} jsonfunc;


};





#endif






