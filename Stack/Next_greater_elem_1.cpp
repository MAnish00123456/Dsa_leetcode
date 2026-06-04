// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

//use a monotonic decreasing stack for nums2 elements and top should be < bottom. use a Hashmap to store for each num in nums2 , its NGE means stack top element;


#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>

class Solution {
    public:
        std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::unordered_map<int,int>Map;
            std::stack<int>st;
            for(int i = nums2.size()-1 ; i >= 0 ; i--){
                while(!st.empty() && st.top() <= nums2[i]) st.pop();
                Map[nums2[i]] = st.empty()?-1:st.top();
                st.push(nums2[i]);
            }
            std::vector<int>Ans;
            for(int val : nums1){
                Ans.push_back(Map[val]);
            }
            return Ans;
        }
    };
    int main(){
        std::vector<int> nums1 = {4,1,2};
        std::vector<int> nums2 = {1,3,4,5,2};
        Solution sol1;
        std::vector<int> NSE= sol1.nextGreaterElement(nums1,nums2);
        for(int val : NSE)std::cout<<val<<" ";
        return 0;
    }