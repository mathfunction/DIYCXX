/*==================================================================
  utf8 本質為 vector<string>
  print_utf8( something ) 可以正確地把中文印出來 (跨平台)
	目前 something 支援格式如下: 
		vector<string>
	

  s2u8(_str) 回傳出 vector<string> , 每一個 index 代表一個 UTF8 字元
  u8s2(_str) vector<string> ---> string 
  wintrick 在 windows cmd  正確輸出 trick " \b"
====================================================================*/
#ifndef __UTF8STR_HPP__
#define __UTF8STR_HPP__

#if defined _WIN32 || defined _WIN64
	#include<windows.h>
#endif

#include<iostream>
#include<vector>

//==============================================================================
namespace cxxuseful{
	using namespace std;
	typedef vector<string> utf8;

	inline utf8 s2u8(const string& str){
		vector<string> vc;
		for(int i=0;i<str.size();i++){
			int c = (unsigned char) str[i];
			if(c>=0 && c<=127){
			    vc.push_back(string(1,str[i]));
			}else if((c & 0xE0) == 0xC0){
			    vc.push_back(string(1,str[i])+str[i+1]); 
			    i+=1;
			}else if((c & 0xF0) == 0xE0){
			    vc.push_back(string(1,str[i])+str[i+1]+str[i+2]); 
			    i+=2;
			}else if((c & 0xF8) == 0xF0){ 
			    vc.push_back(string(1,str[i])+str[i+1]+str[i+2]+str[i+3]); 
			    i+=3;
			}else{
			     break;
			}//end_else
		}//endfor
			return vc;
	}//end_utf8


	inline string u82s(const utf8 &v){
		string output = "";
		for(int i=0;i<v.size();i++){
			output += v[i];
		}//endfor
		return output;
	}//end_utf8



	// 在 windows cmd  輸出的保險輸出
	string wintrick(const string& str){
		return " \b"+str;
	}




	// ======================================================================================
	void print_utf8(const utf8 &vc){
		#if defined _WIN32 || defined _WIN64
			SetConsoleOutputCP(65001); // 調到 utf8 模式
		#endif
		cout << "[\n";
		for(int i=0;i<vc.size();i++){
			cout << "\t" << i << " : " ;
			#if defined _WIN32 || defined _WIN64
				// bug windows_cmd 加入 dummy 空格+退格
				cout << wintrick(vc[i]);
			#else
				cout << vc[i];
			#endif 
			cout << "\n";
		}//endfor
		cout << "]\n";
		#if defined _WIN32 || defined _WIN64
			SetConsoleOutputCP(950); // 預設 Big5
		#endif
	}//end_printutf8


	
	


};

#endif