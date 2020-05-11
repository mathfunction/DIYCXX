
#include "cxxuseful.hpp"



using namespace std;
using namespace cxxuseful;


void run(int id,int *p){
	for(int i=0;i<100;i++){
		p[id] += 1;
	}//endfor
}




int main(){

	int buffer[4] = {0,0,0,0};
	ThreadsPiplines::funcTable[0] = std::bind(run,0,&buffer[0]);
	ThreadsPiplines::funcTable[1] = std::bind(run,1,&buffer[0]);
	ThreadsPiplines::funcTable[2] = std::bind(run,2,&buffer[0]);
	ThreadsPiplines::funcTable[3] = std::bind(run,3,&buffer[0]);


	
	ThreadsPiplines::init();

	
	ThreadsPiplines::run_all();
	ThreadsPiplines::wait_all_idle();
	
	for(int i=0;i<4;i++){
		cout << buffer[i] << endl;
	}//endfor
	

	
	ThreadsPiplines::join();
	
	








	return 0;
}//end_main