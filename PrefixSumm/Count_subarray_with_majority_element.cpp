// You are given an integer array nums and an integer target.
// Return the number of subarrays of nums in which target is the majority element.
// The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

// Input: nums = [1,2,2,3], target = 2

// Output: 5

// Explanation:

// Valid subarrays with target = 2 as the majority element:

// nums[1..1] = [2]
// nums[2..2] = [2]
// nums[1..2] = [2,2]
// nums[0..2] = [1,2,2]
// nums[1..3] = [2,2,3]
// So there are 5 such subarrays.

#include<iostream>
#include<vector>
#include<unordered_map>


class Solution {
    using ll = long long ;
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        
        ll currsum = 0;
        std::unordered_map<int,int>Hashmap;
        Hashmap[0] = 1;
        ll leftValidpoints = 0;
        ll res = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                leftValidpoints += Hashmap[currsum];
                currsum+=1;
            }else{
                currsum-=1;
                leftValidpoints -= Hashmap[currsum];
            }
                Hashmap[currsum]+=1;
                res += leftValidpoints;
        }
        return res;
    }
};

int main(){
    std::vector<int> nums = {2,2,2,2,1,7};
    int target  = 2;
    Solution sol1;
    int count = sol1.countMajoritySubarrays(nums,target);
    std::cout<<count;
    return 0;
}
/*
so basically we need to find prefixsum , if our num = target inc sum else dec
for ex . nums = [2,2,1,7,2]
            PS = [1,2,1,0,1]
            now what we did in medium lvl of this question was to find subarray sums ,now lets see , if we need subarray sum from i to j , we can get it by 
            sum = PS[j] - PS[i-1] and then checked if this sum is > 0 , then we have our target in majority in that subarray

            from this inequality , we can say that PS[j] - PS[i-1] > 0  
                                                    PS[j] > PS[i-1] (key thought)
            this inequality says that , for every sum at j index , if we can find count ofsubarrays whose sum is less than our current j index sum to the left of this index , we cann say that all these subarrays are valid with majority element as target
        
        for ex , if our j = 1 , so our currsum = 2. we need to find count of subarrays having sum less than 2 , i.e , sum = 0 and 1
        //this information can be stored in a hashmap to use it later on
        //Hashmap will contain sum = 0 with  count = 1 in start 

        if for our index j = 2, our nums[j] != target , it means we will subtract 1 from our currsum , i.e , currsum = 1 now.
        now we will subtract all the count of subarrays whose sum is equal to currsum , as these subarrays are not valid ones


        in the end we store our currsum and count of it in hashmap 
        result will store total valid left count of subarrays at each index 
*/