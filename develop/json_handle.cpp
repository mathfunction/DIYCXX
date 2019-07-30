/*---------------------------------------------------------------------------
	
	這是解析 DIY Json 實作:
		
		ReadJson :  
			need pythonlike.hpp
		JsonParser 參考網址:
			http://notes.eatonphil.com/writing-a-simple-json-parser.html?fbclid=IwAR02w6X2hC8MO4NHSXlQWlgikxSzHWz50lsMcQQ_RYlOjxx2DCqFXOjlAeY

	存在 bug 
	1. value 值 不可以是空字串 ""
	2. 中文處理??







----------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
//#include"pythonlike.hpp"

using namespace std;
//using namespace pythonlike;


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
	/*
	class ReadJson{
		private:
			string longstr;
			vector<Pystring> longtokens;


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

		public:				
			ReadJson(string filename,bool _boolPrint=true,string option="first_order"){
				ifstream fin(filename.c_str(),ios::in);
				stringstream ss;
				ss << fin.rdbuf();
				longstr = compress(ss.str());
				longtokens = Pystring(longstr).tokens({":[",":{","]","{","}",",","},"});
				if(checkEven()==false){
					cerr << "checkEven Failed !! " << endl;
					exit(1);
				}//endif

				if(_boolPrint == true){
					printLoad();
				}//endif
			}//end
			
			void printLoad(){
				cerr << longstr << endl;
				for(int i=0;i<longtokens.size();i++){
					cout << "[" << i << "]: " << longtokens[i] << endl;
				}//endfor
			}//endprint
	};
	*/
	class JsonParser{
		private:
			// constants

			char JSON_QUOTE = '"'; 
			char JSON_LEFTBRACKET = '['; 
			char JSON_RIGHTBRACKET = ']';
			char JSON_LEFTBRACE = '{';
			char JSON_RIGHTBRACE = '}';
			char JSON_COLON = ':';
			char JSON_COMMA = ','; 
			unordered_set<char>	JSON_WHITESPACE = {' ','\t','\b','\n','\r'};
			unordered_set<char> JSON_SYNTAX = {'{','}','[',']',',',':'};
			unordered_set<char> JSON_NUMBERS = {'0','1','2','3','4','5','6','7','8','9','-','e','.','E'}; 
			int FALSE_LEN = string("false").size();
			int TRUE_LEN = string("true").size();
			int NULL_LEN = string("null").size();
			// temp
			string _strJson , _numJson , _boolJson , _nullJson;
			// _dictJson
			JsonNode _dictJson;
			JsonNode* _currentPointer;
			// _str[1:]
			string subStr(string &_str,int i,int j){
				return _str.substr(i,j-i);
			}//end_handle1
			string charStr(char &c){
				return string(1,c);
			}

			void pair_update(pair<string,string> _pair,string &_strtoken,string &_strRemain){
				_strtoken = _pair.first;
				_strRemain = _pair.second;
			}
			JsonNode get(){
				return _dictJson;
			}//end_get()

			//==========================================================================
			// lex
			vector<string> lex(string _str){
				vector<string> tokens;
				while(_str.size()){
					
					//============================================================================
					// lex_string 
					pair_update(lex_string(_str),_strJson,_str);
					if(_strJson.size()){
						tokens.push_back("STR_"+_strJson);
						continue;
					}//endif
					//============================================================================
					// lex_numbers 
					pair_update(lex_number(_str),_numJson,_str);
					if(_numJson.size()){
						if(_numJson.find(".") != -1){
							tokens.push_back("DBL`"+_numJson);
						}else{
							tokens.push_back("INT`"+_numJson);
						}//end_else
						continue;
					}//endif

					// lex_numbers 
					pair_update(lex_bool(_str),_boolJson,_str);
					if(_boolJson.size()){
						tokens.push_back("BOOL`"+_boolJson);
						continue;
					}//endif

					// lex_null
					pair_update(lex_null(_str),_nullJson,_str);
					if(_nullJson.size()){
						tokens.push_back("NULL`");
						continue;
					}//endif

					//============================================================================
					// neglect !!
					if(JSON_WHITESPACE.find(_str[0]) != JSON_WHITESPACE.end()){
						_str = subStr(_str,1,_str.size());
					//============================================================================
					// special char  
					}else if(JSON_SYNTAX.find(_str[0]) != JSON_SYNTAX.end()){
						tokens.push_back(charStr(_str[0]));
						_str = subStr(_str,1,_str.size());
					//============================================================================
					}else{
						cerr << "[Error] Unexpected character: " << _str[0] << endl;
						exit(1);
					}//end_else

				}//end_while
				return tokens;
			}//end_lex


			pair<string,string> lex_string(string &_str){
				_strJson = "";
				if(_str[0] == JSON_QUOTE){
					_str = subStr(_str,1,_str.size());
				}else{
					return pair<string,string>("",_str);
				}//end_else

				for(int i=0;i<_str.size();i++){
					if(_str[i] == JSON_QUOTE){
						return pair<string,string> (_strJson,subStr(_str,_strJson.size()+1,_str.size()));
					}else{
						_strJson += _str[i];
					}//end_else
				}//endfor
				
			}//end_lex_string
			//==========================================

			pair<string,string> lex_number(string &_str){
				_numJson = "";
				for(int i=0;i<_str.size();i++){
					if(JSON_NUMBERS.find(_str[i])!= JSON_NUMBERS.end()){
						_numJson += _str[i];
					}else{
						break;
					}//end_else
				}//endfor
				
				string rest = subStr(_str,_numJson.size(),_str.size());
				return pair<string,string>(_numJson,rest);
			}//end_lex_number 

			
			pair<string,string> lex_bool(string &_str){
				int string_len = _str.size();
				if((string_len >= TRUE_LEN)&& (subStr(_str,0,TRUE_LEN)  == "true")){
					return pair<string,string>("true",subStr(_str,TRUE_LEN,_str.size()));
				}else if((string_len >= FALSE_LEN)&& (subStr(_str,0,FALSE_LEN)  == "false")){
					return pair<string,string>("false",subStr(_str,FALSE_LEN,_str.size()));
				}else{
					return pair<string,string>("",_str);
				}//end_else
			}//end
			

			pair<string,string> lex_null(string &_str){
				int string_len = _str.size();
				if((string_len >= NULL_LEN)&&(subStr(_str,0,NULL_LEN)== "null")){
					return pair<string,string>("null",subStr(_str,NULL_LEN,_str.size()));
				}else{
					return pair<string,string>("",_str);
				}//end_else
			}//end
			
			//============================================================================
			// parse 
			vector<string> parse(vector<string> &tokens,bool _isRoot=false){
				string t = tokens[0];
				if((_isRoot == true)&&(t!= charStr(JSON_LEFTBRACE))){
					cerr << "[Error] Root must be an object " << endl;
					exit(1);
				}//endif
				if(t == charStr(JSON_LEFTBRACKET)){
					tokens.erase(tokens.begin());
					return parse_array(tokens);
				}else if(t == charStr(JSON_LEFTBRACE)){
					tokens.erase(tokens.begin());
					return parse_dict(tokens);
				}else{
					tokens.erase(tokens.begin());
					return tokens;
				}//end_else
			}//end_parse

			vector<string> parse_array(vector<string> &tokens){
				string t = tokens[0];
				if(t == charStr(JSON_RIGHTBRACKET)){
					tokens.erase(tokens.begin());
					return tokens;
				}//endif

				while(1){
					tokens = parse(tokens);
					t = tokens[0];
					if (t == charStr(JSON_RIGHTBRACKET)){
						tokens.erase(tokens.begin());
						return tokens;
					}else if(t!= charStr(JSON_COMMA)){
						cerr << "[Error] Expected comma after object in array" << endl;
						exit(1);
					}else{
						tokens.erase(tokens.begin());
					}//end_else
				}//end_while
				cerr << "[Error] Expected end-of-array" << endl;
				exit(1);
			}//end_parse_array	

			vector<string> parse_dict(vector<string> &tokens){
				string t = tokens[0];
				if(t == charStr(JSON_RIGHTBRACE)){
					tokens.erase(tokens.begin());
					return tokens;
				}//endif
				while(1){
					// extract key
					string json_key = tokens[0];
					tokens.erase(tokens.begin());
					// check 
					if(tokens[0] != charStr(JSON_COLON)){
						cerr << "[Error] Expected colon after key in object, got:" << t << endl;
						exit(1);
					}//endif
					tokens.erase(tokens.begin());
					// extract value
					tokens = parse(tokens);
					
					t = tokens[0];
					if(t == charStr(JSON_RIGHTBRACE)){
						tokens.erase(tokens.begin());
						return tokens;
					}else if(t != charStr(JSON_COMMA)){
						cerr << "[Error] Expected comma after pair in dict, got:" << t << endl;
						exit(1);
					}else{
						tokens.erase(tokens.begin());
					}
				}//end_while				
				cerr << "[Error] Expected end-of-dict" << endl;
				exit(1);
			}//end_parse_dict


		public:
			JsonParser(string filename,bool _boolPrint=false){
				ifstream fin(filename.c_str(),ios::in);
				stringstream ss;
				ss << fin.rdbuf();
				string longstr = ss.str();
				vector<string> tokens = lex(longstr);
				if(_boolPrint == true){
					for(int i=0;i<tokens.size();i++){
						cout << tokens[i] << endl;
					}//endfor
				}//endif
				int _sizeCheck = parse(tokens,true).size();
				if (_sizeCheck!=0){
					cerr << "[Error] JsonParser[ Unhandled : " << _sizeCheck << " ]" << endl;
					exit(1);
				}else{
					cerr << "[Done] JsonParser[ " << filename << " ]" << endl;
				}//end_else
			}//end_JsonParser
			
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
	
	
	JsonHandle::JsonParser("Init.json",true);
	





	return 0;
}//end_main
