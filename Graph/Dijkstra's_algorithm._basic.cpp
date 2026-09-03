//it is used to find shortest path from source vertex to all other vertices for positive weighted graph

#include<iostream>
#include<vector>
#include<queue>

class Edge{
    public:
    int v , wt;
    Edge(int v , int wt){
        //v = neighbor vertex with edge weight wt 
        this->v = v;
        this->wt = wt;
    }
};

int main(){
    int V = 6;
    std::vector<std::vector<Edge>> g(V);

    g[0].push_back(Edge(1,2)); 
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1)); 
    g[1].push_back(Edge(3,7)); 

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    //dijkstra's algorithm

    //create distance array
    std::vector<int>dist(V,INT_MAX);
    //create min heap , uses a>b comparison , if its true high priority pushed down
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pq;

    pq.push({0,0});//dist[u],u
    //O((V+E)logV)
    dist[0] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        std::vector<Edge>neighs = g[u];

        for(auto& edge: neighs){
            //edge relaxation
            if(dist[edge.v] > dist[u]+edge.wt){
                dist[edge.v] = dist[u] + edge.wt;
                pq.push({dist[edge.v],edge.v});
            }
        }
    }

    for(int num : dist){
        std::cout<<num<<" ";
    }
    return 0;
}