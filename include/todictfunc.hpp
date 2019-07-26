#ifndef __TODICTFUNC_HPP__
#define __TODICTFUNC_HPP__

namespace cxxuseful{

	class ToDictFunc{
		
		public: 
			BoostAny operator()(basic_string<int> &v){return handleList<int>(v);}
			BoostAny operator()(basic_string<double> &v){return handleList<double>(v);}

		private:
			template<typename T> BoostAny handleList(basic_string<T> &v){
				unordered_map<int,T> _dict;
				for(int i=0;i<v.size();i++){
					_dict[i] = v[i];
				}//endfor
				return _dict;
			} 
	} todict;

};

#endif