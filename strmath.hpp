#ifndef __STRMATH_HPP__
#define __STRMATH_HPP__


#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <utility>
#include <algorithm> 
#include "charmath.hpp"

namespace strmath{
	using namespace std;
	using namespace charmath;
	
	

	class Numstring:public string{
		private:
			Numstring& _str = (*this); 
			Numstring get(int i, int j){
				return substr(i, j-i);
			}//end_get
		public:
			// constructor
			Numstring(const char* str):string(str){}; 
			Numstring():string(){};                   
			Numstring(string str) :string(str) {};


			Numstring& addZero(int n=0,char option='l'){
				if(option == 'l'){
					_str.insert(0,string(n,'0'));
					return _str;
				}else{
					_str.append(string(n,'0'));
					return _str;
				}//end_else
			}//end_addzero

			Numstring& addDot(){
				if(_str.find('.') == -1){
					_str.append(".0");
				}else if(_str[_str.size()-1] == '.'){
					_str.append("0");
				}else{
				}
				return _str;
			}//end_addot
			/*
			Numstring strip(){
				int lidx = -1;
				int ridx = _str.size();
				for(int i=0;i<_str.size();i++){
					if(
						_str[i]!='0'
					){
						lidx = i;
						break;
					}//endif
				}//endfor
				for(int i=_str.size()-1;i>-1;i--){
					if(
						_str[i]!='0'
					){
						ridx = i;
						break;
					}//endif
				}//endfor
				
				return this->get(lidx,ridx+1);
			}//end_strip()
			*/
			pair<int,int> scale(bool _boolPrint=false){
				int idx = _str.find('.');
				// simple integers 
				if(idx == -1){
					if (_boolPrint){
						cerr << _str.size() << "," << 0 << endl;
					}//endif
					return make_pair(_str.size(),0);
				}else{
					if (_boolPrint){
						cerr << idx << "," << _str.size()-idx-1 << endl;
					}//endif
					return make_pair(idx,_str.size()-idx-1);
				}//end_else
			}//end_Scale


	};
	int reshape(Numstring &_str1,Numstring &_str2,bool _boolPrint=false){
		//======================================================
		// addDot
		if(_str1.find('.')==-1)
			if(_str2.find('.')!=-1)
				_str1.addDot();
		if(_str1.find('.')!=-1)
			if(_str2.find('.')==-1)
				_str2.addDot();
		//=========================================================
		pair<int,int> s1 = _str1.scale();
		pair<int,int> s2 = _str2.scale();
		
		int s3_1 = 1+max(s1.first,s2.first);
		int s3_2 = max(s1.second,s2.second);	
		int idx = s3_1;

		_str1.addZero(s3_1-s1.first,'l').addZero(s3_2-s1.second,'r'); 
		_str2.addZero(s3_1-s2.first,'l').addZero(s3_2-s2.second,'r');
		if(_boolPrint == true){
			cerr << _str1 << endl;
			cerr << _str2 << endl;
			cerr << ". at " << idx << endl;
		}//endif
		return idx;
	}//end_reshape

	Numstring operator+(Numstring &_str1,Numstring &_str2){
		Numstring _result = "";
		int idxDot = reshape(_str1,_str2);
		int n = _str1.size();
		pair<char,char> _temp1;
		pair<char,char> _temp2;
		char carrier = '0';
		if(idxDot < n){
			for(int i=n-1;i>idxDot;i--){
				_temp1 = PLUSTABLE(_str1[i],_str2[i]);
				_temp2 = PLUSTABLE(_temp1.second,carrier);
				_result += _temp2.second;
				carrier = PLUSTABLE(_temp1.first,_temp2.first).second;
			}//endfor
			_result += ".";
		}//endif
		//cerr << "." ;
		for(int i=idxDot-1;i>-1;i--){
			_temp1 = PLUSTABLE(_str1[i],_str2[i]);
			_temp2 = PLUSTABLE(_temp1.second,carrier);
			_result += _temp2.second;
			carrier = PLUSTABLE(_temp1.first,_temp2.first).second;
		}//endfor 
		reverse(_result.begin(),_result.end());
		return _result; 
	}//end_Numstring

	/*
	Numstring operator-(Numstring _str1,Numstring _str2){
		return Numstring("0");
	}//end_Numstring

	Numstring operator*(Numstring _str1,Numstring _str2){
		return Numstring("1");
	}//end_Numstring

	Numstring operator/(Numstring _str1,Numstring _str2){
		return Numstring("0");
	}//end_Numstring
	*/






















};

	


#endif