// You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

// The total value of an island is the sum of the values of all cells in the island.

// Return the number of islands with a total value divisible by k


// Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

#include<iostream>
#include<vector>

class Solution {
    void dfs(int i , int j , std::vector<std::vector<int>>&grid , std::vector<std::vector<bool>>&visited , int m , int n , long long& sum){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0)return;
        visited[i][j] = true;
        sum  += grid[i][j];
        dfs(i-1,j,grid,visited,m,n,sum);//top
        dfs(i+1,j,grid,visited,m,n,sum);//bottom
        dfs(i,j+1,grid,visited,m,n,sum);//right
        dfs(i,j-1,grid,visited,m,n,sum);//left
    }
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<bool>>visited(m,std::vector<bool>(n,false));

        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] != 0  && !visited[i][j]){
                    long long sum = 0;
                    dfs(i,j,grid,visited,m,n,sum);
                    if(sum%k == 0)cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){

    std::vector<std::vector<int>>grid = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
    int k = 5;
    Solution sol1;
    std::cout<<"Count of islands : "<<sol1.countIslands(grid,k);
    return 0;
}