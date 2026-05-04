// we have been given an integer array nums , and a integer value k , we need to find count of good subarrays in nums
// a good subarray is array where distinct element count is exactly k
// for ex -> nums=[1,2,1,2,3] , good subarray = 7
//[1,2] [2,1] [1,2,1] [1,2,1,2] [2,1,2] [1,2] [2,3]

// the trick to find is :->
//  atMost(k): counts subarrays with at most k distinct elements
//  Sliding window can efficiently maintain a window with ≤ k distinct elements

// its hard to directly find exactly k distinct elements
// so after finding atmost k distinct elements , we have some redundant subarrays which we do not need ,
//   so we find atmost(k-1) distinct elements too , and then subtract the count to find exactly k distinct elements;
// exactly(k) distinct elements = atmost(k) distinct elements - atmost(k-1) elements
// for ex -> if k = 2 , so exactly 2 distinct elements = atmost 2 distinct elements - atmost 1 distinct elements  ,
// which help us to remove redundant subarrays , we do not need

#include<iostream>
#include<vector>
#include<unordered_map>

int CountAtmostKelements(std::vector<int>&nums,int k){
    int l = -1;
    int count = 0;
    std::unordered_map<int,int>M;
    for(int i = 0 ; i < nums.size() ; i++){
        M[nums[i]]++;

        // shrinking our current window till we have only atmost k different integers
        while(M.size() > k ){
            l++;
            M[nums[l]]--;
            if(M[nums[l]] == 0){
                M.erase(nums[l]);
            }
        }
        count += (i-l);
    }
    return count;
}

int subarraysWithKDistinct(std::vector<int>&nums,int k){
return CountAtmostKelements(nums,k) - CountAtmostKelements(nums,k-1);
}


int main(){
    // std::vector<int> nums = {1,2,1,2,3};
    std::vector<int> nums = {1,2,1,3,4};
    int k = 3;
    int Count_Good_subarray = subarraysWithKDistinct(nums,k);
    std::cout<<"Count of good subarray with k distinct integers : "<<Count_Good_subarray<<std::endl;
    return 0;
}