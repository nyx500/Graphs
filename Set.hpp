#ifndef SET_HPP
#define SET_HPP

#include <string>
#include <vector>

#include "Vertex.hpp"

class Vertex;

class Set{
    public:
        std::vector<Vertex*> members;
        Set();
        void addVertex(Vertex* v);
};


#endif
