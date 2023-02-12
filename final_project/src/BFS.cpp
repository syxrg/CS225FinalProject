#include "BFS.h"

BFS::~BFS() {}

BFS::BFS(Graph G): G_(G) {
    vector<list<pair<int,float>>> vec(G.getSize(), list<pair<int,float>>());
    for(int i = 0; i < G.getSize(); i++){
        list<pair<int, float>> adjacent = G.getAdjacentVertices(i);
        for(auto j = adjacent.begin(); j != adjacent.end(); j++){
            vec[j->first].push_back({i, j->second});
        }
    }
}


std::vector<std::string> BFS::search(int i) {
    std::vector<bool> visited;
    visited.resize(G_.getSize());
    for (auto a : visited) {
        a = false;
    }
    std::vector<std::string> airports;
    list<int> queue;
    visited[i] = true;
    queue.push_back(i);
    while(queue.empty() == false) {
        i = queue.front();
        airports.push_back(std::to_string(i));
        queue.pop_front();
        for (auto adj : G_.getAdjacentVertices(i)) {
            if (visited[adj.first] == false) {
                queue.push_back(adj.first);
                visited[adj.first] = true;
            }
        }
    }
    return airports;
}

int BFS::search(int start, int end) {
    std::vector<bool> visited;
    visited.resize(G_.getSize());
    for (auto a : visited) {
        a = false;
    }
    int flights = 0;
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    while(queue.front() != end) {
        start = queue.front();
        flights++;
        queue.pop_front();
        for (auto adj : G_.getAdjacentVertices(start)) {
            if (visited[adj.first] == false) {
                queue.push_back(adj.first);
                visited[adj.first] = true;
            }
        }
    }
    return flights;
}