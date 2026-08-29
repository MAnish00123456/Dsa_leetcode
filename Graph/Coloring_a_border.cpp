// You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
// Two squares are called adjacent if they are next to each other in any of the 4 directions.
// Two squares belong to the same connected component if they have the same color and they are adjacent.
// The border of a connected component is all the squares in the connected component that are either adjacent 
// to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
// You should color the border of the connected component that contains the square grid[row][col] with color.
// Return the final grid.

// Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
// Output: [[2,2,2],[2,1,2],[2,2,2]]
 

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int row, int col, int color) {
            
            int m = grid.size() , n = grid[0].size();
    
            std::queue<std::pair<int,int>>q;
            std::vector<std::vector<bool>>visited(m,std::vector<bool>(n,false));
    
            q.push({row,col});
            visited[row][col] = true;
            int stCol = grid[row][col];
    
            int rDir[4] = {-1,1,0,0};
            int cDir[4] = {0,0,-1,1};
    
            std::vector<std::vector<int>> Ans = grid;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
    
                //color condition
                if(x == 0 || x == m-1 || y == 0 || y == n-1){
                    Ans[x][y] = color;
                }else if(grid[x-1][y] != stCol || grid[x+1][y] != stCol || grid[x][y-1] != stCol || grid[x][y+1] != stCol){
                    Ans[x][y] = color;
                }
                
    
                for(int i = 0 ; i < 4 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
    
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !visited[nRow][nCol] && grid[nRow][nCol] == stCol){
                        q.push({nRow,nCol});
                        visited[nRow][nCol] = true;
                    }
                }
            }
    
            return Ans;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>grid = {{1,1,1},{1,1,1},{1,1,1}};
    int r = 1 , c = 1 , color = 2;

    std::vector<std::vector<int>>Ans = sol1.colorBorder(grid,r,c,color);

    for(const auto& row : Ans){
        for(int v : row){
            std::cout<<v<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}