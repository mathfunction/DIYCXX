/*=================================================================



 __host__   : CPU 調用的 普通函數
 __global__ : CPU 執行到 GPU 得分派函式 	// 實作無法使用常見函式庫
 __device__	: GPU 調用的函式 			// 實作無法使用常見函式庫

 同個 Block 裡面的 threads shard memory !! 
 	blockIdx.x = [0,blocksPerGrid)     block may be coordinate (x,y,z)
 	blockDim.x = threadsPerBlock	   
 	threadIdx.x = [0,threadsPerBlock)  threads may be coordinate (x,y,z)

	<<< blocksPerGrid , threadsPerBlock >>>

====================================================================*/




#include "cxxuseful.hpp"
#include "npp.h"




using namespace cxxuseful;


const int size = 10;
const size_t bytes = size*sizeof(float);

// 平行化實作
__global__ void vecadd(const float *v1,const float *v2,float *v3){
	// 計算 thread id 
	int id = blockIdx.x*blockDim.x+threadIdx.x;
	// 只作用 size 以下的運算
	if(id < size){
		v3[id] = v1[id] + v2[id];
	}//endif
}




// 如何平行化這個程式
__host__ void vecadd_driver(const float *v1,const float *v2,float *v3){
  int threadsPerBlock = size;
  int blocksPerGrid = 1;
  //int threadsPerBlock = 1;
  //int blocksPerGrid = size;
  vecadd<<<blocksPerGrid,threadsPerBlock>>>(v1,v2,v3);
  
  printYellow("Hello vector addtiion !!! ",true);
}



int main(){
	
	
	// CPU 動態配置向量 
	float* c1 = (float*)malloc(bytes);
  	float* c2 = (float*)malloc(bytes);
  	float* c3 = (float*)malloc(bytes);


  	// GPU 動態配置向量
  	float*g1,*g2,*g3;
  	cudaMalloc(&g1,bytes);
  	cudaMalloc(&g2,bytes);
  	cudaMalloc(&g3,bytes);

  	// 賦值
  	for(int i=0;i<size;i++){
  		c1[i] = float(i);
   		c2[i] = float(i);
  	}//endfor
  	// 把 CPU 向量的值複製到 GPU  , 要放置 bytes 進去 
  	cudaMemcpy(g1,c1,bytes,cudaMemcpyHostToDevice);
  	cudaMemcpy(g2,c2,bytes,cudaMemcpyHostToDevice);
  	//====================================================================
  	vecadd_driver(g1,g2,g3);
  	// 回傳答案 
  	cudaMemcpy(c3,g3,bytes,cudaMemcpyDeviceToHost);
  	for(int i=0;i<size;i++){
  		std::cout << "==================================================" << std::endl;
  		std::cout << "c1[" << i <<  "] = " << c1[i]  << std::endl;
  		std::cout << "c2[" << i <<  "] = " << c2[i]  << std::endl;
  		std::cout << "c3[" << i <<  "] = " << c3[i]  << std::endl;
  	}//endfor

  	//===================================================================
  	// 釋放記憶體 GPU , CPU 
  	free(c1);
  	free(c2);
  	free(c3);
  	cudaFree(g1);
  	cudaFree(g2);
  	cudaFree(g3);


	return 0;
}//end_main