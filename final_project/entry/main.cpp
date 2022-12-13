#include "../src/kosaraju.h"
#include "../src/BFS.h"
#include "../src/shortestpaths.h"
#include "../src/graph.h"
#include <iostream>
#include <stack>

using namespace std;

int main() {
    /*
    print the number of strongly connected components for airport routes and their components
    */
    Graph G("../data/adjacency_list.csv", "../data/openflightcode.csv");
    Kosaraju K(G);
    K.calculateSSC();
    vector<vector<int>> ssc = K.getSSC();
    cout << "The number of strongly connected components is " << ssc.size() << endl;
    int num = 1;
    for(auto vec: ssc){
        cout << "The " << "strongly connected component " << num << " : ";
        for(auto v: vec){
            cout << G.getCorrespondence(v) << " ";
        }
        cout << endl;
        num++;
    }
    /*
    Print the number of flights needed to travel between the airports.
    */
    BFS bfs(G);
    cout << bfs.search(737, 3159) << " flights are needed to travel between the airports." << endl;
    
    /**
     * Print the distance between those airports
     * 
    */
   ShortestPaths s;
   auto out = s.dijkstra(G, 737);
   cout << "The distance between those ^ airports is: " << out.first[3159] << std::endl;
   return 0;

}
