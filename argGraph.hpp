#ifndef ARG_GRAPH_HPP
#define ARG_GRAPH_HPP

#include <string>
#include <set>
#include <map>
#include <utility>

// maps a node to the (set of nodes it attacks, set of node that attacks it)
typedef std::string Node;
typedef std::set<Node> nodeSet;
typedef std::map<Node, std::pair<nodeSet, nodeSet>> attackMap;

class argGraph {
    public:
        // Destructor/Constructors
        ~argGraph   ();
        argGraph    ();

        // Iterables?

        // Queries
        bool        empty()                     const;
        int         size()                      const;
        std::string str()                       const;
        int         outDegree()                 const;
        int         inDegree()                  const;
        nodeSet     attackers(Node node) const;

        // Commands
            // add_node takes an attack relation, (a, {b, c})
                //TODO: for efficiency, make take a pointer to a set of strings
        int  add_node   (Node node, nodeSet attacks);
        int  add_attack (Node node, Node    attacks);
        
    private:
        attackMap attack_map;
};

#endif /* ARG_GRAPH_HPP */
