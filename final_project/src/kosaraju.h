#pragma once
#include "graph.h"
#include <algorithm>
#include <stack>
#include <vector>
#include <list>
using namespace std;

class Kosaraju {
    public:
    Kosaraju(Graph G);
    ~Kosaraju();
    void calculateSSC();
    vector<vector<int>> getSSC();
    void visit(int vertex, vector<bool>& visited, stack<int>& s);
    void DFS(int vertex, vector<bool>& visited);
    private:
    Graph G_;
    Graph RevG_;
    vector<vector<int>> ssc_;
};