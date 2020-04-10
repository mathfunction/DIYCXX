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
			//==============================================================================
			// utf8 

			// utf8 encoding
			int u8len(const string& str){
			    int c,i,ix,q;
			    for(q=0,i=0,ix=str.length();i<ix;i++,q++){
			        c = (unsigned char) str[i];
			        if      (c>=0   && c<=127) i+=0;
			        else if ((c & 0xE0) == 0xC0) i+=1;
			        else if ((c & 0xF0) == 0xE0) i+=2;
			        else if ((c & 0xF8) == 0xF0) i+=3;
			        else return 0;//invalid utf8
			    }//endfor
   	 			return q;
			}//end
			// 
			void u8print(const string&str,bool newline=true){
				vector<string> vc = this->u8(str);
				#if defined _WIN32 || defined _WIN64
					SetConsoleOutputCP(65001);
				#endif
				for(int i=0;i<vc.size();i++){
					
					#if defined _WIN32 || defined _WIN64
						// bug windows_cmd 加入 dummy 空格+退格
						vc[i] = " \b"+vc[i];
					#endif 
					cout << vc[i];
				}//endfor
				if(newline == true){
					cout << endl;
				}//endif
				#if defined _WIN32 || defined _WIN64
					SetConsoleOutputCP(950);
				#endif
			}//end_u8print


			vector<string> u8(const string& str){
				vector<string> vc;
				int c,i,ix,q;
			    for(q=0,i=0,ix=str.length();i<ix;i++,q++){
			        c = (unsigned char) str[i];
			        if(c>=0 && c<=127){
			        	vc.push_back(this->c2s(str[i]));
			        	i+=0;
			        }else if((c & 0xE0) == 0xC0){
			        	stringstream ss;
			        	ss << str[i] << str[i+1]; 
			        	vc.push_back(ss.str()); 
			        	i+=1;
			        }else if((c & 0xF0) == 0xE0){ 
			        	stringstream ss;
			        	ss << str[i] << str[i+1] << str[i+2]; 
			        	vc.push_back(ss.str()); 
			        	i+=2;
			        }else if((c & 0xF8) == 0xF0){ 
			        	stringstream ss;
			        	ss << str[i] << str[i+1] << str[i+2] << str[i+3];  
			        	vc.push_back(ss.str()); 
			        	i+=3;
			        }else{
			        	break;
			        }//end_else
			    }//endfor
			    return vc;
			}//end_u8split
			//============================================================================================================
	} shlr;
};
#endif