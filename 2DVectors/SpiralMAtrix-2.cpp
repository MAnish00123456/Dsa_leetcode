/*Given a integer n . 
Make a n*n matrix filled with elements from 1 to n^2 in spiral order*/
#include<iostream>
#include<vector>
#include<math.h>
std::vector<std::vector<int>> generateMatrix(int n){
    if(n<=0){
         return {};
        }
int st=1;
std::vector<std::vector<int>>matrix(n,std::vector<int>(n));
int top=0;
int bottom=matrix.size()-1;
int left=0;
int right=matrix[0].size()-1;

    while(top<=bottom&&left<=right){
        //top row
        for(int i=left;i<=right;i++){
            matrix[top][i]=st;
            st=st+1;
        }
        top=top+1;
        //right column
        for(int i=top;i<=bottom;i++){
            matrix[i][right]=st;
            st=st+1;
        }
        right=right-1;
        //bottom row
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                matrix[bottom][i]=st;
                st=st+1;
            }
            bottom=bottom-1;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                matrix[i][left]=st;
                st=st+1;
            }
            left=left+1;
        }
    }
    return matrix;


}

int main(){
    int integer;
    std::cout<<"Enter a positive integer:"<<std::endl;
    std::cin>>integer;
    std::vector<std::vector<int>>SpiOrder=generateMatrix(integer);
    std::cout<<"integer*integer matrix in spiral order:"<<std::endl;
    for(int i=0;i<SpiOrder.size();i++){
        for(int j=0;j<SpiOrder[i].size();j++){
            std::cout<<SpiOrder[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    return 0;
}