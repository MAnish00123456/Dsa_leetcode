// Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.

// Input: nums = [3,6,2,7,1], k = 6
// Output: 4
// Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
// - [3,6,2,7,1]
// - [3,6,2,7,1]
// - [3,6,2,7,1]
// - [3,6,2,7,1]


#include<iostream>
#include<vector>
using namespace std;
#include<numeric>


// When we are at index i, we only care about the LCMs of subarrays that end exactly at index i.
// The map mp stores these LCM values as key, and how many subarrays ending at the current position share that exact LCM value as value.

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {

        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int g = nums[i];//stores LCM till i-1 indices
            if(nums[i] == k)ans++;
            for(int j = i+1 ; j < nums.size() ; j++){
                if(k % nums[j] != 0)break;//if any number dont fully divide k , then discard subarray
                g = lcm(g,nums[j]);//calculate lcm of current number with lcm of all nums subarray ending at this indice
                if(g == k)ans++;
                if(g > k)break;//if LCM becomes greater than limit , break the subarray
            }
        }
      return ans;

    }
};

//optimized sol
// class Solution {
// public:
//     int subarrayLCM(vector<int>& nums, int k) {

//         int ans = 0;
//         unordered_map<int,int>mp;

//         for(int n : nums){
//             unordered_map<int,int>mp1;
//             if(k % n == 0){
//                 ++mp[n];
//                 for(auto& [num,cnt] : mp){
//                     mp1[lcm(num,n)]+=cnt;
//                 }
//                 ans += mp1[k];
//             }
//         swap(mp,mp1);
//         }
//     return ans;
//     }
// };


// Step-by-Step Code Walkthrough
// if (k % n == 0)An element can only be part of a subarray with an LCM equal to \[K\] if it is a divisor of \[K\]. If n does not cleanly divide k, its LCM with any other number will never equal k. Thus, if k % n != 0, we completely skip the logic, clear our active tracking map (swap(m, m1) clears m because m1 is empty), and effectively reset our subarray streak. 
// ++m[n];This registers a new single-element subarray [n] starting and ending at the current position. Its LCM is simply n.
//  for (auto &[d, cnt] : m) m1[lcm(d, n)] += cnt;We iterate through all the LCMs (d) of the subarrays ending at the previous element.When we extend those subarrays to include the current element n, their new LCM becomes lcm(d, n).We record these updated LCMs into a new temporary map m1.
//  cnt tracks how many subarrays produced that specific LCM value. 
//  res += m1[k];After building out the updated LCM list for all subarrays ending at the current index, we check how many of them successfully reached an LCM exactly equal to k. We accumulate this count into our result.
//   swap(m, m1);We prepare for the next element by transferring the active subarray LCM calculations (m1) over to our primary state tracking map (m).

int main(){
    vector<int>nums = {3,6,2,7,1};
    int k = 6;
    Solution sol1;
    cout << sol1.subarrayLCM(nums,k);
    return 0;
}