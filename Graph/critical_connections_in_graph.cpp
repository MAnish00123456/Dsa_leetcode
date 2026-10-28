// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers 
// ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

#include<vector>
#include<iostream>
using namespace std;

class Solution {
    private:
    int time = 1;

    void  dfs(int node, int parent , vector<bool>&visited , int tin[] , int low[] , vector<int>Adj[] ,vector<vector<int>>&Ans){

        visited[node] = true;
        tin[node] = low[node] = time;
        time++;

        for(auto& ngbr : Adj[node]){
            if(ngbr == parent)continue;

            if(!visited[ngbr]){
                dfs(ngbr,node,visited,tin,low,Adj,Ans);
                low[node] = min(low[node] , low[ngbr]);
                //check node -- ngbr , if its a bridge
                if(low[ngbr] > tin[node]){
                    Ans.push_back({ngbr,node});
                }
            }else{
                //back edge , so compare with time of insertion
                low[node] = min(low[node],tin[ngbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //we will use tarjan's algorithm
        //critical connections are called bridges,. its a pair of edge a--b , where removal of this edge causes the graph to get separated into multiple components
        //for ex    a-b-e  on removal of edge b-e , graph gets separated into 2 components ,we need to find all these edges
                //  | |  
                //  c d  

        //we will maintain a tin(time of insertion in dfs) and low(lowest value node can take from its all neighbors except its parent) for every node in graph, update low value for a node if its neighbors except the parent have less low value than node

        //O(V+2E)
        vector<int>Adj[4];
        vector<bool>visited(n,false);
        int tin[4];
        int low[4]; 

        vector<vector<int>>Ans;

        for(auto& edge : connections){
            Adj[edge[0]].push_back(edge[1]);
            Adj[edge[1]].push_back(edge[0]);
        }

        dfs(0,-1,visited,tin,low,Adj,Ans);
        return Ans;
    }

};

int main(){
    Solution sol1;

    int n = 4;
    vector<vector<int>>connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>>ans = sol1.criticalConnections(n,connections);
    for(auto it : ans){
        for(int v : it){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}