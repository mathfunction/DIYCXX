#ifndef __OTHERFUNC_HPP__
#define __OTHERFUNC_HPP__

namespace cxxuseful{
	using namespace std;
	class OtherFunc{
		public:
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


		// vector<string>  to  vector<int>
		vector<int> vec_s2i(const vector<string> &vs){
			vector<int> output;
			for(int i=0;i<vs.size();i++){
				output.push_back(stoi(vs[i]));
			}//endfor
			return output;
		}//end_vec_s2i

		

	} otherfc;

};

#endif