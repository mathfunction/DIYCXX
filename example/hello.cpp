
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

	//===============================================================================================================
	// json
	json j;
	try{
		 j = jsonfc.read("./example/politics.json");
	}catch(const char* e){
		 // 如果路徑在 examples 裡
		 j = jsonfc.read("./politics.json"); 
	}//end_try
	
	
	// cout << j << endl;   
	
	
	unordered_map<string,string> cov = jsonfc.dict<string,string>(j["衛生組織"]); 
	vector<string> who = jsonfc.list<string>(j["肺炎"]);
	vector<int> sicks = jsonfc.list<int>(j["武漢起始數據"]["累積確診人數"]);
	
	print(cov);
	print(who);
	print(sicks);	
	
	//======================================================================================================================
	// u8string

	typedef u8string u8;

	u8("_______這是 u8string_測試_________").print();
	u8 s1("中國");
	u8 s2("武漢");
	vector<u8> v;
	// concat 測試 !!
	(s1+s2).print();
	(s2+"肺炎").print();
	(s1+s2+"肺炎").print();
	(s1+"的"+s2).print();

	
	s1 = "1二3四5六";
	// 子字串測試
	s1(1,-1).print();
	s1(2,4).print();
	s1(3).print();
	// ngram 測試
	v = s1.ngram(2);
	v[0].print();
	v[1].print();
	v[2].print();

	// 測試相等 !! 
	s1 = "那個";
	if(s1=="那個"){
		s1.print();
	}

	s1 = "這個";
	if(s1=="這個"){
		s1.print();
	}

	s1("我知道");

	s2 = "我知道";
	if(s1 == s2){
		cout << "==" << endl;
	}else{
		cout << "!=" << endl;
	}
	// join 字串
	s1 = u8(",").join({u8("我看"),u8("要去"),u8("哪?")});
	s1.print();


	s1("我看看!知道什麼!到底要知道什麼!!知道");
	s1.print();
	v = s1.split("!");
	print(v);
	v = s1.split(u8("知"));
	print(v);
	s1 = u8("測試").join(v);
	s1.print();
	cout << s1.size() << endl;

	return 0;
}//end_main