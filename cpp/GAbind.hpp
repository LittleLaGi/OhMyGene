#include <vector>
#include <tuple>
#include <string>

class GA {
public:
    using individual_type = std::tuple<std::vector<double>, double>;
    GA(const size_t gene_count, const size_t generation_number, const size_t population_size, const float mating_parent_ratio,
        const float mutation_probability, const std::vector<float> weights, const std::string parent_selection_method,
        const std::string cross_over_methods, const std::string mutation_methods)
        : gene_count(gene_count), generation_number(generation_number), population_size(population_size),
        mating_parent_ratio(mating_parent_ratio), mutation_probability(mutation_probability), weights(weights),
        parent_selection_method(parent_selection_method), cross_over_methods(cross_over_methods),
        mutation_methods(mutation_methods) {}
    // getter for input params: for debug usage
    const size_t getGeneCount() { return gene_count; }
    const size_t getGenerationNumber() { return generation_number; }
    const size_t getPopulationSize() { return population_size; }
    const float getMatingParentRatio() { return mating_parent_ratio; }
    const float getMutationProbability() { return mutation_probability; }
    const std::vector<float> getWeights() { return weights; }
    const std::string getParentSelectionMethod() { return parent_selection_method; }
    const std::string getCrossOverMethods() { return cross_over_methods; }
    const std::string getMutationMethods() { return mutation_methods; }
    // setter for results: for debug usage
    void setLastPopulation(std::vector<individual_type> last_pop) { last_population = last_pop; }
    void setBestFitness(std::vector<double> best_fit) { best_fitness = best_fit; }
    void setNewSolutionRate(std::vector<unsigned> new_sol_rate) { new_solution_rate = new_sol_rate; }
    // getter for results
    std::vector<individual_type> getLastPopulation() { return last_population; }
    std::vector<double> getBestFitness() { return best_fitness; }
    std::vector<unsigned> getNewSolutionRate() { return new_solution_rate; }

    // create initial population
    // initial generation
    // evaluate fitness value for each chromosome
    // selection
    // crossover
    // mutation
    // run

private:
    // params
    const size_t gene_count;
    const size_t generation_number;
    const size_t population_size;
    const float mating_parent_ratio;
    const float mutation_probability;
    const std::vector<float> weights;
    const std::string parent_selection_method;
    const std::string cross_over_methods;
    const std::string mutation_methods;
    // results
    std::vector<individual_type> last_population;
    std::vector<double> best_fitness;
    std::vector<unsigned> new_solution_rate;
};
