//In this question we have given an integer array nums with non negative integers , we need to returnn the longest length of a nice subarray
//A subarray is nice if the bitwise AND of all pair of elements in that window that are in diff position equals 0 , means they dont share same setbit , means there are distinct setbits in that window
//we can track this using variable say usedBit which will store num in that window.
//if current num and usedBit have a setbit in common , we will try to shrink that window from left to make distinct setbits , once it is done we will  calculate the max length in each iteration
//If our current num and usedbit dont have any setbit in common , we will combine them using '|' operator (bitwise or) , to shrink window from left we will use '^' (bitwise xor) , to check if we have common setbit we 
//will use '&' (bitwise and)
#include<iostream>
#include<vector>
#include<algorithm>

int longestNiceSubarray(std::vector<int>& nums){
    int n = nums.size();
    int usedBit =0; //Tracks current subarray values
    int maxLength =1;//Max length of nice subarray
    int l =-1; //windows starting index , from left , currently set to -1
    for(int i =0;i<n;i++){
    //we will check if our current num and Usedbit have any same setbits  using bitwise and
    while((usedBit & nums[i]) !=0){
        l++;
        usedBit^=nums[l]; //using xor operator to safely shrink values from left
    }
    usedBit |=nums[i]; // using bitwise or operator to safely add/extend our current window
    maxLength=std::max(maxLength ,i-l);
    } 
    return maxLength;
}
int main(){
    // std::vector<int> nums = {1,3,8,48,10};
    // std::vector<int> nums = {3,1,5,11,13};
    std::vector<int> nums = {338970160,525086042,19212931,213753017,321613307,553272419,190837185,548628106,793546945,243936947};
    int length = longestNiceSubarray(nums);
    std::cout<<"lenght : "<<length<<std::endl;
    return 0;
}