// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            std::unordered_set<int>st(nums.begin(),nums.end());
            int ans = 0;
    
            for(int num : st){
                //only start sequence if current num is the start of sequence
                if(!st.count(num-1)){
                int cnm = num;
                int ln = 1;
                while(st.count(cnm+1)){
                    cnm = cnm + 1;
                    ln++;
                }
                ans = std::max(ans,ln);
                }
            }
            return ans;
        }
    };

int main(){
    std::vector<int> nums = {100,4,200,1,1,3,3,3,4,2};
    Solution sol1;
    std::cout<<sol1.longestConsecutive(nums);
    return 0;
}