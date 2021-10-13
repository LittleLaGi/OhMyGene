#include <vector>
#include <tuple>
#include <string>

class GA {
public:
    using individual_type = std::tuple<std::vector<double>, double>;
    GA(const size_t generation_number, const float mating_parent_ratio, const float mutation_probability,
        const std::string fitness_function_choice, const std::string parent_selection_method,
        const std::string cross_over_methods, const std::string mutation_methods)
        : generation_number(generation_number), mating_parent_ratio(mating_parent_ratio),
        mutation_probability(mutation_probability), fitness_function_choice(fitness_function_choice),
        parent_selection_method(parent_selection_method), cross_over_methods(cross_over_methods),
        mutation_methods(mutation_methods) {}
    // getter for input params: for debug usage
    const size_t getGenerationNumber() { return generation_number; }
    const float getMatingParentRatio() { return mating_parent_ratio; }
    const float getMutationProbability() { return mutation_probability; }
    const std::string getFitnessFunctionChoice() { return fitness_function_choice; }
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

private:
    // params
    const size_t generation_number;
    const float mating_parent_ratio;
    const float mutation_probability;
    const std::string fitness_function_choice;
    const std::string parent_selection_method;
    const std::string cross_over_methods;
    const std::string mutation_methods;
    // results
    std::vector<individual_type> last_population;
    std::vector<double> best_fitness;
    std::vector<unsigned> new_solution_rate;
};
