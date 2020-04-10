/*================================================================================

	這是關於隨機亂數產生器 !! 
		
		- unif_int(_size,min)  隨機產生 [min,min+_size) 之間的整數
		- draw_one_at_a_time(_dist,_drawsize,_boolPrint,_boolReplacement) 
			逐一從 _dist 離散分布(unoredered_map<string,int>) 抽出 _drawsize 個東西  , _boolReplacement = true 代表取後放回 !!
		


=============================================================================*/
#ifndef __RANDOMFUNC_HPP__
#define __RANDOMFUNC_HPP__

	


namespace cxxuseful{

	class RandomFunc{
		private:
			unsigned seed;
			mt19937 gen;
			//mt19937_64 gen 
			//minstd_rand0 gen
			//minstd_rand gen
			
		public:
			RandomFunc(){
				setSeed();
			}//end_RandFunc
			void setSeed(string _strSeed="__NOW__"){
				if(_strSeed == "__NOW__"){
					this->seed = chrono::system_clock::now().time_since_epoch().count();
				}else{
					this->seed = static_cast<unsigned>(stoi(_strSeed));
				}//end_else
				this->gen = mt19937(this->seed);
				printGreen("RandomFunc set seed to "+_strSeed,true);
			}//end_setSeed
			// [min,min+_size)
			int unif_int(int _size,int min=0){
				return min + gen()%_size;
			}//end unif

			vector<string> draw_one_at_a_time(const unordered_map<string,int> &_dist,int _drawsize=1,bool _boolPrint=false,bool _boolReplacement=false){
				// compute total size , build blackbox
				vector<string> result;
				vector<string> blackbox;
				vector<string>::iterator it;
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
					cerr << "____ result _____" << endl;
					print(result);
				}//endif
				return result;
			}//end_box_draw



	} randomfunc;



};//end_namespace
































#endif
















