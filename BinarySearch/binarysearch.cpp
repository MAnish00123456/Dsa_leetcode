#include<iostream>
#include<vector>
//using normal bs
//  int binarysearch(std::vector<int> &arr,int target,int start,int end){
//     while(start<=end){
//     int mid=start+(end-start)/2;
//     if(target==arr[mid]){
//         return mid;
//     }
//     else if(target>arr[mid]){
//         start=mid+1;
//     }
//     else{
//         end=mid-1;
//     }
// }
// return -1;
//  }

//using recursive bs
// int recbinarysearch(std::vector<int> &array,int target,int start,int end){
//     int mid=start+(end-start)/2;
//     if(target>array[mid]){
//         return recbinarysearch(array,target,mid+1,end);
//     }
//     else if(target<array[mid]){
//         return recbinarysearch(array,target,start,mid-1);
//     }
//     else{
//         return mid;
//     }
//     return -1;
// }

//search an element in a rotated sorted array

int search(std::vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=(st+(end-st)/2);
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[st]<=nums[mid]){//to check if left part is sorted
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
    return -1;
    }
 int main(){
    //odd input
    // std::vector<int> array = {-1,0,3,4,5,9,12};
    //even input
    // std::vector<int> array2={-1,0,3,5,9,12};
    std::vector<int> nums{4,5,6,7,0,1,2};
    int target=0;
    int n=nums.size();
//     int result=recbinarysearch(array,target,0,n-1);
//     int result2=recbinarysearch(array2,target,0,n-1);
//     std::cout<<"the given target in odd array is found at index:"<<result<<"\n"<<std::endl;
//     std::cout<<"the given target in even array is found at index:"<<result2<<" "<<std::endl;
    int result=search(nums,target);
    std::cout<<"the target is found at index:"<<result<<std::endl;
    return 0;

 }