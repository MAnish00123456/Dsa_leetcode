//construction of graph

#include<iostream>
#include<vector>

class Graph{
    int numVertices;
    std::vector<std::vector<int>>adjList;
    public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList.resize(numVertices);
    }

    void addEdge(int u , int v){
        if(u >= numVertices || v >= numVertices || u < 0 || v < 0)return;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void PrintGraph()const{
        for(int i = 0 ; i < numVertices ; i++){
            std::cout<<"vertex "<<i<<" : ";
            for(int ngbr : adjList[i]){
                std::cout<<ngbr<<" ";
            }
            std::cout<<"\n";
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.PrintGraph();
    return 0;
}