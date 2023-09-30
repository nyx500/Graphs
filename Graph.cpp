#include <iostream>
#include <cmath>

#include "Graph.hpp"
#include "DisjointSet.hpp"

Graph::Graph() {
}

void Graph::addVertex(std::string name) {
  // Create the vertex before adding it to the list. If you don't use the 'new' keyword this will create
  // dangling pointers as the vertex will be destroyed following the ending of this function call!
  Vertex* v_ptr = new Vertex(name);
  // Add the pointer to the new vertex to the list
  vlist.push_back(v_ptr);
}

/**Perform linear search on vlist. Return the Vertex if a Vertex object with name property equal to v is found
 * If no vertex with such a name is found, return NULL
*/
Vertex* Graph::getVertex(std::string name) {
  for (Vertex* v : vlist)
  {
    if (v->name == name)
    {
      // If the names match, return ptr to the vertex from vlist
      return v;
    }
  }
  // No match
  return NULL;
}

/**Use getVertex to obtain the vertices identified by the input args v1, v2. 
 * Use the Edge ctor to create a new edge going from v1 to v2
 * Adds it to the corresponding vertex's (v1) adjacency list
 * If vertex v1 != vertex v2 add a second edge originating at v2 and ending at v1, add to v2's adjacency list
*/
void Graph::addEdge(std::string from, std::string to, int weight) {
  // Obtain the source vertex
  Vertex* v1 = getVertex(from);
  // Obtain the destination vertex
  Vertex* v2 = getVertex(to);
  // Create a new edge to go in the adjacency list for source vertex
  Edge* e1 = new Edge{v1, v2, weight};
  v1->adjlist.push_back(e1);
  // If vertices are different, do the same for the destination vertex
  if (v1 != v2)
  {
    Edge* e2 = new Edge{v2, v1, weight};
    v2->adjlist.push_back(e2);
  }
}

/**Obtain the vertices identified by the input args v1 and v2. Performs linear search on corresponding adj list*/
Edge *Graph::getEdge(std::string from, std::string to) {
  Vertex* v1 = getVertex(from);
  Vertex* v2 = getVertex(to);

  for (Edge* e : v1->adjlist)
  {
    if (e->from == v1 && e->to == v2)
    {
      return e;
    }
  }

  return NULL;
}

int Graph::MSTCost() {
  
    Graph* tree = MST();
    std::vector<Edge*> edges;

    for (Vertex* v : tree->vlist)
    {
      for (Edge* e1 : v->adjlist)
      {
        bool already = false;
        for (Edge* e2 : edges)
        {
          if ((e1->from->name == e2->to->name) && (e1->to->name == e2->from->name))
          {
            already= true;
          }
        }
        if (!already)
        {
          edges.push_back(e1);
        }
      }
    }

    int count = 0;
    for (Edge*& edge_to_count : edges)
    {
      count += edge_to_count->weight;
    }

    return count;
}

/**KRUSKAL'S ALGORITHM for Sparse Graphs: return MST (Graph data structure) of the original graph*/
Graph *Graph::MST() {
    // Initalize the MST
    Graph* tree = new Graph();
    // Add separated vertices to the tree with the same names as in vlist but no adjlist
    for (Vertex* v : vlist)
    {
      tree->addVertex(v->name);
    }
    // Create empty disjoint set
    DisjointSet f{};
    // Populate the disjoint set with the disjoint sets containing one vertex each
    for (Vertex* v : vlist)
    {
      f.MakeSet(v);
    }

    std::vector<Edge*> list_of_sorted_edges = sortEdges();

    for (auto& e : list_of_sorted_edges)
    {
      Set* s1 = f.FindSet(e->from);
      Set* s2 = f.FindSet(e->to);
      // Add edges to tree
      if (s1 != s2)
      {
        tree->addEdge(e->from->name, e->to->name, e->weight);
        // Check if sets are different (disjoint) sets and vertices are not in the same set
        f.Union(e->from, e->to);
      }
    }
    return tree;
}

/**Sort the edges in the graph*/
std::vector<Edge*> Graph::sortEdges()
{

  std::vector<Edge*> edges = buildMinEdgeHeap();
  std::vector<Edge*> output;


  while (heap_size > 0)
  {
    Edge* newEdge = extractMin(edges);
    output.push_back(newEdge);
  }

  return output;
}

Edge* Graph::extractMin(std::vector<Edge*>& edges)
{
  Edge* min = edges[0];
  edges[0] = edges[heap_size - 1];
  edges.pop_back();
  heap_size = heap_size - 1;
  minHeapify(edges, 0);
  return min;
}

std::vector<Edge*> Graph::buildMinEdgeHeap()
{
  // Create array of edges in the graph
  std::vector<Edge*> edges;

  for (Vertex* &v : vlist)
  {
    for (Edge* &e : v->adjlist)
    {
      // Set flag to tell if edge is a duplicate
      bool already_added = false;
      // Check for symmetric edges and exclude these
      for (Edge*& already_chosen : edges)
      { 
        // Avoid the duplicate edges
        if (e->from == already_chosen->to && e->to == already_chosen->from)
        { 
          already_added = true;
        }
      }
      if (!already_added)
      {
        edges.push_back(e);
      }
    }
  } // end the for-loop


  // Heapify the array of edges: only heapify the elements which are not leaves, as leaves are already heaps
  for (int j = floor(edges.size() / 2) - 1; j >= 0; --j)
  {
    minHeapify(edges, j);
  }
  heap_size = edges.size();
  return edges;
}

/** Heapifies an edge/node in the heap to create min heap*/
void Graph::minHeapify(std::vector<Edge*>& edges, int root)
{
  int smallest_idx = getIndexOfSmallestNode(edges, root); // arg root is here as input

  if (smallest_idx != root)
  {
    // Swap with child with the largest node if there is one that exists
    Edge* tmp = edges[root];
    edges[root] = edges[smallest_idx];
    edges[smallest_idx] = tmp;
    // Recursive call to minHeapify again
    minHeapify(edges, smallest_idx);
  }

}

/** Gets index of smallest child node in a heap*/
int Graph::getIndexOfSmallestNode(std::vector<Edge*>& edges, int root)
{
  int left_child_index = (2 * root ) + 1;
  int right_child_index = (2 * root ) + 2;
  int smallest_index = root;
  if (left_child_index < edges.size() && edges[left_child_index]->weight < edges[smallest_index]->weight)
  {
    smallest_index = left_child_index;
  }
  if (right_child_index < edges.size() && edges[right_child_index]->weight < edges[smallest_index]-> weight)
  {
    smallest_index = right_child_index;
  }
  return smallest_index;
}

int Graph::SPCost(std::string from, std::string to) {
    return -1;
}

Graph *Graph::SP(std::string from, std::string to) {
    return NULL;
}




