// Given n size , we need to find all possible combinations for n*n board to place all n queens
// All n queens should be placed
// each queen placed should be in safe place means no 2 queens should attack each other either in same row , column , diaginals(both)
// find arrangements according to above condtion
// classic recursion + backtracking problem

#include <iostream>
#include <vector>
#include <string>

bool isSafe(std::vector<std::string> Board, int row, int col, int n)
{
    // checking safety in current row at each column place
    for (int j = 0; j < n; j++)
    {
        if (Board[row][j] == 'Q')
        {
            return false;
        }
    }

    // checking safety in current colmun ateach row place
    for (int i = 0; i < n; i++)
    {
        if (Board[i][col] == 'Q')
        {
            return false;
        }
    }

    // checking left diagonal safety
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (Board[i][j] == 'Q')
        {
            return false;
        }
    }

    // checking right diagonal safety
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (Board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void SolveQueens(std::vector<std::string> &Board, int row, int n, std::vector<std::vector<std::string>> &Ans)
{
    // Base Case when all queens are placed
    if (row == n)
    {
        Ans.push_back(Board);
        return;
    }
    // for each row checking valid column
    for (int j = 0; j < n; j++)
    {
        if (isSafe(Board, row, j, n))
        {
            Board[row][j] = 'Q';
            // after placing the queen , check for other queens if they can be place with this queen arrangement
            SolveQueens(Board, row + 1, n, Ans);

            // reverting the step we did in previous stack frame , after no possible solution is hit with current queen placement(Backtracking in a way)
            Board[row][j] = '.';
        }
    }
}

std::vector<std::vector<std::string>> Nqueens(int n)
{
    // ChessBoard for queens
    // 1D string matrix acting as 2D , where each row have n size space with '.' value
    std::vector<std::string> Board(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> Ans;
    SolveQueens(Board, 0, n, Ans);
    return Ans;
}

int main()
{
    int n = 10;
    std::vector<std::vector<std::string>> Ans = Nqueens(n);
    std::cout << "\nTotal Solutions: " << Ans.size() << std::endl
              << std::endl;

    for (int k = 0; k < Ans.size(); k++)
    {
        std::cout << "Solution " << k + 1 << ":\n";

        for (int i = 0; i < n; i++)
        {
            for (char c : Ans[k][i])
            {
                std::cout << c << " ";
            }
            std::cout << std::endl;
        }

    }
    return 0;
}