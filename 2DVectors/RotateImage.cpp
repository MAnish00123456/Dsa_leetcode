//In this question we have given a 2Dimage and we need to rotate it by 90deg
//we can do that in combination = transpose + reverse
//we first transpose our matrix and then reverse each row

#include<iostream>
#include<vector>
#include<algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    //Transpose
    for(int row = 0 ; row<n ; row++){
        //second loop only runs till row to avoid duplicate swapping, 
        for(int col =0 ; col<row;col++){
            std::swap(matrix[row][col] , matrix[col][row]);
        }
    }

    for(int row = 0 ; row<n ; row++){
        std::reverse(matrix[row].begin(),matrix[row].end());
    }
}

int main(){
    std::vector<std::vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
}