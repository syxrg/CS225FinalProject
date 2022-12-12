#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

class Graph {
    public:
        Graph();
        Graph(string filename);
        ~Graph();
        void initialize(int V, vector<list<pair<int,float>>> adjacency) ;
        int getSize();
        void addEdge(int u, int v, int w);
        void addVertex();
        list<pair<int,float>> getAdjacentVertices(int v);
        void write(string new_file);

    private:
        vector<list<pair<int,float>>> adjacency_;
        // num vertices
        int V_;

};
