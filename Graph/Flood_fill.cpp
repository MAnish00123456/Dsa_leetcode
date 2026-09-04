// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
            
            int m = image.size() , n = image[0].size();
    
            std::queue<std::pair<int,int>>q;
            std::vector<std::vector<bool>>visited(m,std::vector<bool>(n,false));
            q.push({sr,sc});
            visited[sr][sc] = true;
            int rDir[4] = {-1,1,0,0};
            int cDir[4] = {0,0,-1,1};
            int stCol = image[sr][sc];
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
    
                image[x][y] = color;
    
                for(int i = 0  ; i < 4 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
    
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && image[nRow][nCol] == stCol && !visited[nRow][nCol]){
                        visited[nRow][nCol] = true;
                        q.push({nRow,nCol});
                    }
    
                }
    
            }
            return image;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1 , sc = 1 , color = 2;
    std::vector<std::vector<int>>Ans = sol1.floodFill(image,sr,sc,color);

    for(const auto& row : Ans){
        for(int v : row){
            std::cout<<v<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}