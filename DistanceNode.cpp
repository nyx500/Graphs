#include "DistanceNode.hpp"

// Simple constructor to store a pointer to a vertex and distance from source node
DistanceNode::DistanceNode(Vertex* _v, int unsigned _distance) {
    v = _v;
    distance = _distance;
}
