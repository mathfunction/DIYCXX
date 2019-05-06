#ifndef __CHARMATH_HPP__
#define __CHARMATH_HPP__



namespace charmath{
	
	using namespace std;

	string PLUSTABLE(char c1,char c2){
		switch(c1){
			case '0':
				switch(c2){
					case '0':
						return "00";
					case '1':
						return "01";
					case '2':
						return "02";
					case '3':
						return "03";
					case '4':
						return "04";
					case '5':
						return "05";
					case '6':
						return "06";
					case '7':
						return "07";
					case '8':
						return "08";
					case '9':
						return "09";
				}
				break;
			case '1':
				switch(c2){
					case '0':
						return "01";
					case '1':
						return "02";
					case '2':
						return "03";
					case '3':
						return "04";
					case '4':
						return "05";
					case '5':
						return "06";
					case '6':
						return "07";
					case '7':
						return "08";
					case '8':
						return "09";
					case '9':
						return "10";
				}
				break;
			case '2':
				switch(c2){
					case '0':
						return "02";
					case '1':
						return "03";
					case '2':
						return "04";
					case '3':
						return "05";
					case '4':
						return "06";
					case '5':
						return "07";
					case '6':
						return "08";
					case '7':
						return "09";
					case '8':
						return "10";
					case '9':
						return "11";
				}
				break;
			case '3':
				switch(c2){
					case '0':
						return "03";
					case '1':
						return "04";
					case '2':
						return "05";
					case '3':
						return "06";
					case '4':
						return "07";
					case '5':
						return "08";
					case '6':
						return "09";
					case '7':
						return "10";
					case '8':
						return "11";
					case '9':
						return "12";
				}
				break;
			case '4':
				switch(c2){
					case '0':
						return "04";
					case '1':
						return "05";
					case '2':
						return "06";
					case '3':
						return "07";
					case '4':
						return "08";
					case '5':
						return "09";
					case '6':
						return "10";
					case '7':
						return "11";
					case '8':
						return "12";
					case '9':
						return "13";
				}
				break;
			case '5':
				switch(c2){
					case '0':
						return "05";
					case '1':
						return "06";
					case '2':
						return "07";
					case '3':
						return "08";
					case '4':
						return "09";
					case '5':
						return "10";
					case '6':
						return "11";
					case '7':
						return "12";
					case '8':
						return "13";
					case '9':
						return "14";
				}
				break;
			case '6':
				switch(c2){
					case '0':
						return "06";
					case '1':
						return "07";
					case '2':
						return "08";
					case '3':
						return "09";
					case '4':
						return "10";
					case '5':
						return "11";
					case '6':
						return "12";
					case '7':
						return "13";
					case '8':
						return "14";
					case '9':
						return "15";
				}
				break;
			case '7':
				switch(c2){
					case '0':
						return "07";
					case '1':
						return "08";
					case '2':
						return "09";
					case '3':
						return "10";
					case '4':
						return "11";
					case '5':
						return "12";
					case '6':
						return "13";
					case '7':
						return "14";
					case '8':
						return "15";
					case '9':
						return "16";
				}
				break;
			case '8':
				switch(c2){
					case '0':
						return "08";
					case '1':
						return "09";
					case '2':
						return "10";
					case '3':
						return "11";
					case '4':
						return "12";
					case '5':
						return "13";
					case '6':
						return "14";
					case '7':
						return "15";
					case '8':
						return "16";
					case '9':
						return "17";
				}
				break;
			case '9':
				switch(c2){
					case '0':
						return "09";
					case '1':
						return "10";
					case '2':
						return "11";
					case '3':
						return "12";
					case '4':
						return "13";
					case '5':
						return "14";
					case '6':
						return "15";
					case '7':
						return "16";
					case '8':
						return "17";
					case '9':
						return "18";
				}
				break;
		}//end_switch
		return "XX";
		
	}//end_PLUS_TABLE


};











#endif