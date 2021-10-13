.PHONY: clean test

run:
	omg/run.py

test:
	python3 -m pytest test/ -v

testParser:
	python3 -m pytest test/test_parser.py -v

testPrinter:
	python3 -m pytest test/test_printer.py -v

clean:
	rm -rf omg/__pycache__ test/__pycache__ .pytest_cache .vscode