// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    //a normal dfs from each node , if theres a cycle dont include itelse include ita
    bool dfs(int node , vector<bool>&visited , vector<int>&Ans , vector<bool>&recPath, vector<vector<int>>&graph){

        visited[node] = true;
        recPath[node] = true;

        for(int ngbr : graph[node]){
            if(!visited[ngbr]){
                 if(dfs(ngbr,visited,Ans,recPath,graph)){
                  return true;  
                 }
            }else if(recPath[ngbr]){
                return true;
                
            }
        }
        
        recPath[node] = false;
        Ans.push_back(node);
            return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
    vector<bool>visited(n,false);
    vector<int>Ans;
    vector<bool>recPath(n,false);
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
        dfs(i,visited,Ans,recPath,graph);
        }
    }
    sort(Ans.begin(),Ans.end());
return Ans;
    }
};

int main(){
vector<vector<int>>graph = {{1,2},{2,3},{5},{0},{5},{},{}};
Solution sol1;

vector<int> Ans = sol1.eventualSafeNodes(graph);

for(auto it : Ans)cout<<it<<" ";
return 0;
}