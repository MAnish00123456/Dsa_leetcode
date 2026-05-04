//Given hai ki ek 2D integer matrix 'Grid' jiska size n*n hai and usme values ki range [1 to n*n] hai.
//Hume matrix me given hai har value exactly once aayegi but only ek value repeated hai ,lets say 'a' , and ek value hai jo missing hai , lets say 'b',
//HUm ek array banayenge 'ans' and usme a and b ko store karke return kar denge.
//We will use 'unordered_set' for repeating value and we know ki if integer range is [1 to n*n] to uska Expectedsum hoga = n*n*(n*n + 1)/2
// And if agar given matrix ka overall sum nikalenge , lets say Actualsum ,  so we can say that Actualsum = Expectedsum + a - b 
//b = Expectedsum + q - Actualsum
#include<iostream>
#include<vector>
#include<unordered_set>

std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid){
int n = grid.size();
int a , b;
int Expectedsum = 0, Actualsum = 0;
std::vector<int>Ans;
std::unordered_set<int>S;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        Actualsum+=grid[i][j];
        if(S.find(grid[i][j]) != S.end()){
            a=grid[i][j];
            Ans.push_back(a);
        }
        S.insert(grid[i][j]);
    }
}
Expectedsum = (n*n)*(n*n + 1)/2;
b = Expectedsum + a - Actualsum;
Ans.push_back(b);
return Ans;
}

int main(){
    std::vector<std::vector<int>> Grid = {{9,1,7},{8,9,2},{3,4,6}};
    std::vector<int>Ans=findMissingAndRepeatedValues(Grid);
    std::cout<<"The Repeating value in Grid array : "<<Ans[0]<<std::endl;
    std::cout<<"The Missing value in Grid array : "<<Ans[1]<<std::endl;
    return 0;
}