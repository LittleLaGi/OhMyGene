#!/usr/bin/env python3

'''
Tunable Parameters
0. gene count (no default)
    range: > 0
1. generation number (default = 100)
    range: >= 0
2. mating parent ratio (default = 0.5)
    range: > 0 && < 1
3. mutation probability (default = 0.01)
    range: > 0 && < 1
4. weights (if weighted_sum is chosen)
    len(weights) == gene countg
5. parent selection method (default = random selection)
    options:
        random
        rank
        tournament
        roulette_wheel (fitness has to be positive)
6. cross over method (default = single point crossover)
    options:
        single_point
        two_points
        uniform
        scattered
7. mutation method (default = random mutation)
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
        'generation_number' : 100,
        'mating_parent_ratio' : 0.5,
        'mutation_probability' : 0.01,

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