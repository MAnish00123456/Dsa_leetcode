// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Input: grid = [
//     ["1","1","0","0","0"],
//     ["1","1","0","0","0"],
//     ["0","0","1","0","0"],
//     ["0","0","0","1","1"]
//   ]
//   Output: 3

#include <iostream>
#include <vector>

class Solution
{
    void dfs(int i, int j, std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] != '1')
            return;
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited, m, n); // top
        dfs(i + 1, j, grid, visited, m, n); // bottom
        dfs(i, j + 1, grid, visited, m, n); // right
        dfs(i, j - 1, grid, visited, m, n); // left
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        // imagine the grid as a undirected graph , where adjacent ones defines one component of graph , and components are not connected to each other
        // start with 0,0 and explore adjacent nodes which are land , mark all them visited . this will make one component
        // similarly do for each node which will form a component

        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j, grid, visited, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main(){
    std::vector<std::vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '1', '0', '0'},
                                           {'0', '0', '0', '1', '1'}};

   Solution sol1;
    std::cout<<"Number of islands : "<<sol1.numIslands(grid);
    return 0;
}