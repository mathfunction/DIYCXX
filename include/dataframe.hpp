#ifndef __DATAFRAME_HPP__
#define __DATAFRAME_HPP__

#include <fstream>

namespace cxxuseful{
	class DataFrame{
		private:
			std::vector<std::string> colnames;
		public:
			std::unordered_map<std::string,std::vector<BoostAny> >data;
			DataFrame(const std::vector<std::string> &colnames){
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
			DataFrame& operator+=(const std::vector<BoostAny> &row){
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

			std::vector<BoostAny> operator[](int j){
				std::vector<BoostAny> output;
				for(int i=0;i<colnames.size();i++){
					output.push_back(data[colnames[i]][j]);
				}//endfor
				return output;
			}

			void print(int setw_n=10){
				for(int c=0;c<colnames.size();c++){
					std::stringstream ss;
					ss << std::setw(setw_n) << colnames[c] << " | ";
					printYellow(ss.str());
				}
				std::cout << std::endl;
				for(int i=0;i<this->rows();i++){
					for(int j=0;j<this->cols();j++){
						BoostAny &v = data[colnames[j]][i];
						
						if(v.type()==typeid(int)){
							std::cout  << std::setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(std::string)){
							std::cout  << std::setw(setw_n) << type<std::string>(v) << " | ";
						}else if(v.type()==typeid(const char*)){
							std::cout  << std::setw(setw_n) << type<const char*>(v) << " | ";
						}else if(v.type()==typeid(std::string)){
							std::cout  << std::setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(double)){
							std::cout  << std::setw(setw_n) << type<double>(v) << " | ";
						}else if(v.type()==typeid(BoostInt)){
							std::cout  << std::setw(setw_n) << type<BoostInt>(v) << " | ";
						}else if(v.type()==typeid(BoostFloat)){
							std::cout  << std::setw(setw_n) << type<BoostFloat>(v) << " | ";
						}else if(v.type()==typeid(BoostRational)){
							std::cout  << std::setw(setw_n) << type<BoostRational>(v) << " | ";
						}else{
						}//end_else
						
					}//endfor
					std::cout << std::endl;
				}//endfor
			}//end_print
			

			void print(const std::vector<int> &idxs,int setw_n=10){
				for(int c=0;c<colnames.size();c++){
					std::stringstream ss;
					ss << std::setw(setw_n) << colnames[c] << " | ";
					printYellow(ss.str());
				}
				std::cout << std::endl;
				for(int j=0;j<idxs.size();j++){
					if(idxs[j] >= this->rows()) break;
					for(int i=0;i<colnames.size();i++){
						BoostAny &v = data[colnames[i]][idxs[j]];
						if(v.type()==typeid(int)){
							std::cout  << std::setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(std::string)){
							std::cout  << std::setw(setw_n) << type<std::string>(v) << " | ";
						}else if(v.type()==typeid(const char*)){
							std::cout  << std::setw(setw_n) << type<const char*>(v) << " | ";
						}else if(v.type()==typeid(std::string)){
							std::cout  << std::setw(setw_n) << type<int>(v) << " | ";
						}else if(v.type()==typeid(double)){
							std::cout  << std::setw(setw_n) << type<double>(v) << " | ";
						}else if(v.type()==typeid(BoostInt)){
							std::cout  << std::setw(setw_n) << type<BoostInt>(v) << " | ";
						}else if(v.type()==typeid(BoostFloat)){
							std::cout  << std::setw(setw_n) << type<BoostFloat>(v) << " | ";
						}else if(v.type()==typeid(BoostRational)){
							std::cout  << std::setw(setw_n) << type<BoostRational>(v) << " | ";
						}else{
						}//end_else

					}//endfor
					std::cout << std::endl;
				}//endfor
			}//end_print


			void to_csv(std::string csvfile){
				std::ofstream fout(csvfile.c_str(),std::ios::out);
				for(int c=0;c<colnames.size();c++){
					fout << colnames[c] << ",";
				}//endfor
				fout << "\n";
				for(int j=0;j<this->rows();j++){
					for(int i=0;i<colnames.size();i++){
						BoostAny &v = data[colnames[i]][j];
						if(v.type()==typeid(int)){
							fout << type<int>(v) << ",";
						}else if(v.type()==typeid(std::string)){
							fout << type<std::string>(v)  << ",";
						}else if(v.type()==typeid(const char*)){
							fout << type<const char*>(v)  << ",";
						}else if(v.type()==typeid(std::string)){
							fout << type<int>(v)  << ",";
						}else if(v.type()==typeid(double)){
							fout << type<double>(v)  << ",";
						}else if(v.type()==typeid(BoostInt)){
							fout << type<BoostInt>(v)  << ",";
						}else if(v.type()==typeid(BoostFloat)){
							fout << type<BoostFloat>(v)  << ",";
						}else if(v.type()==typeid(BoostRational)){
							fout << type<BoostRational>(v)  << ",";
						}else{
						}//end_else
					}//endfor
					fout << "\n";
				}//endfor
				printGreen("write df to "+csvfile+"\n");
				fout.close();
			}//end_to_csv



	};


};




















#endif