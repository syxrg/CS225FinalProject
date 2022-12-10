#include "../src/kosaraju.h"
#include "../src/graph.h"
#include <iostream>

using namespace std;

int main() {
    /*
    print the number of strongly connected components for airport routes and their components
    */
    Graph G("../data/adjacency_list.csv");
    Kosaraju K(G);
    K.calculateSSC();
    vector<vector<int>> ssc = K.getSSC();
    cout << "The number of strongly connected components is " << ssc.size() << endl;
    int num = 1;
    for(auto vec: ssc){
        cout << "The " << num << "strongly connected component: " << " ";
        for(auto v: vec){
            cout << v << " ";
        }
        cout << endl;
        num++;
    }
    return 0;
}