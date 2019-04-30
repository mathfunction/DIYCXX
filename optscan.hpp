#ifndef __OPTSCAN_HPP__ 
#define __OPTSCAN_HPP__

#include <vector>
#include <future>
#include <unordered_map>
#include <functional> //std::ref
#include "cxxclocker.hpp"

using namespace std;



namespace optscan{
	//=================================================================================
	
	double single_dsum(vector<double> &vec,int start,int n){
		double _sum = 0.0;
		int end = start+n;
		for(int i=start;i<end;i++){
			_sum += vec[i];
		}//endfor
		return _sum;
	}//end_double
	
	
	double parallel_dsum(vector<double> &vec,int num_threads=8){
		// too small
		if(vec.size() < num_threads){
			return single_dsum(vec,0,vec.size());	
		}else{
			vector<future<double> > fu;
			fu.resize(num_threads);
			double _sum = 0.0;
			int FixSize = vec.size()/num_threads;
			int RemainSize = vec.size()% num_threads;
			//=======================================================================
			// parallel
			for(int k=0;k<num_threads-1;k++){
				fu[k] = async(launch::async,single_dsum,ref(vec),k*FixSize,FixSize);
			}//endfor
			fu[num_threads-1] = async(launch::async,single_dsum,ref(vec),(num_threads-1)*FixSize,FixSize+RemainSize);
			//=======================================================================
			// get 
			for(int k=0;k<num_threads;k++){
				_sum += fu[k].get();
			}//endfor
			return _sum;
		}//end_else
	}//end_parallel_sum	 
	//====================================================================================
	

	int single_isum(vector<int> &vec,int start,int n){
		int _sum = 0;
		int end = start+n;
		for(int i=start;i<end;i++){
			_sum += vec[i];
		}//endfor
		return _sum;
	}//end_double
	
	
	int parallel_isum(vector<int> &vec,int num_threads=4){
		// too small
		if(vec.size() < num_threads){
			return single_isum(vec,0,vec.size());	
		}else{
			vector<future<int> > fu;
			fu.resize(num_threads);
			int _sum = 0;
			int FixSize = vec.size()/num_threads;
			int RemainSize = vec.size()% num_threads;
			//=======================================================================
			// parallel
			for(int k=0;k<num_threads-1;k++){
				fu[k] = async(launch::async,single_isum,ref(vec),k*FixSize,FixSize);
			}//endfor
			fu[num_threads-1] = async(launch::async,single_isum,ref(vec),(num_threads-1)*FixSize,FixSize+RemainSize);
			//=======================================================================
			// get 
			for(int k=0;k<num_threads;k++){
				_sum += fu[k].get();
			}//endfor
			return _sum;
		}//end_else
	}//end_parallel_sum	 
	//=======================================================================================

	

	





	



	



};














#endif