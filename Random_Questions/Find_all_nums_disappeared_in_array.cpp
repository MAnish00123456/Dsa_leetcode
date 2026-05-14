// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

#include<iostream>
#include<vector>

class Solution {
    public:
    /*
    * Key Observation:
    *
    * Array contains numbers from 1 to n
    * where n = nums.size()
    *
    * So every value can map directly to an index:
    *
    * value x  ->  index (x - 1)
    *
    * We use this mapping to mark numbers
    * that are present in the array.
    */
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    
            for(int i =  0 ; i < nums.size() ; i++){
                /*
                * abs(nums[i]) is used because
                * values may already have been marked negative earlier.
                *
                * Example:
                * nums[i] = -4
                * actual value still represents 4
                */
               int idx = abs(nums[i]) - 1;
   
               /*
                * Mark corresponding index as negative
                * to indicate that number exists.
                *
                * Negative value means:
                * "this number was seen in array"
                */
                if(nums[idx] > 0){
                    nums[idx] = - nums[idx];
                }
            }
            std::vector<int> result;
            result.reserve(nums.size()-1);
            /*
         * Second pass:
         *
         * Any index still containing positive value
         * means that index was never visited.
         *
         * Therefore:
         * missing number = index + 1
         */
            for(int i = 0 ; i < nums.size() ; i++){
                /*
                * Positive value means:
                * corresponding number was never marked/visited
                */
               if(nums[i] > 0){
   
                   // Convert index back to original number
                   result.push_back(i + 1);
               }
            }
            return result;
        }
    };

    int main(){
        Solution sol1;
        std::vector<int> nums = {4,3,2,7,8,2,3,1};
        std::vector<int> ans = sol1.findDisappearedNumbers(nums);
        for(int val : ans) std::cout<<val<<" ";
        return 0;
    }