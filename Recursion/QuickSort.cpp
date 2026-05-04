//Quick sort algorithm , based on approach pivot and partitiion , we will select a pivot as per our choice and partition our array using pivot , we will push
//elements smaller than pivot to the left of pivot and larger elements to the right , and recursively solve for each part in the same manner


#include<iostream>
#include<vector>
#include<algorithm>



//this function retuns our pivotIndex and partition our array around pivot
int partition(std::vector<int>&nums,int st , int end){
int idx = st -1;//used to partition our array , by pushing smaller values than pivot to the left of pivot
int pivot = nums[end];//we will chose last element as our pivot
//a for loop from st to end for partitioning
for(int j = st ; j<end;j++){
    if(nums[j] <= pivot){
        idx++;
        std::swap(nums[j],nums[idx]);
    }
}
idx++;
std::swap(nums[idx],nums[end]);
return idx;
}






void QuickSort(std::vector<int>&nums , int st , int end){

    if(st>=end){
        return;
    }

    int pivIdx = partition(nums,st,end);

    QuickSort(nums,st,pivIdx-1);//left half
    QuickSort(nums,pivIdx+1,end);//right half
}









int main(){
    std::vector<int> nums = {5,2,6,4,1,3};
    std::cout<<"Before sorting : "<<std::endl;
    for(int val : nums){
        std::cout<<val<<" ";
    }
    QuickSort(nums,0,nums.size()-1);
    std::cout<<"\n";
    std::cout<<"After sorting : "<<std::endl;
    for(int val : nums){
        std::cout<<val<<" ";
    }

}