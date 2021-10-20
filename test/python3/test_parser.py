from omg.parser import Parser
import pytest

class TestParser:
    args = {
        'gene_count' : 5,
        'gene_bound' : [(-10,10), (-10,10), (-10,10), (-10,10), (-10,10)],
        'generation_number' : 100,
        'population_size' : 10,
        'mutation_probability' : 0.01,
        'cross_over_method' : 'single_point'
    }

    # default
    def test_generation_number_default(self):        
        del self.args['generation_number']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['generation_number'] == 100

    def test_population_size_default(self):        
        del self.args['population_size']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['population_size'] == 50
    
    def test_mutation_probability_default(self):        
        del self.args['mutation_probability']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['mutation_probability'] == 0.01

    def test_cross_over_method_default(self):        
        del self.args['cross_over_method']
        parser = Parser(self.args)
        parsed_args = parser.getParams()
        assert parsed_args['cross_over_method'] == 'single_point'

    # pos
    def test_generation_number_valid_pos1(self):        
        self.args['generation_number'] = 10000000
        Parser(self.args)
        self.args['generation_number'] = 100

    def test_population_size_pos1(self):        
        self.args['population_size'] = 15
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['population_size'] = 10

    def test_mutation_probability_valid_pos1(self):        
        self.args['mutation_probability'] = 0.000000000001
        Parser(self.args)
        self.args['mutation_probability'] = 0.01

    def test_gene_count_invalid_pos1(self):        
        self.args['gene_count'] = 0
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['gene_count'] = 5

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

    def test_population_size_neg(self):        
        self.args['population_size'] = -1
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['population_size'] = 10

    def test_mutation_probability_neg(self):        
        self.args['mutation_probability'] = -0.01
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01

    # type
    def test_gene_count_type1(self):        
        self.args['gene_count'] = 5.5
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['gene_count'] = 5

    def test_gene_bound_type1(self):        
        self.args['gene_bound'][3] = '!'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['gene_bound'][3] = (-10, 10)

    def test_gene_bound_type2(self):        
        self.args['gene_bound'][3] = (0, 0, 0)
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['gene_bound'][3] = (-10, 10)

    def test_generation_number_type1(self):        
        self.args['generation_number'] = 100.100
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['generation_number'] = 100
    
    def test_population_size_type1(self):        
        self.args['population_size'] = 5.5
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['population_size'] = 10

    def test_mutation_probability_type1(self):        
        self.args['mutation_probability'] = '???'
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['mutation_probability'] = 0.01
    
    def test_cross_over_method_type1(self):        
        self.args['cross_over_method'] = 6666
        with pytest.raises(TypeError):
            parser = Parser(self.args)
        self.args['cross_over_method'] = 'single_point'

    # wrong option   
    def test_cross_over_method_type(self):        
        self.args['cross_over_method'] = 'LittleLaGi!'
        with pytest.raises(ValueError):
            parser = Parser(self.args)
        self.args['cross_over_method'] = 'single_point'

    # runtime error
    def test_gene_bound_neg1(self):        
        self.args['gene_bound'] = [(-10,10), (-10,10), (-10,10), (-10,10), (-10,10), (-10,10)]
        with pytest.raises(RuntimeError):
            parser = Parser(self.args)
        self.args['gene_bound'] = [(-10,10), (-10,10), (-10,10), (-10,10), (-10,10)]