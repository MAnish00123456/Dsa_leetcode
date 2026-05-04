//In this problem , similar as part 1 , but here we have given duplicate values , so remove them and find min


#include<iostream>
#include<vector>
int findMin(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        // in rsa problems whenever we need to find min num, we always
        // compare our mid to high value because it is more reliable
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else if (nums[mid] < nums[high]) {
            high = mid;
        }
        // to remove duplicates , if our value at mid and value at high are
        // equal , we cant predict which part of array is sorted , so if we
        // just decrease our high pointer , we wont lose the minimum value
        // but actually can predict search space
        else {
            high--;
        }
    }
    return nums[low];
}

int main(){
    std::vector<int> nums = {2,2,2,2,0,1};
    int min = findMin(nums);
    std::cout<<"min : "<<min;
    return 0;
}