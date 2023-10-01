#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Set.hpp"
#include "PriorityQueue.hpp"

class DistanceNode;

class Graph {
public:
  /**List of pointers to the Vertex objects/vertices in the graph*/
  std::vector<Vertex *> vlist;
  int heap_size;
  /**Constructor*/
  Graph();
  /**Create a new Vertex using Vertex ctor and append it to Vertex list*/
  void addVertex(std::string);
  /**Perform linear search on vlist. Return the Vertex if a Vertex object with name property equal to v is found
   * If no vertex with such a name is found, return NULL
  */
  Vertex* getVertex(std::string);
  /**Use getVertex to obtain the vertices identified by the input args v1, v2. 
   * Use the Edge ctor to create a new edge going from v1 to v2
   * Adds it to the corresponding vertex's (v1) adjacency list
   * If vertex v1 != vertex v2 add a second edge originating at v2 and ending at v1, add to v2's adjacency list
  */
  void addEdge(std::string, std::string, int);
  /**Obtain the vertices identified by the input args v1 and v2. Performs linear search on corresponding adj list*/
  Edge *getEdge(std::string, std::string);
  /**Return MST (Graph data structure) of the original graph*/
  Graph *MST();
  /**Sort the edges in the graph*/
  std::vector<Edge*> sortEdges();
  Edge* extractMin(std::vector<Edge*>&);
  /**Create max heap of edges*/
  std::vector<Edge*> buildMinEdgeHeap();
  /** Heapifies an edge/node in the heap to create min heap*/
  void minHeapify(std::vector<Edge*>&, int root);
  /** Gets index of smallest child node in a heap*/
  int getIndexOfSmallestNode(std::vector<Edge*>& edges, int root);
  /**Compute the graph's MST cost*/
  int MSTCost();
  /**Return new graph which contains sequence of vertices of the shortest path from v1 to v2*/
  Graph *SP(std::string, std::string);
  /**Return cost of shortest path from v1 to v2*/
  int SPCost(std::string, std::string);
};

#endif
