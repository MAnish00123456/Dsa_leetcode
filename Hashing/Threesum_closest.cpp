//Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int _3sumclosest(std::vector<int>&nums , int & target){
    std::sort(nums.begin(),nums.end());
    if(nums.size() < 3) return 0;
    int closestSum = INT_MAX;
    for(int i = 0 ; i < nums.size() ; i++){
        int j = i + 1 , k = nums.size()-1;
        while(j < k){
            int currsum = nums[i] + nums[j] + nums[k];
            if(abs(currsum - target) < abs(closestSum-target)){
                closestSum=currsum;
            }
            if(currsum > target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return closestSum;
}

int main(){
    std::vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int closestsum = _3sumclosest(nums,target);
    std::cout<<"closest sum near to our target is : "<<closestsum;
    return 0;
}