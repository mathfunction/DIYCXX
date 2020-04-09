/*==============================================================================
	This is windows print chinese routines 


	chcp 65001 UTF8 , 	most Chinese-Char need 3-Chars 
	chcp 950 BIG5 , 	each Chinese-Char need 2-Chars

	
// 參考網址 :   https://blog.csdn.net/jcjc918/article/details/52200478

===============================================================================*/
#ifndef __CHINESE_HANDLE_HPP__
#define __CHINESE_HANDLE_HPP__

#include <memory>
#include <string>


namespace cxxuseful{

	
	#if defined _WIN32 || defined _WIN64 

	#else
		
		
		void print(const std::wstring& _wstr){
			for(int i=0;i<_wstr.size();i++){
				std::wcout << _wstr[i];
			}//endfor
			std::wcout << "\n";
		}//end_print
		
		std::wstring s2ws(const std::string& _str) {
		  if (_str.empty()) {
		    return L"";
		  }//endif
		  setlocale(LC_CTYPE, "en_US.UTF-8");
		  unsigned len = _str.size()+1;
		  std::unique_ptr<wchar_t[]> p(new wchar_t[len]);
		  mbstowcs(p.get(), _str.c_str(), len);
		  std::wstring _wstr(p.get());
		  return _wstr;
		}

		std::string ws2s(const std::wstring& _wstr) {
		    if (_wstr.empty()) {
		      return "";
		    }//endif
		    setlocale(LC_CTYPE, "en_US.UTF-8");
		    unsigned len = _wstr.size()*4 + 1;
		    std::unique_ptr<char[]> p(new char[len]);
		    wcstombs(p.get(), _wstr.c_str(), len);
		    std::string _str(p.get());
		    return _str;
		}//endif
	#endif

};

#endif