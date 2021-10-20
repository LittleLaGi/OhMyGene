import matplotlib.pyplot

class Printer:
    """
    [input]
    'elites_chromosomes': a list of chromosoms of the elites.
    'elites_weights': a list of weights of the elites.
    'elites_fitness_value' a number represents fitness of the elites.
    'best_fitness': a list of best fitness value of each generation.
    'new_solution_rate' a list of new solution rate of each generation.
    """
    result: dict
    def __init__(self, input: dict):
        self.result = input

    def printElites(self):
        """print out the top num individuals in last population."""
        elites_chromosomes = self.result['elites_chromosomes']
        elites_weights = self.result['elites_weights']
        elites_fitness_value = self.result['elites_fitness_value']
        
        print(f'========== Elites ==========')
        print(f'solution number: {len(elites_chromosomes)}')
        print(f'fitness value: {elites_fitness_value}')
        print()
        for i in range(len(elites_chromosomes)):
            print(f'chromosomes: {elites_chromosomes[i]}')
            print(f'weights: {elites_weights[i]}')
            print()
        print(f'===============================')
        print()


    def plotFitness(self):
        """print out the fitness diagram."""
        best_fitness = self.result['best_fitness']
        if len(best_fitness) < 1:
            raise RuntimeError('The plotFitness() method can only be called after completing at least 1 generation')

        matplotlib.pyplot.plot(best_fitness, linewidth=3, color="#3870FF")
        matplotlib.pyplot.title('Generation vs. Fitness', fontsize=14)
        matplotlib.pyplot.xlabel('Generation', fontsize=14)
        matplotlib.pyplot.ylabel('Fitness', fontsize=14)
        matplotlib.pyplot.show()


    def plotNewSolutionRate(self):
        """print out the new solution rate diagram."""
        new_solution_rate = self.result['new_solution_rate']
        if len(new_solution_rate) < 1:
            raise RuntimeError('The plotNewSolutionRate() method can only be called after completing at least 1 generation')
        
        matplotlib.pyplot.plot(new_solution_rate, linewidth=3, color="#3870FF")
        matplotlib.pyplot.title('Generation vs. New Solution Rate', fontsize=14)
        matplotlib.pyplot.xlabel('Generation', fontsize=14)
        matplotlib.pyplot.ylabel('New Solution Rate', fontsize=14)
        matplotlib.pyplot.show()