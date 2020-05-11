#ifndef __PARALLEL_BLOCK_HPP__
#define __PARALLEL_BLOCK_HPP__

#include <thread>
#include <functional>


namespace cxxuseful{
/*=======================================================================
// 註: while(); 迴圈 要使用 O0 沒最佳化的情況編譯

=========================================================================*/


namespace ThreadsPiplines{
	#ifndef __NUM_CPUS__
		#define __NUM_CPUS__ 4
	#endif


	// global variables
	std::thread threads[__NUM_CPUS__];
	bool idle[__NUM_CPUS__];
	int while_on[__NUM_CPUS__];
	std::function<void()> funcTable[__NUM_CPUS__]; 

	__attribute__((optimize("O0")))
	void threads_main(int id){
		while(while_on[id]){
			while(!idle[id]);
			funcTable[id]();
			idle[id] = false;
		}//end_while
	}//end_run

	void run_all(){
		for(int i=0;i<__NUM_CPUS__;i++){
			idle[i] = true;
		}//endfor
	}



	__attribute__((optimize("O0")))
	void wait_all_idle(){
		for(int i=0;i<__NUM_CPUS__;i++){
			while(idle[i]);
		}//endfor
	}//end_wait



	
	void init(){
		for(int i=0;i<__NUM_CPUS__;i++){
			while_on[i] = 1;
		}//endfor
		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i] = std::thread(threads_main,i);
		}//endfor
		printBlueGreen("create "+std::to_string(__NUM_CPUS__) + "/" + std::to_string(std::thread::hardware_concurrency()) +  " [piplines/numCPUs]",true);
	}//init

	
	void join(){
		for(int i=0;i<__NUM_CPUS__;i++){
			while_on[i] = 0;
		}//endfor

		for(int i=0;i<__NUM_CPUS__;i++){
			idle[i] = true;
		}//endfor

		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i].join();
		}//endfor 

		printBlueGreen("closed "+std::to_string(__NUM_CPUS__) + " pipines",true);

	}

	



};//===============================================================================================================================================


	
	
};







#endif