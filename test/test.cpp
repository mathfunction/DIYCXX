/*

	need boost library 
	

*/
#include"typefunc.hpp"

using namespace typefunc;


int main(){
	
	int a = 2;
	double b = 2.45069;
	string c = "r9409";
	makestr.setMark("|");
	cout << makestr({a,b,c}) << endl;
	makestr.setMark("-");
	cout << makestr({a,b,c}) << endl;

	



	return 0;
}//end_main