// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.

#include<iostream>
#include<vector>

class Solution {
    //  vector<vector<bool>>visited;
     int m , n;
     int areaofIsland(int i , int j , std::vector<std::vector<int>>&grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)return 0;
        grid[i][j] = 0;
       return 1+ areaofIsland(i-1,j,grid)+areaofIsland(i+1,j,grid)+areaofIsland(i,j-1,grid)+areaofIsland(i,j+1,grid);
     }
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
     m = grid.size();
     n = grid[0].size();
     int mxArea = 0;
    //  visited.resize(m,vector<bool>(n,false));
     for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j] == 1){
               int cntof1 = areaofIsland(i,j,grid);
               mxArea = std::max(mxArea,cntof1);
            }
        }
     } 
     return mxArea;  
    }
};

int main(){
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    Solution sol1;
    std::cout<<"Max area : "<<sol1.maxAreaOfIsland(grid);
    return 0;
}