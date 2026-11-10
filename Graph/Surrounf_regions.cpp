// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m = board.size();
            int n = board[0].size();
            vector<vector<bool>>visited(m,vector<bool>(n,false));
    
            queue<pair<int,int>>q;
            for(int i = 0 ; i < m ; i++){
                if(!visited[i][0] && board[i][0] == 'O'){
                    q.push({i,0});
                    visited[i][0] = true;
                }
            }
            for(int i = 0 ; i < n ; i++){
                if(!visited[0][i] && board[0][i] == 'O'){
                    q.push({0,i});
                    visited[0][i] = true;
                }
            }
            for(int i = 0 ; i < n ; i++){
                if(!visited[m-1][i] && board[m-1][i] == 'O'){
                    q.push({m-1,i});
                    visited[m-1][i] = true;
                }
            }
            for(int i = 0 ; i < m ; i++){
                if(!visited[i][n-1] && board[i][n-1] == 'O'){
                    q.push({i,n-1});
                    visited[i][n-1] = true;
                }
            }
    
            int rDir[4] = {-1,1,0,0};
            int cDir[4] = {0,0,-1,1};
    
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
    
                for(int i = 0 ; i < 4 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
    
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !visited[nRow][nCol] && board[nRow][nCol] == 'O'){
                        visited[nRow][nCol] = true;
                        q.push({nRow,nCol});
                    }
                }
            }
    
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j] && !visited[i][j]){
                        board[i][j] = 'X';
                    }
                }
            }
    
        }
    };

    int main(){
        vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

        Solution sol1;
        sol1.solve(board);

        for(auto it : board){
            for(auto c : it){
                cout<<c<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }