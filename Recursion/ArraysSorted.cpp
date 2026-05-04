//given array nums, check if it is sorted in non decresing order using recursion

#include<iostream>
#include<vector>

bool isSorted(std::vector<int>&nums ,int n){
    if(n==0 || n==1){
        return true;
    }
    return nums[n-1]>=nums[n-2] && isSorted(nums,n-1);///to check from last
}

int main(){
    std::vector<int> nums = {5};
    int n = nums.size();
    if(isSorted(nums,n)){
        std::cout<<"sorted";
    }
    else{
        std::cout<<"unsorted";
    }
    return 0;
}