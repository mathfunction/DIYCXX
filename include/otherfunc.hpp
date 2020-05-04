#ifndef __OTHERFUNC_HPP__
#define __OTHERFUNC_HPP__

namespace cxxuseful{
	class OtherFunc{
		public:
		// cumulative 
		std::vector< std::pair<std::string,double> > cumulative(const std::unordered_map<std::string,double> &v){
			std::vector< std::pair<std::string,double> > _output;
			double _sum = 0.0;
			_output.push_back(std::make_pair("START",_sum));
						
			for(auto &k:v){
				if(k.second != 0.0){
					_sum += k.second;
					_output.push_back(std::make_pair(k.first,_sum));
				}//endif
			}//endfor
						
			return _output;
		}//end_cumulative


		// std::vector<std::string>  to  std::vector<int>
		std::vector<int> vec_s2i(const std::vector<std::string> &vs){
			std::vector<int> output;
			for(int i=0;i<vs.size();i++){
				output.push_back(stoi(vs[i]));
			}//endfor
			return output;
		}//end_vec_s2i

		

		template<typename T>
		std::vector<std::pair<T,int> > make_conti(const std::vector<T> &v){
			std::vector<std::pair<T,int> > output;
			int tempIdx = 0;
			int numConnect;
			T tempVal = v[0];
			for(int i=1;i<v.size();i++){
				if(v[i] == tempVal){
					continue;
				}else{
					numConnect = (i-tempIdx);
					output.push_back(std::make_pair(tempVal,numConnect));
					// 更新暫存點 !!
					tempVal = v[i];
					tempIdx = i;
					// 置換空
				}//end_else
			}//endfor
			// tail handle 
			numConnect = v.size()-tempIdx;
			output.push_back(std::make_pair(tempVal,numConnect));
			return output;
		} 


		template<typename T>
		std::vector<T> join_conti(const std::vector<std::pair<T,int> > &v){
			std::vector<T> output;
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