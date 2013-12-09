test:
	c++ ./tests/functions.cpp -std=c++11 -o "./tests/test_functions"
	./tests/test_functions
clean:
	rm -f ./tests/test_functions
