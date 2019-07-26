/*---------------------------------------------------------------------------------------------

	Author:	Plus & Minus 
	#	Last update:	2018/03/23
	#   Version: C++ 11 
	#
	#	This is C++ class Source " Natural_Dual_Correspondence " 
	#	The formal mathematical operations , check the Natural_Dual_Correspondence.pdf for detail 
	#   The Main Data Structure is unordered_map<T1,unordered_set<T2>
	#   To test this head file , you can compile and run "test_Natural_Dual_Correspondence_Source.cpp"

	Note: Source , API must be in the same folder 
----------------------------------------------------------------------------------------------*/
#ifndef __NATURAL_DUAL_CORRESPONDENCE_SOURCE_HPP__
#define __NATURAL_DUAL_CORRESPONDENCE_SOURCE_HPP__
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace Natural_Dual_Correspondence_Source{


template<typename T1,typename T2>
void addElement(unordered_map<T1,unordered_set<T2> > &_dict,T1 i,T2 j){
	if(_dict.find(i)==_dict.end()){
		unordered_set<T2> newset;
		_dict[i] = newset;
	}
	_dict[i].insert(j);
}//end_add_element


template<typename T1,typename T2>
void printElement(unordered_map<T1,unordered_set<T2> > &_dict){
	typename unordered_map<T1,unordered_set<T2> >::iterator it;
	typename unordered_set<T2>::iterator jt;
	for(it=_dict.begin();it!=_dict.end();++it){
		for(jt=_dict[it->first].begin();jt!=_dict[it->first].end();++jt){
			cout << "key = " << it->first << " value = " << *jt << endl;
		}//endfor
	}//endfor
}//end_print_element



template<typename T1,typename T2>
unordered_map<T2,unordered_set<T1> > DualCorrespondence(unordered_map<T1,unordered_set<T2> > &_dictPrimal){
	unordered_map<T2,unordered_set<T1> > _dictDual;
	typename unordered_map<T1,unordered_set<T2> >::iterator it;
	typename unordered_set<T2>::iterator jt;
	for(it=_dictPrimal.begin();it!=_dictPrimal.end();++it){
		for(jt=_dictPrimal[it->first].begin();jt!=_dictPrimal[it->first].end();++jt){
			if(_dictDual.find(*jt)==_dictDual.end()){
				unordered_set<T1> newset;
				_dictDual[*jt] = newset;
			}//endif
			_dictDual[*jt].insert(it->first);
		}//endfor
	}//endfor
	return _dictDual;
}//endDualCorrespondence








};

#endif





/*---------------------------------------------------------------------------------------------
	#include "Natural_Dual_Correspondence_Source.hpp"
	using namespace Natural_Dual_Correspondence_Source;

	int main(){
		
		unordered_map<int,unordered_set<int> > _dictPrimal;
		addElement<int,int>(_dictPrimal,1,2);
		addElement<int,int>(_dictPrimal,1,3);
		addElement<int,int>(_dictPrimal,2,4);
		addElement<int,int>(_dictPrimal,3,4);
		addElement<int,int>(_dictPrimal,4,5);
		addElement<int,int>(_dictPrimal,4,6);
		cout << "Primal: " << endl;
		printElement<int,int>(_dictPrimal);
		cout << "Dual:" << endl;
		unordered_map<int,unordered_set<int> > _dictDual = DualCorrespondence(_dictPrimal);
		printElement<int,int>(_dictDual);


		return 0;
	}//end_main 

--------------------------------------------------------------------------------------------*/








