/*

	g++ -std=c++11 -O3 -o test test.cpp -I. -I./src -I"C:\Users\Tommy_Cheng\Desktop\cxx_useful\3rdparty\boost_1_68_0"
	g++ -std=c++11 -O3 -o test test.cpp -I. -I./src -I"../../cxx_useful/third_party/boost_1_70_0"

*/


#include <iostream>
#include <functional>
#include <unordered_map>
#include <typeinfo>
#include "boost/any.hpp"
using namespace std;


namespace typefunc{
	//=======================================================================
	template<typename T>
	class Typefunc{
		private:
			// type_name
			string STR_NAME = typeid(string).name();
			string INT_NAME = typeid(int).name();
			string DOUBLE_NAME = typeid(double).name();
			string CONSTCHAR_NAME = "PKc";

		protected:
			boost::any _output;
			// implementation 
			virtual void handleDouble(double d){
				_output = d;
			}//end_handleDouble
			virtual void handleInt(int i){
				_output = i;
			}//end_handleInt
			virtual void handleString(string s){
				_output = s;
			}//end_handleString
			
		public:
			T operator()(boost::any val){
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
				return boost::any_cast<T>(_output);
			}//end_get
					
	};
	//=================================================================================

	
	










};//end_namespace 


using namespace typefunc;




int main(){
	
	
	
	

	return 0;
}//end_main