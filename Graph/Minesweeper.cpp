// Let's play the minesweeper game (Wikipedia, online game)!

// You are given an m x n char matrix board representing the game board where:

// 'M' represents an unrevealed mine,
// 'E' represents an unrevealed empty square,
// 'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
// digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
// 'X' represents a revealed mine.
// You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

// Return the board after revealing this position according to the following rules:

// If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
// If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.


// Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
// Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]

#include<iostream>
#include<vector>
#include<queue>

class Solution {
    public:
        std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click) {
            int m = board.size() , n = board[0].size();
            if(board[click[0]][click[1]] == 'M'){
                board[click[0]][click[1]] = 'X';
                return board;
            }
            
            std::vector<std::vector<bool>>visited(m,std::vector<bool>(n,false));
    
            std::queue<std::pair<int,int>>q;
            q.push({click[0],click[1]});
            visited[click[0]][click[1]] = true;
    
            int rDir[8] = {-1,1,0,0,-1,1,-1,1};
            int cDir[8] = {0,0,1,-1,1,1,-1,-1};
    
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                int mineCount = 0;
    
                //neighbors check for mines
                for(int i = 0 ; i < 8 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
    
                    if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n){
                        if(board[nRow][nCol] == 'M'){
                            mineCount++;
                        }
                    }
                }
    
                if(mineCount > 0){
                    board[x][y] = mineCount + '0';
                }else{
                    board[x][y] = 'B';
                    //add neighbors only when mineCount is 0 for current block , add only unrevealed squares
                     for(int i = 0 ; i < 8 ; i++){
                    int nRow = x + rDir[i];
                    int nCol = y + cDir[i];
    
                    if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && !visited[nRow][nCol] && board[nRow][nCol] =='E'){
                        visited[nRow][nCol] = true;
                        q.push({nRow,nCol});
                    }
                }
                }
    
            }
            return board;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<char>>board = {     {'B', '1', 'E', '1', 'B'},
    {'B', '1', 'M', '1', 'B'},
    {'B', '1', '1', '1', 'B'},
    {'B', 'B', 'B', 'B', 'B'}};

    std::vector<int>click = {1,2};
    std::vector<std::vector<char>>Ans = sol1.updateBoard(board,click);
    for (const auto& row : Ans) {
        for (char element : row) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
return 0;   
}