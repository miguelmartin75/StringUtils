CXX=c++
CXX_ARGS=-std=c++11

all: test
test:
	$(CXX) $(CXX_ARGS) tests/functions.cpp -o tests/test_functions
	./tests/test_functions
clean:
	rm ./tests/test_functions

