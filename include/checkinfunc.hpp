#ifndef __CHECKINFUNC_HPP__ 
#define __CHECKINFUNC_HPP__



namespace cxxuseful{
	
	class CheckInFunc{
		public:
			// check_elements_in std::vector<T>
			template<class T> 
			int operator()(const std::vector<T>&v,const T &e){
				int idx = distance(v.begin(),find(v.begin(),v.end(),e));
				if (idx == v.size()){
					return -1;
				}//endif
				return idx;
			}//end_checkin

			// 檢查 A subset B !!
			template<class T>
			bool subset(const std::unordered_set<T> &A,const std::unordered_set<T> &B){
				for(auto &a:A){
					if(B.find(a)==B.end()){
						return false;
					}//endif
				}//endfor 
				return true;
			}//end_subset


	} checkin;



};



#endif