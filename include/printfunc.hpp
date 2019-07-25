
#ifndef __PRINTFUNC_HPP__
#define __PRINTFUNC_HPP__
#include "typefunc.hpp"


namespace typefunc{
	class PrintFunc:public Base{
			public:
				
				BoostAny operator()(basic_string<int> &v){
					printGreen("basic_string<int>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end

				BoostAny operator()(basic_string<double> &v){
					printGreen("basic_string<double>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end

				BoostAny operator()(vector<int> &v){
					printGreen("vector<int>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end

				BoostAny operator()(vector<double> &v){
					printGreen("vector<double>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(to_string(v[i]),true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end

				BoostAny operator()(vector<string> &v){
					printGreen("vector<string>",true);
					printYellow("[",true);
					for(int i=0;i<v.size();i++){
						cerr << "\t" << i << " : " ;
						printYellow(v[i],true);
					}//endfor
					printYellow("]",true);
					return v;
				}//end

		} print;
};


#endif