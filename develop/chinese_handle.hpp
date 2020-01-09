/*==============================================================================
	This is windows print chinese routines 


	chcp 65001 UTF8 , 	most Chinese-Char need 3-Chars 
	chcp 950 BIG5 , 	each Chinese-Char need 2-Chars

	


===============================================================================*/
#ifndef CHINESE_HANDLE
#define CHINESE_HANDLE

#include<iostream>
#include<string>

using namespace std;

class WideStr{
	public:
		wstring ws;
		string s;
		int size;
		WideStr(wstring ws){
			this->ws = ws;
		}//end_widestr
		WideStr(string s){
			unsigned len = s.size()*2;
    		setlocale(LC_CTYPE, "");
    		wchar_t *buffer = new wchar_t[len];
    		mbstowcs(buffer,s.c_str(),len);
    		this->ws = wstring(buffer);
    		delete[] buffer;
		}//end_widestr
		void print(){
			setlocale(LC_CTYPE, "");
			for(int i=0;i<ws.size();i++){
				wprintf(L"%c",ws[i]);
			}//endfor
		}//end_print	
};//end_class




#endif