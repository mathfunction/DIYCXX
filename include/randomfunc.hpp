/*================================================================================

	這是關於隨機亂數產生器 !! 
		
		- unif_int(_size,min)  隨機產生 [min,min+_size) 之間的整數
		- draw_one_at_a_time(_dist,_drawsize,_boolPrint,_boolReplacement) 
			逐一從 _dist 離散分布(unoredered_map<std::string,int>) 抽出 _drawsize 個東西  , _boolReplacement = true 代表取後放回 !!
		


=============================================================================*/
#ifndef __RANDOMFUNC_HPP__
#define __RANDOMFUNC_HPP__

	


namespace cxxuseful{
	
	class RandomFunc{
		private:
			unsigned seed;
			std::mt19937 gen;
			//mt19937_64 gen 
			//minstd_rand0 gen
			//minstd_rand gen
			
		public:
			RandomFunc(){
				setSeed();
			}//end_RandFunc
			void setSeed(std::string _strSeed="__NOW__"){
				if(_strSeed == "__NOW__"){
					this->seed = std::chrono::system_clock::now().time_since_epoch().count();
				}else{
					this->seed = static_cast<unsigned>(std::stoi(_strSeed));
				}//end_else
				this->gen = std::mt19937(this->seed);
				printGreen("RandomFunc set seed to "+_strSeed,true);
			}//end_setSeed
			double unif_real(double min=0,double max=1){
				std::uniform_real_distribution<> dist(min,max);
				return dist(gen);
			}//end_unif_real

			// [min,min+_size)
			int unif_int(int _size,int min=0){
				return min + gen()%_size;
			}//end unif

			std::vector<std::string> draw_one_at_a_time(const std::unordered_map<std::string,int> &_dist,int _drawsize=1,bool _boolPrint=false,bool _boolReplacement=false){
				// compute total size , build blackbox
				std::vector<std::string> result;
				std::vector<std::string> blackbox;
				std::vector<std::string>::iterator it;
				for(auto &kv:_dist){ 
					for(int i=0;i<kv.second;i++){
						blackbox.push_back(kv.first);
					}//endfor
				}//endfor
				if(_boolPrint){ 
					print(blackbox);
				}//endif
				// draw 
				for(int i=0;i<_drawsize;i++){
					if(blackbox.empty()){
						break;
					}else{
						it = blackbox.begin();
						it += this->unif_int(blackbox.size());
						result.push_back(*it);
						if(_boolReplacement == false){
							blackbox.erase(it);
						}//endif
					}//endif
				}//endfor

				if(_boolPrint){
					std::cout << "____ result _____" << std::endl;
					print(result);
				}//endif
				return result;
			}//end_box_draw



	} randfc;



};//end_namespace
































#endif
















