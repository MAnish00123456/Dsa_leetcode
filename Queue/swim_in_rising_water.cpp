// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

// You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//greedy bfs
class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            
            int n = grid.size();
            vector<int>vis(n*n+1,0);
    
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    
            pq.push({grid[0][0],{0,0}});
            vis[grid[0][0]] = 1;
            int rDir[4] = {-1,1,0,0};
            int cDir[4] = {0,0,-1,1};
            int t =0;
            while(!pq.empty()){
                auto [v,coord] = pq.top();pq.pop();
                auto[r,c] = coord;
    
                if(r == n-1 && c == n-1){
                    t = v;
                    break;
                }
                for(int i = 0 ; i < 4 ; i++){
                    int nRow = r + rDir[i];
                    int nCol = c + cDir[i];
    
                    if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < n && vis[grid[nRow][nCol]] == 0){
    
                        vis[grid[nRow][nCol]] = 1;
                        int nextTime = max(v,grid[nRow][nCol]);
                        pq.push({nextTime,{nRow,nCol}});
                    }
                }
            }
            return t;
        }
    };

int main(){
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    
    Solution sol1;
    cout<<sol1.swimInWater(grid);
    return 0;
}