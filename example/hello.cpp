/*============================================================================================
	
	這是關於函式庫的範例使用

=========================================================================================*/
#include"cxxuseful.hpp"
using namespace cxxuseful;

int main(){
	//================================================
	// cmdcolor
	printRed("red",true);
	printGreen("green",true);
	printYellow("yellow",true);
	printBlueGreen("green",true);
	printBlue("blue",true);
	printPurple("purple",true);

	//===============================================
	// makestr
	int a = 2;
	double b = 2.45069;
	string c = "r9409";
	cout << makestr({a,b,c},"_") << endl;
	cout << makestr({a,b,c},"-") << endl;
	//================================================
	// 



	



	return 0;
}//end_main