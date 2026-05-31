// You are given a sorted integer array nums and an integer k.
// Return an array such that each distinct element appears at most k times, while preserving the relative order of the elements in nums.
// Note: If a distinct element appears at least k times, then it must appear exactly k times in the resulting array.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,1,2,2,3]

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
class Solution {
    public:
        std::vector<int> limitOccurrences(std::vector<int>& nums, int k) {
    
            std::unordered_map<int,int>Map;
            for(int val : nums)Map[val]++;
            int count = 0;
            std::vector<int>Ans;
            for(const auto& [key,val] : Map){
                if(val <= k){
                    while(val != 0){
                        Ans.push_back(key);
                        Map[key]--;
                    }
                }else{
                    while(count != k){
                        Ans.push_back(key);
                        count++;
                    }
                    count = 0;
                }
            }
            std::sort(Ans.begin(),Ans.end());
            return Ans;
        }

        //inplace array modification solution exists, given below(i understood this optimal one)
        /*
        Key Observation:
    
        Since the array is sorted, duplicates are consecutive.
    
        Let i represent the size of the valid array built so far.
    
        When processing a number n:
    
        - If fewer than k elements have been written,
          n is always valid.
    
        - Otherwise, check nums[i-k].
    
          nums[i-k] is the element that would become the
          k-th most recent occurrence in the valid array.
    
          If nums[i-k] == n:
              We already kept k copies of n.
              Skip this occurrence.
    
          If nums[i-k] != n:
              Fewer than k copies exist.
              Keep n.
    
        Time  : O(n)
        Space : O(1)
    */
        std::vector<int> OlimitOccurrences(std::vector<int>&nums , int k){
            int i  = 0;
            for(int n : nums){
            
                if(i < k || n != nums[i-k]){
                    nums[i++]=n;
                }
            }
            while(nums.size() > i)nums.pop_back();

            return nums;
        }
    };




    int  main(){
        std::vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        Solution sol1;
        std::vector<int>Ans = sol1.OlimitOccurrences(nums,k);
        for(int val : Ans)std::cout<<val<<" ";
        return 0;
    }