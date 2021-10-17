.PHONY: clean test
PINC = `python3 -m pybind11 --includes`
SUFFIX = `python3-config --extension-suffix`

all:
	g++ -Wall -shared -std=c++11 -fPIC $(PINC) src/GAbind.cpp -o GAbind$(SUFFIX) -I/usr/include/python3.8 -I/home/littlelagi/OhMyGene/include

run:
	omg/run.py

test: testPython testCpp

testPython:
	python3 -m pytest test/python3/ -v

testParser:
	python3 -m pytest test/python3/test_parser.py -v

testPrinter:
	python3 -m pytest test/python3/test_printer.py -v

testGA:
	python3 -m pytest test/python3/test_GA.py -v

testCpp:
	cd test/cpp && \
	cmake -S . -B build && \
	cmake --build build && \
	cd build && ctest

clean:
	rm -rf omg/__pycache__ test/python3/__pycache__ .pytest_cache .vscode *.so test/cpp/build