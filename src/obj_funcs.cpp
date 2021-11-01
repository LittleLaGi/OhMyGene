#include "GA.hpp"

#include <numeric>

/* declaration of user defined objective functions */
double objfunc1(std::vector<double>);
double objfunc2(std::vector<double>);


/* register user defined objective functions */
void GA::addObjectiveFunctions(){
  objective_functions.push_back(&objfunc1);
  objective_functions.push_back(&objfunc2);
}


/* definition of user defined objective functions */
double objfunc1(std::vector<double> gene){
  return std::accumulate(gene.begin(), gene.end(), 0);
}

/* definition of user defined objective functions */
double objfunc2(std::vector<double> gene){
  return std::accumulate(gene.begin(), gene.end(), 0);
}
