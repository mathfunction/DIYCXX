

#include "cxxuseful.hpp"


using namespace cxxuseful;
using namespace std;
using json = nlohmann::json;

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
	j = jsonfc.read("politics.json");
	
	
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


	// join 字串
	s1 = u8(",").join({u8("我正要去"),u8("空中大學"),u8("!!")});
	s1.print();


	// split 字串
	vector<u8> v;
	s1("!看我看看!知道什麼!到底要知道什麼!!知道什麼不知道!知道最好!!看!");
	s1.print();
	v = s1.ngram(3);
	print(v);
	v = s1.split("!");
	print(v);
	v = s1.split(u8("知道"));
	print(v);

	s1 = u8("測試").join(v);
	s1.print();
	
	//==========================================================================================================================
	// set

	unordered_map<int,int> dict2 = {
		{1,1},
		{3,2},
		{5,4},
		{7,5},
		{9,10},
		{11,12}
	};
	unordered_set<int> _setA = setfunc.keys<int,int>(dict2);
	print(_setA);
	unordered_set<int> _setB = setfunc.vals<int,int>(dict2);
	print(_setB);

	print(setfunc.union2<int>(_setA,_setB));
	print(setfunc.diff2<int>(_setA,_setB));
	print(setfunc.diff2<int>(_setB,_setA));
	print(setfunc.inter2<int>(_setA,_setB));


	//==============================================================================
	// FilePath !! 
	FilePath f("/mnt/c/Users/XXX/Desktop/怕.jpg");
	f.print();
	print(f.tokens());
	FilePath("C:\\Program Files (x86)\\微軟\\HelloWorld.cpp","\\").print();
	
	#if defined _WIN32 || defined _WIN64
		// __FILE__ = C macro 取得此檔案的絕對路徑
		FilePath(__FILE__,"\\").print();
	#else
		FilePath(__FILE__).print();
	#endif

	cout << "DataFrame : " << endl;
	


	//========================================================================
	// DataFrame
	DataFrame df({"name","integers","doubles"});
	df += {"A",1,0.345};
	df += {"B",4,0.3224};
	df += {"C",6,0.4554};
	df += {"BoostInt",BoostInt(1),BoostInt(239293)};  // 
	df += {"BoostFloat",BoostFloat(2.3209),BoostFloat(2.349034)};
	df += {"BoostRational",BoostRational(14,16),BoostRational(2,3)};
	df.print({0,1,2,3,4,5},/*setn=*/20);

	//========================================================================
	
	// create 3 x 4 x 5 matrix 
	cxxTensor<int> matA({5,4});
	for(int i=0;i<matA.shape(0);i++){
		for(int j=0;j<matA.shape(1);j++){
			matA[{i,j}] = i+j;
		}//endfor
	}//endfor

	printBlueGreen("============= cxxTensor =================",true);



	matA.print();
	printYellow("__________ dual ____________",true);
	auto d = matA.dual();
	vector<int> coo_sum4 = d[4];
	for(int i=0;i<coo_sum4.size();i++){
		print(matA.fromIdx(coo_sum4[i]));
	}//endfor


	printYellow("__________ copy ____________",true);
	cxxTensor<int> cmatA = matA;
	cmatA.print();

	printYellow("__________ assignments ____________",true);
	matA[{1,1}] = 2000;
	matA[{2,3}] = 2000;
	matA.assign({/*coos=*/{0,1},{1,2},{1,3}},/*vals=*/{1000,1000,1000});
	matA.print();

	printYellow("_________ reshape ____________",true); 
	matA.reshape({3,2,2});
	matA.print();
	matA.reshape({1,3,4});
	matA.print();
	matA.reshape({12,1});
	matA.print();
	matA.reshape({1,12});
	matA.print();
	printYellow("__________ transpose __________",true);
	matA.reshape({3,4});
	cxxTensor<int> matB = matA.transpose({1,0});
	matA.print();
	matB.print();
	

	printYellow("_________ constant _________",true);
	cxxTensor<BoostFloat> matC({3,3,3},1.2349034);
	matC.print();
	printYellow("________ initialize _________",true);
	matC = {1.247834,2.549859,3.498,4.4893,5.4309,6.4039,7.4390};
	matC.print();
	matC = {{1,1,1},{2,3,4},{5,8,9}};
	matC.print();
	matC = {
		{{1,1,1},{1,1,1},{1,1,1}},
		{{2,2,2},{2,2,2},{2,2,2}}
	};
	matC.print();
	
	matC = {{
		{{1,2,3},{4,5,6},{7,8,9}},
		{{10,11,12},{13,14,15},{16,17,18}},
		{{19,20,21},{22,23,24},{25,26,27}}
	}};
	
	matC.print();

	//======================================================================
	// SIMD 
	vector<int> result;
	{
		Timer t2("SIMD");
		for(int i=0;i<1000;i++){
			result = avxfunc.add_8ints({-1,2,3,4,5,-6,7,8},{1,2,3,4,5,6,7,8});
		}//endfor
	}
	print(result);
	
	return 0;
}//end_main