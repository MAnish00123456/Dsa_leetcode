// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

class Solution {
    public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
            std::unordered_map<int,int>Map;
            for(int num : nums)Map[num]++;
    
            auto cmp = [](const auto& n1 , const auto& n2){
                return n1.second > n2.second;
            };
    
            std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(cmp)>pq(cmp);
    
            for(auto &p : Map){
                pq.push(p);
                if(pq.size() > k)pq.pop();
            }
            
            nums ={};
            for(int i = 0 ; i < k ; i++){
                nums.push_back(pq.top().first);
                pq.pop();
            }
            return nums;
        }
    };
 
    int  main(){
        std::vector<int> nums = {1,1,1,2,3,3};
        int k = 2;
        Solution sol1;
        std::vector<int> Ans = sol1.topKFrequent(nums,k);
        for(int val : Ans)std::cout<<val<<" ";
        return 0;
    }