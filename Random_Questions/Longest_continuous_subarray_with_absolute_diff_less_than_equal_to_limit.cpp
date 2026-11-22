// You are given an array of integers nums and an integer limit.

// Return the size of the longest non-empty subarray such that the absolute difference between every pair of elements in this subarray is less than or equal to limit.

// Input: nums = [8,2,4,7], limit = 4

// Output: 2

// Explanation:

// Checking every subarray, where the absolute difference is taken over all pairs of its elements:
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |4-2| = 2 <= 4.
// [2,4,7] with maximum absolute diff |7-2| = 5 > 4. Note that the pair (2, 7) is not adjacent, but it is still compared.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |7-4| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.


#include<iostream>
#include<vector>
#include<set>

using namespace std;


class Solution { 
    public: 
        int longestSubarray(vector<int>& nums, int limit) {
            // Keeps track of the elements in the current sliding window in sorted order
            multiset<int> ms; 
            
            int longestAns = 0; // Tracks the maximum length of a valid subarray
            int left = -1;      // Left boundary index of the sliding window
            
            // Expand the window by moving the right pointer
            for(int right = 0 ; right < nums.size() ; right++){
                ms.insert(nums[right]); // Add the current element to the window
                
                // Shrink the window from the left if the maximum absolute difference 
                // between the max element (*ms.rbegin()) and min element (*ms.begin()) exceeds the limit
                while(*ms.rbegin() - *ms.begin() > limit){
                    left++; 
                    auto it = ms.find(nums[left]); // Find a single instance of the element leaving the window
                    ms.erase(it);                  // Remove only that specific instance from the multiset
                }
                
                // Update the maximum length found so far (window size is right - left)
                longestAns = max(longestAns, right - left); 
            } 
            
            return longestAns; 
        } 
    };

int main(){
    vector<int>nums = {8,2,4,7};
    int limit = 4;

    Solution sol1;
    cout<<sol1.longestSubarray(nums,limit);
    return 0;
}

