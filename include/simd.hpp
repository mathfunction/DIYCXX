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
				std::vector<int> add_8ints(const std::vector<int> &v1,const std::vector<int> &v2){
					__m256i avx_v1 = _mm256_set_epi32(v1[7],v1[6],v1[5],v1[4],v1[3],v1[2],v1[1],v1[0]);
					__m256i avx_v2 = _mm256_set_epi32(v2[7],v2[6],v2[5],v1[4],v2[3],v2[2],v2[1],v2[0]);
					__m256i result =_mm256_add_epi32(avx_v1,avx_v2);
					int *p = (int*)&result;
					return {p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]};
				}



		} avxfunc;
	};
#endif



#endif