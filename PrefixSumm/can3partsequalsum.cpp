//in this question , we have been given an array nums and we need to check if we  can do 3 partitions of given array each having sum equal'
//from wht i saw is that if we do a totalsum of nums array , and do TS%3 and if its not equal to 0 then its hard to do 3 partition , so we simply return false;
//else if its true then we start doing sum from start again then check if sum = TS/3 , then we increment our partition, if later on partition >=3 then  we return true'

#include<iostream>
#include<vector>

bool can3partsequalsum(std::vector<int>&nums){
    int n =nums.size();
    int TS =0;
    for(int val:nums){
        TS+=val;
    }
    if(TS%3!=0) return false;
    int partitions = 0 , i=0 , sum=0;
    while(i<n){
        sum+=nums[i];
        if(sum == TS/3){
            partitions++;
            sum=0;
            if(partitions>=3){
                return true;
            }
        }
        i++;
    }
    // if(partitions<2 || i == n){
    //     return false;
    // }
    return false;
}
int main(){
    std::vector<int>nums = {0,2,1,-6,6,-7,9,1,2,0,1};
    // std::vector<int>nums = {0,2,1,-6,6,7,9,-1,2,0,1};
    // std::vector<int>nums = {3,3,6,5,-2,2,5,1,-9,4};
    if(can3partsequalsum(nums)){
        std::cout<<"yes";
    }
    else{
        std::cout<<"false";
    }
    return 0;
}