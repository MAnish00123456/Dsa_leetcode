// You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:

// 0 represents grass,
// 1 represents fire,
// 2 represents a wall that you and fire cannot pass through.
// You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.

// Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.

// Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.

// A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

// Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
// Output: 3
// Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
// You will still be able to safely reach the safehouse.
// Staying for more than 3 minutes will not allow you to safely reach the safehouse.

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    int m, n;
    std::vector<std::vector<int>> FireReach;
    
    // A multi source bfs to preCompute the amt of minutes will it take for fire
    // to reach each cell
    void FireBFS(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    FireReach[i][j] = 0;
                }
            }
        }
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        int min = 0;
        while (!q.empty()) {
            int sz = q.size();
            min++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nRow = x + dRow[i];
                    int nCol = y + dCol[i];

                    if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                        FireReach[nRow][nCol] == -1 && grid[nRow][nCol] != 2) {
                        FireReach[nRow][nCol] = min;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        // for(int i = 0 ;i < m ; i++){
        //     for(int j = 0 ; j < n ;j++){
        //         cout<<FireReach[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }

    // single source bfs for the person to travel
    bool isAbleToreach(int initialWait,std::vector<std::vector<int>>& grid) {
        //early check for higher waiting time 
        if (FireReach[0][0] != -1 && initialWait >= FireReach[0][0])
            return false;
            std::vector<std::vector<int>> visited(m,std::vector<int>(n,0));
            std::queue<std::pair<int, int>> q;
        //directions , up down left right
        int rDir[4] = {-1, 1, 0, 0};
        int cDir[4] = {0, 0, -1, 1};

        int crntTime = initialWait;//store total time of travelling

        q.push({0, 0});

        while (!q.empty()) {
            crntTime++;
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
                    //boundary check and if no wall and no visited
                    if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] != 2 && visited[nRow][nCol] != -2) {
                        //if next step reaches safehouse and a special check acc to question , its valid if we reach in safehouse with fire at same time
                        //return true ,if we reach before fire or we both reach together or fire never comes to safehouse
                        if (nRow == m - 1 && nCol == n - 1 &&
                            (FireReach[nRow][nCol] >= crntTime ||
                             FireReach[nRow][nCol] == -1)) {
                            return true;
                        }
                        //if current block makes us die before we even reach further , we will skip this block and try a new block
                        if (FireReach[nRow][nCol] != -1 &&
                            crntTime >= FireReach[nRow][nCol]) {
                            continue;
                        }
                                q.push({nRow, nCol});
                                visited[nRow][nCol] = -2;
                        
                    }
                }
            }
        }
        return false;
    }

public:
    int maximumMinutes(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        FireReach.resize(m, std::vector<int>(n, -1));
        FireBFS(grid);
        // Binary search to get maximum minutes to wait before moving
        // we can move instant without waiting or we can wait for total grid
        // size and still be able to reach safehouse
        int l = 0, r = m * n, maxMinutes = -1;

        while (l <= r) {
            int maxAllowedMinutes = l + (r - l) / 2;
            if (isAbleToreach(maxAllowedMinutes, grid)) {
                maxMinutes = maxAllowedMinutes;
                l = maxAllowedMinutes + 1;
            } else {
                r = maxAllowedMinutes - 1;
            }
        }
        if (maxMinutes >= m * n)
            return 1e9;
        return maxMinutes;
    }
};

int main(){
    std::vector<std::vector<int>> grid = {
        {0, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 2, 1, 0},
        {0, 2, 0, 0, 1, 2, 0},
        {0, 0, 2, 2, 2, 0, 2},
        {0, 0, 0, 0, 0, 0, 0}
    };
    Solution sol1;
    std::cout<<"Max number of minutes we can wait before moving : "<<sol1.maximumMinutes(grid);
    return 0;
}