#include "GAbind.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
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


namespace py = pybind11;
PYBIND11_MODULE(GAbind, m) {
  m.doc() = "uderlying GA class for OMG";
  py::class_<GA>(m, "GA")
    .def(py::init<const size_t, const std::vector<GA::bound>, const size_t, const size_t,
                  const float, const float, const std::vector<float>, const std::string,
                  const std::string, const std::string>())
    /* getter for input params: for debug usage */
    .def("getGeneCount", &GA::getGeneCount)
    .def("getGeneBound", &GA::getGeneBound)
    .def("getGenerationNumber", &GA::getGenerationNumber)
    .def("getPopulationSize", &GA::getPopulationSize)
    .def("getMatingParentRatio", &GA::getMatingParentRatio)
    .def("getMutationProbability", &GA::getMutationProbability)
    .def("getWeights", &GA::getWeights)
    .def("getParentSelectionMethod", &GA::getParentSelectionMethod)
    .def("getCrossOverMethods", &GA::getCrossOverMethods)
    .def("getMutationMethods", &GA::getMutationMethods)
    /* getter for internal data structures: for debug usage */
    .def("getParents", &GA::getParents)
    /* setter for results: for debug usage */
    .def("setLastPopulation", &GA::setLastPopulation)
    .def("setBestFitness", &GA::setBestFitness)
    .def("setNewSolutionRate", &GA::setNewSolutionRate)
    /* getter for results */
    .def("getLastPopulation", &GA::getLastPopulation)
    .def("getBestFitness", &GA::getBestFitness)
    .def("getNewSolutionRate", &GA::getNewSolutionRate)
    /* basic GA operation */
    .def("createInitialPopulation", &GA::createInitialPopulation);
}

