/*print all the elements in spiral order
if mat=[1,2,3];[4,5,6];[7,8,9]
answer would be {1,2,3,6,9,8,7,4,5}
*/
#include<iostream>
#include<vector>
std::vector<int> PrintSpiralOrder(std::vector<std::vector<int>>matrix){
    int top=0;
    int bottom=matrix.size()-1;
    int left=0;
    int right=matrix[0].size()-1;
    std::vector<int>Answer;
    while(top<=bottom&&left<=right){
        //1st row from left to right
        for(int i=left;i<=right;i++){
            Answer.push_back(matrix[top][i]);
        }
        top=top+1;//increment row
        
        //rightmost column from top to bottom
        for(int i=top;i<=bottom;i++){
            Answer.push_back(matrix[i][right]);
        }
        right=right-1;//decrement column

        //bottom row from right to left
        if(top<=bottom){//check if that bottom row exist or not to print
            for(int i=right;i>=left;i--){
                Answer.push_back(matrix[bottom][i]);
            }
            bottom=bottom-1;//decrement last row to 2nd last row
        }

        //leftmost column from bottom to top
        if(left<=right){//check if the leftmost column exist or not to print
            for(int i=bottom;i>=top;i--){
                Answer.push_back(matrix[i][left]);
            }
            left=left+1;//increment leftmost column
        }
    }
    return Answer;
}

int main(){
    int row,col;
    // std::cout<<"Enter no of rows and cols:"<<std::endl;
    // std::cin>>row>>col;
    // std::vector<std::vector<int>>matrix(row,std::vector<int>(col));
    std::vector<std::vector<int>>matrix{{1,2,3,4},{5,6,11,12},{21,7,8,9}};
    // std::cout << "\n";
    // std::cout << "Enter elements of array:" << std::endl;

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         std::cin >> matrix[i][j];
    //     }
    // }
    // std::cout<<matrix.size()<<"\t"<<matrix[0].size();

    std::vector<int> Answer=PrintSpiralOrder(matrix);
    std::cout<<"Spiral order of matrix is :"<<std::endl;
    for(int i=0;i<Answer.size();i++){
        std::cout<<Answer[i]<<"\t";
    }
    return 0;
}