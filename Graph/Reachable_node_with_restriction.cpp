// There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
// You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. 
// You are also given an integer array restricted which represents restricted nodes.
// Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
// Note that node 0 will not be a restricted node.

// Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
// Output: 4
// Explanation: The diagram above shows the tree.
// We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
class Solution {
    public:
        int reachableNodes(int n,std::vector<std::vector<int>>& edges, std::vector<int>& restricted) {
         std::unordered_set<int>visited(restricted.begin(),restricted.end());
    
       std::vector<std::vector<int>> AdjList(n);
         for(auto& pair : edges){
            AdjList[pair[0]].push_back(pair[1]);
            AdjList[pair[1]].push_back(pair[0]);
         }   
    
        std::queue<int>q;
        q.push(0);
        visited.insert(0);
        int cnt = 1;
        while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto& ngbr : AdjList[node]){
                    if(!visited.count(ngbr)){
                        cnt++;
                        visited.insert(ngbr);
                        q.push(ngbr);
                    }
                }
        }
         return cnt;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    std::vector<int>restricted = {4,5};
    int n = 7;
    std::cout<<"Number of reachable nodes : "<<sol1.reachableNodes(n,edges,restricted);
    return 0;
}