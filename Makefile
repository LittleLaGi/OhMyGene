.PHONY: clean test
PINC = `python3 -m pybind11 --includes`
SUFFIX = `python3-config --extension-suffix`

all:
	g++ -Wall -shared -std=c++11 -fPIC $(PINC) cpp/GAbind.cpp -o GAbind$(SUFFIX) -I/usr/include/python3.8

run:
	omg/run.py

test:
	python3 -m pytest test/ -v

testParser:
	python3 -m pytest test/test_parser.py -v

testPrinter:
	python3 -m pytest test/test_printer.py -v

testGA:
	python3 -m pytest test/test_GA.py -v

clean:
	rm -rf omg/__pycache__ test/__pycache__ .pytest_cache .vscode *.so