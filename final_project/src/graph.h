#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <map>
using namespace std;

class Graph {
    public:
        Graph();
        Graph(string filename);
        Graph(string filename, string hashfile);
        ~Graph();
        void initialize(int V, vector<list<pair<int,float>>> adjacency);
        int getSize();
        void addEdge(int u, int v, int w);
        void addVertex();
        list<pair<int,float>> getAdjacentVertices(int v);
        void write(string new_file);
        int getWeight(int u, int v);
        /***
        * takes in a key and returns the value from the map
        */
        int getCorrespondence(int val)

    private:
        vector<list<pair<int,float>>> adjacency_;
        // num vertices
        int V_;
        map<int,int> map_;
};
