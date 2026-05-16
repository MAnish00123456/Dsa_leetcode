// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.


#include<iostream>
#include<vector>

//we will use the same technique used in find all nums disappeared in array ,, as our range of elements is from 1 - n , we can use those values to mark indices in array . Ans as our array have duplicates , so ther will be
//2 numbers that will point to the same index , so when we encounter a already marked number we will know that current element is duplicate

class Solution {
    public:
        std::vector<int> findDuplicates(std::vector<int>& nums) {
            if(nums.size() < 2)return {};
            std::vector<int>Ans;
            int n = nums.size()/2;
            Ans.reserve(n);
    
            for(int i = 0 ; i < nums.size() ; i++){
                int idx = abs(nums[i]) - 1;//idx value corresponding to current element
                if(nums[idx] > 0){
                    nums[idx] = -nums[idx];//mark number as visited
                }else{
                    Ans.push_back(abs(nums[i]));
                }
            }
            return Ans;
        }
    };

    int main(){
Solution sol1;
std::vector<int>nums = {4,3,2,7,8,2,3,1};
std::vector<int>Duplicate = sol1.findDuplicates(nums);
for(int val : Duplicate){
    std::cout<<val<<" ";
}
return 0;
    }