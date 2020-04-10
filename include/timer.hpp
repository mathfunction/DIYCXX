/*===================================
	實作參考 :
		https://www.youtube.com/watch?v=oEx5vGNFrLk
- 用法如下，可以測量以下 block 程式執行時間 !! 

{
	Timer t("block1");
}

=====================================*/

#ifndef __TIMER_HPP__
#define __TIMER_HPP__


#include <iostream>
#include <chrono>


namespace cxxuseful{
	using namespace std;
	
	
	class TimerBaseClocker{
		public:
			TimerBaseClocker(){ m_start = -1;}
			void clear(){ m_start = -1;}
			bool IsStarted() const {return (m_start != -1);}
			void Start(){ m_start = clock();}
			clock_t GetMs(){
				clock_t now;
				if(IsStarted()){
					now = clock();
					clock_t dt = now - m_start;
					return dt;
				}//end_if
				return 0 ;
			}//end_GetMs  
		private:	
			clock_t m_start;
	};

	class Timer : public TimerBaseClocker{
		private:
			string program_name;
		public:
			Timer(string program_name){
				this->program_name = program_name;
				Start();	
			};
			~Timer(){
				clock_t t = GetMs();
				cerr << "Block{" << program_name << "} : " << 1000*((float)t)/CLOCKS_PER_SEC << " ms" << endl;
			};
	};
	
	


};//end_cxxuseful





#endif 