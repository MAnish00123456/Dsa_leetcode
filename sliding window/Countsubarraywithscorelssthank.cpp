//in this problem , we have an integer array nums and a integer k.
//we have to count all the subarrays if the score of that subarray is strictly less than k.
//score is equal to our sum of all values in that window * size of that window
//this is almost similar to subarrayproductlessthanK , as it also uses dynamic size sliding window

#include<iostream>
#include<vector>

long long countSubarrays(std::vector<int>& nums, long long k) {
    int n = nums.size();
    long long count = 0;
    int l = -1;              // starting index of our window from left
    long long currscore = 0; // to calculate score of the subarray
    for (int i = 0; i < n; i++) {
        currscore += nums[i]; // extending the current window from right side
        while (currscore * (i - l) >= k &&
               l < i) { // reducing the size of window from left if given
                        // condition is not fulfilled aka  score * size of
                        // that subarray is less than K
            l++;
            currscore -= nums[l];
        }
        count += (i - l); // no of subarrays in this range, as if our current
                     // subarray has fulfilled the condition , then all the
                     // subarrays btw them will also fulfill the condition
    }
    return count;
}

int main(){
    std::vector<int> nums = {2,1,4,3,5};
    long long k =10;
    int count = countSubarrays(nums , k);
    std::cout<<"Count : "<<count;
    return 0;
}