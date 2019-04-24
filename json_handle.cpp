/*---------------------------------------------------------------------------
	

----------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<unordered_map>

using namespace std;



namespace JsonHandle{
	
	class JsonNode{
		private:
			unordered_map<string,JsonNode*> dict;
			basic_string<JsonNode*> list;
			string val;
		public:
			JsonNode*& operator[](string _str){
				return dict[_str];
			}//end_Tree
			
			JsonNode*& operator[](int _idx){
				return list[_idx];
			}
		~JsonNode(){
			dict.clear();
			list.clear();
		}//end_JsonNode
	};
	


	class ReadJson{
		private:
			string longstr;
			JsonNode _dictJson;
		public:			
			void parser(){
				

			}//end_parser

			void tokenizer(){
				bool _collectButton = false;
				string _temp = "";
				for(int i=0;i<longstr.size();i++){
					// handle button 
					if(longstr[i] == '\"'){
						if(_collectButton == true){
							cout << _temp << endl;
							_temp = "";
						}//endif
						_collectButton = !_collectButton;
						continue;
					}//endif
					if(_collectButton == true){
						_temp += longstr[i];
					}//endif
				}//endfor
			}//end_tokenizer
			
			ReadJson(string filename,bool _boolPrint=true){
				ifstream fin(filename.c_str(),ios::in);
				stringstream ss;
				ss << fin.rdbuf();
				longstr = compress(ss.str());
				if(checkEven()==false){
					cerr << "checkEven Failed !! " << endl;
					exit(1);
				}//endif
				if(_boolPrint == true){
					printLoad();
				}//endif
			}//end
			string compress(string _str){
				string output;
				for(int i=0;i<_str.size();i++){
					if (
						(_str[i] == '\n') ||
						(_str[i] == '\r') ||
						(_str[i] == '\t') || 
						(_str[i] == ' ')
					){
						// do nothing
					}else{
						output += _str[i];
					}//end_else
				}//endfor
				return output;
			}//end_compress
			void printLoad(){
				cerr << longstr << endl;
				//this->tokenizer();
			}//endprint
			bool checkEven(){
				unordered_map<string,int> _count;
				_count["[]"] = 0;
				_count["{}"] = 0;
				_count["\""] = 1;
				for(int i=0;i<longstr.size();i++){
					if(longstr[i] == '['){
						_count["[]"] += 1;
					}else if(longstr[i] == ']'){
						_count["[]"] -= 1;
					}else if(longstr[i] == '\"'){
						_count["\""] *= (-1);
					}else if(longstr[i] == '{'){
						_count["{}"] += 1;
					}else if(longstr[i] == '}'){
						_count["{}"] -= 1;
					}else{
					}//endelse
				}//endfor
				if(_count["[]"] != 0) 
					return false;
				if(_count["{}"] != 0)
					return false; 
				if(_count["\""] != 1)
					return false;
				return true;
			}//end_checkEven

	};

};



int main(){
		
	
	JsonHandle::ReadJson("../testfile/json1.json");

	

	





	return 0;
}//end_main
