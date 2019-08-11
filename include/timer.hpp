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

	};


};//end_cxxuseful





#endif 