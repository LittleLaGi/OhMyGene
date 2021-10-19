#include "GA.hpp"

#include <random>
#include <stdexcept>


void GA::createInitialPopulation(){
  std::random_device rd;
  std::default_random_engine eng(rd());

  for (size_t i = 0; i < population_size; ++i){
    gene g;
    for (size_t j = 0; j < gene_count; ++j){
      const size_t lower = std::get<0>(gene_bound[j]);
      const size_t upper = std::get<1>(gene_bound[j]);
      std::uniform_real_distribution<double> distr(lower, upper);
      g.push_back(distr(eng));
    }
    parents.emplace_back(g, 0);
  }  
}


/* selection */
std::vector<size_t> GA::selectParents(){
  if (parent_selection_method == "random"){
    return randomSelection();
  }
  throw std::runtime_error("Can't match any selection method!");
}

std::vector<size_t> GA::randomSelection(){
    std::vector<size_t> ret;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, population_size);
    for (size_t i = 0; i < mating_parent_num; ++i)
      ret.push_back(distr(eng));

    return ret;
}
