#include <iostream>

auto MaxRowSum(int matrix[][4], int row, int col)
{
    int maxSum = 0;
    int rowCount = 0;
    std::pair<int, int> pair;
    int diagonalSum = 0;
    for (int i = 0; i < row; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < col; j++)
        {
            rowSum += matrix[i][j];
            rowCount = i;
        }
        if (rowSum > maxSum)
        {
            rowCount++;
        }
        maxSum = std::max(maxSum, rowSum);
    }
    pair = {maxSum, rowCount};
    return pair;
}

int PrimaryDiagonalSum(int matrix[][4], int row, int col)
{
    int PdiagonalSum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                PdiagonalSum += matrix[i][j];
            }
            continue;
        }
    }
    return PdiagonalSum;
}

int SecondaryDiagonalSum(int matrix[][4], int row, int col)
{
    int SdiagonalSum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if (i + j == col - 1)
            {
                SdiagonalSum += matrix[i][j];
            }
            continue;
        }
    }
    return SdiagonalSum;
}
int PDdiagonalSum(int matrix[][4],int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        sum+=matrix[i][i];
        if(i!=row-1-i){
            sum+=matrix[i][row-1-i];
        }
    }
    return sum;
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int rows = 4;
    int cols = 4;
    std::pair<int, int> pair = MaxRowSum(matrix, rows, cols);
    int PdiagonalSum = PrimaryDiagonalSum(matrix, rows, cols);
    int SdiagonalSum = SecondaryDiagonalSum(matrix, rows, cols);
    int totalDiagonalSum=PdiagonalSum+SdiagonalSum;
    std::cout << "The maximum sum from all the rows element sum would be: " << pair.first << " and the row was : " << pair.second<<std::endl;
    std::cout<<"The primary diagonal sum is : "<<PdiagonalSum<<std::endl;
    std::cout<<"The secondary diagonal sum is : "<<SdiagonalSum<<std::endl;
    // std::cout<<"The total diagonal sum is : "<<totalDiagonalSum<<std::endl;
    std::cout<<"The total diagonal sum is : "<<PDdiagonalSum(matrix,rows,cols)<<std::endl;
    return 0;
}