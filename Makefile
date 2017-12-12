argGraph: argGraph.hpp argGraph.cpp
	g++ -Wall -Wextra -std=c++11 argGraph.cpp -o argGraph

clean:
	rm argGraph -f
