#pragma once
#include "graph.h"
#include <algorithm>
#include <stack>
#include <vector>
#include <list>
using namespace std;

class Kosaraju {
    public:
    /**
    * Initializer for Kosaraju class 
    */
    Kosaraju(Graph G);
    /**
    * Destructor for Kosaraju class
    */
    ~Kosaraju();
    /**
    * Calculate the strongly connected components and store it in ssc_
    */
    void calculateSSC();
    /**
    * Returns the strongly connected components as vector<vector<int>> form
    */
    vector<vector<int>> getSSC();
    /**
    * Intermediate step to calculate strongly connected components
    * Store all the vertices in stack in the reverse order that it was visited using DFS
    */
    void visit(int vertex, vector<bool>& visited, stack<int>& s);
    /**
    * Intermediate step to calculate strongly connected components
    * DFS function used in Kosaraju::visit()
    */
    void DFS(int vertex, vector<bool>& visited);
    private:
    Graph G_;
    Graph RevG_;
    vector<vector<int>> ssc_;
};