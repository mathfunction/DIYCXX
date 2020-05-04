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
				std::basic_string<int> add_ints(const std::basic_string<int> &v1,const std::basic_string<int> &v2){
					std::basic_string<int> _output;
					for(int i=0;i<v1.size();i+=8){
						int *p1 = (int*)&v1[i];
						int *p2 = (int*)&v2[i];
						__m256i avx_v1 = _mm256_set_epi32(p1[7],p1[6],p1[5],p1[4],p1[3],p1[2],p1[1],p1[0]);
						__m256i avx_v2 = _mm256_set_epi32(p2[7],p2[6],p2[5],p2[4],p2[3],p2[2],p2[1],p2[0]);
						__m256i temp =_mm256_hadd_epi32(avx_v1,avx_v2);
						int *p = (int*)&temp;
						for(int j=0;j<8;j++){
							_output += p[j];
						}//endfor
					}
					return _output;
				}
				std::basic_string<int> add_ints_baseline(const std::basic_string<int> &v1,const std::basic_string<int> &v2){
					std::basic_string<int> _output;
					for(int i=0;i<v1.size();i++){
						_output += (v1[i]+v2[i]);
					}//endfor
					return _output;
				}


		} avxfunc;
	};
#endif



#endif