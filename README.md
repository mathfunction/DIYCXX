



# [ 開發中 ]

### 專案概述

 - 這是嘗試讓 C++ 一些易用好開發的函式庫 ~  
 - **headfile-only**  都在 ./include/ 只需要 #include\<cxxuseful\>  in ***[yourfile]***
- 詳細用法可見 ./example/hello.cpp
- ./develop/ 為開發中檔案+測試 (無法使用)
- 作者: Fuyuan Cheng 
- 更新日期: 2019.07.26 

### 測試環境 (作業系統 / **終端機** / compiler)

- windows 10 , cmd , g++ (tdm-1) 5.1.0 , CodeBlocks  (C++11,C++14)
- mac os , terminal  , Apple LLVM version 10.0.0 (clang-1000.10.44.4)

### 函式庫需求(預先安裝)

- standard C++ boost library  1_X_0   [X>=66]  <https://www.boost.org/>

### 編譯指令

===============================================================================

g++ -std=c++11 -O3 -o [yourfile] [yourfile].cpp -I [path_to_boost_library]  -I[path_to_include]

===============================================================================

### ./include/ 檔案說明

| 檔名               | 說明                                |
| ------------------ | ----------------------------------- |
| boost_includes.hpp | 關於此專案會需要用到的 boost 函式庫 |
| cmdcolor           | 關於在終端機上顯示顏色              |
| makestrfunc        | 建立字串實用程序                    |
| printfunc          | 列印 STL 結構實用程序               |
| todictfunc         | STL結構 轉換成 HashTable 實用程序   |

