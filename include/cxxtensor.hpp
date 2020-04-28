
#ifndef __CXXTENSOR_HPP__
#define __CXXTENSOR_HPP__

namespace cxxuseful{
	using namespace std;
	template <typename T>
	class cxxTensor{
		private:
			vector<T> _arr;
			basic_string<int>  _shape;
			basic_string<int>  _prodshape;

			
			
		public:
			cxxTensor(const basic_string<int>& _shape){
				this->reshape(_shape);
			}
			basic_string<int> shape(){
				return _shape;
			}//end
			int shape(int i){
				return _shape[i];
			}


			cxxTensor& reshape(const basic_string<int> &_shape){
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



			inline basic_string<int> fromIdx(int idx){
				basic_string<int> coo;
				int _sum = 0;
				for(int i=1;i<_prodshape.size();i++){
					coo += (idx/_prodshape[i]);
					idx -= coo[i-1]*_prodshape[i];
				}//endfor
				return coo;
			}
			inline int toIdx(const basic_string<int>& coo){
				int idx = 0;
				for(int i=0;i<coo.size();i++){
					idx += (coo[i]*_prodshape[i+1]);
				}//endfor
				return idx;
			}//endfromIdx


			// reallocate
			cxxTensor transpose(const basic_string<int> &order){
				basic_string<int> _newshape;
				basic_string<int> coo;
				basic_string<int> rcoo;

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

			int size(){
				return _arr.size();
			}//end_size
			T& operator[](int i){
				return _arr[i];
			}//end_arr
			


			T& operator[](const basic_string<int>& coo){
				return _arr[toIdx(coo)];
			}

			void print(){
				cout << "shape : ";
				for(int i=0;i<_shape.size();i++){
					cout << _shape[i] << " x ";
				}//endfor
				cout << endl;
				for(int i=0;i<_arr.size();i++){
					basic_string<int> coo = this->fromIdx(i);
					cout << "(";
					for(int j=0;j<coo.size();j++){
						cout << coo[j] << ",";
					}
					cout  << ") : " << _arr[i] << endl;
				}//endfor
				cout << "--------------------" << endl;
			}//end_print()
	};


};



#endif