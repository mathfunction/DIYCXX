
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
			cxxTensor& reshape(const vector<int> &_shape){
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
				return *this;
			}//end_shape
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
			inline int toIdx(const vector<int>& coo){
				int idx = 0;
				for(int i=0;i<coo.size();i++){
					idx += (coo[i]*_prodshape[i+1]);
				}//endfor
				return idx;
			}//endfromIdx


			cxxTensor transpose(const vector<int> &order){
				vector<int> _newshape;
				for(int i=0;i<order.size();i++){
					_newshape.push_back(_shape[order[i]]);
				}
				cxxTensor _newTensor(_newshape);
				vector<int> coo;
				vector<int> rcoo;
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
			


			T& operator[](const vector<int>& coo){
				return _arr[toIdx(coo)];
			}

			void print(){
				cout << "shape : ";
				for(int i=0;i<_shape.size();i++){
					cout << _shape[i] << " x ";
				}//endfor
				cout << endl;
				for(int i=0;i<_arr.size();i++){
					vector<int> coo = fromIdx(i);
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