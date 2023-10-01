#include <iostream>
#include <vector>
#include "DistanceNode.hpp"

class DistanceNode;

class PriorityQueue{
    public:
        // array to store heap in initialized when create PriorityQueue object
        std::vector<DistanceNode*> dnodes;
        // ctor
        PriorityQueue();
        // min-heap/priority queue INSERT operation
        void Insert(DistanceNode* dn);
        // heapify up op for after inserting node to maintain heap property
        void HeapifyUp(int); // arg is the 'root' index for current element you want to heapify
        // Maintains heap property by moving the node down the tree
        void HeapifyDown(int);
        // Extract element with highest priority (minimum priority) from the priority queue
        DistanceNode* ExtractMin();
        // Decrease the key (distance/priority) of an element in the min-heap
        void DecreaseKey(std::string name_of_node, int new_distance);
    private:
        // helper funcs are private
        int Parent(int);
        int LeftChild(int);
        int RightChild(int);
        // Swap two elements by referencing their index in the DistanceNodes vector called dnodes
        void SwapElements(int, int);

};