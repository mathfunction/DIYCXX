#ifndef __BINARY_HANDLE_HPP__
#define __BINARY_HANDLE_HPP__


#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "string_handle.hpp"
#include "big_number.hpp"

using namespace std;
using namespace string_handle;



namespace binary_handle{

	int InvBinary(vector<string> &vec,bool _boolPrint=false){
		int sum = 0 ;
		int prod = 1;
		for(int i=vec.size()-1;i>(-1);--i){
			sum += atoi(vec[i].c_str()) * prod;
			prod*=2;
		}//endfor
		if(sum < 0){
			cout << "Warning ... out of int !!!" << endl;
		}//endif
		if(_boolPrint==true){
			cout << "sum = " << sum << endl;
		}//endif
		return sum;
	}//end_InvBinary


	//vector<string> Binary(int sum,int size);

	int InvBinary(vector<int> &vec,bool _boolPrint=false){
		int sum = 0 ;
		int prod = 1;
		for(int i=vec.size()-1;i>(-1);--i){
			sum += vec[i]*prod;
			prod*=2;
		}//endfor
		if(sum < 0){
			cout << "Warning ... out of int !!!" << endl;
		}//endif
		if(_boolPrint==true){
			cout << "sum = " << sum << endl;
		}//endif
		return sum;
	}//end_InvBinary


	string strBinary(vector<int> &vec,bool _boolPrint=false){
		string output = makestr(vec);
		if(_boolPrint == true){
			cout << output << endl;
		}//endif
		return output;
	}//end_strBinary

	vector<int> Binary(int num,int encoding_size,bool _boolPrint=false){
		vector<int> output;
		while(num > 0){
			if((num-1)%2==0){
				output.push_back(1);
			}else{
				output.push_back(0);
			}//end_else
			num = num/2;
		}//end_while
		while (output.size() < encoding_size){
			output.push_back(0);
		}//endwhile
		if(_boolPrint==true){
			cout << "Input : " << num << endl;
			cout << "Output : ";
			for(int i=output.size()-1;i>-1;i--){
				cout << output[i] ;
			}//endfor
			cout << endl;
		}//endif
		// note need to reversed 
		return output;
	}//end_Binary
	bool check_only_1_diff(vector<int> &v1,vector<int> &v2);
	vector<int> create_merge_vec(vector<int> &v1,vector<int> &v2);
	int compute_sum(vector<int> &v);
	/*----------------------------------------------
	Given subset S in {0,1}^{K} need to reduced to {0,1,2}^{K}  2 equiv = {0,1}
	with x,y can be merge if |k in K : x_k != y_k| = 1
	-----------------------------------------------*/
	
	class Binary_Merge_Algorithm{
		private:
			
			// key1 = sum of binary vector 
			int encoding_size;
			unordered_map<int,unordered_map<string,vector<int> > > binaries;
		public:
			Binary_Merge_Algorithm(int encoding_size);
			void summary();
			void add(vector<int> &vec);
			unordered_map<int,unordered_map<string,vector<int> > > merge(bool _boolPrint=false);
			bool check_correctness();

	};

}//end_namespace 































int binary_handle::compute_sum(vector<int> &v){
	int sum = 0; 
	for(int i=0;i<v.size();i++){
		sum += v[i];
	}//endfor
	return sum;
}//end_compute_vec_sum

vector<int> binary_handle::create_merge_vec(vector<int> &v1,vector<int> &v2){
	vector<int> output;
	for(int i=0;i<v1.size();i++){
		if(v1[i]!=v2[i]){
			output.push_back(2);
		}else{
			output.push_back(v1[i]);
		}//end_else
	}//endfor
	return output;
}//end_binary_handle::create_merge_vec



bool binary_handle::check_only_1_diff(vector<int> &v1,vector<int> &v2){
	int diffcount = 0;
	for(int i=0;i<v1.size();i++){
		if(v1[i]!=v2[i]) diffcount+=1;
		if(diffcount > 1) return false;
	}//endfor
	if(diffcount == 0) return false;
	return true;
}//end_binary_handle::check_only_1_diff


void binary_handle::Binary_Merge_Algorithm::add(vector<int> &vec){
	binaries[compute_sum(vec)][binary_handle::strBinary(vec)] = vec;
}//end_binary_handle::Binary_Merge_Algorithm::add

binary_handle::Binary_Merge_Algorithm::Binary_Merge_Algorithm(int encoding_size){
	this->encoding_size = encoding_size;
}//end_





void binary_handle::Binary_Merge_Algorithm::summary(){
	cout << "__________information of Binaries____________" << endl;
	cout << "Encoding Size = [" << this->encoding_size << "]" <<endl;
	int sum = 0;
	for(int i=0;i<=2*this->encoding_size;i++){
		cout << "level = " <<  i ;
		if((this->binaries.find(i))!=(this->binaries).end()){
			cout << " size = " <<  (this->binaries[i]).size() << endl;
			sum += (this->binaries[i]).size();
		}else{
			cout << " size = 0 "<< endl;
		}//end_else
	}//endfor 
	cout << "Size = [" << sum << "] " << endl;
}//end_summary


unordered_map<int,unordered_map<string,vector<int> > > binary_handle::Binary_Merge_Algorithm::merge(bool _boolPrint){
	// bi-gram for loop
	int upper_bound = 2*this->encoding_size;
	for(int i=0;i<=upper_bound;i++){
		// both bucket exists
		if(binaries.find(i)!=binaries.end() && binaries.find(i+1)!=binaries.end()){
			vector<string> temp_delete_i;
			//vector<string> temp_delete_i1;
			/*
			if(_boolPrint == true){
				cout << "Scan [" << i <<"][" << i+1 << "]" << endl;
			}//endif
			*/
			// scan bucket i & bucket i+1 
			for(unordered_map<string,vector<int> >::iterator it=binaries[i].begin();it!=binaries[i].end();++it){
				for(int j=0;j<this->encoding_size;j++){
					vector<int> vec_1_diff = it->second;
					// change only 1 element !!
					if(vec_1_diff[j] == 2){ 
						continue;
					}else if(vec_1_diff[j] == 1){
						continue;
					}else{
						vec_1_diff[j] = 1;
					}//end_else
					// check existence in next bucket by use int key !!
					string _strRE = binary_handle::strBinary(vec_1_diff);
					if(binaries[i+1].find(_strRE)!= binaries[i+1].end()){
						// create new merge vector and put into the new bucket 
						vector<int> _mergevec = binary_handle::create_merge_vec(it->second,vec_1_diff);
						// give new id 
						binaries[binary_handle::compute_sum(_mergevec)][binary_handle::strBinary(_mergevec)] = _mergevec;
						// remember the id
						temp_delete_i.push_back(it->first);
						binaries[i+1].erase(_strRE);
						break;
					}//endif
				}//endfor
			}//endfor
			//======================================================
			// delete binaries
			for(int j=0;j<temp_delete_i.size();j++){
				binaries[i].erase(temp_delete_i[j]);
			}//endfor
			/*
			for(int j=0;j<temp_delete_i1.size();j++){
				binaries[i+1].erase(temp_delete_i1[j]);
			}//endfor
			*/
		}//endif
	}//endfor
	//_________________________________________________
	if(_boolPrint == true){
		for(unordered_map<int,unordered_map<string,vector<int> > >::iterator it=binaries.begin();it!=binaries.end();++it){
			for(unordered_map<string,vector<int> >::iterator jt=(it->second).begin();jt!=(it->second).end();++jt){
				cout << "[ ";
				for(int i=0;i<(jt->second).size();i++){
					cout << jt->second[i] ;
					if(i!=(jt->second.size()-1))
						cout << ",";  
				}//endfor
				cout << " ]" << endl;
			}//endfor
		}//endfor
	}//endif 
	return binaries;
}//end_binary_handle







#endif


/*

//-------------------------------------------------------------------------
//
//command line :
//	g++ -std=c++11 -o test test.cpp -I.
//
//--------------------------------------------------------------------------




#include <iostream>
#include "binary_handle.hpp"
#include "string_handle.hpp"


using namespace binary_handle;
using namespace string_handle;
using namespace std;


int main(){




	newline("Binary_Merge_Algorithm");
	Binary_Merge_Algorithm buffer = Binary_Merge_Algorithm(3);
	vector<int> r1 = intlist("[1,0,0]");
	vector<int> r2 = intlist("[1,0,1]");
	vector<int> r3 = intlist("[0,0,0]");
	vector<int> r4 = intlist("[1,1,1]");
	vector<int> r5 = intlist("[1,1,0]");
	vector<int> r6 = intlist("[0,0,1]");
	vector<int> r7 = intlist("[0,1,0]");
	vector<int> r8 = intlist("[0,1,1]");	

	buffer.add(r1);
	buffer.add(r2);
	print(r1);
	print(r2);
	buffer.merge(true);
	printYellow("---------------",true);
	buffer.add(r3);
	buffer.add(r4);
	print(r3);
	print(r4);
	buffer.merge(true);
	printYellow("---------------",true);
	buffer.add(r5);
	buffer.add(r6);
	buffer.add(r7);
	print(r5);
	print(r6);
	print(r7);
	buffer.merge(true);
	printYellow("---------------",true);
	buffer.add(r8);
	print(r8);
	buffer.merge(true);


	return 0;
}//end_main


*/