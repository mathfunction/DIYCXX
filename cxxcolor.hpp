/*---------------------------------------------------------------------------
last update : 2018.02.07


You can use those subroutines to print colorful message in Windows Command Line    

----------------------------------------------------------------------------*/
#ifndef __CXXCOLOR_HPP__
#define __CXXCOLOR_HPP__
#include <iostream>
#include <windows.h>

using namespace std;

namespace cxxcolor{

	HANDLE _CXXCOLOR_=GetStdHandle(STD_OUTPUT_HANDLE);

	
	void printDarkBlue(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 1);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkBlue
	
	void printDarkGreen(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 2);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkGreen
	
	void printDarkBlueGreen(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 3);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkBlueGreen
	
	void printDarkRed(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 4);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkRed
	
	void printDarkPurple(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 5);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkPurple
	
	void printGold(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 6);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printGold

	//origin
	void printDarkWhite(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printDarkWhite

	void printGray(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 8);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printGray

	void printBlue(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 9);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printBlue

	void printGreen(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 10);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printGreen

	void printBlueGreen(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 11);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printBlueGreen

	void printRed(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 12);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printRed

	void printPurple(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 13);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printPurple

	void printYellow(string str,bool newline=false){
		SetConsoleTextAttribute(_CXXCOLOR_, 14);
		cout << str;
		if(newline == true) cout << endl;
		SetConsoleTextAttribute(_CXXCOLOR_, 7);
	}//end_printYellow

};//end_cxxcolor

#endif 



/*---------------------------------------------------------------
#include <iostream>
#include "cxxcolor.hpp"

using namespace std;
using namespace cxxcolor;


int main(){


	// true means newline !! 
	printDarkBlue("DarkBlue",true);
	printDarkGreen("DarkGreen",true);
	printDarkBlueGreen("DarkBlueGreen",true);
	printDarkRed("DarkRed",true);
	printDarkPurple("DarkPurple",true);
	printGold("Gold",true);
	printDarkWhite("DarkWhite",true);
	printGray("Gray",true);
	printGreen("Green",true);
	printBlueGreen("BlueGreen",true);
	printRed("Red",true);
	printPurple("Purple",true);
	printYellow("Yellow",true);


	printDarkBlue("DarkBlue ");
	printDarkGreen("DarkGreen ");
	printDarkBlueGreen("DarkBlueGreen ");
	printDarkRed("DarkRed ");
	printDarkPurple("DarkPurple ");
	printGold("Gold ");
	printDarkWhite("DarkWhite ");
	printGray("Gray ");
	printGreen("Green ");
	printBlueGreen("BlueGreen ");
	printRed("Red ");
	printPurple("Purple ");
	printYellow("Yellow ");


	return 0;
}//end_main

----------------------------------------------------------*/








