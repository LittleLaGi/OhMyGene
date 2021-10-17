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
        mating_parent_ratio = self.params.get('mating_parent_ratio', None)
        mutation_probability = self.params.get('mutation_probability', None)
        weights = self.params.get('weights', None)
        parent_selection_method = self.params.get('parent_selection_method', None)
        cross_over_method = self.params.get('cross_over_method', None)
        mutation_method = self.params.get('mutation_method', None)
        
        ga = GAbind.GA(gene_count, gene_bound, generation_number, population_size, mating_parent_ratio,
                        mutation_probability, weights, parent_selection_method, cross_over_method,
                        mutation_method)
        
        ga.createInitialPopulation()

        parents = ga.getParents()
        for i in range(len(parents)):
            print(f'{i}: {parents[i]}')