#include "../src/kosaraju.h"
#include "../src/graph.h"
#include <iostream>

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
    std::cout << bfs.search(737, 3159) << " flights are needed to travel between the airports." << endl;
    return 0;
}
