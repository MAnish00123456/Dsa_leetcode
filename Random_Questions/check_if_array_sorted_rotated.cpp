// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array
// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].


//in this approach , we will traverse our array twice by assuming it a circular array ,we will increment count when we find numbers in ascending order and  if at any point  out count equals to our array size means we can make 
//a sorted array from given array

#include<iostream>
#include<vector>

class Solution {
    public:
        bool check(std::vector<int>& nums) {
           int count = 1;
           int n = nums.size();
           if(n == 1)return true;
           for(int i = 1 ; i < nums.size()*2 ; i++){
            if(nums[i%n] >= nums[(i-1) % n]){
                count++;
            }else{
                count=1;
            }
            if(count == n)return true;
           } 
        return false;
        }
    };
    
    int main(){
        std::vector<int> nums = {3,4,5,1,2};
        Solution sol1;
        if(sol1.check(nums)){
            std::cout<<"array is sorted and rotated";
        }else{
            std::cout<<"array is not sorted and rotated";
        }
        return 0;
    }