// You are given an integer array nums.
// Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

// Input: nums = [2,3,4]
// Output: 3
// Explanation:
// The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

#include<iostream>
#include<vector>

class Solution {
    public:
        int longestSubsequence(std::vector<int>& nums) {
            //only 3 cases for answers are possible ,
            //either ans is 0 or nums.size() , or nums.size()-1
    
            //0 is when all elements in nums have xor = 0, which is either all nums are 0 
            //or they cancel out each other ,so we can remove one element to get non zero xor ,ans = nums.size()-1
            //or xor of all nums is non zero causing ans nums.size();
    
            int xor_nums = 0;
            int all_zero = 0;
            for(int num : nums){
                if(num == 0){
                    all_zero++;
                }
                xor_nums ^= num;
            }
    
            if(xor_nums != 0){
                return nums.size();
            }
            if(all_zero == nums.size())return 0;
    
            return nums.size()-1;
        }
    };

int main(){
    std::vector<int> nums = {2,3,4};
    Solution sol1;
    std::cout<<"Longest subsequence : "<<sol1.longestSubsequence(nums);
    return 0;
}