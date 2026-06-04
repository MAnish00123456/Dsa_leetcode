// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this numbe

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.


#include<iostream>
#include<vector>
#include<stack>

class Solution {
    public:
        std::vector<int> nextGreaterElements(std::vector<int>& nums) {
            std::vector<int> Ans(nums.size());
            std::stack<int> st;
            
            //as our array is circular , BF would be traversing circular indices for each num.
            //we can do this process using stack too, just repeat the monotonic decreasing stack property twice on array , so if in 1 pass we didnt find correct ans , we can find it in 2nd pass
    
            for(int i= 2* nums.size()-1; i >=0 ; i--){
                while(!st.empty() && st.top() <= nums[i%nums.size()]) st.pop();
                //for current num , next greater can be stack.top() but its not confirmed, can rechange in 2nd pass
                Ans[i%nums.size()] = st.empty()?-1:st.top();
                st.push(nums[i%nums.size()]);
            }
        
            return Ans;
        }
    };

    int main(){
        std::vector<int> nums = {1,2,3,4,3};
        Solution sol1;
        std::vector<int> Ans = sol1.nextGreaterElements(nums);
        for(int val : Ans)std::cout<<val<<" ";
        return 0;
    }