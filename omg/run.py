#!/usr/bin/env python3

'''
Tunable Parameters
1. gene count (no default)
    range: > 0

2. gene bound (no default)
    len(gene_bound) == gene_count
    gene value: [lower, upper]

3. generation number (default = 100)
    range: >= 0

4. population size (default = gene_count * 10)
    constraint: population_size % 2 == 0

5. mutation probability (default = 0.01)
    range: > 0 && < 1

6. cross over method (default = single point crossover)
    options:
        single_point
        two_points
        uniform
        scattered
'''
import sys
sys.path.append('/home/littlelagi/OhMyGene')
from printer import Printer
from wrapper import GAwrapper

def main():

    args = {
        'gene_count' : 5,
        'gene_bound' : [(0,100), (0,100), (0,100), (0,100), (0,100)],
        'generation_number' : 50,
        'population_size' : 10,
        'mutation_probability' : 0.01,
        'cross_over_method' : 'single_point'
    }

    ga = GAwrapper()
    ga.setParams(args)
    ga.run()




    """ test Printer """
    # result = {
    #     'elites_chromosomes' : [
    #         [1.1, -1.1], [2.2, -2.2], [3.3, -3.3], [4.4, -4.4]
    #     ],
    #     'elites_weights' : [
    #         [0.1, 0.6, 0.3], [0.2, 0.4, 0.4], [0.1, 0.8, 0.1], [0.4, 0.3, 0.3]
    #     ],
    #     'elites_fitness_value' : 0.00123,
    #     'best_fitness': [
    #         0.1, 0.09, 0.08, 0.07, 0.06, 0.05, 0.04, 0.03, 0.02 ,0.01
    #     ],
    #     'new_solution_rate': [
    #         10, 8, 8, 5, 3, 4, 4, 4, 2, 2
    #     ]
    # }
    # printer = Printer(result)

    # printer.printElites()
    # printer.plotFitness()
    # printer.plotNewSolutionRate()


if __name__ == "__main__":
    main()