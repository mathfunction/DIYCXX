#ifndef __CHARMATH_HPP__
#define __CHARMATH_HPP__

#include <utility>

namespace charmath{
	
	using namespace std;
	pair<char,char> PLUSTABLE(char c1,char c2){
		switch(c1){
			case '.':
				switch(c2){
					case '.':
						return pair<char,char>('.','.');
				}
				break;
			case '0':
				switch(c2){
					case '0':
						return pair<char,char>('0','0');
					case '1':
						return pair<char,char>('0','1');
					case '2':
						return pair<char,char>('0','2');
					case '3':
						return pair<char,char>('0','3');
					case '4':
						return pair<char,char>('0','4');
					case '5':
						return pair<char,char>('0','5');
					case '6':
						return pair<char,char>('0','6');
					case '7':
						return pair<char,char>('0','7');
					case '8':
						return pair<char,char>('0','8');
					case '9':
						return pair<char,char>('0','9');
				}
				break;
			case '1':
				switch(c2){
					case '0':
						return pair<char,char>('0','1');
					case '1':
						return pair<char,char>('0','2');
					case '2':
						return pair<char,char>('0','3');
					case '3':
						return pair<char,char>('0','4');
					case '4':
						return pair<char,char>('0','5');
					case '5':
						return pair<char,char>('0','6');
					case '6':
						return pair<char,char>('0','7');
					case '7':
						return pair<char,char>('0','8');
					case '8':
						return pair<char,char>('0','9');
					case '9':
						return pair<char,char>('1','0');
				}
				break;
			case '2':
				switch(c2){
					case '0':
						return pair<char,char>('0','2');
					case '1':
						return pair<char,char>('0','3');
					case '2':
						return pair<char,char>('0','4');
					case '3':
						return pair<char,char>('0','5');
					case '4':
						return pair<char,char>('0','6');
					case '5':
						return pair<char,char>('0','7');
					case '6':
						return pair<char,char>('0','8');
					case '7':
						return pair<char,char>('0','9');
					case '8':
						return pair<char,char>('1','0');
					case '9':
						return pair<char,char>('1','1');
				}
				break;
			case '3':
				switch(c2){
					case '0':
						return pair<char,char>('0','3');
					case '1':
						return pair<char,char>('0','4');
					case '2':
						return pair<char,char>('0','5');
					case '3':
						return pair<char,char>('0','6');
					case '4':
						return pair<char,char>('0','7');
					case '5':
						return pair<char,char>('0','8');
					case '6':
						return pair<char,char>('0','9');
					case '7':
						return pair<char,char>('1','0');
					case '8':
						return pair<char,char>('1','1');
					case '9':
						return pair<char,char>('1','2');
				}
				break;
			case '4':
				switch(c2){
					case '0':
						return pair<char,char>('0','4');
					case '1':
						return pair<char,char>('0','5');
					case '2':
						return pair<char,char>('0','6');
					case '3':
						return pair<char,char>('0','7');
					case '4':
						return pair<char,char>('0','8');
					case '5':
						return pair<char,char>('0','9');
					case '6':
						return pair<char,char>('1','0');
					case '7':
						return pair<char,char>('1','1');
					case '8':
						return pair<char,char>('1','2');
					case '9':
						return pair<char,char>('1','3');
				}
				break;
			case '5':
				switch(c2){
					case '0':
						return pair<char,char>('0','5');
					case '1':
						return pair<char,char>('0','6');
					case '2':
						return pair<char,char>('0','7');
					case '3':
						return pair<char,char>('0','8');
					case '4':
						return pair<char,char>('0','9');
					case '5':
						return pair<char,char>('1','0');
					case '6':
						return pair<char,char>('1','1');
					case '7':
						return pair<char,char>('1','2');
					case '8':
						return pair<char,char>('1','3');
					case '9':
						return pair<char,char>('1','4');
				}
				break;
			case '6':
				switch(c2){
					case '0':
						return pair<char,char>('0','6');
					case '1':
						return pair<char,char>('0','7');
					case '2':
						return pair<char,char>('0','8');
					case '3':
						return pair<char,char>('0','9');
					case '4':
						return pair<char,char>('1','0');
					case '5':
						return pair<char,char>('1','1');
					case '6':
						return pair<char,char>('1','2');
					case '7':
						return pair<char,char>('1','3');
					case '8':
						return pair<char,char>('1','4');
					case '9':
						return pair<char,char>('1','5');
				}
				break;
			case '7':
				switch(c2){
					case '0':
						return pair<char,char>('0','7');
					case '1':
						return pair<char,char>('0','8');
					case '2':
						return pair<char,char>('0','9');
					case '3':
						return pair<char,char>('1','0');
					case '4':
						return pair<char,char>('1','1');
					case '5':
						return pair<char,char>('1','2');
					case '6':
						return pair<char,char>('1','3');
					case '7':
						return pair<char,char>('1','4');
					case '8':
						return pair<char,char>('1','5');
					case '9':
						return pair<char,char>('1','6');
				}
				break;
			case '8':
				switch(c2){
					case '0':
						return pair<char,char>('0','8');
					case '1':
						return pair<char,char>('0','9');
					case '2':
						return pair<char,char>('1','0');
					case '3':
						return pair<char,char>('1','1');
					case '4':
						return pair<char,char>('1','2');
					case '5':
						return pair<char,char>('1','3');
					case '6':
						return pair<char,char>('1','4');
					case '7':
						return pair<char,char>('1','5');
					case '8':
						return pair<char,char>('1','6');
					case '9':
						return pair<char,char>('1','7');
				}
				break;
			case '9':
				switch(c2){
					case '0':
						return pair<char,char>('0','9');
					case '1':
						return pair<char,char>('1','0');
					case '2':
						return pair<char,char>('1','1');
					case '3':
						return pair<char,char>('1','2');
					case '4':
						return pair<char,char>('1','3');
					case '5':
						return pair<char,char>('1','4');
					case '6':
						return pair<char,char>('1','5');
					case '7':
						return pair<char,char>('1','6');
					case '8':
						return pair<char,char>('1','7');
					case '9':
						return pair<char,char>('1','8');
				}
				break;
		}//end_switch
		return pair<char,char>('X','X');
	}//end_PLUS_TABLE

	/*
	pair<char,char> MULTABLE(char c1,char c2){
		switch(c1){
			case '0':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '1':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '2':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '3':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '4':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '5':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '6':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '7':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '8':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
			case '9':
				switch(c2){
					case '0':
						break;
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					case '9':
						break;
				}
				break;
		}//end_switch
	}//end_MUL_TABLE
	*/

















};



























#endif