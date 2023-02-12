### Results

We found 48 strongly connected components, but with one strongly connected components that has the majority of airport nodes (namely 29th strongly connected component with 3127 nodes). Note not all the airports are strongly connected. We were expecting one single strongly connected component, but we realized that this was due to route.dat not having all the actual routes. There are airport nodes that can be reached from other airports, but that do not have flights leaving that airport, which makes no sense. Also, some routes might not be present because we erased some vertices without openflight code (n/a) and edges incoming or outcoming to those vertices.


### Algorithms: BFS, Dijkstra, Kosaraju

### BFS

There are two things the BFS functions achieve. One function performs breadth-first search on the graph represented by an adjacency list and stores and returns all nodes traversed by the breadth-first search, represented by a vector of strings in which each string is a node visited. It uses the standard BFS algorithm with a queue. Another function takes in two numbers representing two nodes, and returns the number of vertices traversed when DFS is performed starting at the node represented by the first argument of the function and ending at the node represented by the second argument.  It also uses the standard BFS algorithm with a queue. Both functions have a running time of O(n), where n is the number of nodes. 

### Dijkstra 

The Dijkstra’s Algorithm consists in figuring out the shortest path from a vertex u (source) to v (target). We initiate two vectors: infinity for  predecessor “p” except source vertex (we give it a value 0) and shortest distance “d” vectors, the former being a vector denoting the precedent vertex so far thats in the shortest path from u-> v and the latter p[v] with the shortest distance d[v] so far from u to v. Using the priority queue, we remove one vertex at a time (call it u’)  with the minimum distance value and “relax” the adjacent vertices (in other words, update the shortest distance values if the shortest path from u-> v is shorter if we take edge u’->v).  We do this until the priority queue is empty. The runtime will be (v+e(logv)). It is important to mention that this algorithm works only in the presence of positive edges, which is the case for us the distance between two airport nodes)


### Kosaraju 

The Kosaraju Algorithm consists in performing two DFS, once to figure out the ordering necessary for the second dfs sweep by storing them in a stack- this was done using visit method, and second time removing one node at a time until the stack is empty we get the correct strongly connected components by looking the reachability from the removed node from the reversed graph-this was done in the dfs method. This will take twice the time to run a dfs algorithm, so the run time is linear. 

### Example Output

See output.png
