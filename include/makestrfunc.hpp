#ifndef __MAKESTRFUNC_HPP__ 
#define __MAKESTRFUNC_HPP__



namespace typefunc{	

	class MakeStrFunc{
		public:
			void setMark(string delimiter){
				this->delimiter = delimiter;
			}

			string operator[](basic_string<BoostAny> v){
				string _str = title;
				for(int i=0;i<v.size();i++){
					if(typeid(v[i])==typeid(int)){
						
					}else if(typeid(v[i])==typeid(double)){

					}else if(typeid(v[i])==typeid(string)){

					}else{
						cerr << "[Error] Unable to find type in makestr" << endl;
						exit(1);
					}



				}//endfor
				return _str;
			}

		private:
			string delimiter = "_";
			string title = "";












	} makestr;



};






#endif