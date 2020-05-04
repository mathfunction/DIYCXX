/*==============================================


- shlr(std::vector<>,分隔符,頭標) // 支援混雜型態 int , double , std::string , ... !! 
	ex: shlr({1,0.123,"456"},"_","X")  ====> "X_1_0.123_456"


- shlr.c2s 可把 char 轉成 std::string
- shlr.c2ccp 可把 char 轉成 const char* 

================================================*/

#ifndef __STRHANDLER_HPP__
#define __STRHANDLER_HPP__


namespace cxxuseful{


	class StrHandler{
		public:
			std::string operator()(const std::vector<std::string> &v,std::string delimiter="_",std::string title="[Key]"){
				std::string _output = title;
				for(int i=0;i<v.size();i++){
					_output += delimiter;
					_output += v[i];
				}//endfor
				return _output;
			}//end
			std::string operator()(const std::vector<BoostAny> &v,std::string delimiter="_",std::string title="[Key]"){
				std::stringstream ss;
				ss << title;
				for(int i=0;i<v.size();i++){
					ss << delimiter;
					if(v[i].type() == typeid(std::string)){
						ss << type<std::string>(v[i]);
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
				return std::string(1,c).c_str();
			}
			std::string c2s(char c){
				return std::string(1,c);
			}
			

			

			




	} shlr;
};
#endif