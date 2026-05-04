//In this question we have given an integer array  nums and a non negative integer called as target , we have to search thi starget in nums and return the index if found else -1
//but the catch is this array is rotated with  k indices , For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
//The property of this kind of array  is that its either left part or right part is sorted and we need to apply binary search in that part
//we will first find which half is sorted

#include<iostream>
#include<vector>

bool isPresent(std::vector<int>&nums , int target , int & idx){
    int st=0;
    int end=nums.size()-1;
    while(st<=end){
        int mid=(st+(end-st)/2);
        if(nums[mid]==target){
            idx = mid;
            return true;
        }
        if(nums[st]<=nums[mid]){//to check if left part is sorted
            if(nums[st]<=target&&target<=nums[mid]){//if yes , then check if target belongs to left part
                end=mid-1;
            }
            else{//if not,then search in right part
                st=mid+1;
            }
        }
        else{//if right part of array is sorted
            if(nums[mid]<=target&&target<=nums[end]){//if yes, chcek iif target is available in right part
                st=mid+1;
            }
            else{// if not,search in left part
                end=mid-1;
            }
        }
    }
return false;
}


int main(){
    std::vector<int>nums = {4,5,6,7,0,1,2};
    int target = 9;
    int idx =-1;
    if(isPresent(nums,target,idx)){
        std::cout<<target <<" is present at index : "<<idx;
    }
    else{
        std::cout<<target <<" is not present in array , hence index : "<<idx;

    }
    return 0;
}