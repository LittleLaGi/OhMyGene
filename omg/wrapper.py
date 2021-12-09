import GAbind
from parser import Parser

class GAwrapper:
    params: dict
    ga: GAbind.GA
    result: dict

    def setParams(self, input: dict):
        self.params = Parser(input).getParams()

    def run(self):
        gene_count = self.params.get('gene_count', None)
        gene_bound = self.params.get('gene_bound', None)
        generation_number = self.params.get('generation_number', None)
        population_size = self.params.get('population_size', None)
        mutation_probability = self.params.get('mutation_probability', None)
        cross_over_method = self.params.get('cross_over_method', None)
        
        self.ga = GAbind.GA(gene_count, gene_bound, generation_number, population_size, 
                        mutation_probability, cross_over_method)
        
        self.ga.createInitialPopulation()

        debug_flag = 0

        for i in range(0, self.ga.getGenerationNumber()):
            if (debug_flag):
                print(f"=========== Generation {i + 1} ===========")
                print()
                print(f"---------- parents ----------")
                parents = self.ga.getParents()
                for i in range(len(parents)):
                    print(f'{i}: {parents[i]}')

            self.ga.evaluateFitnessValue()

            if (debug_flag):
                print()
                print(f"---------- fitness & weights ----------")
                fitness = self.ga.getFitnessValues()
                weights = self.ga.getWeights()
                for i in range(len(fitness)):
                    print(f'{i}: {fitness[i]}   {weights[i]}')

            self.ga.updateElites()

            if (debug_flag):
                print()
                print(f"---------- Elites ----------")
                elites_chromosomes = self.ga.getElitesChromosomes()
                elites_weights = self.ga.getElitesWeights()
                elites_fitenss = self.ga.getElitesFitnessValue()
                print(f'fitness: {elites_fitenss}')
                for i in range(len(elites_chromosomes)):
                    print(f'{i}: {elites_chromosomes[i]}')

            self.ga.updateSelectedOrder()
            self.ga.crossover()

            if (debug_flag):
                print()
                print(f"---------- children ----------")
                children = self.ga.getChildren()
                for i in range(len(children)):
                    print(f'{i}: {children[i]}')

            self.ga.mutation()
            self.ga.updateParents()
            self.ga.randomReplace()


        elites_chromosomes = self.ga.getElitesChromosomes()
        elites_weights = self.ga.getElitesWeights()
        elites_fitness_value = self.ga.getElitesFitnessValue()
        best_fitness = self.ga.getBestFitness()
        self.result = {
            'elites_chromosomes' : elites_chromosomes,
            'elites_weights' : elites_weights,
            'elites_fitness_value' : elites_fitness_value,
            'best_fitness' : best_fitness
        }


    def getResult(self):
        return self.result