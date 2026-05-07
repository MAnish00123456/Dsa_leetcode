// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j]
//  in nums2. If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
    public:
       std:: vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::unordered_map<int,int>Map2;
            for(int i = 0 ; i < nums2.size() ; i++){
                Map2[nums2[i]]=i;
            }
           std:: vector<int>Ans;
            for(int j = 0 ;  j < nums1.size() ; j++){
                int idx = Map2[nums1[j]];
                if(idx == nums2.size()-1){
                    Ans.push_back(-1);
                    continue;
                }
                int greater= -1;
                for(int k = idx + 1 ; k < nums2.size() ; k++){
                    if(nums2[k] > nums2[idx]){
                        greater=nums2[k];
                        Ans.push_back(greater);
                        break;
                    }
                }
                if(greater == -1) Ans.push_back(greater);
            }
            return Ans;
        }
    };
    int main(){
        std::vector<int> nums1 = {4,1,2};
        std::vector<int> nums2 = {1,3,4,2};
        Solution sol1;
        std::vector<int> Ans = sol1.nextGreaterElement(nums1,nums2);
        for(int val : Ans){
            std::cout<<val<<"  ";
        }
        return 0;
    }

    //this can also be solved efficiently using monotonic decreasing stack .... i havent studied stack yet (07-05-2026) so didnt implemented the solution