// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where 
// heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0),
//  and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
    
            int m = heights.size();
            int n = heights[0].size();
           vector<vector<int>>dist(m,vector<int>(n,1e9));
    
            int rDir[4] = {-1,1,0,0};
            int cDir[4] = {0,0,-1,1};
    
            //effort,row,col
            priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>>pq;
    
            dist[0][0] = 0;
            //current effort = 0
            pq.push({0,{0,0}});
    
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
    
                int oldEffort = it.first;
                int row = it.second.first;
                int col = it.second.second;
    
                for(int i = 0 ; i < 4 ; i++){
                    int nRow = row + rDir[i];
                    int nCol = col + cDir[i];
    
                    if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n){
                        int newEffort = max(abs(heights[nRow][nCol] - heights[row][col]),oldEffort);//diff = current effort
                        if(newEffort < dist[nRow][nCol]){
                            dist[nRow][nCol] = newEffort;
                            pq.push({newEffort,{nRow,nCol}});
                        }
                    }
                }
            }
    
            return dist[m-1][n-1];
            
        }
    };

int main(){
    vector<vector<int>>heights = {{1,2,2},{3,8,2},{5,3,5}};
    Solution sol1;
    cout<<sol1.minimumEffortPath(heights);
    return 0;
}