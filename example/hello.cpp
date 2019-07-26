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
	printBlueGreen("bluegreen",true);
	printBlue("blue",true);
	printPurple("purple",true);


	//===============================================
	// makestr
	int a = 2;
	double b = 0.12345949;
	string c = "I'm string";
	string _str = makestr({c,b,a,a},"_","[head]");
	cout << _str << endl;
	//================================================
	// print
	vector<int> _vec({1,2,3,4,5,6,7});
	unordered_map<string,int> _dict({
		{"key1",45},
		{"key2",46}
	});
	print(_vec);
	print(_dict);
	//================================================
	// todict
	basic_string<int> _bastr({2,3,4,5,6,7,8});
	print(_bastr);
	auto _dictBastr = type<unordered_map<int,int> >(todict(_bastr));
	print(_dictBastr);
	//==================================================
	



	return 0;
}//end_main