#include "Graph.hpp"
#include <climits>
#include <list>
#include <iterator>
namespace ariel {

    Graph::Graph(){}
    //undirected graph is just a directed graph with an edge from a to b and b to a.
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        Graph::adjMatrix = matrix;
        if(matrix.size() != matrix[0].size()){
            exit(EXIT_FAILURE);
        }
        edges = 0;
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix.size();j++){
                if(matrix[i][j] != 0){
                    edges++;
                }
            }
        }
        vxs = matrix.size();
    }
    void Graph::printGraph() const{
        std::cout<< "Graph with " << std::to_string(Graph::vxs) << " vertices and " << std::to_string(Graph::edges) << " edges." << std::endl;
    }
    void Graph::dfs(int v,std::vector<bool>&visited) const{
        visited[v] = true;
        for(int i =0; i < Graph::size() ;i++){
            if(Graph::adjMatrix[v][i] != 0 && !visited[i]){
                dfs(i,visited);
            }
        }
    }
    int Graph::size() const{
        return Graph::adjMatrix[0].size();
    }

    std::vector<std::vector<int>> Graph::getGraph() const {
        return Graph::adjMatrix;
    }
    std::vector<std::vector<int>> Graph::getPrevMatrix() const {
        return Graph::prevMatrix;
    }
    std::vector<std::vector<int>> Graph::getDistMatrix() const {
        return Graph::distMatrix;
    }

    void Graph::floydWarshall(){
        //Fills prevMatrix and distMatrix appropriately.
        int n = Graph::size();

        std::vector<std::vector<int>> dist(n, std::vector<int>(n)); //Initializing an array within an array -> a MATRIX
        std::vector<std::vector<int>> prev(n, std::vector<int>(n,INT_MAX)); //Initializing the prev array, which is required for backtracking

        //Copy matrix into dist.
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                //we need prepare our matrix accordingly.
                if(i == j) prev[i][j] = i;
                if(i != j && Graph::adjMatrix[i][j] == 0){
                    dist[i][j] = INT_MAX;
                } else{
                    dist[i][j] = Graph::adjMatrix[i][j];
                    prev[i][j] = i;
                }
            }
        }

        //The Floyd-Warshall Algorithm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] != INT_MAX && dist[j][i] != INT_MAX && i != j && i != k && j != k) {
                        //We have to insure dist[k][j] and dist[i][k] are not individually equal to INT_MAX because summing them up could result in unexpected errors.
                        if (dist[j][k] > dist[j][i] + dist[i][k]) {
                            dist[j][k] = dist[j][i] + dist[i][k];
                            prev[j][k] = prev[i][k];
                        }
                    }
                }
            }
        }
        prevMatrix = prev;
    }

    void Graph::floydWarshallNegCycle(){
        //Fix this
        int n = Graph::size();
        std::vector<std::vector<int>> dist = Graph::getGraph(); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (dist[i][k] != INT_MAX && dist[j][k] > dist[j][i] + dist[i][k] && dist[j][i] != INT_MAX) {
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }
        distMatrix = dist;
    }

    int Graph::getEdges() const{
        return Graph::edges;
    }

}
