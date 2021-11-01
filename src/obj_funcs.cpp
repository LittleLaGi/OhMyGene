#include "GA.hpp"

#include <numeric>
#include <cmath>

/* declaration of user defined objective functions */

// double objfunc1(std::vector<double>);
// double objfunc2(std::vector<double>);

double objSphere(std::vector<double>);


/* register user defined objective functions */
void GA::addObjectiveFunctions(){
  // objective_functions.push_back(&objfunc1);
  // objective_functions.push_back(&objfunc2);

  objective_functions.push_back(&objSphere);
}


/* definition of user defined objective functions */

// double objfunc1(std::vector<double> gene){
//   return std::accumulate(gene.begin(), gene.end(), 0);
// }

// double objfunc2(std::vector<double> gene){
//   return std::accumulate(gene.begin(), gene.end(), 0);
// }

double objSphere(std::vector<double> gene){
  double ret = 0.0;
  const double RADIOUS = 10.0;
  
  for (auto x : gene)
    ret += x * x;

  return std::abs(ret - RADIOUS);
}