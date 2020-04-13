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
				if(end == -1){
					end = this->size();
				}//endif
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


			// ngram
			vector<u8string> ngram(int n=2){
				vector<u8string> output;
				int m = this->size()-n+1;
				for(int i=0;i<m;i++){
					output.push_back(this->operator()(i,i+n));
				}//endfor
				return output;
			}//end_ngram

			bool operator==(const u8string& _u8str2){
				if(this->size() != _u8str2.v.size()){
					return false;
				}//endif
				for(int i=0;i<_u8str2.v.size();i++){
					if(this->v[i] != _u8str2.v[i]){
						return false;
					}//endif
				}//endfor
				return true;
			}

			bool operator==(const string& _str){
				u8string _u8str2(_str);
				if(this->size() != _u8str2.v.size()){
					return false;
				}//endif
				for(int i=0;i<_u8str2.v.size();i++){
					if(this->v[i] != _u8str2.v[i]){
						return false;
					}//endif
				}//endfor
				return true;				
			}

			
			vector<u8string> split(const u8string & delimiter){
				vector<u8string> output;

				return output;
			}//end_split


			u8string join(const vector<u8string> &u8vec){
				u8string output;
				return output;
			}//end_join



		
	};

};






































#endif