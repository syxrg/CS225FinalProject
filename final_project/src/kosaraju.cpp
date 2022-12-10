#include "kosaraju.h"

void Kosaraju::visit(int vertex, vector<bool>& visited, stack<int>& s){
    visited[vertex] = true;
    for(auto v: G_.getAdjacentVertices(vertex)){
        if(!visited[v.first]){
            visit(v.first, visited, s);
        }
    }
    s.push(vertex);
}

void Kosaraju::DFS(int vertex, vector<bool>& visited){
    ssc_[ssc_.size()-1].push_back(vertex);
    visited[vertex] = true;
    for(auto v: RevG_.getAdjacentVertices(vertex)){
        if(!visited[v.first]){
            DFS(v.first, visited);
        }
    }
}

Kosaraju::Kosaraju(Graph G): G_(G), RevG_() {
    vector<list<pair<int,float>>> vec(G.getSize(), list<pair<int,float>>());
    for(int i = 0; i < G.getSize(); i++){
        list<pair<int, float>> adjacent = G.getAdjacentVertices(i);
        for(auto j = adjacent.begin(); j != adjacent.end(); j++){
            vec[j->first].push_back({i, j->second});
        }
    }
    RevG_.initialize(G.getSize(), vec);
}

Kosaraju::~Kosaraju() {};

void Kosaraju::calculateSSC(){
    ssc_.clear();
    int numComp = 0;
    stack<int> s;
    vector<bool> visited(G_.getSize(), false);
    for(int i = 0; i < G_.getSize(); i++){
        if(!visited[i]) {
            visit(i, visited, s);
        }
    }

    visited.clear();
    visited.assign(RevG_.getSize(), false);
    while(!s.empty()){
        int vertex = s.top();
        s.pop();
        if(!visited[vertex]){
        ssc_.push_back(vector<int>());
        DFS(vertex, visited);
        numComp++;
        }
    }

}

vector<vector<int>> Kosaraju::getSSC(){
    return ssc_;
}

