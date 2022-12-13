#pragma once
#include "graph.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <list>

class BFS {
    public:
    /**
    * Initializer for BFS class 
    */
    BFS(Graph G);
    /**
    * Destructor for BFS class
    */
    ~BFS();
    /**
    * BFS algorithm 
    */
    std::vector<std::string> search(int start);
    /**
    * BFS algorithm for finding the flights one needs to take from one airport to another. 
    * Start is the the airport one departs from, and end is the destination.
    */
    int search(int start, int end);
    private:
    Graph G_;    
};