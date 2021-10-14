#!/usr/bin/env python3

'''
Tunable Parameters
0. gene count (no default)
    range: > 0
0.1 gene bound (no default)
    len(gene_bound) == gene_count
    lower bound constraint: >= 0
    upper bound constraint: <= RAND_MAX
        Note: RAND_MAX dependents on underlying C++ library, but is guaranteed to be at least 32767.
        ref: https://www.cplusplus.com/reference/cstdlib/RAND_MAX/
1. generation number (default = 100)
    range: >= 0
2. population size (default = gene_count * 10)
3. mating parent ratio (default = 0.5)
    range: > 0 && < 1
4. mutation probability (default = 0.01)
    range: > 0 && < 1
5. weights (no default)
    len(weights) implicitly determines objective function counts ( > 0)
    w >= 0 && w <= 1 for w in weights
6. parent selection method (default = random selection)
    options:
        random
        rank
        tournament
        roulette_wheel (fitness has to be positive)
7. cross over method (default = single point crossover)
    options:
        single_point
        two_points
        uniform
        scattered
8. mutation method (default = random mutation)
    options:
        random
        swap
        scramble
        adaptive
'''

from parser import Parser
from printer import Printer

def main():
    args = {
        'gene_count' : 5,
        'gene bound' : [(0,100), (0,100), (0,100), (0,100), (0,100)],
        'generation_number' : 100,
        'population size' : 10,
        'mating_parent_ratio' : 0.5,
        'mutation_probability' : 0.01,
        'weights' : [0.2, 0.2, 0.2, 0.2, 0.2],
        'parent_selection_method' : 'random',
        'cross_over_method' : 'single_point',
        'mutation_method' : 'random'
    }
    parser = Parser(args)
    parsed_args = parser.getParams()

    
    result = {
        'last_population': [
            ([1.1, -1.1], 0.01), ([2.2, -2.2], 0.02), ([3.3, -3.3], 0.03), ([4.4, -4.4], 0.04),
            ([5.5, -5.5], 0.05), ([6.6, -6.6], 0.06), ([7.7, -7.7], 0.07), ([8.8, -8.8], 0.08)
        ],
        'best_fitness': [
            0.1, 0.09, 0.08, 0.07, 0.06, 0.05, 0.04, 0.03, 0.02 ,0.01
        ],
        'new_solution_rate': [
            10, 8, 8, 5, 3, 4, 4, 4, 2, 2
        ]
    }
    printer = Printer(result)
    """
    printer.printTopPercent(1)
    printer.printTopPercent(5)
    printer.printTopPercent(10)
    printer.printTopPercent(50)
    printer.printTopPercent(100)
    """
    printer.plotFitness()
    printer.plotNewSolutionRate()


if __name__ == "__main__":
    main()