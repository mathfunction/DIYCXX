/*=============================================================================== 
	JSON for Modern C++ / single_include https://github.com/nlohmann/json
	#include "json.hpp"
	using json = nlohmann::json;
===============================================================================*/

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
	};


};


#endif






