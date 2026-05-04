//given an array ={!,2,3} for ex.
//print all the subsets for the given array 
//we use recursion and backtracking to solve it
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
// #define std::vector<std::vector<int>>Final;

void PS(std::vector<int>&nums , std::vector<int>&ans ,int i ,std::vector<std::vector<int>>&Final){
//Base Case
if(i == nums.size()){
        Final.push_back(ans);
    return;
}

//inclusion case
ans.push_back(nums[i]);
PS(nums,ans,i+1,Final);//check for next value

//backtrack
ans.pop_back();
//removing duplicate elements to get unique subset
int idx = i+1;//next element index for which we will call function to exclude it
while(idx < nums.size() && nums[idx] == nums[idx-1]){
    idx++;//skipping index value until we found a non duplicate number
}
//exclusion case for that non duplicate number
PS(nums,ans,idx,Final);
}

std::vector<std::vector<int>> PrintSubset(std::vector<int>&nums){
    std::sort(nums.begin(),nums.end());
std::vector<int>Ans;
int i =0;
std::vector<std::vector<int>>Final;
PS(nums,Ans,i,Final);
return Final; 
}

int main(){
std::vector<int> nums={1,2,2};
std::vector<std::vector<int>>Final = PrintSubset(nums);
for(auto subset:Final){
    for(auto val:subset){
        std::cout<<val;
    }
    std::cout<<"\n";
}
return 0;
}