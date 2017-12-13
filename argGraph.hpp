#ifndef ARG_GRAPH_HPP
#define ARG_GRAPH_HPP

#include <string>
#include <set>
#include <map>
#include <utility>


class argGraph {
    
    public:
        typedef std::string Node;
        typedef std::set<Node> nodeSet;
        // maps a node to (set of nodes it attacks, set of nodes that attacks it)
        typedef std::map<Node, std::pair<nodeSet, nodeSet>> attackMap;

        // Iterables?

        // Queries
        bool        empty()              const;
        int         size()               const;
        std::string str()                const;
        int         outDegree(Node node);
        int         inDegree(Node node);
        nodeSet     attackers(Node node);
        nodeSet     attacks(Node node);

        // Commands
            // add_node takes an attack relation, a attacks {b, c}
        void add_node   (Node node, nodeSet &attacks);
        void add_attack (Node node, Node    attacks);
        
    private:
        attackMap _attack_map;
};

#endif /* ARG_GRAPH_HPP */
