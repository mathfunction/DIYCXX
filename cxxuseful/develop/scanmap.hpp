#ifndef __SCANMAP_HPP__
#define __SCANMAP_HPP__

#include <unordered_map>
#include <map>
#include "string_handle.hpp"


using namespace std;



namespace scanmap{
	template<class T> void counting(unordered_map<T,int> &_dict,T key){
		if(_dict.find(key)==_dict.end()){
			_dict[key] = 0;
		}//endif
		_dict[key] += 1;
	}//end_counting


	template<class T> void counting(map<T,int> &_dict,T key){
		if(_dict.find(key)==_dict.end()){
			_dict[key] = 0;
		}//endif
		_dict[key] += 1;
	}//end_counting


	template<class T,class S> unordered_map<S,T> inverse(unordered_map<T,S> &_dict,bool _boolPrint=false){
		unordered_map<S,T> output;
		typename unordered_map<T,S>::iterator it;
		for(it=_dict.begin();it!=_dict.end();++it){
			output[it->second] = it->first;
		}//endfor
		if(_boolPrint == true){
			string_handle::print(output);
		}//endif
		return output;
	}//end_inverse


};








#endif