

#include<iostream>
#include<vector>

void Plusone(std::vector<int>&nums){
for(int i = nums.size()-1;i>=0;i--){
    if(nums[i] + 1 != 10){
        nums[i] += 1;
        break;
        // return nums;
    }
    nums[i]=0;
    if(i==0){
        nums.insert(nums.begin(),1);
    }
}
}

int main(){
std::vector<int> nums = {9,9};
Plusone(nums);
for(int val : nums){
    std::cout<<val<<" ";
}
return 0;
}