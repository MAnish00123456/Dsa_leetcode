// Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// The greatest common divisor of an array is the largest integer that evenly divides all the array elements.

// Input: nums = [9,3,1,2,6,3], k = 3
// Output: 4
// Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
// - [9,3,1,2,6,3]
// - [9,3,1,2,6,3]
// - [9,3,1,2,6,3]
// - [9,3,1,2,6,3]

#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
using namespace std;

//  (O(N log M) time, where N is the size of the array and M is the maximum element in the array.
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int ans = 0;

        unordered_map<int,int>mp;//tracks all the active GCDs of subarrays ending at the previous index (i-1)

        for(int num : nums){
            unordered_map<int,int>mp1;//stores new gcd values after including current num
            if(num % k == 0){
                ++mp[num];//add num as a standalone subarray of length 1, and then combine it with historical subarrays.
                //combine current number with all historic gcd values to get new gcd and store in mp1
                for(auto [d,cnt] : mp){
                    mp1[gcd(num,d)] += cnt;
                }
                ans +=  mp1[k];
            }
            swap(mp1,mp);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int subarrayGCD(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         int g = 0;

//         for(int i = 0 ; i < n ; i++){
//             g = nums[i];
//             if(g == k)ans++;
//             for(int j = i+1 ; j < n ; j++){
//                 if(nums[j] % k!= 0)break;
//                 g = gcd(g,nums[j]);

//                 if(g == k)ans++;
//                 if(g < k)break;
//             }
//         }
//         return ans;   
//     }
// };

int main(){
    vector<int>nums = {9,3,1,2,6,3};
    int k = 3;
    Solution sol1;
    cout<< sol1.subarrayGCD(nums,k);
    return 0;
}