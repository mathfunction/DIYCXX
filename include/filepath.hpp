/*==================================================================












===============================================================*/
#ifndef __FILEPATH_HPP__
#define __FILEPATH_HPP__



namespace cxxuseful{
	class FilePath{
		private:
			u8string _path;
			u8string _dirname;
			std::vector<u8string> _tokens;
			u8string _filename;
			u8string _name;
			u8string _type;
		public:
			FilePath(const std::string &_str,std::string delimiter="/"){
				_path = u8string(_str);
				_tokens = _path.split(delimiter,true);
				_filename = _tokens[_tokens.size()-1]; 
				std::vector<u8string> temp = _filename.split(".");
				_type = temp[temp.size()-1];
				_name = substr(temp,0,-1);
				_dirname = substr(_tokens,0,-1);
			}//end_FileTokens
			void print(){
				std::cout << "absolute path : ";
				_path.print();
				std::cout << "- dirname : ";
				_dirname.print();
				std::cout << "- filename : ";
				_filename.print();
				std::cout << "- name : ";
				_name.print();
				std::cout << "- type : ";
				_type.print();
			}
			std::string dirname(){
				return _dirname.str;
			}
			
			std::vector<u8string> tokens(){
				return _tokens;
			}
			std::string filename(){
				return _filename.str;
			}
			std::string type(){
				return _type.str;
			}
	};


	std::string FileDir(const std::string &_str){
		if(_str[0] == '.'){
			return FilePath(_str,"/").dirname();
		}else{
			return FilePath(_str,"\\").dirname();
		}//end_else
	}

	// 回傳引用 (.hpp) 的 main.cpp 的絕對位置!!
	#ifndef __MainDir__
		#define __MainDir__ FileDir(__FILE__) 
	#endif
	
	
	





};















#endif