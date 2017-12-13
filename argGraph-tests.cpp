#include <iostream>
#include "argGraph.hpp"

typedef argGraph::Node      Node;
typedef argGraph::nodeSet   nodeSet;
// maps a node to (set of nodes it attacks, set of nodes that attacks it)
typedef argGraph::attackMap attackMap;

int main() {
    argGraph test;

    nodeSet a_attacks {"f"};
    nodeSet f_attacks {"a"};
    nodeSet b_attacks {"a"};
    nodeSet e_attacks {"f", "b"};
    nodeSet c_attacks {"b", "d"};
    nodeSet d_attacks {"c"};

    test.add_node("a", a_attacks);
    test.add_node("f", f_attacks);
    test.add_node("b", b_attacks);
    test.add_node("e", e_attacks);
    test.add_node("c", c_attacks);
    test.add_node("d", d_attacks);

    std::cout << test.str() << std::endl;

    std::cout << "In a: ";
    std::cout << test.outDegree("a") << std::endl;
    return 0;
}

