#include "graph.h"


using namespace std;

// code below assumes no V_ (no need for traversal or Dijkstra's)
// also write to txt instead of csv
Graph::Graph(string filename) {
    fstream fs;
    fs.open(filename);
    
    int V;
    vector<list<pair<int,float>>> adjacency;
    list<pair<int,float>>  adjacent;
    string line, word1, word2;
    
    getline(fs, line);
    V = stoi(line);
    for(int i = 0; i < V; i++){
        adjacency.push_back({});
    }
  
    while(getline(fs, line)){
        adjacent.clear();
        stringstream s(line);
        getline(s, word1, ',');
        int first = stoi(word1);
        while(getline(s, word1, ',')){
            getline(s, word2, ',');
            adjacent.push_back({stoi(word1), stof(word2)});
        }
        adjacency[first] = adjacent;
    }
    fs.close();
    initialize(V, adjacency);
}
Graph::Graph(){};
Graph::~Graph(){};
void Graph::write() {
    // create the txt file
    /*ofstream graph_file("adj_ls.txt");

    // first line is not the number of vertices, we don't need this info
    for(auto adj_ls : adjacency_) {
        for(auto node : adj_ls) {
            graph_file << node << " ";
        }
        graph_file << std::endl;
    }

    graph_file.close();*/
}

void Graph::addEdge(int u, int v, int w){
    if(u < getSize() && u >= 0){
        adjacency_[u].push_back({v, w});
    }
}

void Graph::addVertex(){
    V_++;
    adjacency_.push_back(list<pair<int,float>>());
}

void Graph::initialize(int V, vector<list<pair<int,float>>> adjacency){
    V_ = V;
    adjacency_ = adjacency;
}

int Graph::getSize(){
    return V_;
}

list<pair<int,float>> Graph::getAdjacentVertices(int v){
    return adjacency_[v];
}
