/*===========================================================================
	
	// 把 std::unordered_map 拆解至 std::unordered_map 	
		setfunc.keys()
		setfunc.vals()
	


=============================================================================*/



#ifndef __SETFUNC_HPP__ 
#define __SETFUNC_HPP__





namespace cxxuseful{
	
	class SetFunc{
		public:
			template<class T,class S> 
			std::unordered_set<T> keys(const std::unordered_map<T,S> &v){
				std::unordered_set<T> _output;
				for(auto &k:v){
					_output.insert(k.first);
				}//endfor
				return _output;
			}//end_keys

			template<class T,class S>
			std::unordered_set<T> vals(const std::unordered_map<S,T> &v){
				std::unordered_set<T> _output;
				for(auto &k:v){
					_output.insert(k.second);
				}//endfor
				return _output;
			}//end_values

			template<class T>
			std::unordered_set<T> fromlist(const std::vector<T> &v){
				std::unordered_set<T> s;
				for(int i=0;i<v.size();i++){
					s.insert(v[i]);
				}//endfor
				return s;
			}


			template<class T>
			std::unordered_set<T> inter2(const std::unordered_set<T> &A,const std::unordered_set<T> &B){
				std::unordered_set<T> C;
				for(auto &a:A){
					if(B.find(a)!=B.end()){
						C.insert(a);
					}//endif
				}//endfor
				return C;
			}//end

			template<class T>
			std::unordered_set<T> union2(const std::unordered_set<T> &A,const std::unordered_set<T> &B){
				std::unordered_set<T> C;
				for(auto &a:A){
					C.insert(a);
				}//endfor
				for(auto &b:B){
					C.insert(b);
				}
				return C;
			}//end

			template<class T>
			std::unordered_set<T> diff2(const std::unordered_set<T> &A,const std::unordered_set<T> &B){
				std::unordered_set<T> C;
				for(auto &a:A){
					if(B.find(a)==B.end()){
						C.insert(a);
					}//endif
				}//endfor
				return C;
			}//end




	} setfunc;











};








#endif