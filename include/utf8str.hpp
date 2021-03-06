/*==================================================================
  utf8 本質為 std::vector<std::string>
  	print_utf8( something ) 可以正確地把中文印出來 (跨平台)
	目前 something 支援格式如下: 
		std::vector<std::string>
	

  	s2u8(_str) 回傳出 std::vector<std::string> , 每一個 index 代表一個 UTF8 字元
 	u8s2(_str) std::vector<std::string> ---> std::string 
  	wintrick 在 windows cmd  正確輸出 trick " \b"


	
	class u8string   (utf8 中文字串)
	
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
	std::vector<u8string> s.ngram(2) 
	
	// split
	std::vector<u8string> v = s.split(u8string(","))
	u8string u8string(",").join(v)
	
	// strip
	
	// rstrip

	// lstrip
	

====================================================================*/
#ifndef __UTF8STR_HPP__
#define __UTF8STR_HPP__




namespace cxxuseful{
	
	typedef std::vector<std::string> utf8;

	inline utf8 s2u8(const std::string& str){
		std::vector<std::string> vc;
		for(int i=0;i<str.size();i++){
			int c = (unsigned char) str[i];
			if(c>=0 && c<=127){
			    vc.emplace_back(std::string(1,str[i]));
			}else if((c & 0xE0) == 0xC0){
			    vc.emplace_back(std::string(1,str[i])+str[i+1]); 
			    i+=1;
			}else if((c & 0xF0) == 0xE0){
			    vc.emplace_back(std::string(1,str[i])+str[i+1]+str[i+2]); 
			    i+=2;
			}else if((c & 0xF8) == 0xF0){ 
			    vc.emplace_back(std::string(1,str[i])+str[i+1]+str[i+2]+str[i+3]); 
			    i+=3;
			}else{
			     break;
			}//end_else
		}//endfor
		return vc;
	}//end_utf8


	

	


	inline std::string u82s(const utf8 &v){
		std::string output = "";
		for(int i=0;i<v.size();i++){
			output += v[i];
		}//endfor
		return output;
	}//end_utf8

	// 在 windows cmd  輸出的保險輸出
	std::string wintrick(const std::string& str){
		return " \b"+str;
	}

	
	void print_utf8(const utf8 &vc){
		#if defined _WIN32 || defined _WIN64
			SetConsoleOutputCP(65001); // 調到 utf8 模式
		#endif
		std::cout << "[\n";
		for(int i=0;i<vc.size();i++){
			std::cout << "\t" << i << " : " ;
			#if defined _WIN32 || defined _WIN64
				// bug windows_cmd 加入 dummy 空格+退格
				std::cout << wintrick(vc[i]);
			#else
				std::cout << vc[i];
			#endif 
			std::cout << "\n";
		}//endfor
		std::cout << "]\n";
		#if defined _WIN32 || defined _WIN64
			SetConsoleOutputCP(950); // 預設 Big5
		#endif
	}//end_printutf8
	
	




	// ======================================================================================
	// 主要物件 !! 
	// ======================================================================================
	class u8string{
		public:
			utf8 v;
			// 建構
			u8string(){
				v = s2u8("");
			}
			u8string(const std::string &_str){
				v = s2u8(_str);
			}//end_UTF8
			std::string to_str() const {
				return u82s(this->v);
			}
			const char* c_str() const {
				return u82s(this->v).c_str();
			}


			//=======================================================================
			int size(){
				return v.size();
			}//end_size
			void print(bool _boolNewline=true){
				#if defined _WIN32 || defined _WIN64
					SetConsoleOutputCP(65001); 
					std::cout << wintrick(this->to_str());
					if(_boolNewline) std::cout << std::endl;
					SetConsoleOutputCP(950); 
				#else 
					std::cout << this->to_str();
					if(_boolNewline) std::cout << std::endl;
				#endif
			}//end_print
			//=======================================================================
			// copy
			u8string& operator=(const std::string &_str){
				v = s2u8(_str);
				return *this; 
			}



			// 初始化 
			u8string& operator()(const std::string &_str){
				v = s2u8(_str);
				return *this; 
			}

			// 這個會複製子字串 !! 
			u8string operator[](const std::initializer_list<int> &p){
				utf8 v2;
				if(p.size() == 1){
					v2.emplace_back(v[p.begin()[0]]);
				}else if(p.size() ==  2){
					if(p.begin()[1] == -1){
						for(int k=p.begin()[0];k<v.size();k++){
							v2.emplace_back(v[k]);
						}//endfor
					}else{
						for(int k=p.begin()[0];k<p.begin()[1];k++){
							v2.emplace_back(v[k]);
						}//endfor
					}//end_else
				}else{
					std::cout << "operator[] error in utf8str.hpp !!" << std::endl; 
					std::exit(1);
				}//end_else
				return u8string(u82s(v2));
			}


			std::string& operator[](int idx){
				return v[idx];
			}



			// concat 
			u8string operator+(const u8string& _u8str2){
				return u8string(this->to_str()+_u8str2.to_str());
			}
			u8string operator+(const std::string& _str){
				return u8string(this->to_str()+_str);
			}


			// ngram
			std::vector<u8string> ngram(int n=2){
				std::vector<u8string> output;
				int m = this->size()-n+1;
				for(int i=0;i<m;i++){
					output.emplace_back(this->operator[]({i,i+n}));
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

			bool operator==(const std::string& _str){
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

			u8string join(const std::vector<std::string> &vec){
				std::vector<u8string> u8vec;
				for(int i=0;i<vec.size();i++){
					u8vec.emplace_back(u8string(vec[i]));
				}//endfor
				return this->join(u8vec);
			}


			u8string join(const std::vector<u8string> &u8vec){
				std::string output;
				int n = u8vec.size();
				for(int i=0;i<n;i++){
					output+= u8vec[i].to_str();
					if(i<n-1){
						output += this->to_str();
					}//endif
				}//endfor
				return u8string(output);
			}//end_join
			
			



			std::vector<u8string> split(const u8string &delimiter,bool _boolFull=false){
				if (delimiter.v.size() == 0){
					return this->ngram(1);
				}//endif
				std::vector<u8string> output;
				int n = this->size();
				int dn = delimiter.v.size();
				int m = n-dn+1;
				int _idx = 0;
				for(int i=0;i<m;i++){
					if ((this->operator[]({i,i+dn})) == delimiter){
						output.emplace_back(this->operator[]({_idx,i}));
						if(_boolFull) output.emplace_back(delimiter);
						_idx = i+dn;
						i +=(dn-1);
					}//endif
				}//endfor
				output.emplace_back(this->operator[]({_idx,n}));
				return output;
			}//end_split
			


			std::vector<u8string> split(const std::string &delimiter="",bool _boolFull=false){
				std::vector<u8string> output;
				u8string u8d = u8string(delimiter);
				output = this->split(u8d,_boolFull);
				return output;
			}//end_split


			




	};
		
	// 選擇子字串 !! 
	u8string substr(const std::vector<u8string>&u8v,int m,int n){
		std::string output;
		if(n==-1){
			n = u8v.size()-1;
		}
		for(int i=m;i<n;i++){
			output += u8v[i].to_str();
		}//endfor
		return u8string(output);
	}






};

#endif