// in this problem , Its a updated version of Search 2D Matrix , isme hume diya hai ki , har row me elements ascendong order me hai and har column me ascending order me hai. 
//Hume isme element search karna hai agar element mila to return true nhi to return false. .
// To isme hum approach lagayenge ki ek range lekar uspar binary search lagayenge.
//Range ki starting value:-(0,0) hum imagine karenge and last value as (row-1,col-1), To isme mid hum imagine karke chalenge (0,col-1) and har baar hum mid pe check karenge ki if target exist on mid
//or not. Agar target mid se bada hai to row + 1 nahi to col -1

#include<iostream>
#include<vector>

bool SearchSorted2Darray(std::vector<std::vector<int>>& matrix ,int target){
int rows=matrix.size()-1;
int cols=matrix[0].size()-1;
int currRow = 0 , currCol = cols;
while(currRow<=rows && currCol>=0){
    if(matrix[currRow][currCol] == target){
        return true;
    }
    else if (target > matrix[currRow][currCol])
    {
        currRow++;
    }
    else{
        currCol--;
    }
}
return false;
}

int main(){
   std::vector<std::vector<int>> matrix={{1,3,5,7},{8,11,16,18},{23,30,34,40}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    int target ;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] <<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout << "Enter target element:" << std::endl;
    std::cin >> target;
    std::cout<<"\n";
    if(SearchSorted2Darray(matrix , target)){
        std::cout<<target<<" found";
    }
    else{
        std::cout<<target<<" not found";
        }
        return 0;
}