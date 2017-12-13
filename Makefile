argGraph-tests: argGraph.hpp argGraph.cpp argGraph-tests.cpp
	g++ -Wall -Wextra -std=c++11 argGraph.cpp argGraph.hpp argGraph-tests.cpp -o argGraph-tests

clean:
	rm argGraph-tests -f
