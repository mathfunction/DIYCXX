
#ifndef __CXXTENSOR_HPP__
#define __CXXTENSOR_HPP__

namespace cxxuseful{
	using namespace std;
	template <typename T>
	class cxxTensor{
		private:
			vector<T> _arr;
			vector<int>  _shape;
			vector<int>  _prodshape;
			inline int toIdx(const vector<int>& coo){
				int idx = 0;
				for(int i=0;i<coo.size();i++){
					idx += (coo[i]*_prodshape[i+1]);
				}//endfor
				return idx;
			}//endfromIdx
			inline vector<int> fromIdx(int idx){
				vector<int> coo;
				int _sum = 0;
				for(int i=1;i<_prodshape.size();i++){
					idx -= _sum;
					coo.push_back(idx/_prodshape[i]);
					_sum += coo[i-1]*_prodshape[i];
				}//endfor
				return coo;
			}


		public:
			cxxTensor(const vector<int>& _shape){
				this->reshape(_shape);
			}
			vector<int> shape(){
				return _shape;
			}//end
			int shape(int i){
				return _shape[i];
			}
			void reshape(const vector<int> &_shape){
				int _size = 1;
				int n = _shape.size();
				this->_prodshape.resize(n);
				for(int i=0;i<n;i++){
					_size *= _shape[n-1-i];
					this->_prodshape[n-1-i] = _size;
				}//endfor
				this->_prodshape.push_back(1);
				this->_shape = _shape;
				this->_arr.resize(_size);
			}//end_shape
			
			

			int size(){
				return _arr.size();
			}//end_size
			T& operator[](int i){
				return _arr[i];
			}//end_arr
			


			T& operator[](const vector<int>& coo){
				return _arr[toIdx(coo)];
			}

			void print(){
				for(int i=0;i<_arr.size();i++){
					vector<int> coo = fromIdx(i);
					cout << "(";
					for(int j=0;j<coo.size();j++){
						cout << coo[j] << ",";
					}
					cout  << ") : " << _arr[i] << endl;
				}//endfor
			}//end_print()
	};


};



#endif