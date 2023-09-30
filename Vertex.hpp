#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>

#include "Edge.hpp"

// I am disappointed that C++ needs forward declarations for
// mutually-recursive class definitions (classes which refer to one another)
// This is used to resolve circular dependency
// We start by forward declaring ClassB before defining ClassA.
// This tells the compiler that there is a class named ClassB even though its full definition
// has not been encountered yet.
// 
class Edge;

class Vertex {
public:
  /**Name of the node/vertex*/
  std::string name;
  /**Adjacency List: preferred implementation - adjList stores an array (C++ vector) of pointers to Edge objects */
  std::vector<Edge *> adjlist;
  /**Constructor: take in the name of the new vertex. Create a new instance of the adjacency list*/
  Vertex(std::string);
};

#endif
