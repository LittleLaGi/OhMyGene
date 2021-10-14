#include "GAbind.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;


PYBIND11_MODULE(GAbind, m) {
  m.doc() = "uderlying GA class for OMG";
  py::class_<GA>(m, "GA")
    .def(py::init<const size_t, const std::vector<GA::bound>, const size_t, const size_t,
                  const float, const float, const std::vector<float>, const std::string,
                  const std::string, const std::string>())
    // getter for input params: for debug usage
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
    // setter for results: for debug usage
    .def("setLastPopulation", &GA::setLastPopulation)
    .def("setBestFitness", &GA::setBestFitness)
    .def("setNewSolutionRate", &GA::setNewSolutionRate)
    // getter for results
    .def("getLastPopulation", &GA::getLastPopulation)
    .def("getBestFitness", &GA::getBestFitness)
    .def("getNewSolutionRate", &GA::getNewSolutionRate);
}

