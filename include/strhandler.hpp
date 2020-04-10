/*==============================================

- shlr.c2s 可把 char 轉成 string
- shlr.c2ccp 可把 char 轉成 const char* 




================================================*/

#ifndef __STRHANDLER_HPP__
#define __STRHANDLER_HPP__

#include<cstdlib>

namespace cxxuseful{
	class StrHandler{
		public:
			// c == char , const char* => ccp
			const char* c2ccp(char c){
				return string(1,c).c_str();
			}
			string c2s(char c){
				return string(1,c);
			} 

	} shlr;
};
#endif