/*--------------------------------------------

    vector<string> files =  get_all_files_names_within_folder("./folder");
    //  string_handle.hpp
    print(files);
------------------------------------------*/



#ifndef __FILE_SYSTEM_HPP__
#define __FILE_SYSTEM_HPP__

#include <vector>
#include <windows.h>
#include <sstream>
#include "string_handle.hpp"


using namespace std;


namespace file_system{


    // windows 
    vector<string> get_all_files_names_within_folder(string folder){
        vector<string> names;
        string search_path = folder + "/*.*";
        WIN32_FIND_DATA fd; 
        HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
        if(hFind != INVALID_HANDLE_VALUE) { 
            do { 
                // read all (real) files in current folder
                // , delete '!' read other 2 default folder . and ..
                if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                    names.push_back(fd.cFileName);
                }
            }while(::FindNextFile(hFind, &fd)); 
            ::FindClose(hFind); 
        } 
        return names;
    }//end_get_all_files_names_within_folder





    vector<string> getTailFiles(string filedir,string tail,bool _boolPrint=false){
        vector<string> output;
        vector<string> _listGridFiles =  get_all_files_names_within_folder(filedir);
            for(int i=0;i<_listGridFiles.size();i++){
                vector<string> temp = string_handle::split(_listGridFiles[i]);
                if(temp[temp.size()-1] == tail){
                    output.push_back(_listGridFiles[i]);
                }//endif
            }//endfor
        if(_boolPrint == true){
            string_handle::print(output);
        }//endif
        return output;
    }//end_readGridFile




    vector<string> addDir(vector<string> &files,string folder="./",bool _boolPrint=false){
        vector<string> output;
        for(int i=0;i<files.size();i++){
            output.push_back(folder + files[i]);
        }//endfor
        if(_boolPrint == true){
            string_handle::print(output);
        }//endif
        return output;
    }//end_addDirs





}//end_namespace



#endif





