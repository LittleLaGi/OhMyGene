#!/usr/bin/env python3

import GAbind
import pytest

class TestGAInputParams:
    generation_number = 100
    mating_parent_ratio = 0.5
    mutation_probability = 0.01
    fitness_function_choice = 'weighted_sum'
    parent_selection_method = 'random'
    cross_over_method = 'single_point'
    mutation_method = 'random'

    ga = GAbind.GA(generation_number, mating_parent_ratio, mutation_probability,
                    fitness_function_choice, parent_selection_method, cross_over_method,
                    mutation_method)

    def test_getGenerationNumber1(self):
        assert self.ga.getGenerationNumber() == 100

    def test_MatingParentRatio1(self):
        assert round(self.ga.getMatingParentRatio(), 1) == 0.5

    def test_getMutationProbability1(self):
        assert round(self.ga.getMutationProbability(), 2) == 0.01

    def test_getFitnessFunctionChoice1(self):
        assert self.ga.getFitnessFunctionChoice() == 'weighted_sum'

    def test_getParentSelectionMethod1(self):
        assert self.ga.getParentSelectionMethod() == 'random'

    def test_getCrossOverMethods1(self):
        assert self.ga.getCrossOverMethods() == 'single_point'

    def test_getMutationMethods1(self):
        assert self.ga.getMutationMethods() == 'random'