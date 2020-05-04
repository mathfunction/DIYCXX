/*==================================================================
	cxxTensor::
		[{座標}]         回傳 _arr 陣列值
		dual       回傳一對多 _arr[i] ----> std::vector(i)
		shape      顯示形狀
		reshape    重訂形狀 (值得排列方式不變)
		fromIdx    1 維位置 到 多維座標
		toIdx      多維座標 到 1 維位置
		transpose  轉置運算 <會複製出新的矩陣>
		ptr        取得 arr 指標
		assign     多位置賦值

		






====================================================================*/




#ifndef __CXXTENSOR_HPP__
#define __CXXTENSOR_HPP__


namespace cxxuseful{
	template <typename T>
	class cxxTensor{
		private:
			std::vector<T> _arr;
			std::basic_string<int>  _shape;
			std::basic_string<int>  _prodshape;
			
			
		public:
			
			//==================================================================================================
			// init
			cxxTensor(const std::initializer_list<T>& _init){
				this->reshape({int(_init.size())});
				for(int i=0;i<_init.size();i++){
					_arr[i] = _init.begin()[i];
				}//endfor
			}//end_cxxTensor

			cxxTensor(const std::initializer_list<std::initializer_list<T> >& _init2){
				this->reshape({int(_init2.size()),int(_init2.begin()[0].size())});
				for(int i=0;i<_init2.size();i++){
					for(int j=0;j<_init2.begin()[0].size();j++){
						this->operator[]({i,j})= _init2.begin()[i].begin()[j];
					}//endfor
				}//endfor
			}

			cxxTensor(const std::initializer_list<std::initializer_list<std::initializer_list<T> > >&_init3){
				this->reshape({
					int(_init3.size()),
					int(_init3.begin()[0].size()),
					int(_init3.begin()[0].begin()[0].size())
				});
				for(int i=0;i<_init3.size();i++){
					for(int j=0;j<_init3.begin()[0].size();j++){
						for(int k=0;k<_init3.begin()[0].begin()[0].size();k++){
							this->operator[]({i,j,k})= _init3.begin()[i].begin()[j].begin()[k];
						}//endfor
					}//endfor
				}//endfor
			}
			
			cxxTensor(const std::initializer_list<std::initializer_list<std::initializer_list<std::initializer_list<T> > > > &_init4){
				this->reshape({
					int(_init4.size()),
					int(_init4.begin()[0].size()),
					int(_init4.begin()[0].begin()[0].size()),
					int(_init4.begin()[0].begin()[0].begin()[0].size())
				});
				for(int i=0;i<_init4.size();i++){
					for(int j=0;j<_init4.begin()[0].size();j++){
						for(int k=0;k<_init4.begin()[0].begin()[0].size();k++){
							for(int t=0;t< _init4.begin()[0].begin()[0].begin()[0].size();t++){
								this->operator[]({i,j,k,t})= _init4.begin()[i].begin()[j].begin()[k].begin()[t];
							}//endfor
						}//endfor
					}//endfor
				}//endfor
			}//end_cxxTensor
			
			


			cxxTensor(const std::basic_string<int>& _shape){
				this->reshape(_shape);
			}
			cxxTensor(const std::basic_string<int>& _shape,const T& constant){
				this->reshape(_shape);
				for(int i=0;i<_arr.size();i++){
					_arr[i] = constant;
				}//endfor
			}
			//=====================================================================================================


			std::basic_string<int> shape(){
				return _shape;
			}//end
			int shape(int i){
				return _shape[i];
			}
			std::vector<T>& data(){
				return _arr;
			}//end_data

			cxxTensor& reshape(const std::basic_string<int> &_shape){
				int _size = 1;
				int n = _shape.size();
				this->_prodshape.resize(n);
				for(int i=0;i<n;i++){
					_size *= _shape[n-1-i];
					this->_prodshape[n-1-i] = _size;
				}//endfor
				// {IJK,JK,K,1}
				this->_prodshape += 1;
				this->_shape = _shape;
				this->_arr.resize(_size);
				return *this;
			}//end_shape



			inline std::basic_string<int> fromIdx(int idx){
				std::basic_string<int> coo;
				int _sum = 0;
				for(int i=1;i<_prodshape.size();i++){
					coo += (idx/_prodshape[i]);
					idx -= coo[i-1]*_prodshape[i];
				}//endfor
				return coo;
			}
			inline int toIdx(const std::basic_string<int>& coo){
				int idx = 0;
				for(int i=0;i<coo.size();i++){
					idx += (coo[i]*_prodshape[i+1]);
				}//endfor
				return idx;
			}//endfromIdx


			// reallocate
			cxxTensor transpose(const std::basic_string<int> &order){
				std::basic_string<int> _newshape;
				std::basic_string<int> coo;
				std::basic_string<int> rcoo;

				for(int i=0;i<order.size();i++){
					_newshape += _shape[order[i]];
				}
				cxxTensor _newTensor(_newshape);
				
				for(int i=0;i<_arr.size();i++){
					coo = this->fromIdx(i);
					rcoo.resize(coo.size());
					for(int j=0;j<rcoo.size();j++){
						rcoo[j] = coo[order[j]];
					}//endfor
					_newTensor[rcoo] = _arr[i];
				}//endfor
				return _newTensor;
			}//end_transpose 


			cxxTensor& assign(const std::vector<std::basic_string<int> >&coos,const std::vector<T> &vals){
				std::vector<T*> ptrs = this->ptr(coos);
				for(int i=0;i<ptrs.size();i++){
					*ptrs[i] = vals[i];
				}//endfor
				return *this;
			}//endfor


			



			std::unordered_map<T,std::vector<int> > dual(){
				std::unordered_map<T,std::vector<int> > d;
				for(int i=0;i<_arr.size();i++){
					d[_arr[i]].emplace_back(i);
				}//endfor
				return d;
			}//dual

			int size(){
				return _arr.size();
			}//end_size
			inline T& operator[](int i){
				return _arr[i];
			}//end_arr
			

			inline T& operator[](const std::basic_string<int>& coo){
				return _arr[toIdx(coo)];
			}
			
			std::vector<T*> ptr(const std::vector<std::basic_string<int> >&coos){
				std::vector<T*> output;
				for(int i=0;i<coos.size();i++){
					output.emplace_back(&_arr[toIdx(coos[i])]);  
				}//endfor
				return output;
			}//end_ptr 

			T* ptr(){
				return &_arr[0];
			}

			void print(){
				std::cout << "shape : ";
				for(int i=0;i<_shape.size();i++){
					std::cout << _shape[i] << " x ";
				}//endfor
				std::cout << std::endl;
				for(int i=0;i<_arr.size();i++){
					std::basic_string<int> coo = this->fromIdx(i);
					std::cout << "(";
					for(int j=0;j<coo.size();j++){
						std::cout << coo[j] << ",";
					}
					std::cout  << ") : " << _arr[i] << std::endl;
				}//endfor
				std::cout << "--------------------" << std::endl;
			}//end_print()



	};


};



#endif