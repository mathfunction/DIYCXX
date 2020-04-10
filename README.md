### 專案概述 [ 開發中!! ]

 - 這是嘗試讓 C++ 一些易用好開發的函式庫 ~  
 - **headfile-only**  都在 include/* 只需要 #include\<cxxuseful\>  in yourfile
- 詳細用法可見 example/hello.cpp
- 作者: Plus & Minus
- 更新日期: 2020.04.10 

### 測試環境 (作業系統 / **終端機** / 編譯器)

- windows 10 , cmd , g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
- mac os , terminal  , Apple LLVM version 10.0.0 (clang-1000.10.44.4)

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

```shell
g++ -std=c++14 -O3 -o yourfile.cpp -I"{yourpath}/include/" -I"{yourpath}/thirdparty/{dirname}"
```



### include/* 檔案說明

| 檔名               | 說明                                |
| ------------------ | ----------------------------------- |
| boost_includes.hpp | 關於此專案會需要用到的 boost 函式庫 |
| cmdcolor           | 關於在終端機上顯示顏色              |
| makestrfunc        | 建立字串實用程序                    |
| printfunc          | 列印 STL 結構實用程序               |
| todictfunc         | STL結構 轉換成 HashTable 實用程序   |

