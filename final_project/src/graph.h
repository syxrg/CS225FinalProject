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
    
    /**
    * initializes graph with V many vertices and edges given as a adjacency list
    */
    void initialize(int V, vector<list<pair<int,float>>> adjacency) ;
    /**
    * returns number of vertices in Graph 
    * @return V_
    */
    int getSize();
    /**
    add a directed edge from u to v
    */
    void addEdge(int u, int v, int w);
    /**
    add a vertex
    */
    void addVertex();
    /**
    * for vertex v, return all vertices adjacent to v
    * @return list of adjacent vertices from v 
    */
    list<pair<int,float>> getAdjacentVertices(int v);
    /**
    * convert adjacency list into csv file
    * first row contains number of total vertices
    * second row onwards contains all the weighted edges starting vertex u
    * to v expressed as u, v, w(u->v), v', w(u-v'), ...
    * ie) 0, 1, 2.3434343, 2, 3.4543222, ...
    */
    void write();
    /***
    * takes in a key and returns the value from the map
    */
    int getCorrespondence(int val);

    private:
    /**
    * V_ = number of vertices
    * adjacency_ = adjacency list
    */
    int V_;
    vector<list<pair<int,float>>> adjacency_;
    map<int,int> map_;
};
