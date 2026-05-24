// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

#include<iostream>
#include<vector>

class Solution {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
    
            /*
                Let n = nums.size()
    
                The smallest missing positive number will always lie
                in the range [1, n + 1].
    
                Example:
                [1,2,3] -> answer = 4
                [3,4,-1,1] -> answer = 2
    
                So we only care about numbers inside this range.
            */
            int maxRangeVal = nums.size() + 1;
    
            /*
                Step 1: Remove useless values
    
                Numbers <= 0 cannot contribute to the answer.
                Numbers > n+1 also cannot affect the smallest
                missing positive.
    
                Replace them with sentinel value (n+1) so they
                can be ignored later.
    
                Example:
                [-1,4,10,2]
                becomes
                [5,4,5,2]  (assuming n=4)
            */
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= 0 || nums[i] > maxRangeVal) {
                    nums[i] = maxRangeVal;
                }
            }
    
            /*
                Step 2: Use array indices as presence markers
    
                If number x exists, mark index (x-1) negative.
    
                Example:
                nums = [3,4,1,5]
    
                value 3 -> mark index 2
                value 4 -> mark index 3
                value 1 -> mark index 0
    
                Negative value means:
                "corresponding number exists"
    
                abs() is needed because an element may already
                have been marked negative earlier.
            */
            for (int i = 0; i < maxRangeVal - 1; i++) {
    
                // Convert current value into index
                int idx = abs(nums[i]) - 1;
    
                /*
                    Conditions:
                    idx < n  -> valid position
                    nums[idx] > 0 -> avoid double negation
                */
                if (idx < maxRangeVal - 1 && nums[idx] > 0) {
                    nums[idx] = -nums[idx];
                }
            }
    
            /*
                Step 3: Find first unmarked position
    
                Positive index means that number was never found.
    
                Example:
                nums = [-1,-2,3,-4]
    
                index 0 -> number 1 exists
                index 1 -> number 2 exists
                index 2 -> still positive
    
                Therefore answer = 3
            */
            for (int i = 1; i < maxRangeVal; i++) {
                if (nums[i - 1] > 0) {
                    return i;
                }
            }
    
            /*
                If every index was marked negative,
                numbers 1..n all exist.
    
                Therefore smallest missing positive = n+1
            */
            return maxRangeVal;
        }
    };
    int main(){
        std::vector<int> nums = {1,2,0};
        Solution sol1;
        int missingNum = sol1.firstMissingPositive(nums);
        std::cout<<missingNum;
        return 0;
         
    }