#!/usr/bin/env python3

import GAbind
import pytest

class TestGAInputParams:
    gene_count = 5
    generation_number = 100
    population_size = 10
    mating_parent_ratio = 0.5
    mutation_probability = 0.01
    weights = [0.2, 0.2, 0.2, 0.2, 0.2]
    parent_selection_method = 'random'
    cross_over_method = 'single_point'
    mutation_method = 'random'

    ga = GAbind.GA(gene_count, generation_number, population_size, mating_parent_ratio,
                    mutation_probability, weights, parent_selection_method, cross_over_method,
                    mutation_method)

    def test_getGeneCount1(self):
        assert self.ga.getGeneCount() == 5

    def test_getGenerationNumber1(self):
        assert self.ga.getGenerationNumber() == 100

    def test_getPopulationSize1(self):
        assert self.ga.getPopulationSize() == 10

    def test_MatingParentRatio1(self):
        assert round(self.ga.getMatingParentRatio(), 1) == 0.5

    def test_getMutationProbability1(self):
        assert round(self.ga.getMutationProbability(), 2) == 0.01

    def test_getWeights1(self):
        for w in self.ga.getWeights():
            assert round(w, 1) == 0.2

    def test_getParentSelectionMethod1(self):
        assert self.ga.getParentSelectionMethod() == 'random'

    def test_getCrossOverMethods1(self):
        assert self.ga.getCrossOverMethods() == 'single_point'

    def test_getMutationMethods1(self):
        assert self.ga.getMutationMethods() == 'random'