#include <limits>
#include <algorithm>
#include <set>
#include <queue>
#include "shortestpaths.h"

pair<vector<float>, vector<int>> ShortestPaths::dijkstra(Graph G, int src) {

    vector<float> costs = {};
    vector<int> paths = {};

    float inf = std::numeric_limits<float>::infinity();
    // built in faster for pq implement than writing own class
    std::priority_queue<pair<float,int>, vector<pair<float,int>>, greater<pair<float,int>>> pq;

    // init d with inf, p with empty (-1 used since idx 0-N-1 denotes pre)
    // also build heap
    for(int i = 0; i < G.getSize(); i++) {
        costs.push_back(inf);
        paths.push_back(-1);
        if(i != src) {
            pq.push({inf, i});
        }
        else {
            // use pairs with dist first, easier for cpp pq
            pq.push({0.0, src});
        }
    }
    costs[src] = 0;

    int u = -1;
    // repeat n times:
    while(!pq.empty()) {
        // removeMin()
        u = pq.top().second;
        pq.pop();

        list<pair<int, float>> neighbors = G.getAdjacentVertices(u);
        for(auto pair : neighbors) {
            int v = pair.first;
            if(pair.second + costs[u] < costs[v]) {
                costs[v] = pair.second + costs[u];
                paths[v] = u;
                pq.push({costs[v],v});
            }
        }
    }
    return {costs, paths};
}

// backup written earlier, not for grade
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

int ShortestPaths::closest_dest(size_t src) {
    int min_dist = std::numeric_limits<int>::infinity();
    int dest = src;
    for(size_t i = 0; i < all_dists.size(); i++) {
        if(i != src && all_dists[src][i] < min_dist) {
            dest = i;
        }
    }
    return dest;
}
