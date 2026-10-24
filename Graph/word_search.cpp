// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

#include<iostream>
#include<vector>
using namespace std;


class Solution {
    private:
    bool dfs(int r , int c , int x, string word,vector<vector<char>>&board){
    if(r<0 || c <0 || r>= m || c >= n || board[r][c] == '.' || board[r][c] != word[x])return false;
    if(x == word.size()-1)return true;
    char old = board[r][c];
    board[r][c] = '.';
    bool res =  dfs(r+1,c,x+1,word,board)||dfs(r-1,c,x+1,word,board)||dfs(r,c+1,x+1,word,board)||dfs(r,c-1,x+1,word,board);
    board[r][c] = old;
    return res;
    }
    
    int m , n;
    public:
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size() , n = board[0].size();
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j] == word[0] && dfs(i,j,0,word,board)){
                        return true;
                    }
                }
            }
            return false;
        }
    };

int main(){
    vector<vector<char>>board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    Solution sol1;
    if(sol1.exist(board,"ABCCED"))cout<<"found";
    else cout<<"not found";
    return 0;
}