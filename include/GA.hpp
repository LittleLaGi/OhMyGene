#include <vector>
#include <tuple>
#include <string>


class GA {
public:
    using gene = std::vector<double>;
    using fitness = double;
    using individual = std::tuple<gene, fitness>;
    using bound = std::tuple<size_t, size_t>;
    GA(const size_t gene_count, const std::vector<bound> gene_bound, const size_t generation_number, const size_t population_size,
        const float mating_parent_ratio, const float mutation_probability, const std::vector<float> weights,
        const std::string parent_selection_method, const std::string crossover_method, const std::string mutation_method)
        : gene_count(gene_count), gene_bound(gene_bound), generation_number(generation_number), population_size(population_size),
        mating_parent_ratio(mating_parent_ratio), mutation_probability(mutation_probability), weights(weights),
        parent_selection_method(parent_selection_method), crossover_method(crossover_method),
        mutation_method(mutation_method) 
        {
            mating_parent_num = (int)(population_size * mating_parent_ratio);
            if (mating_parent_num % 2)
                mating_parent_num += 1;
        }

    /* getter for input params: for debug usage */
    const size_t getGeneCount() { return gene_count; }
    const std::vector<bound> getGeneBound() { return gene_bound; }
    const size_t getGenerationNumber() { return generation_number; }
    const size_t getPopulationSize() { return population_size; }
    const float getMatingParentRatio() { return mating_parent_ratio; }
    const float getMutationProbability() { return mutation_probability; }
    const std::vector<float> getWeights() { return weights; }
    const std::string getParentSelectionMethod() { return parent_selection_method; }
    const std::string getCrossOverMethod() { return crossover_method; }
    const std::string getMutationMethod() { return mutation_method; }
    /* getter for internal data structures: for debug usage */
    const std::vector<individual> getParents() { return parents; }
    const std::vector<individual> getChildren() { return children; }
    const size_t getMatingParentNum() { return mating_parent_num; }
    const std::vector<size_t> getSelectedParents() { return selected_parents; }
    /* setter for results: for debug usage */
    void setLastPopulation(std::vector<individual> last_pop) { last_population = last_pop; }
    void setBestFitness(std::vector<double> best_fit) { best_fitness = best_fit; }
    void setNewSolutionRate(std::vector<unsigned> new_sol_rate) { new_solution_rate = new_sol_rate; }
    /* getter for results */
    std::vector<individual> getLastPopulation() { return last_population; }
    std::vector<double> getBestFitness() { return best_fitness; }
    std::vector<unsigned> getNewSolutionRate() { return new_solution_rate; }
    
    /* basic GA operation */
    // initialize indivisuals according to gene_bound and push them into parents
    void createInitialPopulation();
    // evaluate fitness value for each chromosome: x
        // for each wi and objective function fi:
        // fitness = sum(wi * norm(fi(x)))
        // signature for each fi: double f(std::vector<double>)
    void evaluateFitnessValue();
    // selection: return indices fo parents
    void selectParents();
    void randomSelection();
    // crossover: produce offsprings from selected parents,
    //            push offsprings and selected parents into children
    void crossover();
    individual singlePointCrossover(size_t index, size_t p1_i, size_t p2_i);
    // mutation
    void mutation();
    // no "run" function => implemented in wrapper => convient for debugging

    /* helper functions */

    /* objective functions */
    double objFunc1(gene);

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
    const std::string crossover_method;
    const std::string mutation_method;
    /* results */
    std::vector<individual> last_population;
    std::vector<double> best_fitness;
    std::vector<unsigned> new_solution_rate;
    /* internal data structures for GA */
    size_t mating_parent_num;
    std::vector<individual> parents;
    std::vector<individual> children;
    std::vector<size_t> selected_parents;
};
