

#ifndef __PYTHONLIKE_HPP__
#define __PYTHONLIKE_HPP__
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>

namespace pythonlike{
	using namespace std;
	

	class Pystring :public string{
		private:
			Pystring& _str = (*this); 
			Pystring get(int i, int j){
				return substr(i, j-i);
			}//end_get
		public:
			// constructor
			Pystring(const char* str):string(str){}; 
			Pystring():string(){};                   
			Pystring(string str) :string(str) {};
			//-----------------------------------------------------------------------
			int toint(){
				return atoi(_str.c_str());
			}//end_toint
			double todbl(){
				return atof(_str.c_str());
			}
			
			Pystring strip(){
				int lidx = -1;
				int ridx = _str.size();
				for(int i=0;i<_str.size();i++){
					if(
						(_str[i]!='\n')&&
						(_str[i]!='\r')&&
						(_str[i]!='\t')&&
						(_str[i]!=' ')
					){
						lidx = i;
						break;
					}//endif
				}//endfor
				for(int i=_str.size()-1;i>-1;i--){
					if(
						(_str[i]!='\n')&&
						(_str[i]!='\r')&&
						(_str[i]!='\t')&&
						(_str[i]!=' ')
					){
						ridx = i;
						break;
					}//endif
				}//endfor
				return this->get(lidx,ridx+1);
			}//end_strip()
			vector<Pystring> split(Pystring delimiter=" ",bool _boolRemain=false){
				vector<Pystring> _output;
				// ngram scan
				int _dlen = delimiter.size();
				int _slen = _str.size();
				int _currentidx = 0;
				for(int i=0;i<_slen-_dlen+1;i++){
					if(_str.get(i,i+_dlen) == delimiter){
						_output.push_back(_str.get(_currentidx,i));
						if(_boolRemain == true){
							_output.push_back(_str.get(i,i+_dlen));
						}//endif
						_currentidx = i+_dlen;
					}//endif;	
				}//endfor
				_output.push_back(_str.get(_currentidx,_slen));
				return _output;
			}//end_split()
			//--------------------------------------------------------------------------
			vector<Pystring> splits(unordered_set<string> _setDelimiter,bool _boolRemain=false){
				vector<Pystring> _output;
				// ngram scan
				int _dlen = 1;
				int _slen = _str.size();
				int _currentidx = 0;
				for(int i=0;i<_slen-_dlen+1;i++){
					if(_setDelimiter.find(_str.get(i,i+_dlen)) != _setDelimiter.end()){
						_output.push_back(_str.get(_currentidx,i));
						if(_boolRemain == true){
							_output.push_back(_str.get(i,i+_dlen));
						}//endif
						_currentidx = i+_dlen;
					}//endif;	
				}//endfor
				_output.push_back(_str.get(_currentidx,_slen));
				return _output;
			}//end_splits

			Pystring join(vector<Pystring> _list){
				Pystring _output = "";
				int _llen = _list.size();
				for(int i=0;i<_llen;i++){
					_output += _list[i];
					if(i!=_llen-1){
						_output += _str;
					}//endif
				}//endfor

				return _output;
			}//end_join()

			
			Pystring join(basic_string<int> _list){
				Pystring _output = "";
				int _llen = _list.size();
				for(int i=0;i<_llen;i++){
					_output += to_string(_list[i]);
					if(i!=_llen-1){
						_output += _str;
					}//endif
				}//endfor
				return _output;
			}//end_join()

			
			unordered_map<int,char> dict(){
				unordered_map<int,char> _output;
				for(int i=0;i<_str.size();i++){
					_output[_output.size()] = _str[i];
				}//endfor
				return _output;
			}//end_dict

			unordered_map<char,basic_string<int> > invdict(){
				unordered_map<char,basic_string<int> > _output;
				for(int i=0;i<_str.size();i++){
					if(_output.find(_str[i]) == _output.end()){
						basic_string<int> temp;
						_output[_str[i]] = temp;
					}//endif
					_output[_str[i]] += i;
				}//endfor
				return _output;
			}//end_invdict


			//====================================================================
			// test code 
			//====================================================================
			void test(){
				cerr << _str.dict().size() << endl;
				cerr << _str.invdict().size() << endl;
				vector<Pystring> vec = _str.splits({":","{","["},true);
				vector<Pystring> vec2 = _str.split(",",true);
				for(int i=0;i<vec.size();i++){
					cerr <<  "["<< i << "] : " << vec[i] << endl;
				}//endfor
				cerr << Pystring("_").join(vec) << endl;
				cerr << Pystring("_").join(vec2) << endl;
			}//end_test



	};





};


#endif 


/*--------------------------------------------------------------
#include"pythonlike.hpp"

using namespace std;
using namespace pythonlike;

int main(){
	
	Pystring("152,652,64").test();
	
	return 0;
}//end_main


--------------------------------------------------------------*/