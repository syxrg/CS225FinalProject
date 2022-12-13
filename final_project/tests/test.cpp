#include "graph.h"
#include "kosaraju.h"
#include "shortestpaths.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * check if 2 files equal (same # rows with same values). used to test graph write
 * @param file1 first file
 * @param file2 other file
 * @return if files equal
*/
bool file_match(string file1, string file2) {
    fstream a(file1);
    fstream b(file2);
    string line1;
    string line2;
    while(getline(a, line1) && getline(b, line2)){
        if(line1 != line2) {
            return false;
        }
    }
    return !(getline(a, line1) || getline(b, line2));
}

TEST_CASE("GraphRead: Simple, Directed Pentagon") {
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

TEST_CASE("file_match: same file") {
    REQUIRE(file_match("../data/readGraph1.csv", "../data/readGraph1.csv"));
}

TEST_CASE("file_match: 1 line different") {
    REQUIRE(!file_match("../data/readGraph1.csv", "file_match_test1.csv"));
}

TEST_CASE("file_match: num lines different") {
    REQUIRE(!file_match("../data/readGraph1.csv", "file_match_test2.csv"));
}

TEST_CASE("file_match: deleted line") {
    REQUIRE(!file_match("../data/readGraph1.csv", "file_match_test3.csv"));
}

TEST_CASE("write: unmodified graph") {
    /**
     *       1    2    3    4    5     
     *    0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
   Graph G("../data/readGraph1.csv");
   G.write("../tests/write_test1.txt");
   REQUIRE(file_match("../data/readGraph1.csv", "../tests/write_test1.txt"));
}

TEST_CASE("write: after adding nodes, edges") {
    /**
     *       1    2    3    4    5     
     *    0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    Graph G("../data/readGraph1.csv");
    // adding an edge between two existing nodes, 2x
    G.addEdge(1,3,2);
    G.addEdge(2,4,6);
    // adding edge to a new node
    G.addVertex();
    G.addEdge(4,5,6);
    G.write("../tests/write_test2.txt");
    REQUIRE(file_match("../tests/write_test2_expected.csv", "../tests/write_test2.txt"));
 }

TEST_CASE("Kosaraju: Simple, Directed Pentagon") {
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

TEST_CASE("dijkstra: directed cycle") {
    /**
     *       1    2    3    4    5     
     *    0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    ShortestPaths s;
    Graph G("../tests/write_test1.txt");
    auto out = s.dijkstra(G, 0);
    vector<float> exp_dist = {0, 1, 3, 6, 10};
    vector<int> exp_pre = {-1, 0, 1, 2, 3};
    REQUIRE(exp_dist == out.first);
    REQUIRE(exp_pre == out.second);
 }

 TEST_CASE("dijkstra: perfect tree") {
    /**
     *                 0
     *              1/   \2
     *             1       2
     *          3/  \4   5/  \6
     *          3    4   5    6
    */
    ShortestPaths s;
    Graph G("../data/readGraph2.csv");
    auto out = s.dijkstra(G, 0);
    vector<float> exp_dist = {0, 1, 2, 4, 5, 7, 8};
    vector<int> exp_pre = {-1, 0, 0, 1, 1, 2, 2};
    REQUIRE(exp_dist == out.first);
    REQUIRE(exp_pre == out.second);
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


TEST_CASE("BFS: Number of edges between nodes in a tree"){
    /*
    *                 0
    *              1/   \2
    *             1       2
    *          3/  \4   5/  \6
    *          3    4   5    6
    */
    Graph G("../data/readGraph2.csv");
    BFS bfs(G);
    int result = bfs.search(0, 4);
    int expected = 4;   
    REQUIRE(result == expected); 
    int result2 = bfs.search(0, 6);
    REQUIRE(result2 == 6); 
}

TEST_CASE("BFS: number of edges between nodes in a simple, directed pentagon") {
    /*
    * w(e):  1    2    3    4    5     
    * e:   0 -> 1 -> 2 -> 3 -> 4 -> 0     
    */
    Graph G("../data/readGraph1.csv");
    BFS bfs(G);
    int result = bfs.search(0, 4);
    int expected = 4;   
    REQUIRE(result == expected);  
    int result2 = bfs.search(0, 3);
    int expected2 = 3;   
    REQUIRE(result2 == expected2);  
}