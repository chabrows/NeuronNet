#include "random.h"
using namespace std;

RandomNumbers::RandomNumbers(unsigned long int s){
	if(s==0){
		std::random_device rd;		
		s = rd();
		seed=s;
		rng = std::mt19937(seed);
	} else {
		seed = s;
		rng = std::mt19937(seed);
	}
}

 void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper){
	 
	 std::uniform_real_distribution<> uniform(lower, upper);
	 
	 for(unsigned int i=0; i<tab.size(); ++i){
		 
		 tab[i] = (uniform(rng));
	}
	 
}
   
double RandomNumbers::uniform_double(double lower, double upper){
	
	std::uniform_real_distribution<> uniform(lower, upper);
	return uniform(rng);
}

void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd){
	
	std::normal_distribution<> normale(mean, sd);
	
	 for(unsigned int i=0; i<tab.size(); ++i){
		 
		tab[i] = (normale(rng));
	}
	
}

double RandomNumbers::normal(double mean, double sd){
	
	std::normal_distribution<> normale(mean, sd);
	return normale(rng);
}


void RandomNumbers::poisson(std::vector<int>& tab, double mean){
	
	std::poisson_distribution<> poi(mean);
	
	for(unsigned int i=0; i<tab.size(); ++i){
		tab[i] =(poi(rng));
	}
}

int RandomNumbers::poisson(double mean){
	
	std::poisson_distribution<> poi(mean);
	return poi(rng);
}







