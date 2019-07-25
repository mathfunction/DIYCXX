
#ifndef __RANDOMLIB_HPP__
#define __RANDOMLIB_HPP__

#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


namespace randomlib{


void set_seed(){
    srand(time(NULL));
}//end_set_seed

//print vector function 
void printv(vector<int> &a){
	for(int i=0;i<a.size();i++)	cout << a[i] << "," ;
}//endprint 

void printv(vector<double> &a){
	for(int i=0;i<a.size();i++)	cout << a[i] << "," ;
}//endprint 

double Xbar(vector<int> &a){
	double sum = 0;
	for(int i=0;i<a.size();i++)	sum += (double)a[i];
	sum = sum/a.size();
	return sum ; 
}//endXbar

double Xbar(vector<double> &a){
	double sum = 0 ; 
	for(int i=0;i<a.size();i++)	sum += a[i];
	sum = sum/a.size();
	return sum ;
}//endXbar



//____________________________________________________________________________________________________________
/* uniform_integer_distribution */

vector<int> uniform_int(int min ,int max,int N){

		 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 
    	
    	 uniform_int_distribution<> dis(min, max);
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen));
    	 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_uniform_int 
//___________________________________________________________________________________________________________
/* uniform_double_distribution */

vector<double> uniform_real(double min ,double max,int N){

		 vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 
    	
    	 uniform_real_distribution<> dis(min, max);
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen));
    	 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_uniform_int

//___________________________________________________________________________________________________________
/* beroulli_int */
vector<int> bernoulli_int(double p,int N){

	 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 
    	
    	 bernoulli_distribution dis(p);
    	 for(int i=0 ; i<=N ;i++){
    	 	if(dis(gen)==true) temp.push_back(1);
    	 	else temp.push_back(0);
    	 }//endfor 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_bernoulli
//___________________________________________________________________________________________________________
/* binomial_int */
vector<int> binomial_int(double p, int trial , int N){

	 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 
    	 binomial_distribution<> dis(trial,p);
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_binomial_int

//_______________________________________________________________________________________________________________
/* negative_binomial_int */
vector<int> negative_binomial_int(double p, int trial , int N){

	 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 
    	 negative_binomial_distribution<> dis(trial,p);
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_negative_binomial_int

//___________________________________________________________________________________________________________________

/* geometric_int */ 
vector<int> geometric_int(double p, int N){

	 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 geometric_distribution<> dis(p);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)+1); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_geometric_int

//___________________________________________________________________________________________________________________

/* poisson_int */ 
vector<int> poisson_int(double lambda, int N){

	 vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 poisson_distribution<> dis(lambda);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_poisson_int

//___________________________________________________________________________________________________________________

/* exponential_double */ 
vector<double> exponential_double(double lambda, int N){

	 vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 exponential_distribution<> dis(lambda);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_exponential_double

//_______________________________________________________________________________________________________________________

/* gamma_double */ 
vector<double> gamma_double(double alpha , double beta , int N){
	 vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 gamma_distribution<> dis(alpha,beta);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_gamma_double

//______________________________________________________________________________________________________________________

/*  normal_double */
vector<double> normal_double(double mu , double sigma , int N){
	 vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 normal_distribution<> dis(mu,sigma);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_normal_double
//_______________________________________________________________________________________________________________________

vector<double> lognormal_double(double mu , double sigma , int N){
	 vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 lognormal_distribution<> dis(mu,sigma);
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_lognormal_double

//_________________________________________________________________________________________________________________________
/* discrete distribution */
// need to put weights
vector<int> discrete_int(vector<double> &weights , int N){
	vector<int> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
    	 discrete_distribution<> dis(weights.begin(),weights.end());
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_discrete_int



//______________________________________________________________________________________________________________________________
/*piecewise constant distribution */


vector<double> piecewise_constant_double(vector<double> &partitions , vector<double> &weights  , int N){
	vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
		 //p.s:: weights.size() = partitions.size()-1
    	 piecewise_constant_distribution<> dis(partitions.begin(),partitions.end(),weights.begin());
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_piecewise_constant 





//______________________________________________________________________________________________________________________________

/* piecewise linear distribution */

   //p_k = w_k / S     S = sum (1/2)*(w_k+w_{k+1})(b_{k+1}-b_k)
vector<double> piecewise_linear_double(vector<double> &partitions , vector<double> &weights  , int N){
	vector<double> temp ; 
		 unsigned int seed = (unsigned int)rand();
		 default_random_engine gen(seed) ; 
		 //p.s:: weights.size() = partitions.size()   equal size 
    	 piecewise_linear_distribution<> dis(partitions.begin(),partitions.end(),weights.begin());
    	 /* save the number of success trial */
    	 for(int i=0 ; i<=N ;i++) temp.push_back(dis(gen)); 
    	 /*copy final to first*/
    	 temp[0]= temp[N];
    	/* delete final */
    	 temp.pop_back();
    	 return temp ; 
}//end_piecewise_linear 






//______________________________________________________________________________________________________________________________
};//end_namespace

#endif


/*
int main(){
	vector<double> weights{1,1,1,1,1,1};
	vector<double> partitions{0,1,2,3,4,5};
    vector<double> a = piecewise_linear_double(partitions,weights,10000);
    //printv(a);
	cout << "Sample Mean = " << Xbar(a) << endl;
   return 0 ; 
}//end_main 
*/
