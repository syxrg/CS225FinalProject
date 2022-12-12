#include <limits>
#include "graph.h"
#include "shortestpaths.h"

void ShortestPaths::shortest_paths(Graph G) {
    int size = G.getSize();
    int inf = std::numeric_limits<int>::infinity();
    for(int i = 0; i < size; i++) {
        vector<int> vec = {};
        for(int j = 0; j < size; j++) {
            vec.push_back(inf);
        }
        dists.push_back(vec);
    }

    for(int j = 0; j < size; j++) {
        dists[j][j] = 0;
        for(auto pair : G.getAdjacentVertices(j)) {
            dists[j][pair.first] = pair.second;
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if(dists[j][k] > dists[j][i] + dists[i][k]) {
                    dists[j][k] = dists[j][i] + dists[i][k];
                }
            }
        }
    }

}

int ShortestPaths::min_dist(int u, int v) {
    return dists[u][v];
}

int ShortestPaths::closest_dest(int src) {
    int min_dist = std::numeric_limits<int>::infinity();
    int dest = src;
    for(size_t i = 0; i < dists.size(); i++) {
        if(i != src && dists[src][i] < min_dist) {
            dest = i;
        }
    }
    return dest;
}