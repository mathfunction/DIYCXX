/*=====================================================================================



















========================================================================================*/





#ifndef __U8STRING_HPP__
#define __U8STRING_HPP__

#include<iostream>
#include<vector>
#include<string>
#include "utf8str.hpp"


namespace cxxuseful{
	using namespace std;
	
	class u8string{
		public:
			utf8 v;
			string str;
			// 建構
			u8string(){
				str = "";
				v = s2u8(str);
			}
			u8string(const string &_str){
				str = _str;
				v = s2u8(str);
			}//end_UTF8

			//=======================================================================
			int size(){
				return v.size();
			}//end_size
			void print(){
				#if defined _WIN32 || defined _WIN64
					SetConsoleOutputCP(65001); 
					cout << wintrick(str) << endl;
					SetConsoleOutputCP(950); 
				#else 
					cout << str << endl;
				#endif
			}//end_print
			//=======================================================================
			// copy
			u8string& operator=(const string &_str){
				str = _str;
				v = s2u8(str);
				return *this; 
			}

			// substr
			u8string operator()(int first,int end){
				utf8 v2;
				for(int k=first;k<end;k++){
					v2.push_back(v[k]);
				}//endfor
				return u8string(u82s(v2));
			}

			// concat 
			u8string operator+(const u8string& _u8str2){
				return u8string(this->str+_u8str2.str);
			}
			u8string operator+(const string& _str){
				return u8string(this->str+_str);
			}


			
			




		
	};

};






































#endif