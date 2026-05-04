#include<iostream>
#include<vector>

int main(){
    std::vector<std::vector<int>> matrix={{1,2,3},{4,5,6,10,11},{7,8,9,12,13,14}};//Syntax
    //for no of rows
    int row=matrix.size();
    //no of col   matrix[i].size()
    int col=matrix[0].size();
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}