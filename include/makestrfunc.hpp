#ifndef __MAKESTRFUNC_HPP__ 
#define __MAKESTRFUNC_HPP__



namespace typefunc{	

	class MakeStrFunc{
		public:
			void setMark(string delimiter){
				this->delimiter = delimiter;
			}

			string operator()(vector<BoostAny> v){
				stringstream ss;
				ss << title;
				for(int i=0;i<v.size();i++){
					ss << delimiter;
					if(v[i].type() == typeid(string)){
						ss << type<string>(v[i]);
					}else if(v[i].type() == typeid(const char*)){
						ss << type<const char*>(v[i]);
					}else if(v[i].type() == typeid(int)){
						ss << type<int>(v[i]);
					}else if(v[i].type() == typeid(double)){
						ss << type<double>(v[i]);
					}else{
						ss << "@";
					}
				}//endfor
				return ss.str();
			}

		private:
			string delimiter = "_";
			string title = "[Key]";

	} makestr;



};






#endif