


#include<iostream>
#include<vector>

int Merger(std::vector<int>&nums,int st , int mid , int end , std::vector<int>&temp){
    int i = st , k = st , j = mid + 1;
    int countInv = 0;
    while(i<=mid && j<=end){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
            countInv += (mid - i + 1);
        }
    }
    while(i<=mid){
        temp[k++] = nums[i++];
    }
    while(j<=end){
        temp[k++] = nums[j++];
    }

    for(int idx = st ; idx<=end;idx++){
        nums[idx] = temp[idx];
    }
return countInv;
}



int CountInversion(std::vector<int>&nums,int st , int end,std::vector<int>&temp){

    if(st<end){
        int mid = st + (end-st)/2;
        int LeftInvcount = CountInversion(nums,st,mid,temp);//left
        int RightInvCount = CountInversion(nums,mid+1,end,temp);//right
        int Invcount = Merger(nums,st,mid,end,temp);
        return (LeftInvcount + RightInvCount + Invcount);

    }
return 0;
}










int main(){
    std::vector<int> nums = {1,3,5,10,2,6,8,9};
    std::vector<int>Temp(nums.size());
    int countInv = CountInversion(nums,0,nums.size()-1 , Temp); 
        for(int val : nums){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
    std::cout<<countInv<<std::endl;
    return 0;
}