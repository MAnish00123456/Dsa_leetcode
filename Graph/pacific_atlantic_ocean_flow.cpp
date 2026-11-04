// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south,
//  east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        int rows , cols;
        void dfs(int r , int c , vector<vector<bool>>&visit,int prevheight,vector<vector<int>>&heights){
            if(r < 0 || c < 0 || r >= rows || c >= cols || heights[r][c] < prevheight || visit[r][c])return;
            visit[r][c] = true;
            dfs(r+1,c,visit,heights[r][c],heights);
            dfs(r-1,c,visit,heights[r][c],heights);
            dfs(r,c+1,visit,heights[r][c],heights);
            dfs(r,c-1,visit,heights[r][c],heights);
        }
    public:
    //so instead of doin dfs from each cell , we gonna do opposite
    //we gonna travel from oceans to surfaces on condition if surface height is greater than previous height
    ///then at last , we gonna check each cell , and if that cell is present in both atlantic and pacific sets , it means using this cell water can flow to both oceans
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            rows = heights.size() , cols = heights[0].size();
            vector<vector<bool>>atlantic(rows,vector<bool>(cols,false)) , pacific(rows,vector<bool>(cols,false));
    
            //top and bottom oceans 
            for(int c = 0 ; c < cols ; c++){
                dfs(0,c,pacific,heights[0][c],heights);
                dfs(rows-1,c,atlantic,heights[rows-1][c],heights);
            }
    
            //left and right oceans
            for(int r = 0 ; r < rows ; r++){
                dfs(r,0,pacific,heights[r][0],heights);
                dfs(r,cols-1,atlantic,heights[r][cols-1],heights);
            }
    
            vector<vector<int>>Ans;
            for(int r = 0 ; r < rows ; r++){
                for(int c = 0 ; c < cols ; c++){
                    if(atlantic[r][c] && pacific[r][c]){
                        Ans.push_back({r,c});
                    }
                }
            }
            return Ans;
        }
    };

int main(){
    vector<vector<int>>heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5}};
    Solution sol1;
    vector<vector<int>>ans = sol1.pacificAtlantic(heights);
    for(auto it : ans){
        for(auto i : it)cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}