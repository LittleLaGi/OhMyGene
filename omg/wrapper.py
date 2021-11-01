import GAbind
from parser import Parser

class GAwrapper:
    params: dict
    ga: GAbind.GA

    def setParams(self, input: dict):
        self.params = Parser(input).getParams()

    def run(self):
        gene_count = self.params.get('gene_count', None)
        gene_bound = self.params.get('gene_bound', None)
        generation_number = self.params.get('generation_number', None)
        population_size = self.params.get('population_size', None)
        mutation_probability = self.params.get('mutation_probability', None)
        cross_over_method = self.params.get('cross_over_method', None)
        
        ga = GAbind.GA(gene_count, gene_bound, generation_number, population_size, 
                        mutation_probability, cross_over_method)
        
        ga.createInitialPopulation()

        for i in range(0, ga.getGenerationNumber()):
            print(f"=========== Generation {i + 1} ===========")
            print()
            print(f"---------- parents ----------")
            parents = ga.getParents()
            for i in range(len(parents)):
                print(f'{i}: {parents[i]}')

            ga.evaluateFitnessValue()

            print()
            print(f"---------- fitness & weights ----------")
            fitness = ga.getFitnessValues()
            weights = ga.getWeights()
            for i in range(len(fitness)):
                print(f'{i}: {fitness[i]}   {weights[i]}')

            ga.updateElites()

            print()
            print(f"---------- Elites ----------")
            elites_chromosomes = ga.getElitesChromosomes()
            elites_weights = ga.getElitesWeights()
            elites_fitenss = ga.getElitesFitnessValue()
            print(f'fitness: {elites_fitenss}')
            for i in range(len(elites_chromosomes)):
                print(f'{i}: {elites_chromosomes[i]}')

            ga.updateSelectedOrder()
            ga.crossover()

            print()
            print(f"---------- children ----------")
            children = ga.getChildren()
            for i in range(len(children)):
                print(f'{i}: {children[i]}')

            ga.mutation()
            ga.updateParents()
            ga.randomReplace()