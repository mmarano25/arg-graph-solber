#include <iostream>
#include "argGraph.hpp"
#include <string>

typedef argGraph::Node      Node;
typedef argGraph::nodeSet   nodeSet;
// maps a node to (set of nodes it attacks, set of nodes that attacks it)
typedef argGraph::attackMap attackMap;

// Queries
bool argGraph::empty() const {
    return _attack_map.empty();
}

int argGraph::size() const {
    return _attack_map.size();
}

std::string set_to_string(std::set<std::string> &data) {
    std::string result = "";
    for(std::string const &s: data) {
        result += (s + " ");
    }
    return result;
}

std::string argGraph::str() const {
    // TODO get to work, need to fix += on string, perhaps add .str to each added thing?
    std::string result = "";
    for( std::pair<Node,std::pair<nodeSet, nodeSet>> node_data: _attack_map ) {
        result += node_data.first;
        result += " -> \t";
        result += set_to_string(node_data.second.first);
        result += "\n";
        result += "  <- \t";
        result += set_to_string(node_data.second.second);
        result += "\n";
    }
    return result;
}

int argGraph::inDegree(Node node) {
    return _attack_map[node].second.size();
}

int argGraph::outDegree(Node node) {
    return _attack_map[node].first.size();
}

nodeSet argGraph::attackers(Node node) {
    return _attack_map[node].second;
}

nodeSet argGraph::attacks(Node node) {
    return _attack_map[node].first;
}

// Commands
void argGraph::add_node(Node node, nodeSet &attacks) {
    // Updates both the node's attacking set and all nodes it attacks
    _attack_map[node].first.insert(attacks.begin(), attacks.end());
    for( Node a: attacks ) {
        _attack_map[a].second.insert(node);
    }
}

void argGraph::add_attack(Node node, Node attacks) {
    _attack_map[node].first.insert(attacks);
    _attack_map[attacks].second.insert(node);
}

