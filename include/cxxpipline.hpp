




#ifndef __CXXPIPLINE_HPP__
#define __CXXPIPLINE_HPP__

#include <queue>
#include <thread>
#include <chrono>
#include <mutex>

namespace cxxuseful{


	

namespace cxxpipline{

	#define __NUM_CPUS__ 4
	

	
	std::queue<int> q[__NUM_CPUS__];
	std::mutex mtx;
		
	void push(int i,int val){
		mtx.lock();
		q[i].push(val);
		mtx.unlock();
	}

	std::thread threads[__NUM_CPUS__];
	bool _boolClosed = false;

	void threads_main(int id){
		
		if(_boolClosed){
			return;
		}
		if(!q[id].empty()){
			std::cout << q[id].front() << std::endl;
			q[id].pop();
			threads_main(id);
			// callback
		}
		
	}//end_threads_main
		
	void init(){
		for(int i=0;i<__NUM_CPUS__;i++){
			threads[i] = std::thread(threads_main,i);
		}//endfor
	}


	

	void closed(){
		_boolClosed = true;
	}


	





};













};//end_cxxpipline















#endif