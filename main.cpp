#include <iostream>
#include <cmath>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include "Set.hpp"
#include "DisjointSet.hpp"


int main(){
    // std::cout << "Welcome to the Graphs Formative Programming Exercise!"<< std::endl;
    // // Create a Vertex (test)
    // Vertex v1("London");
    // std::cout << "New vertex created with name: " << v1.name << std::endl;
    // std::cout << "Size of adjacency list of new vertex: " << v1.adjlist.size() << std::endl;
    // // Create another Vertex (text)
    // Vertex v2("Berlin");
    // std::cout << "New vertex created with name: " << v2.name << std::endl;
    // std::cout << "Size of adjacency list of new vertex: " << v2.adjlist.size() << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // Create the graph
    Graph g{};
    g.addVertex("London");
    g.addVertex("Berlin");
    g.addVertex("Rome");
    g.addVertex("Paris");
    g.addVertex("Amsterdam");

    // std::cout << "Finding vertex ptr if exists... " << g.getVertex("London") << std::endl;
    // std::cout << "Checking if non-existing vertex search returns NULL: " << g.getVertex("Madrid") << std::endl;
    // std::cout << std::endl;

    // Adding an edge between London and Berlin
    g.addEdge("London", "Berlin", 5);
    g.addEdge("London", "Amsterdam", 2);
    g.addEdge("London", "Paris", 1);
    g.addEdge("Paris", "Berlin", 6);
    g.addEdge("Paris", "Rome", 4);
    g.addEdge("Paris", "Amsterdam", 1);
    g.addEdge("Rome", "Berlin", 7);
    g.addEdge("Rome", "Amsterdam", 6);
    g.addEdge("Berlin", "Amsterdam", 3);
    g.addEdge("Rome", "London", 9);

    // for (Edge* e : g.getVertex("London")->adjlist)
    // {
    //     std::cout << "Edge printed... " << "FROM: " << e->from->name << std::endl;
    //     std::cout << "TO: " << e->to->name << std::endl;
    //     std::cout << "Weight: " << e->weight << std::endl;
    // }

    // for (Edge* e : g.getVertex("Berlin")->adjlist)
    // {
    //     std::cout << "Edge printed... " << "FROM " << e->from->name << std::endl;
    //     std::cout << "TO " << e->to->name << std::endl;
    //     std::cout << "Weight: " << e->weight << std::endl;
    // }

    // Search for an edge (returns pointer to the edge)
    // Edge* e1 = g.getEdge("London", "Berlin");
    // std::cout <<"Found edge!" << std::endl;
    // std::cout << "Source vertex: " << e1->to->name << std::endl;
    // std::cout << "Destination vertex: " << e1->from->name << std::endl;
    // std::cout << "Weight of this edge: " << e1->weight << std::endl;
    // std::cout << std::endl;
    // std::cout<<"**************************************************************************"<<std::endl;
    // std::cout << std::endl;
    // Edge* e2 = g.getEdge("London", "Rome");
    // std::cout <<"Found edge!" << std::endl;
    // std::cout << "Source vertex: " << e2->to->name << std::endl;
    // std::cout << "Destination vertex: " << e2->from->name << std::endl;
    // std::cout << "Weight of this edge: " << e2->weight << std::endl;

    // Vertex x("X");
    // Vertex y ("Y");
    // Vertex z("Z");

    // Create disjoint set out of 3 vertices
    // DisjointSet f{};
    // f.MakeSet(&x);
    // f.MakeSet(&y);
    // f.MakeSet(&z);

    // for (Set* subset : f.subsets)
    // {
    //     for (Vertex* v : subset->members)
    //     {
    //         std::cout << v->name << " : " << v << std::endl;
    //     }
    // }

    // Test UNION operation
    // f.Union(&x, &z);

    // Find set
    // if (f.FindSet(&x) != NULL)
    // {
    //     std::cout << "Set with the element 'x' exists after union and is not null" << std::endl;
    //     std::cout << "Members of the set containing x: " << std::endl;
    //     for (Vertex* v : f.FindSet(&x)->members)
    //     {
    //         std::cout << "Vertex with value of " << v->name << std::endl;
    //     }
    // }

    // f.Union(&x, &y);
    //    // Find set
    // if (f.FindSet(&y) != NULL)
    // {
    //     std::cout << "Set with the element 'y' exists after union and is not null" << std::endl;
    //     std::cout << "Members of the set containing y: " << std::endl;
    //     for (Vertex* v : f.FindSet(&y)->members)
    //     {
    //         std::cout << "Vertex with value of " << v->name << std::endl;
    //     }
    // }

    // std::vector<Edge*> se = g.sortEdges();
    // for (auto& e : se)
    // {
    //     std::cout << e->from->name << ", " << e->to->name << ", " << e->weight << std::endl;
    // }

    std::cout << g.MSTCost() << std::endl;

    return 0;
}