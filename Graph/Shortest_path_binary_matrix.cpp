// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

 
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            if(grid[0][0] != 0 || grid[m-1][m-1] != 0)return -1;
    
            std::queue<std::tuple<int,int,int>>q;
            q.push({0,0,1});
            int shortestPath =-1;
    
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    auto [x,y,cnt] = q.front();
                    q.pop();
                    if(x == m-1 && y == m-1){
                        shortestPath = cnt;
                    }
                    //down
                    if(x<m-1 && grid[x+1][y] == 0 ){
                        q.push({x+1,y,cnt+1});
                        grid[x+1][y] = -1;
                    }
                    //right
                    if(y<m-1 && grid[x][y+1] == 0){
                        q.push({x,y+1,cnt+1});
                        grid[x][y+1] = -1;
                    }
                    //up
                    if(x>0 && grid[x-1][y] == 0){
                        q.push({x-1,y,cnt+1});
                        grid[x-1][y] = -1;
                    }
                    if(y>0 && grid[x][y-1] == 0){
                        q.push({x,y-1,cnt+1});
                        grid[x][y-1] = -1;
                    }
                    //lower right diagonal
                    if(x<m-1 && y<m-1 && grid[x+1][y+1] == 0){
                        q.push({x+1,y+1,cnt+1});
                        grid[x+1][y+1] = -1;
                    } 
                    //upward left diagonal
                    if(x>0 && y<m-1 && grid[x-1][y+1] == 0){
                        q.push({x-1,y+1,cnt+1});
                        grid[x-1][y+1] = -1;
                    } 
                    //upward right diagonal
                    if(x>0 && y>0 && grid[x-1][y-1] == 0){
                        q.push({x-1,y-1,cnt+1});
                        grid[x-1][y-1] = -1;
                    } 
                    //lower left diagonal
                    if(x<m-1 && y>0 && grid[x+1][y-1] == 0){
                        q.push({x+1,y-1,cnt+1});
                        grid[x+1][y-1] = -1;
                    } 
                    
    
                }
            }
            return shortestPath;
        }
    };

int main(){
    std::vector<std::vector<int>>grid = {{0,0,0},{1,1,0},{1,1,0}};
    Solution sol1;
    std::cout<<"Shortest path size : "<<sol1.shortestPathBinaryMatrix(grid);
    return 0;
}