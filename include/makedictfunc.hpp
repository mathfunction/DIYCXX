/*======================================================================
	- mkdict(std::basic_string<T>) 把一維陣列轉換成 std::unordered_map  (預設從 0 ,1,2... 開始 , _bool1based== true ==> 從 1,2,3...開始)
	- mkdict.dist(std::vector<T>) 把陣列 轉成 個數 std::unordered_map<T,int>
	- mkdict.dual(std::vector<T>) 把陣列 轉成  T 對應位置 std::unordered_map <T,std::vector<int> >
=======================================================================*/
#ifndef __MAKEDICTFUNC_HPP__
#define __MAKEDICTFUNC_HPP__


namespace cxxuseful{
	class MakeDictFunc{
		
		public: 
			BoostAny operator()(const std::basic_string<int> &v){return handleList<int>(v);}
			BoostAny operator()(const std::basic_string<double> &v){return handleList<double>(v);}
			template<typename T> 
			std::unordered_map<T,int> dist(const std::vector<T> &_array){
				std::unordered_map<T,int> output;
				for(int i=0;i<_array.size();i++){
					if(output.find(_array[i])==output.end()){
						output[_array[i]] = 0;
					}//endif
					output[_array[i]] += 1;
				}//endfor
				return output;
			}//count

			template<typename T> 
			std::unordered_map<T,std::vector<int> > dual(const std::vector<T> &_array){
				std::unordered_map<T,std::vector<int> > output;
				for(int i=0;i<_array.size();i++){
					output[_array[i]].push_back(i);
				}//endfor
			}//end_dual





			
		private:
			template<typename T> BoostAny handleList(const std::basic_string<T> &v,bool _bool1based=false){
				std::unordered_map<int,T> _dict;
				for(int i=0;i<v.size();i++){
					if(_bool1based == false){
						_dict[i] = v[i];
					}else{
						_dict[i+1] = v[i];
					}//end_else
				}//endfor
				return _dict;
			}




	} mkdict;

};

#endif