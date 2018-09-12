/*

	This is a class you can measure time easily !! 


*/
#ifndef __CXXCLOCKER_HPP__
#define __CXXCLOCKER_HPP__
#include <iostream>
#include <ctime>
using namespace std;

namespace cxxclocker{

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
		public:
		Timer(){
			Start();	
		};
		~Timer(){
			clock_t t = GetMs();
			cout << "It costs " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << ")" << endl;
		};
	};
}

#endif 


/*
#include "cxxclocker.hpp"

int main(){
	
	{//--------------------------------------------------------------------------------------
		cxxclocker::Timer clock;
		
		for(int i=0;i<10e8;i++){
			if(i!=-1) continue;
		}
	}//--------------------------------------------------------------------------------------


	return 0;
}//end_main

*/