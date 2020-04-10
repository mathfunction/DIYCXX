/*======================================================================
	- mkdict(basic_string<T>) 把一維陣列轉換成 unordered_map  (預設從 0 ,1,2... 開始 , _bool1based== true ==> 從 1,2,3...開始)

=======================================================================*/
#ifndef __MAKEDICTFUNC_HPP__
#define __MAKEDICTFUNC_HPP__


namespace cxxuseful{
	using namespace std;
	class MakeDictFunc{
		
		public: 
			BoostAny operator()(const basic_string<int> &v){return handleList<int>(v);}
			BoostAny operator()(const basic_string<double> &v){return handleList<double>(v);}
			
			
		private:
			template<typename T> BoostAny handleList(const basic_string<T> &v,bool _bool1based=false){
				unordered_map<int,T> _dict;
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