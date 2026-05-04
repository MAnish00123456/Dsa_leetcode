//In this problem , we have given a integer array nums with size n and an integer k .. we have to return the count of contiguous subarray whosd product is strictly less than our k
//this is a type of dynamic size sliding window problem

#include<iostream>
#include<vector>
#include<algorithm>

int numSubarrayProductLessThanK(std::vector<int> & nums  , int k){
int n = nums.size();
int count =0;
int l=-1;//starting index of our window
long long currProd =1;
for(int i=0;i<n;i++){
currProd*=nums[i];//extending the current window
while(currProd >= k && l<i){//shrinking the size of window from left if given condition is not fulfilled;
    l++;
    currProd/=nums[l];
}
count+=(i-l);//no of subarrays in this range
}
return count;
}

int main(){
    std::vector<int> nums = {10,5,2,6};
    // std::vector<int> nums = {1,9,2,8,6,4,3};
    int k =100;
    int count = numSubarrayProductLessThanK(nums , k);
    std::cout<<count;
    return 0;
}