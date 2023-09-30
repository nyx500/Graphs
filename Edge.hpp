#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

// I am disappointed that C++ needs forward declarations for
// mutually-recursive class definitions
class Vertex;

class Edge {
public:
  /**Origin vertex: pointer to Vertex object */
  Vertex *from;
  /**Destination vertex: pointer to Vertex object*/
  Vertex *to;
  /**Weight of the edge (must be an integer)*/
  int weight;
  /**Constructor: must take in as args source vertex, destination vertex, weight
   * Creates a new edge by assigning it an origin vertex (from) and destination vertex (to)
  */
  Edge(Vertex *, Vertex*, int);
};

#endif
