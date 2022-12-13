#pragma once

#include "graph.h"
// #include "priorityqueue.h"

using namespace std;

class ShortestPaths {
    public:
        void floyd_warshall(Graph G);
        int min_dist(int u, int v);
        int closest_dest(size_t src);
        pair<vector<float>, vector<int>> dijkstra(Graph G, int src);
    private:
        vector<vector<int>> all_dists;
        // vector<int> new_neighbors(vector<int> vec, set<int> seen);
        
};