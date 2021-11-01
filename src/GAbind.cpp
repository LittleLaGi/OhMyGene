#include "GA.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;
PYBIND11_MODULE(GAbind, m) {
  m.doc() = "uderlying GA class for OMG";
  py::class_<GA>(m, "GA")
    .def(py::init<const size_t, const std::vector<std::tuple<double, double>>, const size_t, 
                  const size_t, const float, const std::string>())
    /* getter for input params: for debug usage */
    .def("getGeneCount", &GA::getGeneCount)
    .def("getGeneBound", &GA::getGeneBound)
    .def("getGenerationNumber", &GA::getGenerationNumber)
    .def("getPopulationSize", &GA::getPopulationSize)
    .def("getMutationProbability", &GA::getMutationProbability)
    .def("getCrossOverMethod", &GA::getCrossOverMethod)
    /* getter for internal data structures: for debug usage */
    .def("getParents", &GA::getParents)
    .def("getChildren", &GA::getChildren)
    .def("getWeights", &GA::getWeights)
    .def("getFitnessValues", &GA::getFitnessValues)
    .def("getSelectedOrder", &GA::getSelectedOrder)
    /* setter for results: for debug usage */
    .def("setElitesChromosomes", &GA::setElitesChromosomes)
    .def("setElitesWeights", &GA::setElitesWeights)
    .def("setElitesFitnessValue", &GA::setElitesFitnessValue)
    .def("setBestFitness", &GA::setBestFitness)
    .def("setNewSolutionRate", &GA::setNewSolutionRate)
    /* getter for results */
    .def("getElitesChromosomes", &GA::getElitesChromosomes)
    .def("getElitesWeights", &GA::getElitesWeights)
    .def("getElitesFitnessValue", &GA::getElitesFitnessValue)
    .def("getBestFitness", &GA::getBestFitness)
    .def("getNewSolutionRate", &GA::getNewSolutionRate)
    /* basic GA operation */
    .def("createInitialPopulation", &GA::createInitialPopulation)
    .def("evaluateFitnessValue", &GA::evaluateFitnessValue)
    .def("updateElites", &GA::updateElites)
    .def("updateSelectedOrder", &GA::updateSelectedOrder)
    .def("crossover", &GA::crossover)
    .def("mutation", &GA::mutation)
    .def("updateParents", &GA::updateParents)
    .def("randomReplace", &GA::randomReplace);
}

