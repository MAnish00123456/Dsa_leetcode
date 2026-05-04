//This question is based on our fixed size sliding window problem , in which we first calculate whatever given in question say sum , upto size of subarray say k , then we iterate from k to n-1 , and each time 
//we are adding our current value  and subtracting our 1st value from sum to get new subarray summ , then performing operations required in O(n) TC

//In this question we have given an array nums , and an integer value 'k' prolly our window size , we have to calculate maximum average subarray and return that value. 
#include<iostream>
#include<vector>
#include<algorithm>

double findMaxAverage(std::vector<int>&nums , int k){
    int n = nums.size();
    double currsum = 0 , Maxavg =0;
    //our currsum and maxavg we assume is our first k terms
    for(int i =0;i<k;i++){
        currsum+=nums[i];
    }
    Maxavg = currsum / k;
    double curravg=0;
    for(int j =k;j<n;j++){
        currsum=currsum + nums[j] - nums[j-k];
        curravg = currsum / k;
        Maxavg = std::max(curravg,Maxavg);
    }
    return Maxavg;
}

int main(){
    std::vector<int> nums = {1,12,-5,-6,50,3};
    int k =4;//our window size 
    double MaxAvg = findMaxAverage(nums,k);
    std::cout<<"Maximum average subarray sum : "<<MaxAvg<<std::endl;
    return 0;
}