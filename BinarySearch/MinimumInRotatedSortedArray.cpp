//in this question , we have given an array nums , which is rotated by some k indices , we need to find minimum number in that array
//in RSA problems whenever we need to work on :- Minimum in Rotated Sorted Array ,, Peak Element ,, First True / First Valid Position :- 7️⃣ Problems using this pattern
// Very common interview problems:
// Koko Eating Bananas
// Capacity To Ship Packages Within D Days
// Split Array Largest Sum
// Minimum Number of Days to Make m Bouquets
// All use check() + binary search on answer.
 
//we always do low < high and check our mid with high instead of low

#include<iostream>
#include<vector>
#include<climits>
int findMin(std::vector<int>& nums) {
    int low = 0 , high = nums.size()-1;
    while(low < high){
        int mid = low + (high-low)/2;
        //in boundary problems or min max , always checks with nums[high], 
        //in this if our value on mid is greater than value on high so possibly our min exists in mid+1 to high range
        if(nums[mid] > nums[high]){
            low = mid +1;
        }
        else{
            high = mid;
        }
    }
    return nums[low];
}

int main(){
    // std::vector<int> nums = {3,4,5,1,2};
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int min = findMin(nums);
    std::cout<<"min : "<<min;
    return 0;
}