// Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
// An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
// We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number 
// less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

// Input: nums = [3,5,2,6], k = 2
// Output: [2,6]
// Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.

#include<iostream>
#include<vector>

//for lexicographical questions , always think of a monotonic stack and check condition

class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int>ans;//act as monotonic stack , maintain an increasing stack for generating lexicographically low number
        //used safety check so we only pop from stack if we have enough elements left to the right of the current index to make subsequence of size k , even if have to include some big nums ,
        //  this check ensures we end up with k size subsequence

        for(int i = 0 ; i < nums.size() ; i++){
            while(!ans.empty() && nums[i] < ans.back() && k - ans.size() <= n - i - 1)ans.pop_back();
            if(ans.size() < k)ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main(){
    std::vector<int> nums = {3,5,2,6};
    int k = 2;
    Solution sol1;
    std::vector<int>Ans = sol1.mostCompetitive(nums,k);
    for(int num :Ans){
        std::cout<<num<<" ";
    }
    return 0;
}