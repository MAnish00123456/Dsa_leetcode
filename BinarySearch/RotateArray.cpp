

#include<iostream>
#include<vector>
#include<algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n; // preventing rotation from invalid indices ,, it helps preventing repeated rotations
    //for ex -> n = 7 , k = 10, we will get same rotation after rotating 10 times or 7%10 times , as after rotating 7 times , we get same rotated array as we had in start

    //reverse whole array first , for ex -> nums[1,2,3,4,5,6,7] , reverse = [7,6,5,4,3,2,1]
    reverse(nums.begin() , nums.end());

    //reverse first k digits , reverse = [7,6,5,4,3,2,1] , k indices reverse = [5,6,7,4,3,2,1]
    reverse(nums.begin(),nums.begin()+k);

    //reverse last n-k digits , k indices reverse = [5,6,7,4,3,2,1] , n-k indice reverse = [5,6,7,1,2,3,4] -> our resultant array
    reverse(nums.begin()+k,nums.end());
}

int main(){
    std::vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    for(int val : nums){
        std::cout<<val<<"\t";
    }
    std::cout<<"\n";
    rotate(nums,k);
    for(int val : nums){
        std::cout<<val<<"\t";
    }
    return 0;
}