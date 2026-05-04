//in this question  ,, Given a sorted array of distinct integers and a target value, return the index if the target is found. 
//If not, return the index where it would be if it were inserted in order.
#include<iostream>
#include<vector>

    int searchInsert(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid +1;//index where target could possible be inserted to maintain sorted order
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }

int main(){
    std::vector<int> nums ={1,3,5,6};
    int target = 7;
    int idx = searchInsert(nums,target);
    std::cout<<"Index or possible index where target could be found to maintain sorted order: "<<idx;
    return 0;
}