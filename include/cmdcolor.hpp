/*====================================================================================
	C++ 跨平台 ( windows / linux / mac ) 支援列印顏色在終端機:
		newline == true 代表換行 !!
		
		printYellow(_str,_newline)
		printRed(_str,_newline)
		printBlue(_str,_newline)
		printBlueGreen(_str,_newline)
		printPurple(_str,_newline)
		printGray(_str,_newline)
		printGold(_str,_newline)
========================================================================================*/
#ifndef __CMDCOLOR_HPP__
#define __CMDCOLOR_HPP__



#if defined _WIN32 || defined _WIN64 
	#include <windows.h>
#endif


namespace cxxuseful{
	namespace cmdcolor{
		using namespace std;
		// ------------------   windows ----------------------------- 
		#if defined _WIN32 || defined _WIN64 
			HANDLE _CMDCOLOR_=GetStdHandle(STD_OUTPUT_HANDLE);



			void printGold(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 6);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printGold

			void printGray(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 8);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printGray


			void printBlue(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 9);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printBlue

			void printGreen(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 10);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printGreen

			void printBlueGreen(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 11);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printBlueGreen

			void printRed(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 12);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printRed

			void printPurple(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 13);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
			}//end_printPurple

			void printYellow(string str,bool newline=false){
				SetConsoleTextAttribute(_CMDCOLOR_, 14);
				cout << str;
				if(newline == true) cout << endl;
				SetConsoleTextAttribute(_CMDCOLOR_, 7);
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
};//end_cxxuseful
	#endif 











