/*============================================================================================
	
	這是關於函式庫的範例使用
	g++ -std=c++11 -O3 -o hello hello.cpp -I"../include" -I"<PATH_TO_BOOST>"


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
	string _str = makestr({2,0.123456,"I'm String"},"_","[head]");
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
	basic_string<int> _bas({2,3,4,5,6,7,8});
	auto _dictBastr = type<unordered_map<int,int> >(todict(_bas));
	print(_dictBastr);
	

	print(todict.cumulative({
		{"a",0.5},
		{"b",0.3},
		{"c",0.2}
	}));

	//==================================================
	// randomfunc
	cout << "toss-coin : " << randomfunc.unif_int(2) << endl;
	cout << makestr(randomfunc.draw_one_at_a_time({{"a",8},{"b",5}},10,true)) << endl;
	//==================================================


	//====================================================
	
	// timer
	{
		Timer timer("test");
		for(int i=0;i<1000;i++){
			cerr << i << "|";
		}
		cerr << endl;

	}

	//======================================================
	// bayesain_stat











	return 0;
}//end_main