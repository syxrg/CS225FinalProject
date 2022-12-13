#include "graph.h"
#include "kosaraju.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace std;
TEST_CASE("GraphRead: Simple, Directed Pentagon", "[weight=5][part=1]") {
    /*
    * w(e):  1    2    3    4    5     
    * e:   0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    Graph G("../data/readGraph1.csv");
    vector<list<pair<int,float>>> expected = {{{1, 1}}, {{2, 2}}, {{3,3}}, {{4,4}}, {{0, 5}} };

}

TEST_CASE("GraphRead: Simple, Directed Tree"){
    /*
    *                 0
    *              1/   \2
    *             1       2
    *          3/  \4   5/  \6
    *          3    4   5    6
    */
    Graph G("../data/readGraph2.csv");
    vector<list<pair<int, float>>> expected = {{{1,1}, {2,2}}, {{3,3}, {4,4}}, {{5,5}, {6,6}}, {}, {}, {}, {} };
    for(int i = 0; i < 5; i++){
        REQUIRE(G.getAdjacentVertices(i) == expected[i]);
    }
}

TEST_CASE("Kosaraju: Simple, Directed Pentagon", "[weight=5][part=1]") {
    /*
    * w(e):  1    2    3    4    5     
    * e:   0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    Graph G("../data/readGraph1.csv");
    Kosaraju k(G);
    k.calculateSSC();
    vector<vector<int>> vec = k.getSSC();
    vector <vector<int>> expected = {{0,4,3,2,1}};
    REQUIRE(vec == expected); 
}

TEST_CASE("Kosaraju: Simple, Directed Tree"){
    /*
    *                 0
    *              1/   \2
    *             1       2
    *          3/  \4   5/  \6
    *          3    4   5    6
    */
    Graph G("../data/readGraph2.csv");
    Kosaraju k(G);
    k.calculateSSC();
    vector<vector<int>> vec = k.getSSC();
    vector <vector<int>> expected = {{0}, {2}, {6}, {5}, {1}, {4}, {3}};
    REQUIRE(vec == expected); 
}

TEST_CASE("BFS: Simple, Directed Pentagon") {
    /*
    * w(e):  1    2    3    4    5     
    * e:   0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    Graph G("../data/readGraph1.csv");
    BFS bfs(G);
    std::vector<std::string> v = bfs.search(0);
    std::vector<std::string> expected = {{"0"}, {"1"}, {"2"}, {"3"}, {"4"}};   
    REQUIRE(v == expected); 
}

TEST_CASE("BFS: Simple, Directed Tree"){
    /*
    *                 0
    *              1/   \2
    *             1       2
    *          3/  \4   5/  \6
    *          3    4   5    6
    */
    Graph G("../data/readGraph2.csv");
    BFS bfs(G);
    std::vector<std::string> v = bfs.search(0);
    std::vector<std::string> expected = {{"0"}, {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}};   
    REQUIRE(v == expected); 
}

