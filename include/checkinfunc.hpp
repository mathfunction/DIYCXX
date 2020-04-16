#ifndef __CHECKINFUNC_HPP__ 
#define __CHECKINFUNC_HPP__



namespace cxxuseful{
	
	class CheckInFunc{
		public:
			// check_elements_in vector<T>
			template<class T> 
			int operator()(const vector<T>&v,const T &e){
				int idx = distance(v.begin(),find(v.begin(),v.end(),e));
				if (idx == v.size()){
					return -1;
				}//endif
				return idx;
			}//end_checkin


	} checkin;



};



#endif