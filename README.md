### DIYCXX 專案概述 [ 開發階段中!! ]

 - 這是嘗試讓 C++ 一些易用輔助開發的函式庫 ~  

 - **headfile-only**  都在 include/*  

   ```c++
   #include "cxxuseful.hpp"
   using namespace cxxuseful;
   /* your codes */
   ```

- 詳細用法可見 example/hello.cpp  或是各 .hpp 置頂註解

- 作者: Plus & Minus

- 更新日期: 2020.04.10 

### 測試環境 (作業系統 / **終端機** / 編譯器)

- windows 10 ,  g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
- mac os  , Apple LLVM version 10.0.0 (clang-1000.10.44.4)

### 函式庫需求(預先安裝)

- 把以下的函式庫下載到 thirdparty/ 

- 第三方函式庫資訊:

  | 函式數名                                                     | 資料夾/檔名   | 用途                             |
  | ------------------------------------------------------------ | ------------- | -------------------------------- |
  | [boost](<https://www.boost.org/>)                            | boost_X_X_X/* | 可視為 STL 擴展                  |
  | [Eigen](<http://eigen.tuxfamily.org/index.php?title=Main_Page>) | Eigen/*       | 線性代數矩陣計算庫               |
  | [xtensor](<https://github.com/xtensor-stack/xtensor/tree/master/include/xtensor>) | xtensor/*     | 處理張量結構庫 (仿 python numpy) |
  | [json](<https://github.com/nlohmann/json/tree/develop/single_include/nlohmann>) | json.hpp      | 處理 json 結構                   |
  |                                                              |               |                                  |
  |                                                              |               |                                  |

### 編譯指令 

直接透過 g++

```shell
g++ -std=c++14 -O3 -o {your.cpp} -I"{yourpath}/include/" -I"{yourpath}/thirdparty/{project_name}"
```

或是透過 python 腳本編譯+試跑，參考  script.py

```shell
python script.py --compile {your.cpp}
python script.py --run {your.cpp}
```



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
| otherfunc.hpp| otherfc |已實作但無法分類區|


