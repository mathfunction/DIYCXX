

#include "cxxuseful.hpp"


using namespace cxxuseful;


extern "C" {
	#include <stdio.h>
	__global__ void helloworld(){
		 printf("Hello world!\n");
	}
}


void cudaInit(void){
	helloworld<<<1,1>>>();
}



int main(){

	cudaInit();
	printGreen("______This is Green________",true);


	return 0;
}