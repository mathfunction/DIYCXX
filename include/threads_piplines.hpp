#ifndef __THREADS_PIPLINES_HPP__
#define __THREADS_PIPLINES_HPP__

#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>


namespace cxxuseful{
/*=======================================================================
// 註: while(); 迴圈 要使用 O0 沒最佳化的情況編譯

=========================================================================*/
#ifndef __NUM_CPUS__
	#define __NUM_CPUS__ 4
#endif

namespace ThreadsPiplines{
	


	// global variables
	std::thread threads[__NUM_CPUS__];
	bool idle[__NUM_CPUS__];
	int while_on[__NUM_CPUS__];
	std::function<void()> funcTable[__NUM_CPUS__]; 
	std::basic_string<int> idleID;

	
	#ifdef __clang__
		[[clang::optnone]]
		void threads_main(int id){
			while(while_on[id]){
				while(idle[id]);
				funcTable[id]();
				idle[id] = true;
			}//end_while
		}//end_run
	#else 
		__attribute__((optimize("O0")))
		void threads_main(int id){
			while(while_on[id]){
				while(idle[id]);
				funcTable[id]();
				idle[id] = true;
			}//end_while
		}//end_run
	#endif

	void run_all(){
		for(int i=0;i<__NUM_CPUS__;i++){
			idle[i] = false;
		}//endfor
	}


	void run(int id){
		idle[id] = false;
	}

	#ifndef __clang__
		[[clang::optnone]]
		void wait_idle(int id){
			while(!idle[id]);
		}
	#else
		void wait_idle(int id){
			while(!idle[id]);
		}
	#endif

	#ifdef __clang__
		[[clang::optnone]]
		void wait_all_idle(){
			for(int i=0;i<__NUM_CPUS__;i++){
				while(!idle[i]);
			}//endfor
		}//end_wait
	#else
		__attribute__((optimize("O0")))
		void wait_all_idle(){
			for(int i=0;i<__NUM_CPUS__;i++){
				while(!idle[i]);
			}//endfor
		}//end_wait
	#endif 

	void check_exists_idle(){
		while(idleID.size()==0){
			for(int i=0;i<__NUM_CPUS__;i++){
				if(idle[i] == true){
					idleID += i;
				}//endif
			}//endfor
		}//end_while
	}

	void run_exists_idle(){
		for(int i=0;i<idleID.size();i++){
			run(i);
		}//endfor
		idleID.clear();
	}

	
	void init(){
		for(int i=0;i<__NUM_CPUS__;i++){
			while_on[i] = 1;
			idle[i] = true;
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
			funcTable[i] = [](){}; // do nothing 
		}

		for(int i=0;i<__NUM_CPUS__;i++){
			idle[i] = false;
		}//endfor

		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i].join();
		}//endfor 

		printBlueGreen("closed "+std::to_string(__NUM_CPUS__) + " pipines",true);

	}

	







};//===============================================================================================================================================


namespace ThreadsPiplines2{
	
	std::queue<int> q[__NUM_CPUS__];
	std::mutex mtx[__NUM_CPUS__];
	std::mutex mtx2;
	
	std::condition_variable cv;
	void push(int i,int val){
		mtx[i].lock();
		q[i].push(val);
		mtx[i].unlock();
	}

	std::thread threads[__NUM_CPUS__];
	

	void threads_main(int id){
		if(!q[id].empty()){
			mtx2.lock();
			std::cout << "======================" << std::endl;
			for(int i=0;i<__NUM_CPUS__;i++){
				std::cout << "[" << i << "] " << q[i].size() << "," ;
			} std::cout << std::endl;
			q[id].pop();
			mtx2.unlock();		
			threads_main(id);
		}else{
			return;
		}
		
	}//end_threads_main
		
	void run(){
		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i] = std::thread(threads_main,i);
		}//endfor
	}
	
	
	void wait_all_empty(){
		std::mutex mtx3;
		std::unique_lock<std::mutex> lock(mtx3);
		cv.wait(lock);
	}
	

	void closed(){
		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i].join();
		}
	}

};

//========================================================================================================
	
};





	




#endif