/*==================================================================================

	print( something )
	
	目前 something 支援格式如下:
		
		- basic_string
			basic_string<int>
			basic_string<double>
		- vector
			vector<int>
			vector<double>
			vector< pair<string,double> >
		
		- unordered_map
			unordered_map<string,string>
			unordered_map<string,double>
			unordered_map<string,int>
			unordered_map<int,int>
			unordered_map<int,double>
		-list
			list<string>



===========================================================================*/


#ifndef __PRINTFUNC_HPP__
#define __PRINTFUNC_HPP__

#include "utf8str.hpp"


namespace cxxuseful{
	using namespace std;
	using namespace cmdcolor;
	class PrintFunc{
			public:

				void operator()(const vector< pair<string,double> > &v){
					printGreen("vector<pair<string,double> >",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t Pair(" << v[i].first << "," ;
						printYellow(to_string(v[i].second)+")",true);

					}//endfor
					printYellow("]",true);
				}	
				void operator()(const basic_string<int> &v){printGreen("basic_string<int>",true); return handleList<int>(v);}
				void operator()(const basic_string<double> &v){printGreen("basic_string<double>",true);return handleList<double>(v);}
				void operator()(const vector<int> &v){printGreen("vector<int>",true);return handleList<int>(v);}
				void operator()(const vector<double> &v){printGreen("vector<double>",true);return handleList<double>(v);}//end
				void operator()(const vector<string> &v){printGreen("vector<string>",true);return handleList(v);}//end
				void operator()(const unordered_map<string,string> &v){printGreen("unordered_map<string,string>",true);return handleDict(v);}//end
				void operator()(const unordered_map<string,double> &v){printGreen("unordered_map<string,double>",true);return handleDict<string,double>(v);}//end
				void operator()(const unordered_map<string,int> &v){printGreen("unordered_map<string,int>",true);return handleDict<string,int>(v);}//end
				void operator()(const unordered_map<int,int> &v){printGreen("unordered_map<int,int>",true);return handleDict<int,int>(v);}//end
				void operator()(const unordered_map<int,double> &v){printGreen("unordered_map<int,double>",true);return handleDict<int,double>(v);}//end
				void operator()(const list<string> &v){printGreen("unordered_map<int,double>",true);return handleList(v);}
			private:

				template<class T,class S>
				void handleDict(const unordered_map<T,S> &v){
					#if defined _WIN32 || defined _WIN64
							SetConsoleOutputCP(65001);
					#endif
					printYellow("{",true);
					for(auto &k:v){
						cerr << "\t"  << k.first << " : " ;
						printYellow(wins(to_string(k.second)),true);
					}//endfor
					printYellow("}",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_handleDict

				void handleDict(const unordered_map<string,string> &v){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
					#endif
					printYellow("{",true);
					for(auto &k:v){
						cerr << "\t" << " \b"+k.first << " : " ;
						printYellow(wins(k.second),true);
					}//endfor
					printYellow("}",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_
				// handle list
				void handleList(const list<string> &v){
					printYellow("[",true);
					int i = 0;
					for(auto &k:v){
						cerr << "\t" << i << " : " ;
						printYellow(k,true);
						i+=1;
					}//endfor
					printYellow("]",true);
				}//end_



				// handle basic_string 
				template<class T>
				void handleList(const basic_string<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(wins(to_string(v[i])),true);
					}//endfor
					printYellow("]",true);
				}//end_

				// handle vector
				template<class T>
				void handleList(const vector<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(wins(to_string(v[i])),true);
					}//endfor
					printYellow("]",true);
				}//end_


				void handleList(const vector<string> &v){
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(65001); 
					#endif
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(wins(v[i]),true);
					}//endfor
					printYellow("]",true);
					#if defined _WIN32 || defined _WIN64
						SetConsoleOutputCP(950); 
					#endif
				}//end_


		} print;
};


#endif