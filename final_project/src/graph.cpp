#include <iostream>
#include <fstream>
using namespace std;

// code below assumes no V_ (no need for traversal or Dijkstra's)
// also adj ls vector of vectors, write to csv

void Graph::write() {
    // create the txt file
    ofstream graph_file("adj_ls.txt");

    // first line is not the number of vertices, we don't need this info
    for(auto adj_ls : adjacency_) {
        for(auto node : adj_ls) {
            graph_file << node << " ";
        }
        graph_file << std::endl;
    }

    graph_file.close();
}