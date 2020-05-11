




#ifndef __CXXPIPLINE_HPP__
#define __CXXPIPLINE_HPP__

#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>



namespace cxxuseful{


	

namespace cxxpipline{

	#define __NUM_CPUS__ 4
	

	
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













};//end_cxxpipline















#endif