#ifndef __DATAFRAME_HPP__
#define __DATAFRAME_HPP__



namespace cxxuseful{
	class DataFrame{
		private:
			vector<string> colnames;
			unordered_map<string,vector<BoostAny> >data;
			
		public:
			DataFrame(const vector<string> &colnames){
				this->colnames = colnames;
			}//endDataFrame
			void clearData(){
				this->data.clear();
			}//end_clearData

			void clearAll(){
				this->colnames.clear();
				this->data.clear();
			}//end_clearAll

			// add a row
			DataFrame& operator+=(const vector<BoostAny> &row){
				for(int i=0;i<colnames.size();i++){
					data[colnames[i]].push_back(row[i]);
				}//endfor
				return *this;
			}
			

			int size(){
				return rows()*cols();
			}//end

			int rows(){
				return data[colnames[0]].size();
			}//end

			int cols(){
				return colnames.size();
			}//end

			void print(int setw_n=10){
				for(int c=0;c<colnames.size();c++){
					stringstream ss;
					ss << setw(setw_n) << colnames[c] << " | ";
					printYellow(ss.str());
				}
				cout << endl;
				for(int r=0;r<rows();r++){
					for(int i=0;i<colnames.size();i++){
						BoostAny &v = data[colnames[i]][r];
						if(v.type()==typeid(int)){
							cout  << setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(const char*)){
							cout  << setw(setw_n) << type<const char*>(v) << " | ";
						}else if(v.type()==typeid(string)){
							cout  << setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(double)){
							cout  << setw(setw_n) << type<double>(v) << " | ";
						}else if(v.type()==typeid(BoostInt)){
							cout  << setw(setw_n) << type<BoostInt>(v) << " | ";
						}else if(v.type()==typeid(BoostFloat)){
							cout  << setw(setw_n) << type<BoostFloat>(v) << " | ";
						}else if(v.type()==typeid(BoostRational)){
							cout  << setw(setw_n) << type<BoostRational>(v) << " | ";
						}else{
						}//end_else

					}//endfor
					cout << endl;
				}//endfor
			}//end_print




	};


};




















#endif