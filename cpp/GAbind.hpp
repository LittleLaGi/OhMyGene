#include <vector>
#include <tuple>
#include <string>

class GA {
public:
    using gene = std::vector<double>;
    using fitness = double;
    using individual_type = std::tuple<gene, fitness>;
    using bound = std::tuple<size_t, size_t>;
    GA(const size_t gene_count, const std::vector<bound> gene_bound, const size_t generation_number, const size_t population_size,
        const float mating_parent_ratio, const float mutation_probability, const std::vector<float> weights,
        const std::string parent_selection_method, const std::string cross_over_methods, const std::string mutation_methods)
        : gene_count(gene_count), gene_bound(gene_bound), generation_number(generation_number), population_size(population_size),
        mating_parent_ratio(mating_parent_ratio), mutation_probability(mutation_probability), weights(weights),
        parent_selection_method(parent_selection_method), cross_over_methods(cross_over_methods),
        mutation_methods(mutation_methods) {}
    
    /* getter for input params: for debug usage */
    const size_t getGeneCount() { return gene_count; }
    const std::vector<bound> getGeneBound() { return gene_bound; }
    const size_t getGenerationNumber() { return generation_number; }
    const size_t getPopulationSize() { return population_size; }
    const float getMatingParentRatio() { return mating_parent_ratio; }
    const float getMutationProbability() { return mutation_probability; }
    const std::vector<float> getWeights() { return weights; }
    const std::string getParentSelectionMethod() { return parent_selection_method; }
    const std::string getCrossOverMethods() { return cross_over_methods; }
    const std::string getMutationMethods() { return mutation_methods; }
    /* getter for internal data structures: for debug usage */
    const std::vector<individual_type> getParents() { return parents; }
    /* setter for results: for debug usage */
    void setLastPopulation(std::vector<individual_type> last_pop) { last_population = last_pop; }
    void setBestFitness(std::vector<double> best_fit) { best_fitness = best_fit; }
    void setNewSolutionRate(std::vector<unsigned> new_sol_rate) { new_solution_rate = new_sol_rate; }
    /* getter for results */
    std::vector<individual_type> getLastPopulation() { return last_population; }
    std::vector<double> getBestFitness() { return best_fitness; }
    std::vector<unsigned> getNewSolutionRate() { return new_solution_rate; }

    /* basic GA operation */
    // initialize indivisuals according to gene_bound and push them input parents
    void createInitialPopulation();
    // create initial population
    // initial generation
    // evaluate fitness value for each chromosome: x
        // for each wi and objective function fi:
        // fitness = sum(wi * norm(fi(x)))
        // signature for each fi: double f(std::vector<double>)
    // selection
    // crossover
    // mutation
    // no "run" function => implemented in wrapper => convient for debugging

    // helper functions


private:
    /* params */
    const size_t gene_count;
    const std::vector<bound> gene_bound;
    const size_t generation_number;
    const size_t population_size;
    const float mating_parent_ratio;
    const float mutation_probability;
    const std::vector<float> weights;
    const std::string parent_selection_method;
    const std::string cross_over_methods;
    const std::string mutation_methods;
    /* results */
    std::vector<individual_type> last_population;
    std::vector<double> best_fitness;
    std::vector<unsigned> new_solution_rate;
    /* internal data structures for GA */
    std::vector<individual_type> parents;
    std::vector<individual_type> children;
};
