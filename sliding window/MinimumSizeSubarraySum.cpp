//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
//using dynamic sliding window approach

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

int minSubArrayLen(std::vector<int>& nums , int target){
    int n = nums.size();
    int sum = 0;
    int minLength = INT_MAX;
    int l =-1;
    for(int i =0;i<n;i++){
        sum+=nums[i];
        while(sum >= target){
            minLength=std::min(minLength , i-l);
            l++;
            sum-=nums[l];
        }
    }
    return minLength==INT_MAX?0:minLength;
}
int main(){
    // std::vector<int> nums = {2,3,1,2,4,3};
    std::vector<int> nums = {1,1,1,1,1,1,1,1};
    int target = 10;
    int minLength = minSubArrayLen(nums , target);
    std::cout<<"minimum length : "<<minLength<<std::endl;
    return 0;
}