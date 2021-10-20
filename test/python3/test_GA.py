import GAbind
import pytest

class TestGAInputParams:
    gene_count = 5
    gene_bound = [(-10,10), (-10,10), (-10,10), (-10,10), (-10,10)]
    generation_number = 100
    population_size = 10
    mutation_probability = 0.01
    crossover_method = 'single_point'

    ga = GAbind.GA(gene_count, gene_bound, generation_number,
                    population_size, mutation_probability, crossover_method,)

    def test_getGeneCount1(self):
        assert self.ga.getGeneCount() == 5

    def test_getGeneCountBound1(self):
        assert self.ga.getGeneBound() == [(-10,10), (-10,10), (-10,10), (-10,10), (-10,10)]

    def test_getGenerationNumber1(self):
        assert self.ga.getGenerationNumber() == 100

    def test_getPopulationSize1(self):
        assert self.ga.getPopulationSize() == 10

    def test_getMutationProbability1(self):
        assert round(self.ga.getMutationProbability(), 2) == 0.01

    def test_getCrossOverMethods1(self):
        assert self.ga.getCrossOverMethod() == 'single_point'