#include<iostream>
#include<vector>

//dont work  in negative weighted cycle
//only works in non cyclic weighted graphs where weight can be negative

class Edge{
    public:
    int v , wt;
    Edge(int v , int wt){
        //v = neighbor vertex with edge weight wt 
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src , std::vector<std::vector<Edge>>g , int V){

std::vector<int>dist(V,INT_MAX);
dist[src] = 0;
//traverse using atmost v-1 edges
for(int v = 0 ; v < V-1 ; v++){
for(int u = 0 ; u < V ; u++){
    for(auto& edge : g[u]){
        if(dist[u] != INT_MAX && dist[u]+edge.wt < dist[edge.v]){
            dist[edge.v] = dist[u] + edge.wt;
        }
    }
}
}

bool hasNegativeCycle = false;
for (int u = 0; u < V; u++) {
    for (auto& edge : g[u]) {
        // If we can still relax any edge, a negative cycle exists
        if (dist[u] != INT_MAX && dist[u] + edge.wt < dist[edge.v]) {
            hasNegativeCycle = true;
            break; 
        }
    }
    if (hasNegativeCycle) break;
}

// 3. Print the result or distances
if (hasNegativeCycle) {
    std::cout << "Graph contains a negative weight cycle!" << std::endl;
} else {
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) std::cout << "INF ";
        else std::cout << dist[i] << " ";
    }
    std::cout << std::endl;
}

}

int main(){
    int V = 5;
    std::vector<std::vector<Edge>> g(V);

    g[0].push_back(Edge(1,2)); 
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,-4)); 
    // g[1].push_back(Edge(4,-1)); 

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));
    g[4].push_back(Edge(1,-1));

    bellmanFord(0,g,V);
    return 0;


}