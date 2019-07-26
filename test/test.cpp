/*

	need boost library 
	

*/
#include"cxxuseful.hpp"
using namespace cxxuseful;

int main(){
	
	int a = 2;
	double b = 2.45069;
	string c = "r9409";
	cout << makestr({a,b,c},"_") << endl;
	cout << makestr({a,b,c},"-") << endl;
	
	



	return 0;
}//end_main