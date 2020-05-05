#ifndef __PARALLEL_BLOCK_HPP__
#define __PARALLEL_BLOCK_HPP__



namespace cxxuseful{
	template<typename T>
	std::vector<T> parallel_vector_block(std::function<T(T)> f,const std::vector<T> &v,int threads=4)
	{
		std::vector<T> output;
		output.resize(v.size());
		#ifdef __APPLE__
			for(int i=0;i<v.size();i++){
				output[i] = f(v[i]);
			}//endfor
		#else
			#pragma omp parallel for num_threads(threads)
			for(int i=0;i<v.size();i++){
				output[i] = f(v[i]);
			}//endfor	
		#endif
		return output;
	}//end



};








#endif