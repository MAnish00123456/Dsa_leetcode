// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

//same as map of highest peak
//multi source bfs , to find nearest 0 for each 1

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            std::vector<std::vector<int>>Ans(m,std::vector<int>(n,INT_MAX));
            std::queue<std::pair<int,int>>q;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(mat[i][j] == 0){
                        Ans[i][j] = 0;
                        q.push({i,j});
                    }
                }
            }
    
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    auto[x,y] = q.front();
                    q.pop();
                    if(x>0 && mat[x-1][y] == 1 && Ans[x-1][y] == INT_MAX){
                        Ans[x-1][y] = Ans[x][y] + 1;
                        q.push({x-1,y});
                    }
                    if(y>0 && mat[x][y-1] == 1 && Ans[x][y-1] == INT_MAX){
                        Ans[x][y-1] = Ans[x][y] + 1;
                        q.push({x,y-1});
                    }
                    if(x<m-1 && mat[x+1][y] == 1 && Ans[x+1][y] == INT_MAX){
                        Ans[x+1][y] = Ans[x][y] + 1;
                        q.push({x+1,y});
                    }
                    if(y<n-1 && mat[x][y+1] == 1 && Ans[x][y+1] == INT_MAX){
                        Ans[x][y+1] = Ans[x][y] + 1;
                        q.push({x,y+1});
                    }
                }
            }
            return Ans;
        }
    };

    int main(){
        std::vector<std::vector<int>>grid = {{0,0,0},{0,1,0},{1,1,1}};
        Solution sol1;
        std::vector<std::vector<int>>Ans = sol1.updateMatrix(grid);
        for(auto& r:Ans){
            for(auto& val : r){
                std::cout<<val<<" ";
            }
            std::cout<<std::endl;
        }
        return 0;
    }