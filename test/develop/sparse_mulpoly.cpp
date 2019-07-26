/*-----------------------------------------------------------------------------------------



	-I "C:\Users\Tommy_Cheng\Desktop\cxx_useful\boost_1_68_0\"
	F(x,y,z) = 2xyz + 3x^2y + 4xy^3 + 5xyz
	F = SparseMulpoly("2,x,0,1,y,0,1+3,x,0,2,y,0,1+4,x,0,1,y,0,3+5,x,0,1,y,0,1,z,0,1")
	

----------------------------------------------------------------------------------------*/


#include <iostream>
#include <unordered_map>
#include <map>
#include <cstdlib>
#include <vector>
#include <utility>
#include <sstream>
// std::stod
#include <string>
// boost::is_any_of()
#include <boost/algorithm/string/classification.hpp>
// boost::algorithm::join()
#include <boost/algorithm/string/join.hpp>
// boost::algorithm::split()
#include <boost/algorithm/string/split.hpp>



using namespace std;



namespace MulPolynomial{

	vector<string> split(string _str,string sym=",",bool _boolPrint=false);
	string join(vector<string> &input,string sym="_",bool _boolPrint=false);
	


	class SparseMulPoly{
		private:
				map<string,pair<int,double> >  extractVar(vector<string> &var,bool _boolPrint=false);
		public:
			void print();
			int getMaxIndex();
			// key = term form 
			unordered_map<string,int> getDictPointer(bool _boolPrint=false); 
			vector<map<string,pair<int,double> > > values;
			SparseMulPoly(string longstr="2,x,1,1,y,2,1+3,x,3,2,y,3,1+4,x,4,1,y,1,3+5,x,5,1,y,4,1,z,3,1");
	};


	////////////////////////////////////////////////////////////////////////////////////////////////

	vector<string> split(string _str,string sym,bool _boolPrint){
		vector<string> output;
		boost::split(output,_str,boost::is_any_of(sym));
		if(_boolPrint == true){
			cout << "[";
			for(int i=0;i<output.size();i++){
				cout << output[i];
				if(i!=output.size()-1){
					cout << ",";
				}//endif 
			}//endfor
			cout << "]";
		}//endif 
		return output;
	}//end_split


	string join(vector<string> &input,string sym,bool _boolPrint){
		string output = boost::algorithm::join(input,sym);
		if(_boolPrint==true){
			for(int i=0;i<output.size();i++){
				cout << output[i] << endl;
			}//endfor
		}//endif
		return output;
	}//end_join


	



	
	map<string,pair<int,double> > SparseMulPoly::extractVar(vector<string> &var,bool _boolPrint){
		map<string,pair<int,double> > output;
		output["coef"] = make_pair(0,stod(var[0]));
		int count = 0;
		string varname;
		int index;
		double exponent;

		for(int i=1;i<var.size();i++){
			count +=1;
			if(i%3==1){
				varname = var[i];
			}else if(i%3==2){
				index = stoi(var[i]);
			}else if(i%3==0){
				exponent = stod(var[i]); 
			}else{
				exit(1);
			}//end_else
			if(count ==3){
				output[varname] = make_pair(index,exponent);
				count = 0;
			}//endif
		}//endfor
		if(_boolPrint==true){
			cout << "===================================[ term ]=====================================" << endl;
			for(map<string,pair<int,double> >::iterator it=output.begin();it!=output.end();++it){
				if(it->first == "coef"){
					cout << it->first << " = " << it->second.second << endl;
				}else{
					cout << it->first << "_" << it->second.first << "^" <<  it->second.second << endl;
				}//end_else 
			}//endfor
		}//endif

		return output;
	}//end_extractVar



	unordered_map<string,int> SparseMulPoly::getDictPointer(bool _boolPrint){
		unordered_map<string,int> output;
		for(int i=0;i<values.size();i++){
			vector<string> temp;
			for(map<string,pair<int,double> >::iterator it=values[i].begin();it!=values[i].end();++it){
				if(it->first != "coef"){
					temp.push_back(it->first); 
					temp.push_back(to_string(it->second.first));
					temp.push_back(to_string((int)it->second.second));
				}//endif
			}//endfor
			output[join(temp,",")] = i;
		}//endfor
		if(_boolPrint == true){
			for(unordered_map<string,int>::iterator it=output.begin();it!=output.end();++it){
				cout <<  it->second << "th = ["<< it->first << "] " << endl;
			}//endfor
		}//endif
		return output;
	}//end_getDictPointer


	SparseMulPoly::SparseMulPoly(string longstr){
		vector<string> ORtokens = split(longstr,"+");
		for(int i=0;i<ORtokens.size();i++){
			vector<string> var = split(ORtokens[i],",");
			map<string,pair<int,double> > _dict = this->extractVar(var);
			values.push_back(_dict);
		}//endfor
	}//end_SparseMulPoly

	void SparseMulPoly::print(){
		for(int i=0;i<values.size();i++){
			cout << values[i]["coef"].second << " " ; 
			for(map<string,pair<int,double> >::iterator it=values[i].begin();it!=values[i].end();++it){
				if(it->first != "coef"){
					cout << it->first << "_{" << it->second.first << "}^{" << it->second.second << "}";
				}//endif
			}//endfor
			if(i!= values.size()-1){
				cout << " + " ;
			}//endif
		}//endfor
		cout << endl;
		//cout << "maxindex : " << this->getMaxIndex() << endl;
	}//end_print

	int SparseMulPoly::getMaxIndex(){
		int max = -1000000;
		for(int i=0;i<values.size();i++){
			for(map<string,pair<int,double> >::iterator it=values[i].begin();it!=values[i].end();++it){
				if(max < it->second.first){
					max = it->second.first;
				}//endif
			}//endfor
		}//endfor
		return max;
	}//endif


	//==========================================================================================================================
	
	SparseMulPoly addition(SparseMulPoly &poly1,SparseMulPoly &poly2){
		vector<string> _vecoutput;
		unordered_map<string,double> _dictoutput;
		unordered_map<string,int> _dictPointer1 = poly1.getDictPointer();
		unordered_map<string,int> _dictPointer2 = poly2.getDictPointer();
		for(unordered_map<string,int>::iterator it=_dictPointer1.begin();it!=_dictPointer1.end();++it){
			string term = it->first;
			if(_dictPointer2.find(term)==_dictPointer2.end()){ 
				_dictoutput[term] = poly1.values[_dictPointer1[term]]["coef"].second;
			}else{
				_dictoutput[term] = poly1.values[_dictPointer1[term]]["coef"].second + poly2.values[_dictPointer2[term]]["coef"].second;
			}//end_else
		}//endfor
		for(unordered_map<string,int>::iterator it=_dictPointer2.begin();it!=_dictPointer2.end();++it){
			string term = it->first;
			if(_dictPointer1.find(term)==_dictPointer1.end()){ 
				_dictoutput[term] = poly2.values[_dictPointer2[term]]["coef"].second;
			}else{
				continue;
			}//end_else
		}//endfor
		// final scan
		for(unordered_map<string,double>::iterator it=_dictoutput.begin();it!=_dictoutput.end();++it){
			_vecoutput.push_back(to_string(it->second)+","+it->first);
		}//endfor
		return SparseMulPoly(join(_vecoutput,"+"));
	}//end_addition



	/*
	SparseMulPoly multiply(SparseMulpoly &poly1,SparseMulpoly &poly2){
		for(int i=0;i<values.size();i++){
			for(int j=0;j<values.size();j++){
				poly1.values[i]
				poly2.values[j]



			}//endfor
		}//endfor
	
	}//end_multiply
	*/





}//end_namespace














using namespace MulPolynomial;




int main(){

	SparseMulPoly F1 = SparseMulPoly("1.2,y,0,1+1.1,x,0,2+1,x,0,3,y,0,2+1,x,0,4");
	SparseMulPoly F2 = SparseMulPoly("1.4,x,0,1+2.3,x,0,2+1,x,0,3+0.1,x,0,4");
	F1.print();
	F2.print();
	SparseMulPoly F3 = addition(F1,F2);
	F3.print();














	return 0;
}//end_main