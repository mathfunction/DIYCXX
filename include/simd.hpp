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
					std::array<float,N> mul(const std::array<float,N> &v1,const std::array<float,N> &v2){
						std::array<float,N> arr;
						constexpr int Q = N/8;
						constexpr int R = N%8;
						constexpr int RL = Q*8;
						constexpr int RU = Q*8+R; 
						// avx part 
						for(int i=0;i<N;i+=8){
							__m256 avx_v1 = _mm256_load_ps(&v1[i]);
							__m256 avx_v2 = _mm256_load_ps(&v2[i]);
							__m256 result = _mm256_mul_ps(avx_v1,avx_v2);	
							_mm256_store_ps(&arr[i],result);
						}//endfor
						for(int i=RL;i<RU;i++){
							arr[i] = v1[i]*v2[i];
						}//endfor
						return arr;
					}//endfor
					//========================================================================================
					// 加法
					template<size_t N>
					std::array<float,N> add(const std::array<float,N> &v1,const std::array<float,N> &v2){
						std::array<float,N> arr;
						constexpr int Q = N/8;
						constexpr int R = N%8;
						constexpr int RL = Q*8;
						constexpr int RU = Q*8+R; 
						// avx part 
						for(int i=0;i<N;i+=8){
							__m256 avx_v1 = _mm256_load_ps(&v1[i]);
							__m256 avx_v2 = _mm256_load_ps(&v2[i]);
							__m256 result = _mm256_add_ps(avx_v1,avx_v2);	
							_mm256_store_ps(&arr[i],result);
						}//endfor
						for(int i=RL;i<RU;i++){
							arr[i] = v1[i]+v2[i];
						}//endfor
						return arr;
					}//endfor
					//===================================================================================
					// 減法
					template<size_t N>
					std::array<float,N> sub(const std::array<float,N> &v1,const std::array<float,N> &v2){
						std::array<float,N> arr;
						constexpr int Q = N/8;
						constexpr int R = N%8;
						constexpr int RL = Q*8;
						constexpr int RU = Q*8+R; 
						// avx part 
						for(int i=0;i<N;i+=8){
							__m256 avx_v1 = _mm256_load_ps(&v1[i]);
							__m256 avx_v2 = _mm256_load_ps(&v2[i]);
							__m256 result = _mm256_sub_ps(avx_v1,avx_v2);	
							_mm256_store_ps(&arr[i],result);
						}//endfor
						for(int i=RL;i<RU;i++){
							arr[i] = v1[i]-v2[i];
						}//endfor
						return arr;
					}//endfor
					//=======================================================================================
					// 除法

					template<size_t N>
					std::array<float,N> div(const std::array<float,N> &v1,const std::array<float,N> &v2){
						std::array<float,N> arr;
						constexpr int Q = N/8;
						constexpr int R = N%8;
						constexpr int RL = Q*8;
						constexpr int RU = Q*8+R; 
						// avx part 
						for(int i=0;i<N;i+=8){
							__m256 avx_v1 = _mm256_load_ps(&v1[i]);
							__m256 avx_v2 = _mm256_load_ps(&v2[i]);
							__m256 result = _mm256_div_ps(avx_v1,avx_v2);	
							_mm256_store_ps(&arr[i],result);
						}//endfor
						for(int i=RL;i<RU;i++){
							arr[i] = v1[i]/v2[i];
						}//endfor
						return arr;
					}//endfor
				

				#endif
				
				template<size_t N>
				std::array<float,N> add_naive(const std::array<float,N> &v1,const std::array<float,N> &v2){
					std::array<float,N> arr;
					for(int i=0;i<v1.size();i++){
						arr[i] = v1[i]+v2[i];
					}//endfor
					return arr;
				}

				template<size_t N>
				std::array<float,N> sub_naive(const std::array<float,N> &v1,const std::array<float,N> &v2){
					std::array<float,N> arr;
					for(int i=0;i<v1.size();i++){
						arr[i] = v1[i]-v2[i];
					}//endfor
					return arr;
				}

				template<size_t N>
				std::array<float,N> div_naive(const std::array<float,N> &v1,const std::array<float,N> &v2){
					std::array<float,N> arr;
					for(int i=0;i<v1.size();i++){
						arr[i] = v1[i]/v2[i];
					}//endfor
					return arr;
				}

				template<size_t N>
				std::array<float,N> mul_naive(const std::array<float,N> &v1,const std::array<float,N> &v2){
					std::array<float,N> arr;
					for(int i=0;i<v1.size();i++){
						arr[i] = v1[i]*v2[i];
					}//endfor
					return arr;
				}
				
		} avxfunc;
	};
#endif



#endif