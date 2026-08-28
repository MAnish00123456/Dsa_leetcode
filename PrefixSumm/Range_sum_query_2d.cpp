// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity

// Input
// ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
// [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
// Output
// [null, 8, 11, 12]

// Explanation
// NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
// numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
// numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
// numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

// class NumMatrix {
//     vector<vector<int>>PSmatrix;
//     int row , col;
//     void fillup(vector<vector<int>>& matrix , int row , int col){
//         for(int i = 1 ; i < PSmatrix.size() ; i++){
//             for(int j = 1 ; j < PSmatrix[0].size() ; j++){
//                 PSmatrix[i][j] = PSmatrix[i-1][j] + PSmatrix[i][j-1] - PSmatrix[i-1][j-1] + matrix[i-1][j-1];
//             }
//         }
//     }
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         this->row = matrix.size();
//         this->col = matrix[0].size();
//         PSmatrix.resize(row+1,vector<int>(col+1,0));
//         fillup(matrix,row,col); 
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         row1++ , col1++ , row2++ , col2++;
//         int sum = 0;
//         sum  = PSmatrix[row2][col2] - PSmatrix[row1-1][col2] - PSmatrix[row2][col1-1] + PSmatrix[row1-1][col1-1];
//         return sum;
//     }
// };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */