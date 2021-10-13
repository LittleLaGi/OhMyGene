import matplotlib.pyplot

class Printer:
    """
    [input]
    'last_population': list of (chromosome, fitness) of the last population.
    'best_fitness': list of best fitness value of each generation.
    'new_solution_rate' list of new solution rate of each generation.
    """
    result: dict
    def __init__(self, input: dict):
        self.result = input

    def printTopNum(self, num: int):
        """print out the top num individuals in last population."""
        last_population = self.result['last_population']

        if num < 0:
            raise ValueError('Negative input number!')

        if len(last_population) < num:
            raise ValueError('Not enough individuals to show!')

        last_population.sort(key = lambda x: x[1])
        
        print(f'====== Top {num} indivisuals ======')
        for i in range(num):
            print(f'{i+1}. {last_population[i][0]}:  {last_population[i][1]}')
        print(f'===============================')
        print()


    def printTopPercent(self, percent: float):
        """print out the top individuals in last population."""
        last_population = self.result['last_population']

        if percent < 0 or percent > 100:
            raise ValueError('Invalid percentage!')

        last_population.sort(key = lambda x: x[1])
        num = int(round(len(last_population) * percent / 100))
        if num == 0:
            num = 1

        print(f'====== Top {num} indivisuals ======')
        for i in range(num):
            print(f'{i+1}. {last_population[i][0]}:  {last_population[i][1]}')
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