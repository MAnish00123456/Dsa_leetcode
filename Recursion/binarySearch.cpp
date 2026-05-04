#include<iostream>
#include<vector>

int binSearch(std::vector<int>&nums , int target , int st , int end){
    if(st<=end){
        int mid = st + (end-st) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] <= target){
            return binSearch(nums,target,mid+1,end);
        }
        else{
           return binSearch(nums,target,st,mid-1);
        }
    }
              return -1;
}
int search(std::vector<int>& nums, int target) {
    int st =0;
    int end = nums.size()-1;
    int idx = binSearch(nums,target,st,end);
    return idx;
}

int main(){
    std::vector<int> nums = {-1,0,3,5,9,12};
int target = 9;
int idx = search(nums,target);
std::cout<<idx;
return 0;
}