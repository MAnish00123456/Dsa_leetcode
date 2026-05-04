//This problem is similar to our book allocation problem
//In this question we have been given an integer array nums and a integer k , we need to split our given array into k non empty subarray such that the largest sum of any subarray is minimized , return the minimized
//largest sum of split  
//for ex => nums = [7,2,5,10,8] , k = 2
//4 ways to split given array in 2 contiguous subarray :- 
// a) [7] [2,5,10,8]  -- maxsum = 25    --|
//b) [7,2] [5,10,8]   -- maxsum = 23    --|--|__> minimized_max_sum = 18(Ans)
//c) [7,2,5] [10,8]   -- maxsum = 18    --|--|
//d) [7,2,5,10] [8]   -- maxsum = 24    --|



#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

//To check if we can split our array into k parts , by allowing only minSum for each subarray
bool isValid(std::vector<int>&nums , int minAllowedsum , int k){
int split = 1;//Currenlty splitted our array into 1 part
int sum = 0;
for(int i = 0 ; i<nums.size() ; i++){
    if(nums[i] > minAllowedsum){
        return false;
    }
    //if each subarray sum is currently less or equal to our allowed sum , we just include that element
    if(sum + nums[i] <= minAllowedsum){
        sum+=nums[i];
    }
    //if any point our current subarray sum exceeds our allowedsum , we need to split our array again , and then continue with that split array
    else{
        split++;
        sum = nums[i];
    }
}
//if our splitting our whole array , our splits become greater than our allowed splits , we will return false
return split > k?false:true;
}


int splitArray(std::vector<int>&nums , int k ){
if(k > nums.size()){
    return -1;
}
int st = *max_element(nums.begin(),nums.end());//Max sum any subarray can have is the maximum element in our array
int ans = 0;//to track our minimized largest sum
int end = std::accumulate(nums.begin(),nums.end(),0);//total sum a subarray can get
while(st<=end){
    int mid = st + (end-st) / 2;//mid becomes our minAllowedSum in each iteration , by using this we need to see if we can split our array into k parts with minimized largest sum of any subarray

    //if we can split array into k parts , we store the mid into ans , and check if we can find a more minimum sum using which we can split our array or not
    if(isValid(nums,mid,k)){
        ans = mid ;
        end = mid - 1;
    }
    //if using our mid , we cant split our array into k partss , we will try to find a bigger mid value using which we can split our array into k parts
    else{
        st = mid + 1;
    }
}
return ans;
}


int main(){
    std::vector<int> nums = {7,2,5,10,8};
    int k = 2;
    int minimized_largest_sum = splitArray(nums,k);
    std::cout<<minimized_largest_sum<<std::endl;
    return 0;
}