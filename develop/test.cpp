/*

	need boost library 
	
	-I"C:\Users\Tommy_Cheng\Desktop\cxx_useful\3rdparty\boost_1_70_0"
	-I"/mnt/c/Users/Tommy_Cheng/Desktop/cxx_useful/3rdparty/boost_1_70_0"
*/

#include <iostream>
#include <cstdlib>
#include "chinese_handle.hpp"


using namespace std;
using namespace cxx_useful;

int main(){ 
	

	print(s2ws("122989我知道"));
	
	/*
	std::wstring _wstr= s2ws(_str);
	for(int i=0;i<_wstr.size();i++){
		std::wcout << _wstr[i] << std::endl;
	}//endfor
	*/
	
	return 0;
}//end_main