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
    private:
    Graph G_;    
};