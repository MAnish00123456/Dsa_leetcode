//given a m*n grid in which a hourglass is defined as 
// A   B  C
//     D
//  E  F  G
//return the maximum sum of hourglass we can acheive

#include<iostream>
#include<vector>
#include<algorithm>


std::vector<std::vector<int>> PS(std::vector<std::vector<int>>& Grid){
    std::vector<std::vector<int>>PS2D(Grid.size()+1,std::vector<int>(Grid[0].size()+1,0));
    for(int i = 1 ;i <= Grid.size();i++){
        for(int j = 1 ; j <= Grid[0].size() ;j++){
            PS2D[i][j] = PS2D[i-1][j] + PS2D[i][j-1] - PS2D[i-1][j-1] + Grid[i-1][j-1];
        }
    }
    return PS2D;
}

//1st approach using PS over 2d grid , efficient , mostly used when our submatrix size is variable
int _1maxSum(std::vector<std::vector<int>>&Grid){
int m = Grid.size();
int n = Grid[0].size();
std::vector<std::vector<int>>Ps = PS(Grid);
int maxSum = 0;

for(int i = 0 ; i <= Grid.size()-3 ; i++){
    for(int j = 0 ; j <= Grid[0].size()-3 ; j++){
        int sum  = 0;
        int r1 = i , c1 = j , r2 = i+2 , c2 = j + 2;

        r1++ , c1++ , r2++ , c2++;
        sum+= Ps[r2][c2] - Ps[r1-1][c2] - Ps[r2][c1-1] + Ps[r1-1][c1-1] - Grid[i+1][j] - Grid[i+1][j+2];
        maxSum = std::max(sum,maxSum); 
    }
}
return maxSum;
}




//2nd approach , as there is fixed size of submatrix ,  we can hard find the sum 
int _2maxSum(std::vector<std::vector<int>>&Grid){
    int m = Grid.size();
    int n = Grid[0].size();
    int maxSum = 0;
    
    for(int i = 0 ; i <= m-3 ; i++){
        for(int j = 0 ; j <= n-3 ; j++){
            int sum  = 0;
            sum+= Grid[i][j] + Grid[i][j+1] + Grid[i][j+2] + Grid[i+1][j+1] + Grid[i+2][j] + Grid[i+2][j+1] + Grid[i+2][j+2];
            maxSum = std::max(sum,maxSum); 
        }
    }
    return maxSum;
    }
int main(){
    std::vector<std::vector<int>>Grid = {{6,2,1,3} , {4,2,1,5} ,{9,2,8,7} ,{4,1,2,9}};
    int max_sum_of_hourglass = _2maxSum(Grid);
    std::cout<<"maximum sum of hourglass fig in given grid is : "<<max_sum_of_hourglass;
    return 0;
}