The following is a documentation for EX1 of SE2 written by 211465786.
Various helpful sources I have used includes: ChatGPT, Wikipedia, GeekForGeeks, StackOverflow.
# Disclaimer
I couldn't get the given makefile to work with my code, therefore I created my own. You should be able to run ./test normally.
Regarding tests, I added 15 tests to the given 5 tests.

# Graph:
Represented by a class.
## Fields
* adjMatrix: The adjacency matrix inserted by calling loadGraph().
* prevMatrix: Parent pointer matrix, initialized as the zero matrix and can be filled by calling floydWarshall(). Mainly used by the 'Algorithms' to detect all shortest paths in every possible type fo graph.
* distMatrix: Distance matrix, initialized as the zero matrix and can be filled by calling floydWarshallNegCycle(). Mainly used by the 'Algorithms' class to detect negative cycles in a graph.
* vxs: # of verties in the given graph.
* edges: # of edges in the given graph.
## Methods:
* Graph(): default constructor.
* loadGraph(): Loads the graph from a given adjacency matrix.
* printGraph(): Prints the edges and vxs in a graph in the correct format.
* size(): Returns # of vxs in the given graph.
* dfs(): Performs recursive depth-first search on the graph stored in adjMatrix.
* getGraph(): Returns the adjMatrix.
* getPrevMatrix(): Returns the parent pointer matrix, which would be filled only after floydWarshall() was called.
* getDistMatrix() const: Returns the distance matrix, which would be filled only after floydWarhallNegCycle() was called.
* floydWarshall(): Performs the Floyd-Warshall algorithm on the adjMatrix and fills prevMatrix correctly to find all-pair * shortest paths.
* floydWarshallNegCycle(): Performs a slightly different implementation of the Floyd-Warshall algorithm on the adjMatrix and fills distMatrix which can be then used to detected negative-weight cycles in the given graph.
* getEdges(): Returns the # of edges in the given graph.

# Algorithms
Represented by a static class to group together all the algorithms in an elegant way.
## Fields:
none
## Methods: 
* isConnected(): Performs DFS on the graph, and returns true if every vx was visited during DFS.
* shortestPath(): Performs a standard implementation of the Floyd-Warshall algorithm on the graph, and generates all possible shortests path between every pair of vxs in the graph.
* isContainsCycle(): 
* isBipartite(): Performs a standard 2-coloring algorithm on the graph, which paints an arbitrary vx in red, and then paints its neighbours blue and so on.. If the graph is 2-colorable it directly implies the graph is Bipartite as teached in Algorithms 1.
* negativeCycle(): Performs a slightly-different implementation of the Floyd-Warshall Algorithm and then iterates upon the main diagonal in the distance matrix for any negative-values which would imply the graph has a negative-weight cycle. Returns true if it finds any.

