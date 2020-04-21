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

		

		template<typename T>
		vector<pair<T,int> > make_conti(const vector<T> &v){
			vector<pair<T,int> > output;
			int tempIdx = 0;
			int numConnect;
			T tempVal = v[0];
			for(int i=1;i<v.size();i++){
				if(v[i] == tempVal){
					continue;
				}else{
					numConnect = (i-tempIdx);
					output.push_back(make_pair(tempVal,numConnect));
					// 更新暫存點 !!
					tempVal = v[i];
					tempIdx = i;
					// 置換空
				}//end_else
			}//endfor
			// tail handle 
			numConnect = v.size()-tempIdx;
			output.push_back(make_pair(tempVal,numConnect));
			return output;
		} 


		template<typename T>
		vector<T> join_conti(const vector<pair<T,int> > &v){
			vector<T> output;
			for(int i=0;i<v.size();i++){
				for(int j=0;j<v[i].second;j++){
					output.push_back(v[i].first);
				}//endfor
			}//endfor 
			return output;
		}//end_joinConsective





	} otherfc;

};

#endif