#ifndef __SIMD_HPP__
#define __SIMD_HPP__



#ifdef __AVX__
	#include <immintrin.h>
	namespace cxxuseful{
		class AVXSupport{
			public:
				AVXSupport(){
					#ifdef __AVX2__
						printGreen("[SIMD] compiled as avx/avx2",true); 
					#else 
						printGreen("[SIMD] compiled as only avx",true);
					#endif

				}
				#ifdef __AVX2__
					//=========================================================================================
					// 乘法
					template<size_t N>
					void mul(float *v1,float *v2){
						constexpr int Q = N/8;
						constexpr int R = N%8;
						int i = Q;
						// avx part 
						while(i--){
							__m256 avx_v1 = _mm256_load_ps(v1);
							__m256 avx_v2 = _mm256_load_ps(v2);
							avx_v1 = _mm256_mul_ps(avx_v1,avx_v2);
							_mm256_store_ps(v1,avx_v1);
							v1+=8;
							v2+=8;
						}//endfor
						for(;i<R;i++){
							v1[i]*=v2[i];
						}
					}//endfor
					//========================================================================================
					// 加法
					template<size_t N>
					void add(float *v1,float *v2){
						constexpr int Q = N/8;
						constexpr int R = N%8;
						int i = Q;
						// avx part 
						while(i--){
							__m256 avx_v1 = _mm256_load_ps(v1);
							__m256 avx_v2 = _mm256_load_ps(v2);
							avx_v1 = _mm256_add_ps(avx_v1,avx_v2);	
							_mm256_store_ps(v1,avx_v1);
							v1+=8;
							v2+=8;
						}//endfor
						for(;i<R;i++){
							v1[i]+=v2[i];
						}
					}//endfor
					//===================================================================================
					// 減法
					template<size_t N>
					void sub(float *v1,float *v2){
						constexpr int Q = N/8;
						constexpr int R = N%8;
						int i = Q;
						// avx part 
						while(i--){
							__m256 avx_v1 = _mm256_load_ps(v1);
							__m256 avx_v2 = _mm256_load_ps(v2);
							avx_v1 = _mm256_sub_ps(avx_v1,avx_v2);	
							_mm256_store_ps(v1,avx_v1);
							v1+=8;
							v2+=8;
						}//endfor
						for(;i<R;i++){
							v1[i]-=v2[i];
						}
					}//endfor
					//=======================================================================================
					// 除法
					template<size_t N>
					void div(float *v1,float *v2){
						constexpr int Q = N/8;
						constexpr int R = N%8;
						int i = Q;
						while(i--){
							__m256 avx_v1 = _mm256_load_ps(v1);
							__m256 avx_v2 = _mm256_load_ps(v2);
							avx_v1 = _mm256_div_ps(avx_v1,avx_v2);	
							_mm256_store_ps(v1,avx_v1);
							v1+=8;
							v2+=8;
						}//endfor
						for(;i<R;i++){
							v1[i]/=v2[i];
						}//endfor
					}//endfor
				

				#endif
				
				
				void add_naive(float *v1,float *v2,int N){
					for(int i=0;i<N;i++){
						v1[i]+=v2[i];
					}//endfor
				}

				
				void sub_naive(float *v1,float *v2,int N){
					for(int i=0;i<N;i++){
						v1[i]-=v2[i];
					}//endfor
				}

				
				void div_naive(float *v1,float *v2,int N){
					for(int i=0;i<N;i++){
						v1[i]/=v2[i];
					}//endfor	
				}

				
				void mul_naive(float *v1,float *v2,int N){
					for(int i=0;i<N;i++){
						v1[i]*=v2[i];
					}//endfor	
				}
				
		} avxfunc;
	};
#endif


#endif