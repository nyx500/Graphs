#include "PriorityQueue.hpp"
#include <cmath> //floor

// ctor
PriorityQueue::PriorityQueue() {
};

// min-heap/priority queue INSERT operation
void PriorityQueue::Insert(DistanceNode* dn) {
    // remember: distancenode has 2 properties/data members, a pointer to a vertex and distance from source node
    dnodes.push_back(dn); // add new node to end of heap
    // Maintain the heap property by heapifying up: input argument is the last inserted node (last index in list)
    HeapifyUp(dnodes.size() - 1);
};

// heapify up op for after inserting node to maintain heap property
void PriorityQueue::HeapifyUp(int index) {
    // Only heapify if the indexed element in dnodes is NOT at pos 0 in the heap array
    while (index > 0)
    {   
        int parentIndex = Parent(index);
        // If distance property of current node is smaller than that of parent's, swap them
        if (dnodes[index]->distance < dnodes[parentIndex]->distance)
        {
            SwapElements(index, parentIndex);
            // Important: remember to update the index as it is stored now at the parent's index after swapping!
            index = parentIndex;
        }
        // If parent has smaller distance property already, terminate execution of the while loop
        else
        {
            break;
        }
    }
}

// Maintains heap property by moving the node down the tree
void PriorityQueue::HeapifyDown(int index)
{   
    // Must get indexes for left child, right child of current node
    int leftchild_index = LeftChild(index);
    int rightchild_index = RightChild(index);
    int smallest_index = index;

    // If left child exists AND its value is smaller than current node's, store left child index as smallest
    if (leftchild_index < dnodes.size() && dnodes[leftchild_index]->distance < dnodes[smallest_index]->distance)
    {
        smallest_index = leftchild_index;
    }

    // If right child exists AND its value is smaller than dist value of node stored in 'smallest' index, 
    // store right child index as smallest
    if (rightchild_index < dnodes.size() && dnodes[rightchild_index]->distance < dnodes[smallest_index]->distance)
    {
        smallest_index = rightchild_index;
    }

    // If distance node entered as input argument is not the node with the smallest distance when compared 
    // to its children swap the smaller node so it goes 'above' the currently selected node
    if (smallest_index != index) // Base case: when current node is smallest compared to children or no children, stop recursion
    {
        SwapElements(index, smallest_index);
        // Recursive call while current node's distance is still greater than its childrens'
        HeapifyDown(smallest_index);
    } 
}

// Extract element with highest priority (minimum priority) from the priority queue
DistanceNode* PriorityQueue::ExtractMin()
{
    // Swap 'root' node (smallest element) with last node in the heap
    SwapElements(0, dnodes.size() - 1);

    // Remove the last node: C++ pop_back regrettably does not return popped off element
    DistanceNode* last_node = dnodes[dnodes.size() - 1];
    dnodes.pop_back();

    // Maintain the heap property by heapifying down
    HeapifyDown(0);
    
    // Return the smallest node that was extracted and placed at the end of the heap
    return last_node;
}

// Decrease the key (distance/priority) of an element in the min-heap
void PriorityQueue::DecreaseKey(std::string name_of_node, int new_distance)
{   
    // Linear search to select the node by name
    for (int i = 0; i < dnodes.size(); ++i)
    {   
        if (dnodes[i]->v->name == name_of_node)
        {
            // Check that new distance is really smaller than old one
            if (new_distance > dnodes[i]->distance)
            {
                std::cout << "PriorityQueue::Decrease Key - new distance is larger than previous distance!" << std::endl;
            }
            // If new distance is smaller, update the 'distance' property (priority) of the DistanceNode
            else
            {
                dnodes[i]->distance = new_distance;
                // Now heapify to preserve the heap property
                HeapifyUp(i);
            }
        }
    }
}


int PriorityQueue::Parent(int index)
{   
    return floor((index-1)/2);
}
int PriorityQueue::LeftChild(int index)
{
    return ((2*index) + 1);
}
int PriorityQueue::RightChild(int index) {
    return ((2*index) + 2);
}

// Swap two elements by referencing their index in the DistanceNodes vector called dnodes
void PriorityQueue::SwapElements(int index1, int index2)
{
    DistanceNode* tmp = dnodes[index1];
    dnodes[index1] = dnodes[index2];
    dnodes[index2] = tmp;
}