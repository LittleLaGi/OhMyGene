#include "GA.hpp"

/* declaration of user defined objective functions */
double objfunc(std::vector<double>);


/* register user defined objective functions */
void GA::addObjectiveFunctions(){
  objective_functions.push_back(&objfunc);

}


/* definition of user defined objective functions */
double objfunc(std::vector<double>){
  return 1.0;
}
