//in this given array , we have to find a value from our given array such that that value is maximum,, using formula : (nums[i] - nums[j]) * nums[k]
//where i < j <  k ,, the bruute force approach would be using a nested for loop 3 times,, taking O(n^3) TC 
//but if we long focus on given formula , we know that the value would be maximum if our nums[i] and nums[k] are maximum which are just prefix and 
//suffix for our nums[j] , , so we should find the max values by making j fixed.. By using prefixmax and suffixmax we could find the max values for our a given j index
//the prefixmax for [i] index would be our max from prefixmax[i-1] and nums[i-1] if our loop starts from 1 , as prefixmax[0] would be 0
//similar for suffixmax for i index would be max from suffixmax[i+1] and nums[i+1]

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>


//Brute force
long long maximumTripletValue(std::vector<int> &nums){
    int n = nums.size();
    long long maxValue=INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                long long value = (nums[i] - nums[j]) * nums[k];
                maxValue=std::max(maxValue,value);
            }
        }
    }
    return maxValue<0?0:maxValue;
}

//optimal ,prefixMax , SuffixMax
    long long OmaximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> PrefixMax(n), Suffixmax(n);
        PrefixMax[0] = 0;
        Suffixmax[n - 1] = 0;
        long long maxValue = INT_MIN;
        for (int i = 1; i < n; i++) {
            PrefixMax[i] = std::max(PrefixMax[i - 1], (long long)nums[i - 1]);
            Suffixmax[n - 1 - i] =
                std::max(Suffixmax[n - i], (long long)nums[n - i]);
        }
        for (int j = 1; j < n - 1; j++) {
            long long value = (PrefixMax[j] -(long long) nums[j]) * Suffixmax[j];
            maxValue = std::max(maxValue, value);
        }
        return maxValue < 0 ? 0 : maxValue;
    }
int main(){
    std::vector<int> nums = {12,6,1,2,7};
    long long value =  maximumTripletValue(nums);
    std::cout<<value<<std::endl;
    return 0;
}