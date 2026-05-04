// You are given an array nums consisting of positive integers.
// We call a subarray of an array complete if the following condition is satisfied:
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.

//this is similar to our problem subarray with k different integers , using trick of atmost(k) - atmost(k-1) to find exactly k distinct integers

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

int CountAtMostKDistinct(std::vector<int>&nums,int k){
    int l = -1;
    int count = 0;
    std::unordered_map<int,int>M;
    for(int i = 0 ; i < nums.size() ; i++){
        M[nums[i]]++;
        while(M.size() > k){
            l++;
            M[nums[l]]--;
            if(M[nums[l]] == 0){
                M.erase(nums[l]);
            }
        }
        count+=(i-l);
    }
    return count;
}

int countCompleteSubarrays(std::vector<int>& nums) {
    int distinct = std::set<int>(nums.begin(),nums.end()).size();
    return CountAtMostKDistinct(nums,distinct) - CountAtMostKDistinct(nums,distinct-1);
}

int main(){
    // std::vector<int> nums = {1,3,1,2,2};
    std::vector<int> nums = {5,5,5,5};
    int count_of_complete_subarray = countCompleteSubarrays(nums);
    std::cout<<"count of complete subarray : "<<count_of_complete_subarray<<std::endl; 
}
