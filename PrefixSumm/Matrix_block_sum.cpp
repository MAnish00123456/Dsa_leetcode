

#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> PSmat(std::vector<std::vector<int>>&Mat){
    std::vector<std::vector<int>>PrefixSumMat(Mat.size()+1 , std::vector<int>(Mat[0].size()+1,0));
    int r= PrefixSumMat.size();
    int c = PrefixSumMat[0].size();
    for(int i = 1 ; i < r ; i++){
        for(int j = 1 ; j<c ; j++){
            PrefixSumMat[i][j] = PrefixSumMat[i-1][j] + PrefixSumMat[i][j-1] - PrefixSumMat[i-1][j-1] + Mat[i-1][j-1];
        }
    }
return PrefixSumMat;
}

void matrixBlockSum(std::vector<std::vector<int>>&Mat , int k){
int m = Mat.size();
int n = Mat[0].size();
std::vector<std::vector<int>>Prefixarray = PSmat(Mat);

std::vector<std::vector<int>>Ans(m,std::vector<int>(n));

for(int i = 0 ; i<m;i++){
    for(int j = 0 ; j < n ; j++){
        int r1 = std::max(0,i-k);
        int c1 = std::max(0,j-k);
        int r2 = std::min(n-1,i+k);
        int c2 = std::min(n-1,j+k);
        r1++ , c1++ , r2++ , c2++;
        Ans[i][j] = Prefixarray[r2][c2] - Prefixarray[r1-1][c2] - Prefixarray[r2][c1-1] + Prefixarray[r1-1][c1-1];
    }
}

for(auto val : Ans){
    for(int elem : val){
        std::cout<<elem<<"   ";
    }
    std::cout<<"\n";
}
}

int main(){
    // std::vector<std::vector<int>>Mat = {{1,1,1,1,1} , {1,2,2,1,2} , {2,1,2,1,1} , {1,3,1,1,1} , {1,2,1,2,1}};
    // std::vector<std::vector<int>>Mat = {{1,2,3} , {4,5,6} , {7,8,9}};
    std::vector<std::vector<int>>Mat = {{6,2,1,3} , {4,2,1,5} , {9,2,8,7} , {4,1,2,9}};
    std::vector<std::vector<int>>Ps=PSmat(Mat);
    for(auto val : Ps){
        for(int elem : val){
            std::cout<<elem<<"  ";
        }
        std::cout<<"\n";
    }
    // matrixBlockSum(Mat,1);

}