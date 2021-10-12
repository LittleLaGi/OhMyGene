.PHONY: clean test

test:
	python3 -m pytest test/ -v

clean:
	rm -rf omg/__pycache__ test/__pycache__ .pytest_cache .vscode