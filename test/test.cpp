/*

	g++ -std=c++11 -O3 -o test test.cpp -I../include  -I"C:\Users\Tommy_Cheng\Desktop\cxx_useful\3rdparty\boost_1_68_0"
	g++ -std=c++11 -O3 -o test test.cpp -I. -I./src -I"../../cxx_useful/third_party/boost_1_70_0"
	

*/
#include "printfunc.hpp"

using namespace typefunc;


int main(){
	vector<string> a({"1289","34898"});
	print(a);
	basic_string<int> b({1,2,3,4,5,6,7});
	print(b);








	return 0;
}//end_main