/*-------------------------------
	source code :
		https://www.youtube.com/watch?v=oEx5vGNFrLk
---------------------------------*/




#ifndef __TIMER_HPP__
#define __TIMER_HPP__


#include <iostream>
#include <chrono>


namespace cxxuseful{
	using namespace std;
	
	
	/*
	class Timer{
		
		public:
			chrono::time_point<chrono::steady_clock> start,end;
			chrono::duration<float> duration;
			string program_name;
		Timer(string program_name){
			this->program_name = program_name;
			start = chrono::high_resolution_clock::now();
		}//end_Timer
		~Timer(){
			end = chrono::high_resolution_clock::now();
			duration = end-start;
			cerr << program_name << " tooks " << duration.count()*1000.0f << " ms" << endl;
		}
		
	};*/

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
				cerr << program_name << " costs " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " s)" << endl;
			};
	};
	
	


};//end_cxxuseful





#endif 