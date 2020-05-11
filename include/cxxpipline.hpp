




#ifndef __CXXPIPLINE_HPP__
#define __CXXPIPLINE_HPP__

#include <queue>
#include <thread>
#include <chrono>
#include <mutex>

namespace cxxuseful{


	




	template<typename T>
	class CxxPipline{
		private:
			std::queue<T> Q;
			std::mutex mtx;
		public:
			CxxPipline(int num_threads){
				for(int i=0;i<num_threads;i++){
				 	std::thread(threads_main,i);
				}//endfor


			}


			void threads_main(int id){
				mtx.lock();
				
				Q.pop();
				if(!Q.empty()){
					threads_main(id);
				}//endif
				mtx.unlock();
			}//end_threads_main





	};



















}















#endif