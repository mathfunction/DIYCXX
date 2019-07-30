#include<iostream>
#include <unordered_map>
#include <map>
#include <vector>


using namespace std;


namespace Polynomial{

	class SparsePoly{
		private:
			unordered_map<int,double> coef;
			int MaxCoef = -100000000;
			void updateMax(int input){
				if(input > MaxCoef){
					MaxCoef = input;
				}//endif
			}//end_updateMax

		public:
			unordered_map<int,double> getCoef(){
				return this->coef;
			}//end
			SparsePoly(){
				coef[0] = 0.0;
				MaxCoef = 0;
			}//end_SparsePoly
			void print(string sym="x"){
				cout << "======================================================" << endl;
				for(unordered_map<int,double>::iterator it=coef.begin();it!=coef.end();++it){
					if(it->second !=0.0){
						if(it->second > 0.0){
								cout << "+";
						}//endif
							cout << it->second  << sym << "^[" << it->first << "]";
					}//endif
				}//endfor
				cout << endl;
				cout << "MaxOrder = " << MaxCoef << endl;
				cout << "=======================================================" << endl;
			}//end_print

			void clearZero(){
				vector<int> delkeys;
				for(unordered_map<int,double>::iterator it=coef.begin();it!=coef.end();++it){
					if(it->second == 0.0){
						delkeys.push_back(it->first);
					}//endif
				}//endfor
				for(int i=0;i<delkeys.size();i++){
					coef.erase(delkeys[i]);
				}//endfor
			}//end_clearZero
			SparsePoly(unordered_map<int,double> coef,bool _boolPrint=false){
				for(unordered_map<int,double>::iterator it=coef.begin();it!=coef.end();++it){
					if(it->second != 0.0){
						this->coef[it->first] = it->second;
						this->updateMax(it->first);
					}//endif
				}//endfor
				if(_boolPrint == true){
					this->print();
				}//endif
			}//end_set
	};

	SparsePoly addition(SparsePoly &poly1,SparsePoly &poly2,bool _boolPrint=false){
		unordered_map<int,double> _dict1 = poly1.getCoef();
		unordered_map<int,double> _dict2  = poly2.getCoef();
		unordered_map<int,double> _dict3;
		// _dict1
		for(unordered_map<int,double>::iterator it=_dict1.begin();it!=_dict1.end();++it){
			if(_dict3.find(it->first) == _dict3.end()){
				_dict3[it->first] = 0.0;
			}//endif
			_dict3[it->first] += it->second;
		}//endfor
		// _dict2 
		for(unordered_map<int,double>::iterator it=_dict2.begin();it!=_dict2.end();++it){
			if(_dict3.find(it->first) == _dict3.end()){
				_dict3[it->first] = 0.0;
			}//endif
			_dict3[it->first] += it->second;
		}//endfor
		SparsePoly output = SparsePoly(_dict3);
		if(_boolPrint == true){
			output.print();
		}//endif 
		return output;
	}//end_addition

	SparsePoly mutiply(SparsePoly &poly1,SparsePoly &poly2,bool _boolPrint=false){
		unordered_map<int,double> _dict1 = poly1.getCoef();
		unordered_map<int,double> _dict2  = poly2.getCoef();
		unordered_map<int,double> _dict3;
		for(unordered_map<int,double>::iterator it=_dict1.begin();it!=_dict1.end();++it){
			for(unordered_map<int,double>::iterator jt=_dict2.begin();jt!=_dict2.end();++jt){
				int key = it->first+jt->first;
				double val = it->second*jt->second;
				if(_dict3.find(key)==_dict3.end()){
					_dict3[key] = 0.0;
				}//endif
				_dict3[key] += val; 
			}//endfor
		}//endfor
		SparsePoly output = SparsePoly(_dict3);
		if(_boolPrint == true){
			output.print();
		}//endif
		return output;
	}//end_multiply
	



};//end_namespace



using namespace Polynomial;

int main(){
	unordered_map<int,double> poly1;
	poly1[0] = 0.1;
	poly1[1] = 0.2;
	poly1[2] = 0.7;
	SparsePoly sparA(poly1,true);

	unordered_map<int,double> poly2;
	poly2[0] = 0.8;
	poly2[1] = 0.1;
	poly2[2] = 0.1;
	
	SparsePoly sparB(poly2,true);
	SparsePoly sparC = mutiply(sparA,sparB,true);


	return 0;
}//end_main 