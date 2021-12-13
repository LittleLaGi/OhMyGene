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
'''

import sys
sys.path.append('/home/littlelagi/OhMyGene')
from printer import Printer
from wrapper import GAwrapper

def main():

    args = {
        'gene_count' : 2,
        'gene_bound' : [(-1, 1), (-1, 1)],
        'generation_number' : 1000,
        'population_size' : 100,
        'mutation_probability' : 0.01,
        'cross_over_method' : 'single_point'
    }

    ga = GAwrapper()
    ga.setParams(args)
    ga.run()
    result = ga.getResult()

    printer = Printer(result)
    printer.printElites()
    printer.plotFitness()

if __name__ == "__main__":
    main()