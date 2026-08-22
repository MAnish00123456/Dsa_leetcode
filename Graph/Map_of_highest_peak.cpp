// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

#include<iostream>
#include<vector>
#include<queue>

// Multi-source BFS:
// All water cells start at distance 0.
//
// BFS explores cells in increasing distance order.
// Therefore, the first time a land cell is reached,
// it is reached from its nearest water source.
//
// Once visited, it never needs to be processed again.

// class Solution {
// public:
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         int m = isWater.size();
//         int n = isWater[0].size();
//      vector<vector<int>>Ans(m,vector<int>(n,INT_MAX));   
//      queue<tuple<int,int,int>>q;

//      for(int i = 0 ; i < m ; i++){
//         for(int j = 0 ; j < n ; j++){
//             if(isWater[i][j] == 1){
//                 Ans[i][j] =0;
//                 q.push({i,j,0});
//             }
//         }
//      }

//      while(!q.empty()){
//         int sz = q.size();
//         while(sz--){
//             auto[x,y,dist] = q.front();
//             q.pop();
//             if(x>0 && isWater[x-1][y] == 0 && Ans[x-1][y] == INT_MAX){
//                 Ans[x-1][y] = min(Ans[x-1][y],dist+1);
//                 q.push({x-1,y,dist+1});
//             } 
//             if(y>0 && isWater[x][y-1] == 0 && Ans[x][y-1] == INT_MAX){
//                 Ans[x][y-1] = min(Ans[x][y-1],dist+1);
//                 q.push({x,y-1,dist+1});
//             } 
//             if(x<m-1 && isWater[x+1][y] == 0 && Ans[x+1][y] == INT_MAX){
//                 Ans[x+1][y] = min(Ans[x+1][y],dist+1);
//                 q.push({x+1,y,dist+1});
//             } 
//             if(y<n-1 && isWater[x][y+1] == 0 && Ans[x][y+1] == INT_MAX){
//                 Ans[x][y+1] = min(Ans[x][y+1],dist+1);
//                 q.push({x,y+1,dist+1});
//             } 
//         }
//      }
//      return Ans;
//     }
// };
class Solution {
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        std::vector<std::vector<int>> Ans(m, std::vector<int>(n, INT_MAX));
        std::queue<std::pair<int,int>> q;

        // All water cells are sources with distance 0.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(isWater[i][j] == 1){
                    Ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Multi-source BFS.
        // First time we reach a cell = minimum distance
        // from any water cell.
        while(!q.empty()){

            auto [x,y] = q.front();
            q.pop();

            // Up
            if(x > 0 && Ans[x-1][y] == INT_MAX){
                Ans[x-1][y] = Ans[x][y] + 1;
                q.push({x-1,y});
            }

            // Left
            if(y > 0 && Ans[x][y-1] == INT_MAX){
                Ans[x][y-1] = Ans[x][y] + 1;
                q.push({x,y-1});
            }

            // Down
            if(x < m-1 && Ans[x+1][y] == INT_MAX){
                Ans[x+1][y] = Ans[x][y] + 1;
                q.push({x+1,y});
            }

            // Right
            if(y < n-1 && Ans[x][y+1] == INT_MAX){
                Ans[x][y+1] = Ans[x][y] + 1;
                q.push({x,y+1});
            }
        }

        return Ans;
    }
};

    int main(){
        std::vector<std::vector<int>>grid = {{0,1},{0,0}};
        Solution sol1;
        std::vector<std::vector<int>>Ans = sol1.highestPeak(grid);
        for(auto& r:Ans){
            for(auto& val : r){
                std::cout<<val<<" ";
            }
            std::cout<<std::endl;
        }
        return 0;
    }