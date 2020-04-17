

#include "cxxuseful.hpp"
using namespace cxxuseful;







int main(int argc,char* argv[]){
	if(argc !=2){
		cout << "=====================" << endl;
		cout << "--server" << endl;
		cout << "--client" << endl;
		cout << "=====================" << endl;

	}else{
		if(string(argv[1])=="--server"){
			AsioServer().run();
		}else if(string(argv[1])=="--client"){
			AsioClient().cmdtest();
		}else{
			
		}//end_else
	}//end_else

	
		




	return 0;
}//end_main