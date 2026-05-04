// There is a knight on an n x n chessboard. In a valid configuration,
//  the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
// You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the
//  cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
// Return true if grid represents a valid configuration of the knight's movements or false otherwise.


//lets say if we got a knight at position (r,c) then there are 8 diff moves it can take that are :(r-2,c+1) , (r-2,c-1)
//(r-1,c+2) , (r-1,c-2) , (r+2,c+1) , (r+2,c-1) , (r+1,c+2) , (r+1,c-2)

#include<vector>
#include<iostream>


    bool isValid(std::vector<std::vector<int>>&grid ,int n , int row , int col , int expVal){

        //boundary conditions + if our current value doesnt match our expected value
        if(row < 0 || col < 0 || row >=n || col >= n || grid[row][col] != expVal){
            return false;
        }
        //if our knight traveled whole board and reach to last value
        if(expVal == (n*n -1)){
            return true;
        }

    //Each ans stores that if the knight chose this move , does this lead to complete valid tour or not
    //Ans stores either :
    //               true -> this move eventually reaches to end correctly
    //               false -> this move fails somewhere 
        bool ans1 = isValid(grid,n,row-2,col+1,expVal+1);
        bool ans2 = isValid(grid,n,row-2,col-1,expVal+1);
        bool ans3 = isValid(grid,n,row-1,col+2,expVal+1);
        bool ans4 = isValid(grid,n,row-1,col-2,expVal+1);
        bool ans5 = isValid(grid,n,row+2,col+1,expVal+1);
        bool ans6 = isValid(grid,n,row+2,col-1,expVal+1);
        bool ans7 = isValid(grid,n,row+1,col+2,expVal+1);
        bool ans8 = isValid(grid,n,row+1,col-2,expVal+1);
        
    //if eventually any move leads to valid complete tour , we will return true else false
    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    
    bool checkValidGrid(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        return isValid(grid,n,0,0,0);
    }

    int main(){
        std::vector<std::vector<int>> grid = {{0,3,6} , {5,8,1} , {2,7,4}};
        if(checkValidGrid(grid)){
            std::cout<<"valid grid";
        }
        else{
            std::cout<<"not valid grid";
        }
        return 0;
    }
