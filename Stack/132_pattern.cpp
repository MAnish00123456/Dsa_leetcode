// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

#include<iostream>
#include<stack>
#include<vector>
class Solution {
    public:
        bool find132pattern(std::vector<int>& nums) {
            if(nums.size() < 3)return false;
    
            //stack stores our candidate j and a min elem associated with candidate j which is present before it
            std::stack<std::pair<int,int>>st;
            //stores minelement for each candidate j
           int minNum = INT_MAX;
            for(int k = 0 ; k < nums.size() ; k++){
                // Remove candidate j values that are <= current value.
    // For a valid 132 pattern we need nums[j] > nums[k].
                while(!st.empty() && st.top().first <= nums[k])st.pop();
                //if stack is non empty , means for candidate k , we got a candidate j having greater value than candidate k.
                //now we need to check if the min number associated with candidate j is also less than our candidate k, it means we got our 132 pattern
                    if(!st.empty() && nums[k] > st.top().second){
                        return true;
                    }
                    //push our current candidate and minNum associated with it that comes before it
                st.emplace(nums[k],minNum);
                //update our minNum for future j candidates
                minNum = std::min(minNum,nums[k]);
            }
            return false;
        }
    };

    int main(){
        std::vector<int> nums= {3,1,4,2};
        Solution sol1;
        if(sol1.find132pattern(nums))std::cout<<"found";
        else std::cout<<"not found";
        return 0;
    }