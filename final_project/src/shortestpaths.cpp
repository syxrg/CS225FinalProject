#include <limits>
#include <algorithm>
#include <set>
#include <queue>
#include "shortestpaths.h"

pair<vector<int>, vector<int>> ShortestPaths::dijkstra(Graph G, int src) {

    vector<int> costs = {};
    vector<int> paths = {};

    set<int> seen; // labeled set
    int inf = std::numeric_limits<int>::infinity();
    vector<int> Q = {};

    for(int i = 0; i < G.getSize(); i++) {
        costs.push_back(inf);
        paths.push_back(-1);
        Q.push_back(i);
    }
    costs[src] = 0;
    
    int u = -1;
    int min_dist = inf;

    while(Q.size()) {
        min_dist = inf;
        for(int i = 0; i < Q.size(); i++) {
            if(costs[Q[i]] < min_dist) {
                min_dist = costs[Q[i]];
                u = Q[i];
            }
        }
        Q.erase(Q.begin()+u);
        list<pair<int, float>> neighbors = G.getAdjacentVertices(u);
        for(auto pair : neighbors) {
            int v = pair.first;
            if(std::find(Q.begin(), Q.end(), pair.first) != Q.end() && pair.second + costs[u] < costs[v]) {
                costs[v] = pair.second + costs[u];
                paths[v] = u;
            }
        }
    }
}

// backup written earlier, not for grading
void ShortestPaths::floyd_warshall(Graph G) {
    int size = G.getSize();
    int inf = std::numeric_limits<int>::infinity();
    for(int i = 0; i < size; i++) {
        vector<int> vec = {};
        for(int j = 0; j < size; j++) {
            vec.push_back(inf);
        }
        all_dists.push_back(vec);
    }

    for(int j = 0; j < size; j++) {
        all_dists[j][j] = 0;
        for(auto pair : G.getAdjacentVertices(j)) {
            all_dists[j][pair.first] = pair.second;
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if(all_dists[j][k] > all_dists[j][i] + all_dists[i][k]) {
                    all_dists[j][k] = all_dists[j][i] + all_dists[i][k];
                }
            }
        }
    }
}

int ShortestPaths::min_dist(int u, int v) {
    return all_dists[u][v];
}

int ShortestPaths::closest_dest(int src) {
    int min_dist = std::numeric_limits<int>::infinity();
    int dest = src;
    for(size_t i = 0; i < all_dists.size(); i++) {
        if(i != src && all_dists[src][i] < min_dist) {
            dest = i;
        }
    }
    return dest;
}

vector<int> ShortestPaths::new_neighbors(vector<int> vec, set<int> seen) {
    size_t i = 0;
    while(i < vec.size()) {
        if(seen.find(vec[i]) != seen.end()) {
            vec.erase(vec.begin()+i);
        }
        else {
            i++;
        }
    }
    return vec;
}
