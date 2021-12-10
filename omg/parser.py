class Parser:
    """Checks the validity of input parameters and performs necessary transformations."""
    params: dict
    cross_over_methods = {'single_point', 'two_points', 'uniform', 'scattered'}

        
    def __init__(self, input: dict):
        self.params = self.parseInput(input)
    
    def getParams(self) -> dict:
        return self.params

    def parseInput(self, input: dict) -> dict:
        output = input
        gene_count = output.get('gene_count', None)
        gene_bound = output.get('gene_bound', None)
        generation_number = output.get('generation_number', None)
        population_size = output.get('population_size', None)
        mutation_probability = output.get('mutation_probability', None)
        cross_over_method = output.get('cross_over_method', None)


        if gene_count is None:
            raise RuntimeError('Gene count has to be provided!')
        elif not isinstance(gene_count, int):
            raise TypeError(f'Wrong type for gene_count: {gene_count}')
        elif gene_count <= 0:
            raise ValueError(f'Invalid number for gene_count: {gene_count}')

        if gene_bound is None:
            raise RuntimeError('Gene bound has to be provided!')
        elif not isinstance(gene_bound, list):
            raise TypeError('Wrong type for gene_bound!')
        elif len(gene_bound) != gene_count:
            raise RuntimeError(f'Length of gene_bound has to be as long as gene_count: {len(gene_bound)} != {gene_count}')
        for b in gene_bound:
            if not isinstance(b, tuple) or len(b) != 2:
                raise TypeError(f'Wrong type bound in gene_bound: {b}')

        if generation_number is None:
            output['generation_number'] = 100
        elif not isinstance(generation_number, int):
            raise TypeError(f'Wrong type for generation_number: {generation_number}')
        elif generation_number < 0:
            raise ValueError(f'Invalid number for generation_number: {generation_number}')

        if population_size is None:
            output['population_size'] = gene_count * 10
        elif not isinstance(population_size, int):
            raise TypeError(f'Wrong type for population size: {population_size}')
        elif population_size < 1 or population_size % 2 != 0:
            raise ValueError(f'Invalid number for population size: {population_size}')

        if mutation_probability is None:
            output['mutation_probability'] = 0.01
        elif not isinstance(mutation_probability, float) and not isinstance(mutation_probability, int):
            raise TypeError(f'Wrong type for mutation_probability: {mutation_probability}')
        elif mutation_probability <= 0 or mutation_probability >= 1:
            raise ValueError(f'Invalid number for mutation_probability: {mutation_probability}')

        if cross_over_method is None:
            output['cross_over_method'] = 'single_point'
        elif not isinstance(cross_over_method, str):
            raise TypeError(f'Wrong type for cross_over_method: {cross_over_method}')
        elif cross_over_method not in self.cross_over_methods:
            raise ValueError(f'Invalid option for cross_over_method: {cross_over_method}')

        return output

    


