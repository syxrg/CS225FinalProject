#pragma once

#include "graph.h"

using namespace std;

class ShortestPaths {
    public:
        void shortest_paths(Graph G);
        int min_dist(int u, int v);
        int closest_dest(int src);
    private:
        vector<vector<int>> dists;
};