/*=====================================================================================
	
	u8string.hpp   (utf8 中文字串)
	
	// init
		u8string s("中文"); 宣告 ;
		u8string("中文") 建構式;
	// assignment 
		s = "中文"
		s("中文")
	// 列印字串
		void s.print() 
		
	// 取得字串長度
		int s.size()

	// ngram
	vector<u8string> s.ngram(2) 
	
	
	// split
	vector<u8string> v = s.split(u8string(","))
	u8string u8string(",").join(v)













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

			u8string& operator()(const string &_str){
				str = _str;
				v = s2u8(str);
				return *this; 
			}

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


			u8string operator()(int idx){
				return u8string(v[idx]);
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




			u8string join(const vector<u8string> &u8vec){
				string output;
				int n = u8vec.size();
				for(int i=0;i<n;i++){
					output+= u8vec[i].str;
					if(i<n-1){
						output += this->str;
					}//endif
				}//endfor
				return u8string(output);
			}//end_join
			
			
			vector<u8string> split(const u8string &delimiter){
				vector<u8string> output;
				int n = this->size();
				int dn = delimiter.v.size();
				int m = n-dn+1;
				int _idx = 0;
				for(int i=0;i<m;i++){
					if ((this->operator()(i,i+dn)) == delimiter){
						output.push_back(this->operator()(_idx,i));
						_idx = i+dn;
						i +=(dn-1);
					}//endif
				}//endfor
				output.push_back(this->operator()(_idx,m));
				return output;
			}//end_split
			

			vector<u8string> split(const string &delimiter){
				vector<u8string> output;
				int n = this->size();
				int dn = delimiter.size();
				int m = n-dn+1;
				int _idx = 0;
				for(int i=0;i<m;i++){
					if ((this->operator()(i,i+dn)) == delimiter){
						output.push_back(this->operator()(_idx,i));
						_idx = i+dn;
						i+=(dn-1);
					}//endif
				}//endfor
				output.push_back(this->operator()(_idx,m));
				return output;
			}//end_split



		
	};

};






































#endif