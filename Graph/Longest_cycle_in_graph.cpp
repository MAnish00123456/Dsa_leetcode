// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node.

// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int longest_cycle_in_graph = -1;

    void dfs(int node , vector<int>&edges ,vector<bool>&visited,vector<bool>&recPath, int count,vector<int>&hash,int i){
        if(node == -1)return;

        visited[node] = true;
        recPath[node] = true;
        count++;
        hash[node] = i++;//at ith time . node enetered in path
        if(edges[node] != -1 && !visited[edges[node]]){
        dfs(edges[node],edges,visited,recPath,count,hash,i);
        }else if(edges[node] != -1 && recPath[edges[node]]){
            //if cycle found , determine whether the node is the head of recPath or somewhere in between
            //if its the head of cycle , then its timestamp would be 0 else if its in middle of path , then we remove all nodes before this node to get node count in cycle
            int cycle = count - hash[edges[node]];
            longest_cycle_in_graph = max(cycle,longest_cycle_in_graph);
        }

        recPath[node] = false;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<bool>visited(n,false);
        vector<bool>recPath(n,false);
        vector<int>hash(n,-1);//stores at what point , node appears in recPath , to determine, whether the node is the head of cycle or is somewhere between

        for(int i = 0 ; i < n ; i++){
            int count = 0;//count nodes in recPath until u find a cycle

            if(!visited[i]){
                dfs(i,edges,visited,recPath,count,hash,0);
            }
        }
    return longest_cycle_in_graph;
    }
};

int main(){
    vector<int>edges = {3,3,4,2,3};
    Solution sol1;
    cout<<sol1.longestCycle(edges);
    return 0;
}