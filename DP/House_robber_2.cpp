// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in
//  a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.z

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            if(nums.size() == 1)return nums[0];
            if(nums.size() == 2)return max(nums[0],nums[1]);
            int ans1 =0;//final ans
    
    
            //rob houses from 0 to n-2  , skipping the last house
            int prev1 = max(nums[1],nums[0]);
            int prev2 = nums[0];
             
            for(int i = 2 ; i < nums.size()-1; i++){
                int newMoney = max(nums[i] + prev2 , prev1);
                prev2 = prev1;
                prev1 = newMoney;
            }
    
            ans1 = max(prev1,ans1);
    
            //rob houses from 1 to n-1 , skipping the first house
             prev1 = nums[1];
             prev2 = 0;
    
            for(int i = 2 ; i < nums.size() ; i++){
                int newMoney = max(nums[i]+prev2,prev1);
                prev2 = prev1;
                prev1 = newMoney;
            }
    
            ans1 = max(ans1,prev1);
    
            return ans1;
        }
    };

int main(){
    Solution sol1;
    vector<int>nums = {1,2,3,1};
    cout<<sol1.rob(nums);
    return 0;
}