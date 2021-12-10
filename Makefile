.PHONY: clean test

PROJECT_ROOT =/home/littlelagi/OhMyGene
PINC =`python3 -m pybind11 --includes`
SUFFIX =`python3-config --extension-suffix`

all:
	g++ -O3 -Wall -shared -std=c++11 -fPIC $(PINC) src/GA.cpp src/GAbind.cpp src/obj_funcs.cpp -o GAbind$(SUFFIX) -I/usr/include/python3.8 -I$(PROJECT_ROOT)/include

run:
	python3 omg/run.py

test: testPython testCpp

testPython:
	python3 -m pytest test/python3/ -v

testParser:
	python3 -m pytest test/python3/test_parser.py -v

testGA:
	python3 -m pytest test/python3/test_GA.py -v

testCpp:
	cmake -S . -B build
	cmake --build build
	cd build && ctest
	
testCppLog:
	cat build/Testing/Temporary/LastTest.log

clean:
	rm -rf omg/__pycache__ test/python3/__pycache__ .pytest_cache .vscode *.so ./build