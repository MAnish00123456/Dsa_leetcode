// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.


//same as m coloring graph

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
    /** 
    A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph's vertices into two distinct sets where:
    
    All edges connect vertices from one set to vertices in the other set.
    No edges exist between vertices within the same set.
    **/
    public:
        bool isBipartite(vector<vector<int>>& graph) {
          //so we define odd set with value 1 , even set with value -1 , they also act as visited array
    
          vector<int>hashSet(graph.size(),0);
    
            auto bfs = [&](int node)->bool{
                if(hashSet[node] != 0)return true;
                queue<int>q;
                q.push(node);
                hashSet[node] = -1;//even set
    
                while(!q.empty()){
                    int n = q.front();
                    q.pop();
    
                    for(int ngbr : graph[n]){
                        //assign neighbors in opposite set than parent
                        if(hashSet[ngbr] != 0 && hashSet[ngbr] == hashSet[n]){
                            //adjacent nodes are in same set
                            return false;//graph is not bipartite
                        }else if(hashSet[ngbr] == 0){
                            //visit it
                            hashSet[ngbr] = -1*hashSet[n];//opposite set
                            q.push(ngbr);
                        }
                    }
                }
            return true;//graph is bipartite
            };
    
            for(int i = 0 ; i < graph.size() ; i++){
                if(!bfs(i)){
                    return false;
                }
            }
            return true;
          
        }
    };

int main(){
    vector<vector<int>>graph = {{1,2,3},{0,2},{0,1,3},{0,2}};

    Solution sol1;
    cout << (sol1.isBipartite(graph) ? "true" : "false") << "\n";
    return 0;
}