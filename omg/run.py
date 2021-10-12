#!/usr/bin/env python3

'''
Tunable Parameters
1. generation number (default = 100)
    range: >= 0
2. mating parent ratio (default = 0.5)
    range: > 0 && < 1
3. mutation probability (default = 0.01)
    range: > 0 && < 1
4. fitness function choice (default = weighted sum)
    options: 
        weighted_sum
        pareto_ranking
5. parent selection method (default = random selection)
    options:
        random
        rank
        tournament
        roulette_wheel
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

def main():
    args = {
        'generation_number' : 100,
        'mating_parent_ratio' : 0.5,
        'mutation_probability' : 0.01,
        'fitness_function_choice' : 'weighted_sum',
        'parent_selection_method' : 'random',
        'cross_over_method' : 'single_point',
        'mutation_method' : 'random'
    }

    parser = Parser(args)
    parsed_args = parser.getParams()


if __name__ == "__main__":
    main()