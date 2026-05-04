//we have a given an integer array nums and a number k ,,we have to return no of non empty subarrays whose sum is divisible by k
#include<iostream>
#include<vector>
#include<unordered_map>
int subarraysDivByK(std::vector<int>&nums , int k)
{
    if(k == 0) return 0;
    int n = nums.size();
    int count = 0;
    for(int i =0;i<n;i++){
        int sum =0;
        for(int j =i;j<n;j++){
            sum+=nums[j];
            if(sum%k == 0){
                count++;
            }
        }
    }
    return count;
}

//we used map to store the remainder valuues we get by sum%k, along with the count, if any point our remainder is less than 0 then we will do this , rem + = rem%k +k
//we will insert 0 as remainder with count 1 in the map beforehand ,, instead of a prefix sum we just need continuos sum so we will just take help of cumulative sum and modular arithmetic
int OsubarraysDivByK(std::vector<int>&nums,int k){
    int n = nums.size();
    if(k == 0) return 0;
    // if(k<0) k= -k;
    int count = 0;
    std::unordered_map<int,int>M;
    M[0]=1;
    int sum =0;
    for(int i =0;i<n;i++){
        sum+=nums[i];
        int rem = sum%k;
        if(rem < 0) rem+=rem%k +k;
            count+=M[rem];
        M[rem]+=1;
    }
    return count;
}
int main(){
    std::vector<int> nums = {4,5,0,-2,-3,1};
    int k = -5;
    int count = OsubarraysDivByK(nums , k );
    std::cout<<"count : "<<count;
    return 0;
}