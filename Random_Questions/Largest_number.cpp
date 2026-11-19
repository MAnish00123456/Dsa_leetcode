// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class Solution {
    public:
        std::string largestNumber(std::vector<int>& nums) {
            
            auto cmp = [](const int& n1 , const int& n2){
                std::string num1 = std::to_string(n1) + std::to_string(n2);
                std::string num2 = std::to_string(n2) + std::to_string(n1);
                //check which combination of numbers is bigger , ab or ba
                if(num1 > num2)return true;
                return false;
            };
    
            std::string res = "";
            std::sort(nums.begin(),nums.end(),cmp);
            for(int val  : nums)res +=(std::to_string(val));
            int idx = 0;//remove leading 0's
            while(idx < res.size() && '0' == res[idx])idx++;
            return idx == res.size()?"0":res.substr(idx);
        }
    };

int main(){
    std::vector<int> nums = {3,30,34,5,9};
    Solution sol1;
    std::cout<<sol1.largestNumber(nums);
    return 0;
}