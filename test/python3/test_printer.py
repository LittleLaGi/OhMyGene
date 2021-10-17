from omg.printer import Printer
import pytest

class TestPrinter:
    result = {
        'last_population': [
            ([1.1, -1.1], 0.01), ([2.2, -2.2], 0.02), ([3.3, -3.3], 0.03), ([4.4, -4.4], 0.04),
            ([5.5, -5.5], 0.05), ([6.6, -6.6], 0.06), ([7.7, -7.7], 0.07), ([8.8, -8.8], 0.08)
        ],
        'best_fitness': [
            0.1, 0.09, 0.08, 0.07, 0.06, 0.05, 0.04, 0.03, 0.02 ,0.01
        ],
        'new_solution_rate': [
            10, 8, 8, 5, 3, 4, 4, 4, 2, 2
        ]
    }
    printer = Printer(result)

    # printTopNum
    def test_printTopNum_valid_num1(self):
        self.printer.printTopNum(1)

    def test_printTopNum_ivalid_num1(self):
        with pytest.raises(ValueError):
            self.printer.printTopNum(9)

    def test_printTopNum_ivalid_num1(self):
        with pytest.raises(ValueError):
            self.printer.printTopNum(-1)

    # printTopPercent
    def test_printTopPercent_valid_num1(self):
        self.printer.printTopPercent(10)

    def test_printTopPercent_valid_num2(self):
        self.printer.printTopPercent(0)

    def test_printTopPercent_ivalid_num1(self):
        with pytest.raises(ValueError):
            self.printer.printTopPercent(-1)

    def test_printTopPercent_ivalid_num2(self):
        with pytest.raises(ValueError):
            self.printer.printTopPercent(101)