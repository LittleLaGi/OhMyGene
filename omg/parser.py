class Parser:
    """Checks the validity of input parameters and performs necessary transformations."""
    params: dict
    parent_selection_methods = {'random', 'rank', 'tournament', 'roulette_wheel'}
    cross_over_methods = {'single_point', 'two_points', 'uniform', 'scattered'}
    mutation_methods = {'random', 'swap', 'scramble', 'adaptive'}

        
    def __init__(self, input: dict):
        self.params = self.parseInput(input)
    
    def getParams(self) -> dict:
        return self.params

    def parseInput(self, input: dict) -> dict:
        output = input
        gene_count = output.get('gene_count', None)
        generation_number = output.get('generation_number', None)
        population_size = output.get('population_size', None)
        mating_parent_ratio = output.get('mating_parent_ratio', None)
        mutation_probability = output.get('mutation_probability', None)
        weights = output.get('weights', None)
        parent_selection_method = output.get('parent_selection_method', None)
        cross_over_method = output.get('cross_over_method', None)
        mutation_method = output.get('mutation_method', None)

        if gene_count is None:
            raise RuntimeError('Gene count has to be provided!')
        elif not isinstance(gene_count, int):
            raise TypeError('Wrong type for gene_count!')
        elif gene_count <= 0:
            raise ValueError('Invalid number for gene_count!')

        if generation_number is None:
            output['generation_number'] = 100
        elif not isinstance(generation_number, int):
            raise TypeError('Wrong type for generation_number!')
        elif generation_number < 0:
            raise ValueError('Invalid number for generation_number!')

        if population_size is None:
            output['population_size'] = gene_count * 10
        elif not isinstance(population_size, int):
            raise TypeError('Wrong type for population size!')
        elif population_size < 1:
            raise ValueError('Invalid number for population size!')

        if mating_parent_ratio is None:
            output['mating_parent_ratio'] = 0.5
        elif not isinstance(mating_parent_ratio, float) and not isinstance(mating_parent_ratio, int):
            raise TypeError('Wrong type for mating_parent_ratio!')
        elif mating_parent_ratio <= 0 or mating_parent_ratio >= 1:
            raise ValueError('Invalid number for mating_parent_ratio!')

        if mutation_probability is None:
            output['mutation_probability'] = 0.01
        elif not isinstance(mutation_probability, float) and not isinstance(mutation_probability, int):
            raise TypeError('Wrong type for mutation_probability!')
        elif mutation_probability <= 0 or mutation_probability >= 1:
            raise ValueError('Invalid number for mutation_probability!')

        if weights is None or len(weights) < 1:
            raise RuntimeError('Weights have to be provided!')
        elif not isinstance(weights, list):
            raise TypeError('Wrong type for weights!')
        else:
            for w in weights:
                if not isinstance(w, float) and not isinstance(w, int):
                    raise TypeError(f'Wrong type for w in weights: {w}')
                if w < 0 or w > 1:
                    raise ValueError(f'Invalid value for w in weights: {w}')

        if parent_selection_method is None:
            output['parent_selection_method'] = 'random'
        elif not isinstance(parent_selection_method, str):
            raise TypeError('Wrong type for parent_selection_method!')
        elif parent_selection_method not in self.parent_selection_methods:
            raise ValueError('Invalid option for parent_selection_method')

        if cross_over_method is None:
            output['cross_over_method'] = 'single_point'
        elif not isinstance(cross_over_method, str):
            raise TypeError('Wrong type for cross_over_method!')
        elif cross_over_method not in self.cross_over_methods:
            raise ValueError('Invalid option for cross_over_method')

        if mutation_method is None:
            output['mutation_method'] = 'random'
        elif not isinstance(mutation_method, str):
            raise TypeError('Wrong type for mutation_method!')
        elif mutation_method not in self.mutation_methods:
            raise ValueError('Invalid option for mutation_method')

        return output

    


