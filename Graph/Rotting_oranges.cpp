// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    //multiSource bfs solution
    //store all rotten oranges in q first , then using all these as primary sources rot other fresh oranges and then these new rotten oranges will be our secondary sources to rot other fresh oranges
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCount_1 = 0;
        std::queue<std::pair<int,int>>q;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    totalCount_1++;
                }
            }
        }
        if(totalCount_1 == 0)return 0;
        int cnt_rotten_1 = 0;
        int minMinutesForRottening = 0;
        while(!q.empty()){
            
            int sz =q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();

                if(x > 0 && grid[x-1][y] == 1){
                    cnt_rotten_1++;
                    q.push({x-1,y});
                    grid[x-1][y] = 2;
                }

                if(y > 0 && grid[x][y-1] == 1){
                    cnt_rotten_1++;
                    q.push({x,y-1});
                    grid[x][y-1] = 2;
                }

                if(x < m-1  && grid[x+1][y] == 1){
                    cnt_rotten_1++;
                    q.push({x+1,y});
                    grid[x+1][y] = 2;
                }

                if(y < n-1 && grid[x][y+1] == 1){
                    cnt_rotten_1++;
                    q.push({x,y+1});
                    grid[x][y+1] = 2;
                }
            }
                if(!q.empty())minMinutesForRottening++;

        }
        if(cnt_rotten_1 == totalCount_1){
            return minMinutesForRottening;
        }
        return -1;
    }
};

int main(){
    std::vector<std::vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution sol1;
    std::cout<<"Number of minutes to rot all(-1 if not all) : "<<sol1.orangesRotting(grid);
    return 0;
}