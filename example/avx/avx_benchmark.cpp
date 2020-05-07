

#include "cxxuseful.hpp"




using namespace cxxuseful;
using namespace std;



int main(){

	#if defined _WIN32 || defined _WIN64 
		const int N = 2048;
		const int T = 100000;	
	#else
		const int N = 4096;
		const int T = 100000;
	#endif
	
	

	float input1[N];
	float computed[N];
	
	float *ptr_input1 = &input1[0];
	float *ptr_computed = &computed[0];

	for(int i=0;i<N;i++){
		ptr_input1[i] = (float)(i+1);
		ptr_computed[i] = 0.99999;
	}//endfor

	
	{
		Timer t1("naive");
		for(int i=0;i<T;i++){
			avxfunc.mul_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.add_naive(ptr_input1,ptr_computed,N);
			avxfunc.mul_naive(ptr_input1,ptr_computed,N);
		}//endfor
		
	}
	//============================================
	for(int i=0;i<10;i++){
		cout << ptr_input1[i]  << endl;
	}
	
	for(int i=0;i<N;i++){
		ptr_input1[i] = (float)(i+1);
		ptr_computed[i] = 0.99999;
	}//endfo
	
	
	{	
		Timer t2("avx2");
		for(int i=0;i<T;i++){
			avxfunc.mul<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.add<N>(ptr_input1,ptr_computed);
			avxfunc.mul<N>(ptr_input1,ptr_computed);
		}
		
	}
	
	for(int i=0;i<10;i++){
		cout << ptr_input1[i]  << endl;
	}













	return 0;
}