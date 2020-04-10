### DIYCXX 專案概述 

$$
\bf 開發階段中～函式名稱，結構隨時有可能改變，僅供參考 !!
$$

 - 作者: Plus & Minus

- 更新日期: 2020.04.10 

 - 這是嘗試讓 C++ 一些易用輔助開發的函式庫

 - **headfile-only**  都在 include/*  

   ```c++
   #include "cxxuseful.hpp"
   using namespace cxxuseful;
   /* your codes */
   ```

- 詳細用法可見 example/hello.cpp 實作或是各 .hpp 置頂註解



### 測試環境 (作業系統 / **終端機** / 編譯器)

- windows 10 ,  g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
- ubuntu18.04 from wsl (windows subsystem for linux)  g++ 4.8.5
- mac os  , Apple LLVM version 10.0.0 (clang-1000.10.44.4)

### 函式庫需求(預先安裝)

- 把以下的函式庫下載到 thirdparty/ ，完成後類似下圖

  ![](./pic/3party.png)

- 第三方函式庫資訊:

  | 函式數名                                                     | 資料夾/檔名   | 用途                |
  | ------------------------------------------------------------ | ------------- | ------------------- |
  | [boost](<https://www.boost.org/>)                            | boost_X_X_X/* | 可視為 STL 擴展函式 |
| [json](<https://github.com/nlohmann/json/tree/develop/single_include/nlohmann>) | json.hpp      | 處理 json 結構      |
  



### 編譯指令 

直接透過 g++

```shell
g++ -std=c++14 -O3 -o {your.cpp} -I"{yourpath}/include/" -I"{yourpath}/thirdparty/{project_name}"
```

或是透過 python 腳本編譯+試跑，

```shell
python script.py --compile {your.cpp}
python script.py --run {your.cpp}
```

若要修改編譯器指令，可參考  script.py 的 cmds 如下圖:

![](./pic/pycmds.png)

### include/*.hpp 檔案說明

| hpp 檔名           | 實體物件名 | 說明                                |
| ------------------ | ----------------------------------- | ----------------------------------- |
| cxxuseful.hpp     | -    | 關於此專案所有 header 引用(包含 STL,Boost,DIY) |
| boost_includes.hpp | - | 關於此專案會需要用到的 boost 函式庫 |
| timer.hpp | - |程式區塊計時相關|
| printfunc.hpp      | print | 列印結構相關           |
| cmdcolor.hpp       | printXXX | 關於在終端機上顯示彩色字串 XXX = { Red , Yellow , Blue , Green ...} |
| makedictfunc.hpp| mkdict | 結構轉 unordered_map 相關|
| jsonfunc.hpp | jsonfc | json 處理相關 |
| randomfunc.hpp | randfc | 亂數產生模擬相關 |
| strhandler.hpp | shlr | 字串輔助相關 |
| utf8str.hpp| - | unicode , 中文字串切割相關|
| otherfunc.hpp| otherfc |已實作但無法分類區|



### 範例:  hello.cpp

- 終端機顯示彩色 string (尚未支援中文)

  ```cpp
  printRed("red",true);
  printGreen("green",true);
  printYellow("yellow",true);
  printBlueGreen("bluegreen",true);
  printBlue("blue",true);
  printPurple("purple",true);
  ```



- 混雜型別轉字串 (尚未支援中文)

  ```cpp
  string _str = shlr({1,0.123,"456"},/*分割元*/"_",/*head*/"X");
  cout << _str << endl;
  ```

  

- 宣告 / 列印 print 結構 

  ```cpp
  vector<int> _vec({1,2,3,4,5,6,7});
  	unordered_map<string,int> _dict({
  		{"key1",45},
  		{"key2",46}
  	});
  	print(_vec);
  	print(_dict);
  ```

- 陣列轉字典(位置=key)

  ```cpp
  basic_string<int> _bas({2,3,4,5,6,7,8});
  auto _dictBastr = type<unordered_map<int,int> >(mkdict(_bas));
  print(_dictBastr);
  ```

  ![](./pic/hello1.png)

- 程式區塊計時

  ```cpp
  { // 計時開始
  		Timer timer("test");
  		for(int i=0;i<1000;i++){
  			cerr << i << "|";
  		}
  		cerr << endl;
  }//計時結束
  ```

  ![](./pic/hello2.png)



- utf8 中文處理/顯示   (註: IDE/文字編輯器 需要為 utf8編碼 )

  ```cpp
  string _cxxstr = "C++中文處理真的很麻煩，超級難⁉⁉最後是用 UTF-8 切中字串 u8len() 變成 vector<string> 😅 ";
  utf8 _cxxstr2 = s2u8(_cxxstr); // utf8 本質上為 vector<string>
  // 把字串裡的"中"字改成"英"
  for(int i=0;i<_cxxstr2.size();i++){
  		if(_cxxstr2[i] == "中"){
  			_cxxstr2[i] = "英";
  		}//endif
  }//endfor
  print_utf8(_cxxstr2);
  ```

  ![](./pic/hello3.png)











