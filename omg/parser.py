class Parser:
    """Checks the validity of input parameters and performs necessary transformations."""
    params: dict
    fitness_function_choices = {'weighted_sum', 'pareto_ranking'}
    parent_selection_methods = {'random', 'rank', 'tournament', 'roulette_wheel'}
    cross_over_methods = {'single_point', 'two_points', 'uniform', 'scattered'}
    mutation_methods = {'random', 'swap', 'scramble', 'adaptive'}

        
    def __init__(self, input: dict):
        self.params = self.parseInput(input)
    
    def getParams(self) -> dict:
        return self.params

    def parseInput(self, input: dict) -> dict:
        output = input
        generation_number = output.get('generation_number', None)
        mating_parent_ratio = output.get('mating_parent_ratio', None)
        mutation_probability = output.get('mutation_probability', None)
        fitness_function_choice = output.get('fitness_function_choice', None)
        parent_selection_method = output.get('parent_selection_method', None)
        cross_over_method = output.get('cross_over_method', None)
        mutation_method = output.get('mutation_method', None)

        if generation_number is None:
            output['generation_number'] = 100
        elif not isinstance(generation_number, int):
            raise TypeError('Wrong type for generation_number!')
        elif generation_number < 0:
            raise ValueError('Invalid number for generation_number!')

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

        if fitness_function_choice is None:
            output['fitness_function_choice'] = 'weighted_sum'
        elif not isinstance(fitness_function_choice, str):
            raise TypeError('Wrong type for fitness_function_choice!')
        elif fitness_function_choice not in self.fitness_function_choices:
            raise ValueError('Invalid option for fitness_function_choice')

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

    


