// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.




#include<iostream>
#include<vector>

int findPeakElement(std::vector<int>& nums) {
    int low = 0 , high = nums.size()-1;
    while(low < high){
        int mid = low + (high - low)/2;
        //if our mid value is smaller than our mid+1 value , so our slope is going upward means peak exists on right half
        if( nums[mid] < nums[mid+1]){
            low = mid +1;
        }
        //else if our mid value is greater than our mid +1 value , so our slope is going downward means peak exists on left side including mid
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    std::vector<int> nums = {1,2,3,1};
    int peak = findPeakElement(nums);
    std::cout<<"Peak element exists at index : "<<peak;
    return 0;
}