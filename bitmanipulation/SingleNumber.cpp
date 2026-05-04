//Leetcode 136. Single Number
//we got a non empty array of integers where everr element appears twice except for one , we gotta find that single one
//for ex , nums={1,1,2,2,3} output will be 3
#include<iostream>
#include<vector>

int SingleNum(std::vector<int>& nums){
    int ans=0;
    for (int val:nums){
        ans=ans^val;
    }
    return ans;
}

int main(){
    std::vector<int> Nums={1,1,3,4,2,2,3};
    int singleNum=SingleNum(Nums);
    std::cout<<"single number in given array is :"<<singleNum;
    return 0;
}