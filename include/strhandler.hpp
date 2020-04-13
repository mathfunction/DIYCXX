/*==============================================


- shlr(vector<>,分隔符,頭標) // 支援混雜型態 int , double , string , ... !! 
	ex: shlr({1,0.123,"456"},"_","X")  ====> "X_1_0.123_456"


- shlr.c2s 可把 char 轉成 string
- shlr.c2ccp 可把 char 轉成 const char* 

================================================*/

#ifndef __STRHANDLER_HPP__
#define __STRHANDLER_HPP__

namespace cxxuseful{
	using namespace std;
	class StrHandler{
		public:
			string operator()(const vector<string> &v,string delimiter="_",string title="[Key]"){
				string _output = title;
				for(int i=0;i<v.size();i++){
					_output += delimiter;
					_output += v[i];
				}//endfor
				return _output;
			}//end
			string operator()(const vector<BoostAny> &v,string delimiter="_",string title="[Key]"){
				stringstream ss;
				ss << title;
				for(int i=0;i<v.size();i++){
					ss << delimiter;
					if(v[i].type() == typeid(string)){
						ss << type<string>(v[i]);
					}else if(v[i].type() == typeid(const char*)){
						ss << type<const char*>(v[i]);
					}else if(v[i].type() == typeid(int)){
						ss << type<int>(v[i]);
					}else if(v[i].type() == typeid(double)){
						ss << type<double>(v[i]);
					}else{
						ss << "<E>";
					}
				}//endfor
				return ss.str();
			}

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