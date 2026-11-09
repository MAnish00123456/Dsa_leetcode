// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

// Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
// Output: 3
// Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    int shortest_cycle_in_graph = INT_MAX;

    void bfs(int start_node, int n, const vector<vector<int>>& AdjList) {
        // dist[i] will store the shortest distance from start_node to i
        vector<int> dist(n, -1);
        queue<pair<int, int>> q; // {current_node, parent_node}

        dist[start_node] = 0;
        q.push({start_node, -1});

        while (!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            for (int ngbr : AdjList[curr]) {
                if (dist[ngbr] == -1) {
                    // Not visited yet
                    dist[ngbr] = dist[curr] + 1;
                    q.push({ngbr, curr});
                } 
                else if (ngbr != parent) {
                    // Found a cycle! Both paths met at this edge  , different paths meeting at same node which is not parent , so total cost would be dist of curr node + dist of ngbr node from any path + 1 for current edge
                    int cycle_len = dist[curr] + dist[ngbr] + 1;
                    shortest_cycle_in_graph = min(shortest_cycle_in_graph, cycle_len);
                }
            }
        }
    }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> AdjList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        // Run BFS from every node to catch the absolute shortest cycle
        for (int i = 0; i < n; i++) {
            bfs(i, n, AdjList);
        }

        return shortest_cycle_in_graph == INT_MAX ? -1 : shortest_cycle_in_graph;  
    }
};


int main(){
    vector<vector<int>>edges = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    int n = 7;

    Solution sol1;

    cout<<sol1.findShortestCycle(n,edges);
    return 0;
}