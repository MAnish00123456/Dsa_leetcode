//in this question we got a sorted array nums, in which each num appears in pair of 2 but there will be only 1 single number that is not in the pair.
//Return that single element.

#include<iostream>
#include<vector>

int singleNonDuplicate(std::vector<int>& nums){
    int size=nums.size();
    int st=0,end=size-1;
    if(size==1){
        return nums[0];
    }
    while(st<end){
        int mid = st + (end-st)/2;

        if(mid==0 && nums[mid]!=nums[mid+1]){ return nums[mid];}
        if(mid==size-1 && nums[size-1]!=nums[size-2]){ return nums[mid];}
        if ( mid>0 && mid < size-1 && nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1] ) {
            return nums[mid];
        }
        if(mid%2==0){
            if(nums[mid]==nums[mid+1]){
                st=mid+2;
            }
            else{
                end=mid-2;
            }
        }
        else if(mid%2!=0){
            if(nums[mid-1]==nums[mid]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        }
    return nums[st];
    }
int main(){
    // std::vector<int> nums={1,1,2,3,3,4,4,8,8};
    std::vector<int> nums={3,3,7,7,10,11,11};
    int singleNum=singleNonDuplicate(nums);
    std::cout<<"Single element in the given sorted array is : "<<singleNum;
    return 0;
}