// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.


using namespace std;
#include<iostream>
#include<vector>

class Solution {
    vector<vector<int>>Ans;
    int n;

    void dfs(int node , vector<int>&Path , vector<vector<int>>&graph){
        if(node == n-1){
            Ans.push_back(Path);
            return;
        }

        for(int ngbr : graph[node]){
            Path.push_back(ngbr);
            dfs(ngbr,Path,graph);
            Path.pop_back();
        }
        
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         n = graph.size();

        vector<int>Path;
        Path.push_back(0);

        dfs(0,Path,graph);

        return Ans;
    }
};

int main(){
    vector<vector<int>>graph = {{1,2},{3},{3},{}};
    Solution sol1;
    vector<vector<int>>Ans = sol1.allPathsSourceTarget(graph);

    for(auto it : Ans){
        for(auto num : it){
            cout<<num << " ";
        }
        cout<<endl;
    }
    return 0;
}