/*---------------------------------------------------------------------------
last update : 2019.07
You can use those subroutines to print colorful message in Windows Command Line    
----------------------------------------------------------------------------*/
#ifndef __CXXCOLOR_HPP__
#define __CXXCOLOR_HPP__


#include <iostream>
#if defined _WIN32 || defined _WIN64 
	#include <windows.h>
#endif

using namespace std;

namespace cxxcolor{

	// ------------------   windows ----------------------------- 
	#if defined _WIN32 || defined _WIN64 
		HANDLE _CXXCOLOR_=GetStdHandle(STD_OUTPUT_HANDLE);



		void printGold(string str,bool newline=false){
			SetConsoleTextAttribute(_CXXCOLOR_, 6);
			cout << str;
			if(newline == true) cout << endl;
			SetConsoleTextAttribute(_CXXCOLOR_, 7);
		}//end_printGold

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

	
	#else
		// ------------------   UNIX -----------------------------
		/*
		foreground background
		black        30         40
		red          31         41
		green        32         42
		yellow       33         43
		blue         34         44
		magenta      35         45
		cyan         36         46
		white        37         47
		
		gray = white
		gold = yellow


		*/


		
		void printBlue(string str,bool newline=false){
			cout << "\033[1;34m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printBlue

		void printGreen(string str,bool newline=false){
			cout << "\033[1;32m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printGreen

		void printBlueGreen(string str,bool newline=false){
			cout << "\033[1;36m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printBlueGreen

		void printRed(string str,bool newline=false){
			cout << "\033[1;31m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printRed

		void printPurple(string str,bool newline=false){
			cout << "\033[1;35m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printPurple

		void printYellow(string str,bool newline=false){
			cout << "\033[1;33m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printYellow

		void printGray(string str,bool newline=false){
			cout << str;
			if (newline) cout << "\n";
		}//end_printGray


		void printGold(string str,bool newline=false){
			cout << "\033[1;33m"<< str <<"\033[0m";
			if (newline) cout << "\n";
		}//end_printGold


	#endif







};//end_cxxcolor

#endif 














/*---------------------------------------------------------------------------
last update : 2018.02.07


You can use those subroutines to print colorful message in Windows Command Line    

----------------------------------------------------------------------------*/
/*
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

*/

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








