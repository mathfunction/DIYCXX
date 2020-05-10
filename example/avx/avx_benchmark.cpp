// compile as clang intel

#include "cxxuseful.hpp"




using namespace cxxuseful;
using namespace std;



int main(){

	
	const int N = 800000;
	const int T = 1000;
	
	
	

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
	//=======================================================
	for(int i=0;i<N;i++){
		ptr_input1[i] = (float)(i+1);
		ptr_computed[i] = 0.99999;
	}//endfor

	
	{
		Timer t2("omp simd");
		#pragma omp simd
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


	
	for(int i=0;i<N;i++){
		ptr_input1[i] = (float)(i+1);
		ptr_computed[i] = 0.99999;
	}//endfo
	
	
	{	
		Timer t3("intel instrinsics");
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
	
	

	








	return 0;
}