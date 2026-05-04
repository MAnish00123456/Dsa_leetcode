//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

//similar to subarray sum equals k

#include<iostream>
#include<vector>
#include<unordered_map>

int numSubarraysWithSum(std::vector<int>& nums, int k) {
std::vector<int> PS(nums.size());
PS[0] = nums[0];
for(int i = 1 ; i < nums.size() ; i++){
    PS[i] = PS[i-1] + nums[i];
}
int count = 0;
std::unordered_map<int,int>M;
for(int j = 0 ; j<nums.size();j++){
    if(PS[j] == k){
        count++;
    }
    int val = PS[j] - k;
    if(M.count(val)){
        count += M[val];
    }
    if(M.find(PS[j]) == M.end()){
        M[PS[j]] = 0;
    }
    M[PS[j]]++;
}
return count;
}

int main(){
std::vector<int> nums = {1,0,1,0,1};
int goal = 2;
int Count = numSubarraysWithSum(nums,goal);
std::cout<<"count : "<<Count;
return 0;
}