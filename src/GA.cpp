#include "GA.hpp"

#include <random>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <iostream>



/* init */
void GA::createInitialPopulation(){
  std::random_device rd;
  std::default_random_engine eng(rd());

  for (size_t i = 0; i < population_size; ++i){
    for (size_t j = 0; j < gene_count; ++j){
      const double lower = std::get<0>(gene_bound[j]);
      const double upper = std::get<1>(gene_bound[j]);
      std::uniform_real_distribution<double> distr(lower, upper);
      parents[i].push_back(distr(eng));
    }
  } 
}


/* evaluate fitness value */
void GA::evaluateFitnessValue(){
  generateRandomWeights();
  for (size_t i = 0; i < parents.size(); ++i){
    gene g = parents[i];
    double fitness = 0;
    for (size_t j = 0; j < objective_functions.size(); ++j)
      fitness += weights[i][j] * objective_functions[j](g);
    fitness_values[i] = fitness;
  }
  // new generation
  ++generation;
}


/* update elites */
void GA::updateElites(){
  double min = *std::min_element(fitness_values.begin(), fitness_values.end());
  // no indivisual is better than elites
  if (min - elites_fitness_value > THRESHOLD){
    best_fitness.push_back(elites_fitness_value);
    return;
  }

  // found better Pareto front
  if (elites_fitness_value - min > THRESHOLD){
    elites_chromosomes.clear();
    elites_set.clear();
    elites_weights.clear();
    elites_fitness_value = min;
  }

  for (size_t i = 0; i < fitness_values.size(); ++i){
    if (fitness_values[i] - min <= THRESHOLD){
      if (elites_set.find(parents[i]) != elites_set.end())
        continue;
      elites_set.insert(parents[i]);
      elites_chromosomes.push_back(parents[i]);
      elites_weights.push_back(weights[i]);
    }
  }

  best_fitness.push_back(elites_fitness_value);
}


/* determine the order to be paired up for crossover */
void GA::updateSelectedOrder(){
  double max = *std::max_element(fitness_values.begin(), fitness_values.end());
  
  std::random_device rd;
  std::default_random_engine eng(rd());
  
  using X = std::tuple<size_t, int>;
  std::vector<X> selected_probs;
  for (size_t i = 0; i < fitness_values.size(); ++i){
    size_t sub = std::round(max - fitness_values[i]);
    std::uniform_int_distribution<size_t> distr(0, sub);
    selected_probs.emplace_back(i, distr(eng));
  }

  // descending
  std::sort(selected_probs.begin(), selected_probs.end(),
            [](X x1, X x2){
              return std::get<1>(x1) > std::get<1>(x2);
            });

  for (size_t i = 0; i < selected_probs.size(); ++i){
    auto index = std::get<0>(selected_probs[i]);
    selected_order[i] = index;
  }
}


/* crossover */
void GA::crossover(){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0, gene_count - 1);

    if (crossover_method == "single_point"){
        for (size_t i = 0; i < parents.size() - 1; i += 2){
            size_t pos = distr(eng);
            children[i] = singlePointCrossover(pos, selected_order[i], selected_order[i + 1], 1);
            children[i + 1] = singlePointCrossover(pos, selected_order[i], selected_order[i + 1], 0);
        }
    }
    else
      throw std::runtime_error("Can't match any crossover method!");
}

GA::individual GA::singlePointCrossover(size_t index, size_t p1_i, size_t p2_i, bool flag){
    gene *g1 = &parents[p1_i];
    gene *g2 = &parents[p2_i];
    gene g;
    
    if (flag){
      g.insert(g.end(), g1->begin(), g1->begin() + index);
      g.insert(g.end(), g2->begin() + index, g2->end());
    }  
    else{
      g.insert(g.end(), g2->begin(), g2->begin() + index);
      g.insert(g.end(), g1->begin() + index, g1->end());
    }

    return g;
}


/* mutation */
void GA::mutation(){
  float prob = mutation_probability;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<double> distr(0, 1);
  for (auto &gene_c : children){
    if (distr(eng) < prob){
      std::uniform_int_distribution<size_t> distr_index(0, gene_count - 1);
      size_t index = distr_index(eng);
      
      const double lower = std::get<0>(gene_bound[index]);
      const double upper = std::get<1>(gene_bound[index]);
      std::uniform_real_distribution<double> distr_gene(lower, upper);

      gene_c[index] = distr_gene(eng);
    }
  }
}


/* update parents */
void GA::updateParents(){
  parents.clear();
  parents.insert(parents.begin(), children.begin(), children.end());
}


/* some of the children are randomly replaced by elites */
void GA::randomReplace(){
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<size_t> distr(0, elites_chromosomes.size());
  size_t replace_num = distr(eng);

  std::random_shuffle(parents.begin(), parents.end());
  for (size_t i = 0; i < replace_num; ++i){
    parents[i] = elites_chromosomes[i];
    weights[i] = elites_weights[i];
  }
}


/* helper functions */
void GA::initInternalDataStructures(){
  parents.resize(population_size);
  children.resize(population_size);
  weights.resize(population_size);
  fitness_values.resize(population_size);
  selected_order.resize(population_size);
}

void GA::generateRandomWeights(){
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> distr(1, 100);

  for (size_t i = 0; i < population_size; ++i){
    std::vector<int> random_num;
    for (size_t k = 0; k < objective_functions.size(); ++k)
      random_num.push_back(distr(eng));

    int sum = std::accumulate(random_num.begin(), random_num.end(), 0);

    weights[i].clear();
    for (size_t k = 0; k < objective_functions.size(); ++k)
      weights[i].push_back((double)random_num[k] / sum);
  }
}

