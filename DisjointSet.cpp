#include <iostream>
#include "DisjointSet.hpp"

/**Constructor just makes empty disjoint set*/
DisjointSet::DisjointSet()
{
}

/**Creates a new set whose only member is a vertex, v, and adds it to this disjoint set*/
void DisjointSet::MakeSet(Vertex* v) 
{   
    // Create a new set with only that vertex as the element
    Set* s = new Set{};
    s->addVertex(v);
    // Add the single-element set to the subsets of the disjoint set
    subsets.push_back(s);
}

/**Returns the value of the 'representative' of the set in real life, but here let us just return the found set */
Set* DisjointSet::FindSet(Vertex* v)
{
    for (auto &s : subsets)
    {
        for (auto &vertex : s->members)
        {
            if (v == vertex)
            {
                return s;
            }
        }
    }
    return NULL;
}

/**Merges two subsets into one set*/
void DisjointSet::Union(Vertex* source, Vertex* destination)
{   
    // Set containing source vertex
    Set* s1;
    // Set containing destination vertex
    Set* s2;

    // Find the correct subsets with the source and destination vertices in them
    for (Set* subset : subsets)
    {
        for (Vertex* v : subset->members)
        {
            if (v == source)
            {
                s1 = subset;
            }
        }
    }

    for (Set* subset : subsets)
    {
        for (Vertex* v : subset->members)
        {
            if (v == destination && subset != s1)
            {
                s2 = subset;
            }
        }
    }

    // Merge the sets
    Set* s3 = new Set();
    for (auto &v : s1->members)
    {
        s3->addVertex(v);
    }
    for (auto &v : s2->members)
    {
        s3->addVertex(v);
    }

    // Remove old sets s1 and s2
    auto iterator = subsets.begin();
    while (iterator != subsets.end())
    {
        if (*iterator == s1 || *iterator == s2)
        {
            iterator = subsets.erase(iterator);
        }
        else
        {
            iterator++;
        }
    }

    // Add s3 to subsets
    subsets.push_back(s3);
}



