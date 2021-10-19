#include "GA.hpp"

#include <random>
#include <stdexcept>

/* init */
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


/* evaluate fitness value */
void GA::evaluateFitnessValue(){

}


/* selection */
void GA::selectParents(){
  if (parent_selection_method == "random")
        randomSelection();
  else
    throw std::runtime_error("Can't match any selection method!");
}

void GA::randomSelection(){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, population_size - 1);
    for (size_t i = 0; i < mating_parent_num; ++i)
      selected_parents.push_back(distr(eng));
}


/* crossover */
void GA::crossover(){
    for (auto i : selected_parents)
        children.push_back(parents[i]);

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0, gene_count - 1);

    if (crossover_method == "single_point"){
        for (size_t i = 0; i < selected_parents.size() - 1; i += 2)
            children.emplace_back(singlePointCrossover(distr(eng), selected_parents[i], selected_parents[i + 1]));
    }
    else
      throw std::runtime_error("Can't match any crossover method!");
}

GA::individual GA::singlePointCrossover(size_t index, size_t p1_i, size_t p2_i){
    // individual: std::tuple<gene, fitness>
    // gene : std::vector<double>
    // fitness : double
    gene *g1 = &std::get<0>(parents[p1_i]);
    gene *g2 = &std::get<0>(parents[p2_i]);
    gene g(g1->begin(), g1->begin() + index);
    g.insert(g.end(), g2->begin() + index, g2->end());

    return {g, 0};
}


/* mutation */
void GA::mutation(){


}