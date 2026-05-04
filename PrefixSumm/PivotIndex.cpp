//in this problem we have given an integer array nums , and we need to find a pivot index , a index at which the sum of the left partof array before that index is equal to the sum of the right part of array
//if our index is at 0 , then leftsum = 0 , and if at n-1 our rightsum = 0;
//return the leftmost index

#include<iostream>
#include<vector>
#include<algorithm>
int pivotIndex(std::vector<int>&nums){
    int n = nums.size();
    std::vector<int> PS(n,0) , SS(n,0);
    PS[0] = nums[0];
    SS[n-1] = nums[n-1];
    for(int i = 1 ;i<n;i++){
        PS[i]=PS[i-1] + nums[i];
        SS[n-i-1] = SS[n-i] + nums[n-i-1];
    }
    std::cout<<"[ ";
    for(int val :PS){
        std::cout<<val<<"\t";
    }
    std::cout<<" ]"<<std::endl;
    std::cout<<"[ ";
    for(int val :SS){
        std::cout<<val<<"\t";
    }
    std::cout<<" ]"<<std::endl;

    for(int j=0;j<n;j++){
        if(PS[j] == SS[j]){ return j;}
    }
    return -1;
}
int main(){
    // std::vector<int> nums={1,7,3,6,5,6};
    std::vector<int> nums={-1,-1,-1,0,1,1};
    int index = pivotIndex(nums);
    std::cout<<"index : "<<index<<std::endl;
    return 0;
}