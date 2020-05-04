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



namespace cxxuseful{
	
	
	
	class TimerBaseClocker{
		public:
			TimerBaseClocker(){ m_start = -1;}
			void clear(){ m_start = -1;}
			bool IsStarted() const {return (m_start != -1);}
			void Start(){ m_start = std::clock();}
			std::clock_t GetMs(){
				std::clock_t now;
				if(IsStarted()){
					now = std::clock();
					std::clock_t dt = now - m_start;
					return dt;
				}//end_if
				return 0 ;
			}//end_GetMs  
		private:	
			std::clock_t m_start;
	};

	class Timer : public TimerBaseClocker{
		private:
			std::string program_name;
		public:
			Timer(std::string program_name){
				this->program_name = program_name;
				Start();	
			};
			~Timer(){
				std::clock_t t = GetMs();
				std::cerr << "Block{" << program_name << "} : " << 1000*((float)t)/CLOCKS_PER_SEC << " ms" << std::endl;
			};
	};
	
	


};//end_cxxuseful





#endif 