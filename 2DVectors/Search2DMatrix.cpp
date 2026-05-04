//In this problem we have to check if a element is present in givcn 2D matrix of size m*n or not, If not present return false else true
//We have to write a solution in O(log(m*n)) T.C , hume given hai ki each row me elements ascending order me hai and current row ke first element humesha greater than hoga last elemnt of previous row
//To iska optimal approach hoga ki hum ppure matrix me pahle correct row find karenge using binary search jis se TC hume O(logm)
//Phir us correct row me element find karenge jiski TC O(logn) hogi. Jisse total TC O(log(m*n)) 
#include <iostream>
#include <vector>

// brute froce method , pure matric pe do For loop lagayenge jisse TC ho jayegi O(m*n)
// bool FoundElement(std::vector<std::vector<int>> matrix, int target)
// {
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[i].size(); j++)
//         {
//             if (matrix[i][j] == target)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//1st approach , binary search on whole 2d matrix , is approach me hum har ek row ko visit karenge and  har row pe binary search lagayenge for finding element
//Iski TC ho jayegi O(mlog(n))
// bool firstapproachFoundElement(std::vector<std::vector<int>>matrix,int target){
//     for(int i=0;i<matrix.size();i++){
//         int st=0;
//         int end=matrix[i].size()-1;
//         while(st<=end){
//             int mid=st+(end-st)/2;
//             if(matrix[i][mid]==target){
//                 return true;
//             }
//             else if(matrix[i][mid]<target){
//                 st=mid+1;
//             }
//             else{
//                 end=mid-1;
//             }
//         }
//     }
//     return false;
// }


//Iski TC ho jayegi O(log(m*n))
    bool OptimalSearchMatrix(std::vector<std::vector<int>>& matrix, int target , int Rows , int Cols) {
        //pahle correct row nikalenge
        int stRow=0;
        int endRow=Rows-1;

        int correctRow=-1;
        //TC - O(log(m)) , m = no of rows
        while(stRow<=endRow){
            int midRow= stRow + (endRow-stRow)/2;
            if(matrix[midRow][0]<=target && target<=matrix[midRow][Cols-1]){
                correctRow=midRow;
                break;
            }
            else if(target > matrix[midRow][Cols-1]){
                stRow=midRow+1;
            }
            else if(target<matrix[midRow][0]){
                endRow=midRow-1;
            }
        }
        if(correctRow==-1) return false;
        
        //if correct row found to us row me elem search karo
        //TC - O(log(n)) , n = no of cols
        int stCol=matrix[correctRow][0];
        int endCol=matrix[correctRow][Cols-1];
        while(stCol<=endCol){
            int midCol = stCol + (endCol-stCol)/2;
            if(midCol == target){
                return true;
            }
            else if( target > midCol){
                stCol = midCol+1;
            }
            else{
                endCol=midCol-1;
            }
        }
        return false;
    }
int main()
{
     std::vector<std::vector<int>> matrix={{1,3,5,7},{10,11,16,18,20},{23,30}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    int target ;
    // std::cout << "Enter no of rows and columns:" << std::endl;
    // std::cin >> rows >> cols;
    // std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    // std::cout << "\n";
    // std::cout << "Enter elements of array:" << std::endl;

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
    if (OptimalSearchMatrix(matrix, target , rows , cols))
    {
        std::cout << target << " found";
    }
    else
    {
        std::cout << target << " not found";
    }
    return 0;
}
