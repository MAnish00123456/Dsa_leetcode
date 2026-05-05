// There are n teams numbered from 0 to n - 1 in a tournament.

// Given a 0-indexed 2D boolean matrix grid of size n * n. For all i, j that 0 <= i, j <= n - 1 and i != j team i is stronger than team j if grid[i][j] == 1, otherwise, team j is stronger than team i.

// Team a will be the champion of the tournament if there is no team b that is stronger than team a.

// Return the team that will be the champion of the tournament.

#include<iostream>
#include<vector>


class Solution {
    public:
        int findChampion(std::vector<std::vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            bool champion;
            for(int i = 0 ; i < row ; i++){
                champion = true;
                for(int j = 0 ; j < col ; j++){
                    if(i!=j && grid[i][j] == 0){
                        champion = false;
                    }
                }
                if(champion){
                    return i;
                }
            }
            return -1;
        }
    };


int main(){
    std::vector<std::vector<int>>grid = {{0,1},{0,0}};
    Solution sol1;
    std::cout<<"winning team index : "<<sol1.findChampion(grid);
    return 0;
}