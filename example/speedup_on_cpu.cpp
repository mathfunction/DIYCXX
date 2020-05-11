

#define __NUM_CPUS__ 2
#include "cxxuseful.hpp"



using namespace std;
using namespace cxxuseful;



queue<int> Q;

mutex mtx;


void do_something(int id,int input){
	mtx.lock();
	std::cout << id << "," << input << std::endl;	
	mtx.unlock();
}




int main(){
	
	for(int i=0;i<10000;i++){
		Q.push(i);
	}//endfor	

	ThreadsPiplines::init();
	{
		Timer timecost(to_string(__NUM_CPUS__));
		while(!Q.empty()){
			ThreadsPiplines::check_exists_idle();
			
			// 註冊函式 
			for(int i=0;i<ThreadsPiplines::idleID.size();i++){
				int id = ThreadsPiplines::idleID[i];
				ThreadsPiplines::funcTable[id] = std::bind(do_something,id,Q.front());
				ThreadsPiplines::run(id);
				Q.pop();
			}//endfor

			ThreadsPiplines::idleID.clear();
		}//end_while
		ThreadsPiplines::wait_all_idle();
		
	}

	ThreadsPiplines::join();
	
	//===========================================

	for(int i=0;i<1000;i++){
		ThreadsPiplines2::push(i%__NUM_CPUS__,i);
	}
	ThreadsPiplines2::run();


	ThreadsPiplines2::wait_all_empty();
	ThreadsPiplines2::closed();




		
	return 0;
}//end_main





