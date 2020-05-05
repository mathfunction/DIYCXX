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


				
				int add_doubles(const std::basic_string<double> &v1,const std::basic_string<double> &v2){
					__m256d avx_v1 ;
					__m256d avx_v2 ;
					__m256d result ;
					for(int i=0;i<v1.size();i+=4){
						avx_v1 = _mm256_load_pd((double*)&v1[i]);
						avx_v2 = _mm256_load_pd((double*)&v2[i]);
						result = _mm256_add_pd(avx_v1,avx_v2);	
					}//endfor
					return 1;
					
				}
				int add_doubles_baseline(const std::basic_string<double> &v1,const std::basic_string<double> &v2){
					double result;
					for(int i=0;i<v1.size();i++){
						result = v1[i] + v2[i];
					}//endfor
					return 1;
				}
				
				

				


		} avxfunc;
	};
#endif



#endif