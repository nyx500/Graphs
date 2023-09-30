#include "Set.hpp"

Set::Set() {
}

void Set::addVertex(Vertex* v ) {
    members.push_back(v);
}