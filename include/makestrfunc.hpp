#ifndef __MAKESTRFUNC_HPP__ 
#define __MAKESTRFUNC_HPP__



namespace cxxuseful{	

	
	class MakeStrFunc{
		public:
			string operator()(const vector<string> &v,string delimiter="_",string title="[Key]"){
				string _output = title;
				for(int i=0;i<v.size();i++){
					_output += delimiter;
					_output += v[i];
				}//endfor
				return _output;
			}//end
			string operator()(const vector<BoostAny> &v,string delimiter="_",string title="[Key]"){
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
						ss << "<E>";
					}
				}//endfor
				return ss.str();
			}

	} makestr;

};



#endif