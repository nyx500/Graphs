#include <iostream>
#include "Vertex.hpp"

class Vertex;

class DistanceNode{
    public:
        Vertex* v;
        int distance;
        // Constructor: takes in 2 args -> name of Vertex + distance from source node for Dijkstra
        DistanceNode(Vertex* _v, int unsigned _distance);
};