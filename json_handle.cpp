/*---------------------------------------------------------------------------
	

----------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<unordered_map>
#include"pythonlike.hpp"

using namespace std;
using namespace pythonlike;


namespace JsonHandle{
	
	class JsonNode{
		public:
			unordered_map<string,JsonNode*> _dict;
			basic_string<JsonNode*> _list;
			string val;

			JsonNode*& operator[](string _str){
				return this->_dict[_str];
			}//end_Tree
			
			JsonNode*& operator[](int _idx){
				return this->_list[_idx];
			}
			// member functions
			void add(string key,string value){
				if(_dict.find(key) == _dict.end()){
					_dict[key] = new JsonNode();
				}//endif
				_dict[key]->val = value;
			}//end_add
			void append(string value){
				_list += new JsonNode();
				_list[_list.size()-1]->val = value;  
			}//end_value


			JsonNode(){}
			~JsonNode(){
				_dict.clear();
				_list.clear();
			}//end_JsonNode
	};


	class ReadJson{
		private:
			string longstr;
			vector<Pystring> longtokens;
		public:			
			
			

			ReadJson(string filename,bool _boolPrint=true){
				ifstream fin(filename.c_str(),ios::in);
				stringstream ss;
				ss << fin.rdbuf();
				longstr = compress(ss.str());
				longtokens = Pystring(longstr).tokens({":[",":{",":","[","]","{","}",",","\""});
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
				for(int i=0;i<longtokens.size();i++){
					cout << "[" << i << "]: " << longtokens[i] << endl;
				}//endfor
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

using namespace JsonHandle;

int main(){
	/*
	JsonNode _dictJson;
	_dictJson.add("1","2");
	_dictJson.add("2","1000");
	_dictJson.append("3");
	_dictJson.append("4");
	_dictJson.append("5");
	*/
	JsonHandle::ReadJson("../testfile/json_samplefile.json");
	
	

	





	return 0;
}//end_main
