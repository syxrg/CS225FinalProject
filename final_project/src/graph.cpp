#include "graph.h"

using namespace std;

/**
 * Graph constructor. init adjacency_ and V_ from existing graph file
 * @param filename graph file name
*/
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
Graph::Graph(string filename, string hashfile) {
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

    fs.open(hashfile);
    while(getline(fs,line)){
        stringstream s(line);
        while(getline(s, word1, ',')){
            getline(s, word2, ',');
            map_.insert({stoi(word1), stoi(word2)});
        }
    }
    fs.close();
}
Graph::Graph(){};
Graph::~Graph(){};

/**
* wrote adjacency list to file
* first row: V_
* following rows: src, dest0, weight0, ... destn, weightn
* @param new_file new graph file name
*/
void Graph::write(string new_file) {
    // create the txt file
    ofstream graph_file(new_file);

    // V is first line
    graph_file << V_ << std::endl;

    // add lines for each node adj ls
    // each line is: src, dest0, weight0, ... destn, weightn
    for(int i = 0; i < V_; i++) {
        // src
        graph_file << i;
        // traverse weight/node pairs in each adj ls, add vals to lines
        for(auto pair : adjacency_[i]) {
            graph_file << ", " << pair.first << ", " << pair.second;
        }
        graph_file << std::endl;
    }

    graph_file.close();
}

/**
 * add a directed edge from existing nodes u to v
 * @param u src
 * @param v dest
 * @param w edge weight
*/
void Graph::addEdge(int u, int v, int w){
    if(u < getSize() && u > -1){
        adjacency_[u].push_back({v, w});
    }
}

/**
add a vertex
*/
void Graph::addVertex(){
    V_++;
    adjacency_.push_back(list<pair<int,float>>());
}

/**
* initializes graph with V many vertices and edges given as a adjacency list
* @param V num vertices 
* @param adjacency adjacency list
*/
void Graph::initialize(int V, vector<list<pair<int,float>>> adjacency){
    V_ = V;
    adjacency_ = adjacency;
}

/**
* returns number of vertices in Graph 
* @return V_
*/
int Graph::getSize(){
    return V_;
}
int Graph::getCorrespondence(int val){
    if(!map_.empty()){
    return map_[val];
    }
    return -1;
}

/**
* for vertex v, return all vertices adjacent to v
* @param v idx of node
* @return list of adjacent vertices from v 
*/
list<pair<int,float>> Graph::getAdjacentVertices(int v){
    return adjacency_[v];
}

int Graph::getWeight(int u, int v) {
    for(auto pair : adjacency_[u]) {
        if(pair.first == v) {
            return pair.second;
        }
    }
    return -1;
}