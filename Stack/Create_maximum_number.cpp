// You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
// Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
// Return an array of the k digits representing the answer.

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]

#include<iostream>
#include<vector>

class Solution {
    std::vector<int>LargerSubsequence(std::vector<int>&nums , int k){
        std::vector<int>Ans;
        int n = nums.size();
        //k - Ans.size() <= n - i - 1
        //this check condition ensures that if we remove our current num from ans then we have enough remaining nums to the right of current index to make a lexicographical greater subsequence of size k
        for(int i = 0 ; i < nums.size() ; i++){
            while(!Ans.empty() && nums[i] > Ans.back() && k - Ans.size() <= n - i - 1){
                Ans.pop_back();
            }
            if(Ans.size() < k)Ans.push_back(nums[i]);
        }
        return Ans;
    }

    //to compare two integer array to find lexicographical greater one
    bool greater(std::vector<int>& nums1 , std::vector<int>& nums2 , int a , int b){
        while(a < nums1.size() || b < nums2.size()){
            if(a >= nums1.size())return false;
            else if(b >= nums2.size())return true;
            else if(nums1[a] > nums2[b])return true;
            else if(nums1[a] < nums2[b])return false;
            else{
                a++;
                b++;
            }
        }
        return true;
    }
public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
       std::vector<int> maxnum(k,0);

       for(int i = 0 ; i <= k ; i++){
        int j = k - i;//try every possible combinations for selection of digits from both arrays
        if(i > nums1.size() || j > nums2.size())continue;

        std::vector<int>mx1 = LargerSubsequence(nums1,i);
        std::vector<int>mx2 = LargerSubsequence(nums2,j);

        std::vector<int>merged;
        int a = 0 , b = 0;
        while(a < mx1.size() || b < mx2.size()){
            if(a >= mx1.size())merged.push_back(mx2[b++]);
            else if(b >= mx2.size())merged.push_back(mx1[a++]);
            else if(mx1[a] > mx2[b])merged.push_back(mx1[a++]);
            else if(mx1[a] < mx2[b])merged.push_back(mx2[b++]);
            else{
                //if numbers at both indices are equal then we check for lexicographical order for remaining numbers in both arrays. if mx1 is lexicographical larger than mx2 after indice a and b. then we merge our index a value for mx1 first
                if(greater(mx1,mx2,a,b))merged.push_back(mx1[a++]);
                else merged.push_back(mx2[b++]);
            }
        }

        if(merged > maxnum)maxnum = merged;
       }
       return maxnum;
    }
};

int main(){
    std::vector<int> nums1 = {3,4,6,5};
    std::vector<int> nums2 = {9,1,2,5,8,3};

    int k = 5;

    Solution sol1;

    std::vector<int> max = sol1.maxNumber(nums1,nums2,k);

    for(int val : max)std::cout<<val<<" ";
    return 0;

}




