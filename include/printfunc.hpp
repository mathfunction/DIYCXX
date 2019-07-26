
#ifndef __PRINTFUNC_HPP__
#define __PRINTFUNC_HPP__



namespace cxxuseful{
	using namespace std;
	using namespace cmdcolor;

	class PrintFunc{
			public:
				BoostAny operator()(basic_string<int> &v){printGreen("basic_string<int>",true); return handleList<int>(v);}
				BoostAny operator()(basic_string<double> &v){printGreen("basic_string<double>",true);return handleList<double>(v);}
				BoostAny operator()(vector<int> &v){printGreen("vector<int>",true);return handleList<int>(v);}
				BoostAny operator()(vector<double> &v){printGreen("vector<double>",true);return handleList<double>(v);}//end
				BoostAny operator()(vector<string> &v){printGreen("vector<string>",true);return handleList(v);}//end
				BoostAny operator()(unordered_map<string,string> &v){printGreen("unordered_map<string,string>",true);return handleDict(v);}//end
				BoostAny operator()(unordered_map<string,double> &v){printGreen("unordered_map<string,double>",true);return handleDict<string,double>(v);}//end
				BoostAny operator()(unordered_map<string,int> &v){printGreen("unordered_map<string,int>",true);return handleDict<string,int>(v);}//end
				BoostAny operator()(unordered_map<int,int> &v){printGreen("unordered_map<int,int>",true);return handleDict<int,int>(v);}//end
				BoostAny operator()(unordered_map<int,double> &v){printGreen("unordered_map<int,double>",true);return handleDict<int,double>(v);}//end
			private:

				template<class T,class S>
				BoostAny handleDict(unordered_map<T,S> &v){
					printYellow("{",true);
					for(auto &k:v){
						cerr << "\t" << k.first << " : " ;
						printYellow(to_string(k.second),true);
					}//endfor
					printYellow("}",true);
					return v;
				}//end_handleDict

				BoostAny handleDict(unordered_map<string,string> &v){
					printYellow("{",true);
					for(auto &k:v){
						cerr << "\t" << k.first << " : " ;
						printYellow(k.second,true);
					}//endfor
					printYellow("}",true);
					return v;
				}//end_


				// handle basic_string 
				template<class T>
				BoostAny handleList(basic_string<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end_

				// handle vector
				template<class T>
				BoostAny handleList(vector<T> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end_


				BoostAny handleList(vector<string> &v){
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(v[i],true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end_


		} print;
};


#endif