/*==================================================================












===============================================================*/
#ifndef __FILEPATH_HPP__
#define __FILEPATH_HPP__

#include "utf8str.hpp"

namespace cxxuseful{
	class FilePath{
		private:
			u8string _path;
			u8string _dirname;
			vector<u8string> _tokens;
			u8string _filename;
			u8string _name;
			u8string _type;
		public:
			FilePath(const string &_str,string delimiter="/"){
				_path = u8string(_str);
				_tokens = _path.split(delimiter,true);
				_filename = _tokens[_tokens.size()-1]; 
				vector<u8string> temp = _filename.split(".");
				_type = temp[temp.size()-1];
				_name = substr(temp,0,-1);
				_dirname = substr(_tokens,0,-1);
			}//end_FileTokens
			void print(){
				cout << "absolute path : ";
				_path.print();
				cout << "- dirname : ";
				_dirname.print();
				cout << "- filename : ";
				_filename.print();
				cout << "- name : ";
				_name.print();
				cout << "- type : ";
				_type.print();
			}
			string dirname(){
				return _dirname.str;
			}
			
			vector<u8string> tokens(){
				return _tokens;
			}
			string filename(){
				return _filename.str;
			}
			string type(){
				return _type.str;
			}
	};










};















#endif