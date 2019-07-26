#ifndef __TODICTFUNC_HPP__
#define __TODICTFUNC_HPP__

#include<utility>
namespace cxxuseful{
	
	class ToDictFunc{
		
		public: 
			BoostAny operator()(const basic_string<int> &v){return handleList<int>(v);}
			BoostAny operator()(const basic_string<double> &v){return handleList<double>(v);}
			// cumulative 
			vector< pair<string,double> > cumulative(const unordered_map<string,double> &v){
				vector< pair<string,double> > _output;
				double _sum = 0.0;
				_output.push_back(make_pair("START",_sum));
				
				for(auto &k:v){
					if(k.second != 0.0){
						_sum += k.second;
						_output.push_back(make_pair(k.first,_sum));
					}//endif
				}//endfor
				
				return _output;
			}//end_cumulative
		private:
			template<typename T> BoostAny handleList(const basic_string<T> &v){
				unordered_map<int,T> _dict;
				for(int i=0;i<v.size();i++){
					_dict[i] = v[i];
				}//endfor
				return _dict;
			} 
	} todict;

};

#endif