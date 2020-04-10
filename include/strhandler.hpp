

#ifndef __STRHANDLER_HPP__
#define __STRHANDLER_HPP__

namespace cxxuseful{
	class StrHandler{
		public:
			// c == char , const char* => ccp
			string c2ccp(char c){
				return string(1,c).c_str();
			}
			string c2s(char c){
				return string(1,c);
			} 

	} shlr;
};
#endif