//In this question we have given an integer array nums ,and a target sum .
//we have to return all possible combinations we can make from elements of the array that add upto target.
//we can include a number multiple times to make it equal to sum
//Given , target is always positive and array always have positive nums. 
//return all possible unique combination
//Now acc to question , we can include a number single time , multiple time or not include it at all
//we will use recursion and backtracking for it
#include<iostream>
#include<vector>
#include<set>

std::set<std::vector<int>>S;//to store only unqiue combinations
//helper function
void GetAllCombinations(std::vector<int>&nums,int idx,std::vector<int>&combination,std::vector<std::vector<int>>&Ans,int target){
//Base cases
//1st -> when we couldnt able to find target after traversing whole array or when our target becomes negative   
int n = nums.size();
if(idx == n || target < 0){
    return;
}
//2nd -> when we got combination , target = 0
if( target == 0){
if(S.find(combination) == S.end()){
    //if the combination is not present in set
    S.insert(combination);
    Ans.push_back(combination);
}
return;
}


//recursive calls
combination.push_back(nums[idx]);//include number
GetAllCombinations(nums,idx+1,combination,Ans,target-nums[idx]);//only include current nuumber once
GetAllCombinations(nums,idx,combination,Ans,target-nums[idx]);// include current nuumber more than once
combination.pop_back();//Backtrack to previous position where we havent include our number, important for exclusion case
GetAllCombinations(nums,idx+1,combination,Ans,target);//we do not include current num
}


//calling function
std::vector<std::vector<int>>combinationSum(std::vector<int>&nums , int target){
std::vector<std::vector<int>>Ans;
std::vector<int>combination;
GetAllCombinations(nums,0,combination,Ans,target);
return Ans;
}

int main(){
    std::vector<int> Nums = {10,1,2,7,6,1,5};
    int target = 8;
    std::vector<std::vector<int>>Ans = combinationSum(Nums,target);
    std::cout<<"Unique combinations : "<<std::endl;
    for(auto combination : Ans){
        std::cout<<"[ ";
        for(auto elem : combination){
            std::cout<<elem<<" ";
        }
        std::cout<<" ]";
        std::cout<<"\n";
    }
    return 0;
}