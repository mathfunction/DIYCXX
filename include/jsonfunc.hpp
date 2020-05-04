/*=============================================================================== 
	底層需依賴第三方 : JSON for Modern C++ / single_include https://github.com/nlohmann/json

	
 -  jsonfunc.read("xxx.json")  可以回傳 json 物件
 -  jsonfunc.dict<T,S>(j) 可以回傳 key = T , value = S 的 std::unordered_map
 -  jsonfunc.list<T>(j)  value = T 的 list
=================================================================================*/



#ifndef __JSONFUNC_HPP__
#define __JSONFUNC_HPP__

namespace cxxuseful{
	class JsonFunc{
		public:
			nlohmann::json read(std::string jsonfile,bool _boolLog=true){
				if(_boolLog == true){
					printBlueGreen("[Read] "+jsonfile,true);
				}
				std::ifstream i(jsonfile);
				nlohmann::json j;
				i >> j;
				return j;
			}//endread
			template<typename T,typename S> std::unordered_map<T,S> dict(nlohmann::json &j){
				std::unordered_map<T,S> d = j;
				return d;
			}
			template<typename T> std::vector<T> list(nlohmann::json &j){
				std::vector<T> v = j;
				return j;
			}

			



	} jsonfc;


};





#endif





