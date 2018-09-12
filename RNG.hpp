#ifndef __RNG_HPP__
#define __RNG_HPP__
	
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std; 

namespace RNG{
	void TimeInit();
	double Unif(double a=0,double b=1);
	int DiscreteDist(vector<double> weights);
	double NormalDist(double mu,double sigma);
	double GammaDist(double alpha,double beta);
	vector<double> DirichletDist(vector<double> alphas,bool _print=false);
	vector<int> CategoryDist(vector<double> weights,bool _print);

};



void RNG::TimeInit(){
	srand(time(NULL));
}//end_RNG::SeedInit

double RNG::Unif(double a,double b){
	if(a > b) exit(1);
	mt19937 gen(rand());
	uniform_real_distribution<> dist(a, b);
	return dist(gen);
}//end_RNG::Unif


/*-----------------------------------------------------------------------------------------
note it can be view as Category Distribution  x \in X view as binary-vector \in {0,1}^|X|
x \in {1,2}  iff (x_1,x_2) = {(1,0),(0,1)}
------------------------------------------------------------------------------------------*/
int RNG::DiscreteDist(vector<double> weights){
	mt19937 gen(rand());
	discrete_distribution<> dist(weights.begin(),weights.end());
	return dist(gen);
}//end_RNG::DiscreteDist


vector<int> RNG::CategoryDist(vector<double> weights,bool _print){
	vector<int> _vecCategory;
	int rdInt = RNG::DiscreteDist(weights);
	for(int i=0;i<weights.size();++i){
		if(i == rdInt){
			_vecCategory.push_back(1);
		}else{
			_vecCategory.push_back(0);
		}
	}//endfor
	if(_print == true){
		cerr << rdInt << " = (" ;
		for(int i=0;i<weights.size();i++){
			cerr << _vecCategory[i] << ",";
		}//endfor
		cerr << " )" << endl;
	}//endif
	return _vecCategory;
}//end_RNG::CategoryDist





double RNG::GammaDist(double alpha,double beta){
	mt19937 gen(rand());
	gamma_distribution<double> dist(alpha,beta);
	return dist(gen);
}//end_RNG::GammaDist


double RNG::NormalDist(double mu,double sigma){
	if (sigma <=0) exit(1);
	mt19937 gen(rand());
	normal_distribution<double> dist(mu,sigma);
	return dist(gen);
}//end_RNG_NormalDist







/*------------------------------------------------------------------------------------
we can generate Dirichket Distribution by using Gamma Distribution 
reference : https://stats.stackexchange.com/questions/69210/drawing-from-dirichlet-distribution

y_i ~ Gamma(alpha_i,1)
x_i = y_i/ sum y 
x is Dirichlet 

-----------------------------------------------------------------------------------------*/
vector<double> RNG::DirichletDist(vector<double> alphas,bool _print){
	vector<double> _vecDirichlet;
 	mt19937 gen(rand());
	double sum = 0;
	for(int i=0;i<alphas.size();i++){
		_vecDirichlet.push_back(GammaDist(alphas[i],1));
		sum += _vecDirichlet[i];
	}//endfor
	for(int i=0;i<alphas.size();i++){
		_vecDirichlet[i] /= sum;
	}//endfor
	if(_print == true){
		for(int i=0;i<alphas.size();i++){
			cerr << _vecDirichlet[i] << ",";
		}//endfor
		cerr << endl;
	}//endif
	return _vecDirichlet;
}//end_RNG::DirichletDist
 




#endif