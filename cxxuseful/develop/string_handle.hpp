#ifndef __STRING_HANDLE_HPP__
#define __STRING_HANDLE_HPP__


#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include "cxxcolor.hpp"

using namespace std;
using namespace cxxcolor;

namespace string_handle{
	//--------------------------------------------------------------------------
	template<class T> string to_string(T num);
	pair<string,unordered_map<int,int> > neg_symbols(string _str,unordered_set<char> &_symbols);
	string inv_neg_symbols(string _str,string _strCompress,unordered_map<int,int> &dict);
	vector<string> split(string _str,char symbol='_',bool _boolPrint=false);
	template<class T> string invsplit(vector<T> &vec,char symbol='_',bool _boolPrint=false);
	
	//makestr
	string makestr(string name,int index1,char symbol='_');
	string makestr(string name,int index1,int index2,char symbol='_');
	string makestr(int index1,int index2,char symbol='_');
	string makestr(int index1,int index2,int index3, char symbol='_');
	string makestr(string tail,string head,char symbol='_');
	template<class T> string makestr(unordered_map<T,unordered_set<int> > &dictPos,bool _boolPrint=false);
	template<class T> string makestr(unordered_map<int,T> &dictInvPos,bool _boolPrint=false);
	template<class T> string makestr(vector<T> &vec);


	//print
	string newline(string center,char sym='_',bool _boolPrint=true);
	template<class T> void print(vector<T> &vec);
	template<class T> void print(unordered_set<T> &set1);
	template<class T,class S> void print(unordered_map<T,S> &dict);
	template<class T> void print(set<T> &set1);
	template<class T> void print(T **A,int m,int n);
	template<class T> void print(T *x,int n);
	template<class T,class S> void print(unordered_map<T,unordered_set<S> > &dependset);
	template<class T,class S> void print(unordered_map<T,set<S> > &dependset);
	template<class T,class S> void print(unordered_map<T,vector<S> > &dependvec);
	// {,,,,}
	unordered_set<string> hashset(string str,bool _boolPrint=false);
	// [,,,,]
	vector<string> list(string str,bool _boolPrint=false);
	vector<int>    intlist(string str,bool _boolPrint=false);
	template<class T> vector<T> list(set<T> &set1,bool _boolPrint=false); 
	set<string> orderedset(string str,bool _boolPrint=false);
	template<class T> set<T> orderedset(vector<T> &vec,bool _boolPrint=false);

	
	template<class T> unordered_set<T> hashset(vector<T> &vec,bool _boolPrint=false);
	// dictCount
	template<class T> unordered_map<T,int> dictCount(vector<T> &vec,bool _boolPrint=false);
	unordered_map<char,int> dictCount(string str,bool _boolPrint=false);
	// dictRatio
	template<class T> unordered_map<T,double> dictRatio(vector<T> &vec,bool _boolPrint=false);
	unordered_map<char,double> dictRatio(string str,bool _boolPrint=false);
	// dictPos
	template<class T> unordered_map<T,unordered_set<int> > dictPos(vector<T> &vec,bool _boolPrint=false);
	unordered_map<char,unordered_set<int> > dictPos(string str,bool _boolPrint=false);
	// dictInvPos
	template<class T> unordered_map<int,T> dictInvPos(vector<T> &vec,bool _boolPrint=false);
	unordered_map<int,char> dictInvPos(string str,bool _boolPrint=false);
	
	// ngram
	vector<string> ngram(vector<string> &vec,int n=2,bool _boolPrint=false);
	vector<string> ngram(string str,int n=2,bool _boolPrint=false);
	
	// ordered ngram 
	vector<string> orderedset_ngram(vector<string> &vec,int n=2,bool _boolPrint=false);
	vector<string> orderedset_ngram(string str,int n=2,bool _boolPrint=false);


	// ordered_element  (each element is set !!)
	template<class T> vector<string> strVec(vector<T> &vec,bool _boolPrint=false); 
	vector<int> intVec(vector<string> &vec,bool _boolPrint=false);
	vector<double> dblVec(vector<string> &vec,bool _boolPrint=false);
	
	// some useful handle 
	int toint(string str);


	// pair 
	template<class T> pair<unordered_map<T,int>,unordered_map<int,T> > give_id_dicts(vector<T> &vec,bool _boolPrint=false);
	// identity_map
	template<class T> unordered_map<T,T>  IdentityMap(unordered_set<T> &set1,bool _boolPrint=false);
	template<class T> unordered_map<T,T>  IdentityMap(set<T> &set1,bool _boolPrint=false);

	template<class T,class S>  unordered_map<S,unordered_set<T> > ValueCollection(unordered_map<T,S> &_dict,bool _boolPrint=false);
	template<class T,class S>  unordered_map<S,set<T> > ValueOrderedCollection(unordered_map<T,S> &_dict,bool _boolPrint=false);

}//end_namespace


//_________________________________________________________________________________________________________________



string string_handle::makestr(string tail,string head,char symbol){
	stringstream ss;
	ss << tail << symbol << head;
	return ss.str();
}//end_makestr





template<class T> unordered_map<T,T>  string_handle::IdentityMap(set<T> &set1,bool _boolPrint){
	unordered_map<T,T> output;
	typename set<T>::iterator it;
	for(it=set1.begin();it!=set1.end();++it){
		output[*it] = (*it);
	}//endfor
	if(_boolPrint==true){
		print(output);
	}//endif
	return output;
}//end_IdentityMap





template<class T> unordered_map<T,T>  string_handle::IdentityMap(unordered_set<T> &set1,bool _boolPrint){
	unordered_map<T,T> output;
	typename unordered_set<T>::iterator it;
	for(it=set1.begin();it!=set1.end();++it){
		output[*it] = (*it);
	}//endfor
	if(_boolPrint==true){
		print(output);
	}//endif
	return output;
}//end_IdentityMap





template<class T,class S>  unordered_map<S,unordered_set<T> > string_handle::ValueCollection(unordered_map<T,S> &_dict,bool _boolPrint){
	typename unordered_map<T,S>::iterator it;
	unordered_map<S,unordered_set<T> > output;
	for(it=_dict.begin();it!=_dict.end();++it){
		output[it->second].insert(it->first);
	}//endfor
	if(_boolPrint==true){
		print(output);
	}//endif
	return output;
}//end_ValueCollections





template<class T,class S>  unordered_map<S,set<T> > string_handle::ValueOrderedCollection(unordered_map<T,S> &_dict,bool _boolPrint){
	typename unordered_map<T,S>::iterator it;
	unordered_map<S,set<T> > output;
	for(it=_dict.begin();it!=_dict.end();++it){
		output[it->second].insert(it->first);
	}//endfor
	if(_boolPrint==true){
		print(output);
	}//endif
	return output;
}//end_ValueCollections









template<class T> pair<unordered_map<T,int>,unordered_map<int,T> > string_handle::give_id_dicts(vector<T> &vec,bool _boolPrint){
	pair<unordered_map<T,int>,unordered_map<int,T> > output;
	for(int i=0;i<vec.size();i++){
		(output.first)[vec[i]] = i;
		(output.second)[i] = vec[i];
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output.first);
		string_handle::print(output.second);
	}//endif
	return output;
}//end_reorder_dicts















vector<int> string_handle::intlist(string str,bool _boolPrint){
	vector<string> temp = list(str);
	return intVec(temp,_boolPrint);
}//end_string_handle






int string_handle::toint(string str){
	return atoi(str.c_str());
}//end_toint


vector<string> string_handle::orderedset_ngram(vector<string> &vec,int n,bool _boolPrint){
	vector<string> output;
	for(int i=0;i<vec.size()-n;i++){
		set<string> tempSet;
		for(int j=0;j<n;j++){
			tempSet.insert(vec[i+j]); 
		}//endfor
		// scan the set 
		string temp = "";
		for(set<string>::iterator it=tempSet.begin();it!=tempSet.end();++it){
			temp += (*it);
		}//endfor
		output.push_back(temp);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_ngram



vector<string> string_handle::orderedset_ngram(string str,int n,bool _boolPrint){
	vector<string> output;
	for(int i=0;i<str.size()-n;i++){
		set<char> tempSet;
		for(int j=0;j<n;j++){
			tempSet.insert(str[i+j]); 
		}//endfor
		string temp = "";
		for(set<char>::iterator it=tempSet.begin();it!=tempSet.end();++it){
			temp += (*it); 
		}
		output.push_back(temp);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_ngram












template<class T> vector<string> string_handle::strVec(vector<T> &vec,bool _boolPrint){
	vector<string> output;
	for(int i=0;i<vec.size();i++){
		stringstream ss;
		ss << vec[i];
		output.push_back(ss.str());
	}//endfor
	if(_boolPrint == true) string_handle::print(output);
	return output;
}//end_strVec



vector<int> string_handle::intVec(vector<string> &vec,bool _boolPrint){
	vector<int> output;
	for(int i=0;i<vec.size();i++){
		output.push_back(atoi(vec[i].c_str()));
	}//endfor
	if(_boolPrint == true) string_handle::print(output);
	return output;
}//end_intVec


vector<double> string_handle::dblVec(vector<string> &vec,bool _boolPrint){
	vector<double> output;
	for(int i=0;i<vec.size();i++){
		output.push_back(atof(vec[i].c_str()));
	}//endfor
	if(_boolPrint == true) string_handle::print(output);
	return output;
}//end_dblVec












template<class T> string string_handle::makestr(unordered_map<int,T> &dictInvPos,bool _boolPrint){
	string output = "";
	typename unordered_map<int,T >::iterator it;
	for(int i=0;i<dictInvPos.size();i++){
		output += dictInvPos[i]; 
	}//endfor
	if(_boolPrint == true) cout << "makestr = " << output << endl;
	return output;
}//end_makestr



template<class T>
string string_handle::makestr(vector<T> &vec){
	stringstream ss;
	for(int i=0;i<vec.size();i++){
		ss << vec[i];
	}//endfor
	return ss.str();
}//end_makestr






template<class T> 
string string_handle::makestr(unordered_map<T,unordered_set<int> > &dictPos,bool _boolPrint){
	typename unordered_map<T,unordered_set<int> >::iterator it; 
	// compute total size 
	int vecsize = 0;
	for(it=dictPos.begin();it!=dictPos.end();++it){
		vecsize += (it->second).size();
	}//endfor	
	vector<string> temp;
	temp.resize(vecsize);
	for(it=dictPos.begin();it!=dictPos.end();++it){
		for(unordered_set<int>::iterator jt=(it->second).begin();jt!=(it->second).end();++jt){
			temp[*jt] = it->first;
		}//endfor
	}//endfor	
	string output = string_handle::makestr(temp);
	if(_boolPrint == true) cout << "makestr = " << output << endl;
	return output;
}






vector<string> string_handle::ngram(string str,int n,bool _boolPrint){
	vector<string> output;
	for(int i=0;i<str.size()-n;i++){
		string temp = "";
		for(int j=0;j<n;j++){
			temp += str[i+j]; 
		}//endfor
		output.push_back(temp);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_ngram




unordered_map<int,char> string_handle::dictInvPos(string str,bool _boolPrint){
	unordered_map<int,char> output;
	for(int i=0;i<str.size();i++){
		output[i] = str[i];
	}//endfor
	if(_boolPrint== true){
		string_handle::print(output);
	}//endif
	return output;
}//dictInvPos



unordered_map<char,unordered_set<int> > string_handle::dictPos(string str,bool _boolPrint){
	unordered_map<char,unordered_set<int> > output;
	for(int i=0;i<str.size();i++){
		output[str[i]].insert(i);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dictPos





unordered_map<char,double> string_handle::dictRatio(string str,bool _boolPrint){
	unordered_map<char,double> output;
	double totalsize = (double)str.size();
	for(int i=0;i<str.size();i++){
		if(output.find(str[i]) == output.end()){
			output[str[i]] = 0.0;
		}//endif
		output[str[i]] += 1.0;
	}//endfor
	unordered_map<char,double>::iterator it;
	for(it=output.begin();it!=output.end();++it){
		(it->second) /= totalsize;
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dict





unordered_map<char,int> string_handle::dictCount(string str,bool _boolPrint){
	unordered_map<char,int> output;
	for(int i=0;i<str.size();i++){
		if(output.find(str[i]) == output.end()){
			output[str[i]] = 0;
		}
		output[str[i]] += 1;
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dictCount







vector<string> string_handle::ngram(vector<string> &vec,int n,bool _boolPrint){
	vector<string> output;
	for(int i=0;i<vec.size()-n;i++){
		string temp = "";
		for(int j=0;j<n;j++){
			temp += vec[i+j]; 
		}//endfor
		output.push_back(temp);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_ngram







template<class T>
unordered_map<int,T> string_handle::dictInvPos(vector<T> &vec,bool _boolPrint){
	unordered_map<int,T> output;
	for(int i=0;i<vec.size();i++){
		output[i] = vec[i];
	}//endfor
	if(_boolPrint== true){
		string_handle::print(output);
	}//endif
	return output;
}//dictInvPos






template<class T> 
set<T> string_handle::orderedset(vector<T> &vec,bool _boolPrint){
	set<T> output;
	for(int i=0;i<vec.size();i++){
		output.insert(vec[i]);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}






string string_handle::newline(string center,char sym,bool _boolPrint){
	string buffer = "\n";
	for(int i=0;i<10;i++) buffer += sym;
	buffer += "[  "+ center +"  ]";
	for(int i=0;i<10;i++) buffer += sym;
	if(_boolPrint == true){
		cout << buffer << endl;
	}//endif
	return buffer;
}






template<class T> 
unordered_map<T,unordered_set<int> > string_handle::dictPos(vector<T> &vec,bool _boolPrint){
	unordered_map<T,unordered_set<int> > output;
	for(int i=0;i<vec.size();i++){
		output[vec[i]].insert(i);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dictPos






template<class T,class S>
void string_handle::print(unordered_map<T,vector<S> > &dependvec){
	typename unordered_map<T,vector<S> >::iterator it;
	string_handle::newline("dependvec",'-');
	for(it=dependvec.begin();it!=dependvec.end();++it){
		cout << "key : " <<  it->first << " value : ";
		string_handle::print(it->second);
	}//endfor
}//end_print



template<class T,class S>
void string_handle::print(unordered_map<T,set<S> > &dependset){
	typename unordered_map<T,set<S> >::iterator it;
	string_handle::newline("dependset",'-');
	for(it=dependset.begin();it!=dependset.end();++it){
		cout << "key : " <<  it->first << " value : ";
		string_handle::print(it->second);
	}//endfor
}//end_print





template<class T,class S>
void string_handle::print(unordered_map<T,unordered_set<S> > &dependset){
	typename unordered_map<T,unordered_set<S> >::iterator it;
	string_handle::newline("dependset",'-');
	for(it=dependset.begin();it!=dependset.end();++it){
		cout << "key : " <<  it->first << " value : ";
		string_handle::print(it->second);
	}//endfor
}//end_print


template<class T,class S> 
void string_handle::print(unordered_map<T,S> &dict){
	typename unordered_map<T,S>::iterator it;
	string_handle::newline("dict",'-');
	for(it=dict.begin();it!=dict.end();++it){
		stringstream ss;
		ss << "key : " <<  it->first <<  " value : "  << it->second;
		printBlueGreen(ss.str(),true);
	}//endfor	
}//end_print




template<class T> 
unordered_map<T,int> string_handle::dictCount(vector<T> &vec,bool _boolPrint){
	unordered_map<T,int> output;
	for(int i=0;i<vec.size();i++){
		if(output.find(vec[i]) == output.end()){
			output[vec[i]] = 0;
		}
		output[vec[i]] += 1;
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dict





template<class T> 
unordered_map<T,double> string_handle::dictRatio(vector<T> &vec,bool _boolPrint){
	unordered_map<T,double> output;
	double totalsize = (double)vec.size();
	for(int i=0;i<vec.size();i++){
		if(output.find(vec[i]) == output.end()){
			output[vec[i]] = 0.0;
		}//endif
		output[vec[i]] += 1.0;
	}//endfor
	typename unordered_map<T,double>::iterator it;
	for(it=output.begin();it!=output.end();++it){
		(it->second) /= totalsize;
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_dict






template<class T> 
unordered_set<T> string_handle::hashset(vector<T> &vec,bool _boolPrint){
	unordered_set<T> output;
	for(int i=0;i<vec.size();i++){
		output.insert(vec[i]);
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_hashset






template<class T> 
vector<T> string_handle::list(set<T> &set1,bool _boolPrint){
	vector<T> output;
	typename set<T>::iterator it;
	for(it=set1.begin();it!=set1.end();++it){
		output.push_back(*it);
	}//endfor
	if(_boolPrint==true){
		string_handle::print(output);
	}//endif
	return output;
}






//makestr
string string_handle::makestr(string name,int index1,char symbol){
	stringstream ss;
	ss << name << symbol << index1 ;
	return ss.str();
}//end_make_string

string string_handle::makestr(string name,int index1,int index2,char symbol){
	stringstream ss;
	ss << name << symbol << index1 << symbol << index2 ;
	return ss.str();
}//end_make_string



string string_handle::makestr(int index1,int index2,char symbol){
	stringstream ss;
	ss << index1 << symbol << index2 ;
	return ss.str();
}//end_make_string


string string_handle::makestr(int index1,int index2,int index3, char symbol){
	stringstream ss;
	ss << index1 << symbol << index2 << symbol << index3;
	return ss.str();
}//end_make_string






vector<string> string_handle::split(string _str,char symbol,bool _boolPrint){
	vector<string> output;
	stringstream ss;
	ss << _str;
	string temp;
	while(getline(ss,temp,symbol)){
		output.push_back(temp);
	}//end_while
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif
	return output;
}//end_split



template<class T>
string string_handle::invsplit(vector<T> &vec,char symbol,bool _boolPrint){
	stringstream ss;
	for(int i=0;i<vec.size();i++){
		ss << vec[i] ;
		if(i!=vec.size()-1){
			ss << symbol;
		}//endif
	}//endfor
	if(_boolPrint == true){
		cout << "invsplit: " << ss.str() << endl;
	}//endif
	return ss.str();
}//end_invsplit




pair<string,unordered_map<int,int> > string_handle::neg_symbols(string _str,unordered_set<char> &_symbols){
	// _dict : newindex ----> oldindex 
	unordered_map<int,int> _dict;
	string _strCompress = ""; 
	int count = 0;
	for(int i=0;i<_str.size();i++){
		if(_symbols.find(_str[i])==_symbols.end()){
			_dict[count] = i;
			count +=1;
			_strCompress += _str[i];
		}//endif
	}//endfor
	return make_pair(_strCompress,_dict);
}//end_fuyuan_string_handle::neg_symbols


string string_handle::inv_neg_symbols(string _str,string _strCompress,unordered_map<int,int> &_dict){
	for(int i=0;i<_strCompress.size();i++){
		_str[_dict[i]] = _strCompress[i];
	}//endfor
	string _strRecover = "";
	for(int i=0;i<_str.size();i++){
		_strRecover += _str[i];
	}//endfor
	return _strRecover;
}//end_fuyuan_string_handle::neg_symbols






template<class T>
string string_handle::to_string(T num){
	stringstream ss;
	ss << num ;
	return ss.str();
}//end_to_string






//=========================================================================================
//print








template<typename T>
void string_handle::print(vector<T> &vec){
	cout << "list = [";
	for(int i=0;i<vec.size();i++){
		printYellow(string_handle::to_string<T>(vec[i]));
		if(i!= (vec.size()-1)) cout << ",";
	}//endfor
	cout << "]" << endl; 	
}

template<typename T>
void string_handle::print(unordered_set<T> &set1){
	typename unordered_set<T>::iterator it;
	cout << "hashset = {";
	for(it=set1.begin();it!=set1.end();++it){
		printYellow(string_handle::to_string<T>(*it));
		cout << ",";
	}//endfor
	cout << "\b}" << endl;
}



template<typename T>
void string_handle::print(set<T> &set1){
	typename set<T>::iterator it;
	cout << "orderedset = {";
	for(it=set1.begin();it!=set1.end();++it){
		printYellow(string_handle::to_string<T>(*it));
		cout << ",";
	}//endfor
	cout << "\b}" << endl;
}





template<class T>
void string_handle::print(T **A,int m,int n){
	newline("Mat2D(Pointer of Pointer)",'-');
	for(int i=0;i<m;i++){
		cout << "(";
		for(int j=0;j<n;j++){
			printGreen(string_handle::to_string<T>(A[i][j]));
			if(j!= (n-1)) cout << ",";
		}//endfor
		cout << ")" << endl; 
	}//endfor

}//end_fuyuan_string_handle


template<class T>
void string_handle::print(T *x,int n){
	cout << "tuple = (";
	for(int i=0;i<n;i++){
		printYellow(string_handle::to_string<T>(x[i]));
		if(i!= (n-1)) cout << ",";
	}//endfor
	cout << ")" << endl;  
}//end_fuyuan_string_handle


//=======================================================================================



set<string> string_handle::orderedset(string str,bool _boolPrint){
	set<string> output;
	string buffer = "";
	int level = 0;
	//scan all string
	for(int i=0;i<str.size();i++){
		if(str[i] == '{'){
				level +=1;
		}else if(str[i]=='}'){ 
			output.insert(buffer);
			buffer = "";
			level -=1;
			break;
		}else if(str[i]==','){
			if(buffer != ""){
				output.insert(buffer);
			}
			buffer = "";
		}else{
			if(level > 0 && str[i]!=' '){
				buffer += str[i];
			}//end_if
		}
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif 

	return output;

}//end_function








unordered_set<string> string_handle::hashset(string str,bool _boolPrint){
	unordered_set<string> output;
	string buffer = "";
	int level = 0;
	//scan all string
	for(int i=0;i<str.size();i++){
		if(str[i] == '{'){
				level +=1;
		}else if(str[i]=='}'){ 
			output.insert(buffer);
			buffer = "";
			level -=1;
			break;
		}else if(str[i]==','){
			if(buffer != ""){
				output.insert(buffer);
			}
			buffer = "";
		}else{
			if(level > 0 && str[i]!=' '){
				buffer += str[i];
			}//end_if
		}
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif 

	return output;

}//end_function



vector<string> string_handle::list(string str,bool _boolPrint){
	vector<string> output;
	string buffer = "";
	int level = 0;
	//scan all string
	for(int i=0;i<str.size();i++){
		if(str[i] == '['){
			level +=1;
		}else if(str[i]==']'){ 
			output.push_back(buffer);
			buffer = "";
			level -=1;
			break;
		}else if(str[i]==','){
			output.push_back(buffer);
			buffer = "";
		}else{
			if(level > 0 && str[i]!=' '){
				buffer += str[i];
			}//end_if
		}
	}//endfor
	if(_boolPrint == true){
		string_handle::print(output);
	}//endif 


	return output;
}//end_function
//---------------------------------------------------------------------------------------------------------------------------

#endif






/* testcode 


//-------------------------------------------------------------------------
//
//command line :
//	g++ -std=c++11 -o test test.cpp -I.
//
//--------------------------------------------------------------------------




#include <iostream>
#include "string_handle.hpp"
using namespace string_handle;


using namespace std;

int main(){

	//----------------------------------------------------------------------
	// print 
	newline("print");
	double x[7]={1,3,-1,3.4,-999,789,1000};
	print(x,7); 

	double **a = new double* [2];
	for(int i=0;i<2;i++){
		a[i] = new double [2];
		for(int j=0;j<2;j++){
			a[i][j] = (double)(i+j+1);
		}//endfor
	}//endfor
	print(a,2,2);
	//------------------------------------------------------------------------
	
	newline("make string");
	// makestr 
	cout << makestr("X",1,3) << endl;
	cout << makestr("Y",1) << endl;
	cout << makestr(1,2,3) << endl;
	cout << makestr(3,4) << endl;



	//----------------------------------------------------------------------
	newline("read str");

	vector<string> vec1 = list("[1,2,3,4,5,6,8,8,8,8,8,8,10]",true);
	ngram(vec1,2,true);
	ngram(vec1,3,true);

	dictCount(vec1,true);
	dictRatio(vec1,true);
	dictPos(vec1,true);
	dictInvPos(vec1,true);
	orderedset(vec1,true);
	unordered_set<string> set1 = hashset("{1,2,3,3,4,5,6,7,8,9}",true);
	set<string> set2 = orderedset("{A,B,A,B,CDER,4,EE}",true);
	vec1 = list(set2,true);
	hashset(vec1,true);

	//--------------------------------------------------------------------------
	//split 
	newline("split");
	vector<string>  vec2 = split("1_2_3_3_5_6",'_',true);
	invsplit(vec2,'|',true);


	//----------------------------------------------------------------------
	// neglect symbols 
	newline("neg_symbols");

	unordered_set<char> symbols({',','_'});
	string _str = "a,b,c,d,,gggg_k_k_";
	string _strCompress = neg_symbols(_str,symbols).first;
	unordered_map<int,int> _dict = neg_symbols(_str,symbols).second;
	cout << "=============================================" << endl;
	cout << "Origin : " << _str << endl;
	cout << "Neglect : " <<  _strCompress << endl;
	cout << "Recover : " << inv_neg_symbols(_str,_strCompress,_dict) << endl;
	cout << "=============================================" << endl;

	newline("string information");
	string signal = "AAAABCDEACDEFNNFGBNNNDFKGJKBNCABC";
	ngram(signal,4,true);
	ngram(signal,3,true);
	orderedset_ngram(signal,3,true);
	dictCount(signal,true);
	dictRatio(signal,true);
	unordered_map<char,unordered_set<int> >_dictPos = dictPos(signal,true);
	unordered_map<int,char> _dictInvPos = dictInvPos(signal,true);
	makestr(_dictPos,true);
	makestr(_dictInvPos,true);
	
	vector<string> temp2 = list("[1.89,2.78,3.43,4.19,5.19,6.11,7,8,9]");
	intVec(temp2,true);
	dblVec(temp2,true);





	return 0;
}//end_main


*/
