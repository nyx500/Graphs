#ifndef DISJOINTSET_HPP
#define DISJOINSET_HPP

#include <string>
#include <vector>

#include "Vertex.hpp"
#include "Set.hpp"

// I am disappointed that C++ needs forward declarations for
// mutually-recursive class definitions
class Vertex;
class Set;

class DisjointSet {
public:
  std::vector<Set*>subsets;
  /**Constructor just makes empty disjoint set*/
  DisjointSet();
  /**Creates a new set whose only member is a vertex, v, and adds it to this disjoint set*/
  void MakeSet(Vertex* v);
  /**Returns the value of the 'representative' of the set in real life, but here let us just return the found set */
  Set* FindSet(Vertex* v);
  /**Merges two subsets into one set*/
  void Union(Vertex* source, Vertex* destination);
};

#endif