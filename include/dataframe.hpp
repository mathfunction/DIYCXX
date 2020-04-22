#ifndef __DATAFRAME_HPP__
#define __DATAFRAME_HPP__



namespace cxxuseful{
	class DataFrame{
		private:
			vector<string> colnames;
		public:
			unordered_map<string,vector<BoostAny> >data;
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

			vector<BoostAny> operator[](int j){
				vector<BoostAny> output;
				for(int i=0;i<colnames.size();i++){
					output.push_back(data[colnames[i]][j]);
				}//endfor
				return output;
			}



			void print(const vector<int> &idxs,int setw_n=10){
				for(int c=0;c<colnames.size();c++){
					stringstream ss;
					ss << setw(setw_n) << colnames[c] << " | ";
					printYellow(ss.str());
				}
				cout << endl;
				for(int j=0;j<idxs.size();j++){
					if(idxs[j] >= this->rows()) break;
					for(int i=0;i<colnames.size();i++){
						BoostAny &v = data[colnames[i]][idxs[j]];
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