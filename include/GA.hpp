#include <vector>
#include <tuple>
#include <string>

#define THRESHOLD 0.01

class GA {
public:
    using gene = std::vector<double>;
    using fitness = double;
    using individual = gene;
    using bound = std::tuple<double, double>;
    GA(const size_t gene_count, const std::vector<bound> gene_bound, const size_t generation_number, 
        const size_t population_size, const float mutation_probability, const std::string crossover_method)
        : gene_count(gene_count), gene_bound(gene_bound), generation_number(generation_number), 
        population_size(population_size), mutation_probability(mutation_probability), crossover_method(crossover_method)
        {
            // order matters!
            addObjectiveFunctions();
            initInternalDataStructures();
        }

    /* getter for input params: for debug usage */
    const size_t getGeneCount() { return gene_count; }
    const std::vector<bound> getGeneBound() { return gene_bound; }
    const size_t getGenerationNumber() { return generation_number; }
    const size_t getPopulationSize() { return population_size; }
    const float getMutationProbability() { return mutation_probability; }
    const std::string getCrossOverMethod() { return crossover_method; }
    /* getter for internal data structures: for debug usage */
    const std::vector<individual> getParents() { return parents; }
    const std::vector<individual> getChildren() { return children; }
    const std::vector<std::vector<double>> getWeights() { return weights; }
    const std::vector<fitness> getFitnessValues() { return fitness_values; }
    const std::vector<size_t> getSelectedOrder() { return selected_order; }
    const std::vector<double(*)(std::vector<double>)> getObjectiveFunctions() { return objective_functions; };
    /* setter for results: for debug usage */
    void setElitesChromosomes(std::vector<gene> chromosomes) { elites_chromosomes = chromosomes; }
    void setElitesWeights(std::vector<std::vector<double>> weights) { elites_weights = weights; }
    void setElitesFitnessValue(double fitness_value) { elites_fitness_value = fitness_value; }
    void setBestFitness(std::vector<double> best_fit) { best_fitness = best_fit; }
    void setNewSolutionRate(std::vector<unsigned> new_sol_rate) { new_solution_rate = new_sol_rate; }
    /* getter for results */
    std::vector<gene> getElitesChromosomes() { return elites_chromosomes; }
    std::vector<std::vector<double>> getElitesWeights() { return elites_weights; }
    double getElitesFitnessValue() { return elites_fitness_value; }
    std::vector<double> getBestFitness() { return best_fitness; }
    std::vector<unsigned> getNewSolutionRate() { return new_solution_rate; }
    
    /* basic RWGA operation */
    // initialize indivisuals according to gene_bound and push them into parents
    void createInitialPopulation();
    // evaluate fitness value for each chromosome: x
        // for each wi and objective function fi:
        // fitness = sum(wi * norm(fi(x)))
        // signature for each fi: double f(std::vector<double>)
    void evaluateFitnessValue();
    // (serial) update elites
    void updateElites();
    // (serial) determine the order to be paired up for crossover 
    void updateSelectedOrder();
    // crossover: produce offsprings from selected parents,
    //            push offsprings and selected parents into children
    void crossover();
    individual singlePointCrossover(size_t index, size_t p1_i, size_t p2_i);
    // mutation
    void mutation();
    // update parents
    // update elites
    // reset internal data structures
    // test stop condition

    /* helper functions */
    // pre-allocate space for efficiency and easily parallelization
    void initInternalDataStructures();
    // generate random weights
    void generateRandomWeights();
    // calculate selection probability of each solution
    // randomly replaced by elites
    void addObjectiveFunctions();
    void addObjectiveFunctionsDebug(double(*func)(std::vector<double>)) { objective_functions.push_back(func); }
    void clearObjtiveFunctions() { objective_functions.clear(); }

private:
    /* params */
    const size_t gene_count;
    const std::vector<bound> gene_bound;
    const size_t generation_number;
    const size_t population_size;   // population_size % 2 == 0
    const float mutation_probability;
    const std::string crossover_method;
    /* results */
    // elites store best-known Pareto front
    std::vector<gene> elites_chromosomes;
    std::vector<std::vector<double>> elites_weights;
    double elites_fitness_value = __DBL_MAX__;
    std::vector<double> best_fitness;
    std::vector<unsigned> new_solution_rate;
    /* internal data structures for GA */
    size_t iteration = 0;
    std::vector<individual> parents;
    std::vector<individual> children;
    std::vector<std::vector<double>> weights;
    std::vector<fitness> fitness_values;
    std::vector<size_t> selected_order;
    std::vector<double(*)(std::vector<double>)> objective_functions;
};
