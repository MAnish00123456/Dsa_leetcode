//In this question we have given a grid of m*n size , and a robot is standing at (0,0) posiion and he have a goal cell at (m-1,n-1) , 
//He can only move in 2 directions either down or right., we need to find count of all the paths he can take to reach goal cell
//return it
//TC =O(mn) , memoization with dp
#include<iostream>
#include<vector>

int findAllPath(int row , int col , std::vector<std::vector<int>> & dp ,int m , int n){
    //boundary condtions
    if(row >= m || col >= n){
        return 0;
    }
    //Base Case , goal cell
    if(row == m-1 && col == n-1){
        return 1;
    }
    if(dp[row][col] != -1){
    return dp[row][col];
    } 

   return dp[row][col] = findAllPath(row+1,col,dp,m,n)+
   //downward movement
    findAllPath(row,col+1,dp,m,n);//right movement
}

int uniquePaths(int m, int n){
std::vector<std::vector<int>>dp(m,std::vector<int>(n,-1));
return  findAllPath(0,0,dp,m,n);

}

int  main(){
    int m = 3;//no of rows
    int n =7;//no of cols
    int count =0;
    count = uniquePaths(m,n);
    std::cout<<"Total paths : "<<count;
    return 0;

}