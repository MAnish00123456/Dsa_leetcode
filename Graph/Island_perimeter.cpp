// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a 
// square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        int islandPerimeter(std::vector<std::vector<int>>& grid) {
            
            int perimeter = 0;
            int m = grid.size() , n = grid[0].size();
            std::vector<std::vector<bool>>visited(m,std::vector<bool>(n,false));
    
            std::queue<std::pair<int,int>>q;
    
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        visited[i][j] = true;
                        break;
                    }
                }
            }
            int rDir[4] = {-1,1,0,0};
            int cDir[4]  = {0,0,-1,1};
    
            while(!q.empty()){
    
                    auto[x,y] = q.front();
                    q.pop();
                    if((x>0 && grid[x-1][y] != 1) || x == 0 ){
                        perimeter++;
                    }
                    if((x<m-1 && grid[x+1][y] != 1) || x == m-1 ){
                        perimeter++;
                    }
                    if((y>0 && grid[x][y-1] != 1) || y == 0 ){
                        perimeter++;
                    }
                    if((y<n-1 && grid[x][y+1] != 1) || y == n-1 ){
                        perimeter++;
                    }
                    for(int i = 0 ; i < 4 ; i++){
                        int nRow = x + rDir[i];
                        int nCol = y + cDir[i];
    
                        if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                            q.push({nRow,nCol});
                            visited[nRow][nCol] = true;
                        }
                    }
                
            }
        return perimeter;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    std::cout<<"Island perimeter : "<<sol1.islandPerimeter(grid);
    return 0;
}