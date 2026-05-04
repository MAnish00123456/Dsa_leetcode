// You are given an integer array nums of length n.
// The score of an index i is defined as the number of indices j such that:
// i < j < n, and
// nums[i] and nums[j] have different parity (one is even and the other is odd).
// Return an integer array answer of length n, where answer[i] is the score of index i.
#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
    public:
        std::vector<int> countOppositeParity(std::vector<int>& nums) {
    
            // Result vector to store answer
            std::vector<int> ans;
    
            // Counters to track how many even/odd elements
            // we have seen so far (from right side)
            int count_even = 0;
            int count_odd = 0;
    
            // Traverse from right to left
            // This allows us to know how many opposite parity
            // elements exist to the right of current index
            for(int i = nums.size() - 1; i >= 0; i--) {
    
                // If current number is even
                if(nums[i] % 2 == 0) {
    
                    // Store how many odd numbers are to the right
                    ans.push_back(count_odd);
    
                    // Update even count
                    count_even++;
                }
                else {
                    // If current number is odd
    
                    // Store how many even numbers are to the right
                    ans.push_back(count_even);
    
                    // Update odd count
                    count_odd++;
                }
            }
    
            // Since we traversed from right to left,
            // reverse the result to restore correct order
            reverse(ans.begin(), ans.end());
    
            return ans;
        }
    };

int main(){
    std::vector<int> nums = {1,2,3,4};
    Solution sol1;
    std::vector<int>Ans = sol1.countOppositeParity(nums);
    for(int val : Ans){
        std::cout<<val<<" ";
    }
    return 0;
}