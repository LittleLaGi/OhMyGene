#!/usr/bin/env python3

from omg.parser import Parser
import pytest

class TestParser:
    args = {
        'gene_count' : 5,
        'generation_number' : 100,
        'mating_parent_ratio' : 0.5,
        'mutation_probability' : 0.01,
        'weights' : [0.2, 0.2, 0.2, 0.2, 0.2],
        'parent_selection_method' : 'random',
        'cross_over_method' : 'single_point',
        'mutation_method' : 'random'
    }

    # default
    def test_generation_number_default(self):        
        del self.args['generation_number']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['generation_number'] == 100

    def test_mating_parent_ratio_default(self):        
        del self.args['mating_parent_ratio']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['mating_parent_ratio'] == 0.5
    
    def test_mutation_probability_default(self):        
        del self.args['mutation_probability']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['mutation_probability'] == 0.01

    def test_parent_selection_method_default(self):        
        del self.args['parent_selection_method']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['parent_selection_method'] == 'random'

    def test_cross_over_method_default(self):        
        del self.args['cross_over_method']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['cross_over_method'] == 'single_point'

    def test_mutation_method_default(self):        
        del self.args['mutation_method']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['mutation_method'] == 'random'

    # pos
    def test_gene_count_valid_pos1(self):        
        self.args['gene_count'] = 10
        Parser(self.args)
        self.args['gene_count'] = 5

    def test_generation_number_valid_pos1(self):        
        self.args['generation_number'] = 10000000
        Parser(self.args)
        self.args['generation_number'] = 100

    def test_mating_parent_ratio_valid_pos1(self):        
        self.args['mating_parent_ratio'] = 0.99999999999
        Parser(self.args)
        self.args['mating_parent_ratio'] = 0.5

    def test_mutation_probability_valid_pos1(self):        
        self.args['mutation_probability'] = 0.000000000001
        Parser(self.args)
        self.args['mutation_probability'] = 0.01

    def test_gene_count_invalid_pos1(self):        
        self.args['gene_count'] = 0
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['gene_count'] = 5

    def test_mating_parent_ratio_invalid_pos1(self):        
        self.args['mating_parent_ratio'] = 1.1
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mating_parent_ratio'] = 0.5

    def test_mating_parent_ratio_invalid_pos2(self):        
        self.args['mating_parent_ratio'] = 1
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mating_parent_ratio'] = 0.5

    def test_mutation_probability_invalid_pos1(self):        
        self.args['mutation_probability'] = 1.1
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01

    def test_mutation_probability_invalid_pos2(self):        
        self.args['mutation_probability'] = 0
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01

    # neg
    def test_generation_number_neg(self):        
        self.args['generation_number'] = -10
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['generation_number'] = 100

    def test_mating_parent_ratio_neg(self):        
        self.args['mating_parent_ratio'] = -0.1
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mating_parent_ratio'] = 0.5

    def test_mutation_probability_neg(self):        
        self.args['mutation_probability'] = -0.01
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01

    # type
    def test_gene_count_type(self):        
        self.args['gene_count'] = 5.5
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['gene_count'] = 5

    def test_generation_number_type1(self):        
        self.args['generation_number'] = 100.100
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['generation_number'] = 100
    
    def test_mating_parent_ratio_type1(self):        
        self.args['mating_parent_ratio'] = 'hello'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['mating_parent_ratio'] = 0.5

    def test_mutation_probability_type1(self):        
        self.args['mutation_probability'] = '???'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01
    
    def test_weights_type1(self):        
        self.args['weights'] = '???'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['weights'] = [0.2, 0.2, 0.2, 0.2, 0.2]

    def test_weights_type2(self):        
        self.args['weights'][1] = '!'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['weights'][1] = 0.2
    
    def test_parent_selection_method_type1(self):        
        self.args['parent_selection_method'] = -3
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['parent_selection_method'] = 'random'
    
    def test_cross_over_method_type1(self):        
        self.args['cross_over_method'] = 6666
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['cross_over_method'] = 'single_point'

    def test_mutation_method_type1(self):        
        self.args['mutation_method'] = 7777
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['mutation_method'] = 'random'

    # wrong option
    def test_parent_selection_method_type(self):        
        self.args['parent_selection_method'] = 'gg inin der'
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['parent_selection_method'] = 'random'
    
    def test_cross_over_method_type(self):        
        self.args['cross_over_method'] = 'LittleLaGi!'
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['cross_over_method'] = 'single_point'

    def test_mutation_method_type(self):        
        self.args['mutation_method'] = ''
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mutation_method'] = 'random'