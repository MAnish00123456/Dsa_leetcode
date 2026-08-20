// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

// Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

// Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
// Output: 2

#include<iostream>
#include<vector>

class Solution {
    std::vector<std::vector<bool>>visited;
    int m , n;
    void findBattleships(int i , int j , std::vector<std::vector<char>>&board){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != 'X')return;
        visited[i][j] = true;
        findBattleships(i-1,j,board);//top
        findBattleships(i+1,j,board);//bottom
        findBattleships(i,j+1,board);//right
        findBattleships(i,j-1,board);//left
    }
public:
int countBattleships(std::vector<std::vector<char>>& board) {
    int cnt =0; 
     m = board.size();
     n = board[0].size();
    visited.resize(m,std::vector<bool>(n,false));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(board[i][j] != '.' && !visited[i][j]){
                findBattleships(i,j,board);
                cnt++;
            }
        }
    }
    return cnt;
}
};

int main(){
    std::vector<std::vector<char>>grid = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution sol1;
    std::cout<<"Count of battleships : "<<sol1.countBattleships(grid);
    return 0;
}