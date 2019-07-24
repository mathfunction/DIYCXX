/*

	g++ -std=c++11 -O3 -o test test.cpp -I. -I./src -I"C:\Users\Tommy_Cheng\Desktop\cxx_useful\3rdparty\boost_1_68_0"

*/


#include <iostream>
#include <functional>
#include <typeinfo>
#include "boost/any.hpp"
using namespace std;




class HandleType{
	private:
		string STR_NAME = typeid(string).name();
		string INT_NAME = typeid(int).name();
		string DOUBLE_NAME = typeid(double).name();
		string CONSTCHAR_NAME = "PKc";
		
	protected:
		boost::any _output;
		virtual boost::any handleDouble(double d){
			cout << "I'm double " << d << endl;
			return _output;
		}
		virtual boost::any handleInt(int i){
			cout << "I'm int " << i << endl;
			return _output;
		}
		virtual boost::any handleString(string s){
			cout << "I'm string " << s << endl;
			return _output;
		}


	public:
		HandleType(boost::any val){
			string _strType = (val.type()).name();
			
			if(_strType == STR_NAME){
				handleString(boost::any_cast<string>(val));
			}else if(_strType == CONSTCHAR_NAME){
				handleString(string(boost::any_cast<const char*>(val)));
			}else if(_strType == INT_NAME){
				handleInt(boost::any_cast<int>(val));
			}else if(_strType == DOUBLE_NAME){
				handleDouble(boost::any_cast<double>(val));
			}else{
				cout << "[Error] Unable to find type : " << _strType << endl;
				exit(1);
			}//end_else		
		}//end_HandleType
		
};



class MyClass:public HandleType{
	protected:
		boost::any handleDouble(double d) override {
			cout << d+1 << endl;
			return _output;
		}
	public:	
		MyClass(boost::any val):HandleType(val){
			handleDouble(1.2);
		}
		
};






int main(){
	
	MyClass a(1.23);
	
	
	
	

	return 0;
}//end_main