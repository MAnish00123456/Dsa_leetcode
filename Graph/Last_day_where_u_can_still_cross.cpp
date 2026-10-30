// //similar as escape the spreading fire
// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
#include<iostream>
#include<vector>
using namespace std;
#include<queue>

class Solution {
    vector<vector<int>>WaterSpread;
    int m , n;

    // Store the exact day on which each cell becomes water.
    // Example: WaterSpread[x][y] = 5 means this cell becomes
    // blocked starting from day 5.
    //
    // This lets us answer:
    // "Is this cell still available on day X?"
    // simply by checking WaterSpread[x][y] > X.
    void fillUpdays(vector<vector<int>>&cells){
        int crntday = 1;

        for(auto& day : cells){
            int x = day[0]-1;
            int y = day[1]-1;

            WaterSpread[x][y] = crntday++;
        }
    }

    // Check whether it is possible to cross the grid if we
    // start trying to cross on 'lastday'.
    //
    // We don't simulate the water spreading day-by-day.
    // Instead, WaterSpread already tells us when every cell
    // becomes blocked.
    bool isAbleToCross(int lastday){

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;

        // On 'lastday', only cells whose flooding day is AFTER
        // lastday are still dry.
        //
        // Start BFS from every dry cell in the first row.
        // This is a multi-source BFS because we can start from
        // multiple valid cells simultaneously.
        for(int j = 0 ; j < n ; j++){
            if(WaterSpread[0][j] > lastday){
                q.push({0,j});
                visited[0][j] = true;
            }
        }

        int rDir[4]  = {-1,1,0,0};
        int cDir[4]  = {0,0,-1,1};

        // We are checking whether a path exists on this fixed day.
        // There is NO day-by-day movement here.
        // 'crntday' remains equal to the day we decided to cross.
        int crntday = lastday;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto[x,y] = q.front();
                q.pop();

                // This cell has already become water by this day,
                // so we cannot stand on it or move through it.
                if(crntday >= WaterSpread[x][y]){
                    continue;
                }

                // Reaching the last row means we successfully crossed.
                if(x == m-1){
                    return true;
                }

                // Explore all four neighbouring cells.
                for(int i = 0 ; i < 4 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];

                    if(nRow >= 0 && nRow < m &&
                       nCol >= 0 && nCol < n &&
                       !visited[nRow][nCol]){

                        // We don't check the water condition here.
                        // It is checked when this cell is popped from
                        // the queue, using WaterSpread[nRow][nCol].
                        q.push({nRow,nCol});
                        visited[nRow][nCol] = true;
                    }
                }
            }
        }

        // No dry path from the first row to the last row.
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        WaterSpread.resize(row,vector<int>(col,0));
        m = row , n = col;

        // Convert the order in 'cells' into:
        // cell -> day on which it gets flooded.
        fillUpdays(cells);

        // We want the LATEST day for which crossing is possible.
        //
        // If crossing is possible on day X, it is also possible
        // on every earlier day.
        //
        // Therefore the answer is monotonic:
        //
        //     possible possible possible impossible impossible
        //                         ^
        //                       answer
        //
        // This allows binary search on the answer.
        int l = 1  , r = row*col;
        int lastday = 0;

        while(l<=r){

            int mid = l + (r-l)/2;

            // Can we still cross if we wait until day 'mid'?
            if(isAbleToCross(mid)){

                // mid works, so try waiting even longer.
                lastday = mid;
                l = mid+1;

            }else{

                // mid doesn't work, so every later day also fails.
                r = mid-1;
            }
        }

        return lastday;
    }
};

int main(){
    Solution sol1;
    int r = 3 , col = 3;
    vector<vector<int>>cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout<<sol1.latestDayToCross(r,col,cells);
    return 0;
}