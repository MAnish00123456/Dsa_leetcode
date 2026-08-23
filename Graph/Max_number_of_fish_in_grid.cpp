// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

#include<iostream>
#include<vector>

class Solution {
    // vector<vector<bool>>visited;
    int m , n;
    int findAmtOfFish(int i , int j , std::vector<std::vector<int>>&grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)return 0;

        int cntFish = grid[i][j];
        grid[i][j] = 0;
        return cntFish + findAmtOfFish(i-1,j,grid) + findAmtOfFish(i+1,j,grid) + findAmtOfFish(i,j+1,grid) + findAmtOfFish(i,j-1,grid);
    }
public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();
    // visited.resize(m,vector<bool>(n,false));

    int mxFish = 0;
    for(int i = 0 ; i < m  ; i++){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j] > 0){
                int amtOf_fish = findAmtOfFish(i,j,grid);
                mxFish = std::max(mxFish,amtOf_fish);
            }
        }
    }
    return mxFish;
    }
};

int main(){
    std::vector<std::vector<int>>grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    Solution sol1;
    std::cout<<"Max number of fish : "<<sol1.findMaxFish(grid);
    return  0;
}