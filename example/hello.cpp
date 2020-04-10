
#include "cxxuseful.hpp"
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
	// shlr
	string _str = shlr({1,0.123,"456"},"_","X");
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
	// makedictfunc
	basic_string<int> _bas({2,3,4,5,6,7,8});
	auto _dictBastr = type<unordered_map<int,int> >(mkdict(_bas));
	print(_dictBastr);
	

	print(otherfc.cumulative({
		{"a",0.5},
		{"b",0.3},
		{"c",0.2}
	}));

	//==================================================
	// randomfunc
	cout << "toss-coin : " << randfc.unif_int(2) << endl;
	cout << shlr(randfc.draw_one_at_a_time({{"a",8},{"b",5}},10,true)) << endl;
	//==================================================
	
	// timer
	{
		Timer timer("test");
		for(int i=0;i<1000;i++){
			cerr << i << "|";
		}
		cerr << endl;

	}
	//=============================================================================================================
	// utf8 
	string _cxxstr = "C++中文處理真的很麻煩，超級難⁉⁉最後是用 UTF-8 切中字串 u8len() 變成 vector<string> 😅 ";
	utf8 _cxxstr2 = s2u8(_cxxstr);
	for(int i=0;i<_cxxstr2.size();i++){
		if(_cxxstr2[i] == "中"){
			_cxxstr2[i] = "英";
		}//endif
	}//endfor
	print_utf8(_cxxstr2);
	return 0;
	
}//end_main