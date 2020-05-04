/*==================================================================================

	print( something )
	
	目前 something 支援格式如下:
		
		- std::basic_string
			std::basic_string<int>
			std::basic_string<double>
		- std::vector
			std::vector<int>
			std::vector<double>
			std::vector< std::pair<std::string,double> >
		
		- std::unordered_map
			std::unordered_map<std::string,std::string>
			std::unordered_map<std::string,double>
			std::unordered_map<std::string,int>
			std::unordered_map<int,int>
			std::unordered_map<int,double>
		-std::list
			std::list<std::string>



===========================================================================*/


#ifndef __PRINTFUNC_HPP__
#define __PRINTFUNC_HPP__



namespace cxxuseful{
	
	
	class PrintFunc{
			public:

				void operator()(const std::vector< std::pair<std::string,double> > &v){
					printGreen("std::vector<std::pair<std::string,double> >",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						std::cout << "\t std::pair(" << v[i].first << "," ;
						printYellow(std::to_string(v[i].second)+")",true);

					}//endfor
					printYellow("]",true);
				}	

				void operator()(const std::vector<BoostAny> &v){
					printGreen("std::vector<BoostAny>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						if(v[i].type()==typeid(int)){
							std::cout << "\t" <<  i << " : " << type<int>(v[i]) << std::endl;
						}else if(v[i].type()==typeid(const char*)){
							std::cout << "\t" <<  i << " : " << type<const char*>(v) << std::endl;
						}else if(v[i].type()==typeid(std::string)){
							std::cout << "\t" <<  i << " : " << type<std::string>(v[i]) << std::endl;
						}else if(v[i].type()==typeid(double)){
							std::cout << "\t" <<  i << " : " << type<double>(v[i]) << std::endl;
						}else if(v[i].type()==typeid(BoostInt)){
							std::cout << "\t" <<  i << " : " << type<BoostInt>(v[i]) << std::endl;
						}else if(v[i].type()==typeid(BoostFloat)){
							std::cout << "\t" <<  i << " : " << type<BoostFloat>(v[i]) << std::endl;
						}else if(v[i].type()==typeid(BoostRational)){
							std::cout << "\t" <<  i << " : " << type<BoostRational>(v[i]) << std::endl;
						}else{
						}//end_else
					}//endfor
					printYellow("]",true);
				}
				void operator()(const std::basic_string<int> &v){printGreen("std::basic_string<int>",true); return handleList<int>(v);}
				void operator()(const std::basic_string<double> &v){printGreen("std::basic_string<double>",true);return handleList<double>(v);}
				void operator()(const std::vector<int> &v){printGreen("std::vector<int>",true);return handleList<int>(v);}
				void operator()(const std::vector<double> &v){printGreen("std::vector<double>",true);return handleList<double>(v);}//end
				void operator()(const std::vector<std::string> &v){printGreen("std::vector<std::string>",true);return handleList(v);}//end
				void operator()(const std::unordered_map<std::string,std::string> &v){printGreen("std::unordered_map<std::string,std::string>",true);return handleDict(v);}//end
				void operator()(const std::unordered_map<std::string,double> &v){printGreen("std::unordered_map<std::string,double>",true);return handleDict<std::string,double>(v);}//end
				void operator()(const std::unordered_map<std::string,int> &v){printGreen("std::unordered_map<std::string,int>",true);return handleDict<std::string,int>(v);}//end
				void operator()(const std::unordered_map<int,int> &v){printGreen("std::unordered_map<int,int>",true);return handleDict<int,int>(v);}//end
				void operator()(const std::unordered_map<int,double> &v){printGreen("std::unordered_map<int,double>",true);return handleDict<int,double>(v);}//end
				void operator()(const std::unordered_set<int> &s){printGreen("std::unordered_set<int>",true);return handleSet<int>(s);}
				//void operator()(const std::unordered_set<std::string> &s){printGreen("std::unordered_set<std::string>",true);return handleSet<std::string>(s);}
				void operator()(const std::list<std::string> &v){printGreen("std::unordered_map<int,double>",true);return handleList(v);}
				void operator()(const std::vector<std::pair<std::string,int> > &s){
					printGreen("std::vector<std::pair<std::string,int> >",true);
					printYellow("[",true);
					for(int i=0;i<s.size();i++){
						std::cout << "\t" << s[i].first << "," << s[i].second << std::endl;
					}//enfor
					printYellow("]",true);
				}



				
				void operator()(const std::vector<u8string> &v){
					printYellow("[",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
						for(int i=0;i<v.size();i++){
							std::cout << "\t" <<  i << " : " <<  wintrick(v[i].str)  << std::endl;
						}
						SetConsoleOutputCP(950); 
					#else
						for(int i=0;i<v.size();i++){
							std::cout << "\t" <<  i << " : " <<  v[i].str  << std::endl;
						}
					#endif
					printYellow("]",true);
				}

				void operator()(const std::string &str){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
					#endif
					std::cout << wintrick(str) << std::endl;
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}
				
			private:
				template<class T>
				void handleSet(const std::unordered_set<T> &s){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001);
					#endif
					printYellow("{",true);
					for(auto &k:s){
						std::cout << "\t";
						printYellow(wintrick(std::to_string(k)),true);
					}//endfor
					printYellow("}",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_handleSet


				template<class T,class S>
				void handleDict(const std::unordered_map<T,S> &v){
					#if defined _WIN32 || defined _WIN64
							SetConsoleOutputCP(65001);
					#endif
					printYellow("{",true);
					for(auto &k:v){
						std::cout << "\t"  << k.first << " : " ;
						printYellow(wintrick(std::to_string(k.second)),true);
					}//endfor
					printYellow("}",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_handleDict

				void handleDict(const std::unordered_map<std::string,std::string> &v){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
					#endif
					printYellow("{",true);
					for(auto &k:v){
						std::cout << "\t" << wintrick(k.first) << " : " ;
						printYellow(wintrick(k.second),true);
					}//endfor
					printYellow("}",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_
				// handle std::list
				void handleList(const std::list<std::string> &v){
					printYellow("[",true);
					int i = 0;
					for(auto &k:v){
						std::cout << "\t" << i << " : " ;
						printYellow(k,true);
						i+=1;
					}//endfor
					printYellow("]",true);
				}//end_



				// handle std::basic_string 
				template<class T>
				void handleList(const std::basic_string<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						std::cout << "\t" << i << " : " ;
						printYellow(wintrick(std::to_string(v[i])),true);
					}//endfor
					printYellow("]",true);
				}//end_

				// handle std::vector
				template<class T>
				void handleList(const std::vector<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						std::cout << "\t" << i << " : " ;
						printYellow(wintrick(std::to_string(v[i])),true);
					}//endfor
					printYellow("]",true);
				}//end_


				void handleList(const std::vector<std::string> &v){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
					#endif
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						std::cout << "\t" << i << " : " ;
						printYellow(wintrick(v[i]),true);
					}//endfor
					printYellow("]",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_


		} print;
};


#endif