#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
namespace ariel{
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        std::vector<std::vector<int>> prevMatrix;
        std::vector<std::vector<int>> distMatrix;
        int vxs;
        int edges;
    public:
        Graph(); 
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        int size() const;
        void dfs(int v,std::vector<bool>& visited) const;
        std::vector<std::vector<int>> getGraph() const;
        std::vector<std::vector<int>> getPrevMatrix() const;
        std::vector<std::vector<int>> getDistMatrix() const;
        void floydWarshall();
        void floydWarshallNegCycle();
        int getEdges() const;
    };
}
#endif 
