#include "BFS.h"

BFS::~BFS() {}

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