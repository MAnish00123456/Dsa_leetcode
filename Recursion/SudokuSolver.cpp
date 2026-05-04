#include<vector>
#include<iostream>

//Function to check if current digit placement is valid or not
bool isSafe(std::vector<std::vector<char>>&Board,int row,int col,char dig){
//check validity for horizontal placement , means no same value in current row
for(int j = 0;j<9;j++){
    if(Board[row][j] == dig){
        return false;
    }
}

//check validity for vertical placement , means no same value in current col
for(int i =0;i<9;i++){
    if(Board[i][col] == dig){
        return false;
    }
}

//Grid placement validity , means no same//repeating value in current 3*3 grid
//for any row , col we will find the starting value for row , col for that particular grid 
int stRow = (row/3) * 3;
int stCol = (col/3) *3;
for(int i = stRow ; i<=stRow+2;i++){
    for(int j = stCol ;j<=stCol+2 ; j++){
        if(Board[i][j] == dig){
            return false;
        }
    }
}
return true;
}

//Helper function to solve the sudoku row by  row
bool Solver(std::vector<std::vector<char>>&Board,int row,int col){
    //Base Case , sudoku is solved
    if(row == 9 ){
        return true;
    }

    //calculating nextrow and nextcol for future calls
    int nextRow = row;
    int nextCol = col +1;
    //when 1st row is solved
    if(nextCol == 9){
        nextRow=row+1;
        nextCol=0;
    }

    //if current position already has a digit , then we skip it and call for another row and col
    if(Board[row][col] != '.'){
        return Solver(Board,nextRow,nextCol);
    }

    //else place digits on every empty space
    for(char dig = '1' ; dig<='9' ; dig++){
        //check if current digit doesnt violate rules of sudoku
        if(isSafe(Board,row,col,dig)){
            Board[row][col]= dig;
            //after  placing  a digit check for other places to see if using current placement of digit gets our sudoku solved or not
            if(Solver(Board,nextRow,nextCol)){
                return true;
            }
            //if  after placement of current digit we are not able to solve our sudoku , we will revert the current digit back to empty space and then recalculate everything for next digit
            Board[row][col] = '.';
        }
    }
    return false;
}


void SudokuSolver(std::vector<std::vector<char>>&Board){
Solver(Board,0,0);
return ;
}


int main(){
    int n =9;
    // std::vector<std::vector<char>>Board(n,std::vector<char>(n,'.'));
    std::vector<std::vector<char>> Board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    for (int i = 0; i < 9; i++)
    {
        // Print horizontal partition line
        if (i % 3 == 0 && i != 0)
        {
            std::cout << "------+-------+------\n";
        }

        for (int j = 0; j < 9; j++)
        {
            // Print vertical partition
            if (j % 3 == 0 && j != 0)
            {
                std::cout << "| ";
            }

            std::cout << Board[i][j] << " ";
        }

        std::cout << "\n";
    }
    SudokuSolver(Board);
    std::cout<<"\n";
    std::cout<<"Solved Sudoku"<<std::endl;
    for (int i = 0; i < 9; i++)
    {
        // Print horizontal partition line
        if (i % 3 == 0 && i != 0)
        {
            std::cout << "------+-------+------\n";
        }

        for (int j = 0; j < 9; j++)
        {
            // Print vertical partition
            if (j % 3 == 0 && j != 0)
            {
                std::cout << "| ";
            }

            std::cout << Board[i][j] << " ";
        }

        std::cout << "\n";
    }
return 0;
}