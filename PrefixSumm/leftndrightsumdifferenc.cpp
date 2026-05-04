// //in this question You are given a 0-indexed integer array nums of size n.

// Define two arrays leftSum and rightSum where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

#include<iostream>
#include<vector>


std::vector<int> leftRightDifference(std::vector<int> &nums){
    int n = nums.size();
    std::vector<int> PS(n,0) , SS(n,0);
    PS[0]=nums[0];
    SS[n-1]=nums[n-1];
    std::vector<int>Ans;
    for(int i =1;i<n;i++){
        PS[i] = PS[i-1] + nums[i];
        SS[n-i-1] = SS[n-i] + nums[n-i-1];
    }
    for(int j=0;j<n;j++){
        int val=PS[j]-SS[j];
        int absVal = val>0?val:-val;
        Ans.push_back(absVal);
    }
    return Ans;
}
int main(){
    // std::vector<int> nums = {10,4,8,3};
    std::vector<int> nums = {1};
    std::vector<int>ans=leftRightDifference(nums);
    std::cout<<"[ ";
    for(int val:ans){
        std::cout<<val<<" ";
    }
    std::cout<<"]";
    return 0;
}