

#include<iostream>
#include<vector>


//TC = total calls * work done in each call
//total calls = k . on each iteration total call = 2^k , so for n times , we got n = 2^k , solve for k , k = log2n
//work done in each call = O(n) {Merge call}
//total TC = O(nlogn) , SC = O(n)

//we can do optimization by passing temp once instead of creating in each recursion call


void Merge(std::vector<int>&nums,int st , int mid , int end){
    std::vector<int>Temp;
    int i = st , j = mid+1;
    while(i<=mid && j<=end){
        if(nums[i] <= nums[j]){
            Temp.push_back(nums[i]);
            i++;
        }
        else{
            Temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid){
        Temp.push_back(nums[i]);
        i++;
    }

    while(j<=end){
        Temp.push_back(nums[j]);
        j++;
    }

    for(int idx = 0 ; idx < Temp.size() ; idx++){
        nums[idx + st] = Temp[idx];
    }
}


void MergeSort(std::vector<int>&nums, int st ,int end){

    if(st >= end){
        return ;
    }
        int mid = st + (end-st)/2;
        //for left part pf array
        MergeSort(nums,st,mid);
        //for right part of array
        MergeSort(nums,mid+1,end);

        //Merge array,(Backtrack call)
        Merge(nums,st,mid,end);
}


//optimized code

void OMerge(std::vector<int>&nums,std::vector<int>&temp,int st , int mid , int end){
        int i = st , j = mid+1 , k = st;
    while(i<=mid && j<=end){
        if(nums[i] <= nums[j]){
temp[k++] = nums[i++];
        }
        else{
temp[k++] = nums[j++];
        }
    }

    while(i<=mid){
        temp[k++] = nums[i++];
    }

    while(j<=end){
        temp[k++] = nums[j++];
    }

    for(int idx = st ; idx <=end ; idx++){
        nums[idx] = temp[idx];
    }
}
void OMergeSort(std::vector<int>&nums,std::vector<int>&temp ,int st ,int end){

    if(st >= end){
        return ;
    }
        int mid = st + (end-st)/2;
        //for left part pf array
        OMergeSort(nums,temp,st,mid);
        //for right part of array
        OMergeSort(nums,temp,mid+1,end);

        //Merge array,(Backtrack call)
        OMerge(nums,temp,st,mid,end);
}
int main(){
    std::vector<int> nums = { 12,31,35,8,32,17};
    int end = nums.size()-1;
    // MergeSort(nums,0,end);
    std::vector<int>Temp(nums.size());
    OMergeSort(nums,Temp,0,end);
    for(int val : nums){
        std::cout<<val<<" ";
    }
    return 0;
}
