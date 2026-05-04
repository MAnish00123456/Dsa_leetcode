// given array se hume maximum product nikalna hai subarray ka, will use kadane algo
//Hum do variable lenge prefix and suffix. prefix me hum prefix subarray ka product store karenge and suffix me suffix subarray ka sum store karenge(last se values lenge).
//phir hum prefix , suffix ka max lenge and then phir hum us se maxP ke sath ka max lene ,, har iteration par. last me return karenge
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
int MaxSubPro(std::vector<int>& nums){
double prefix=1,suffix=1;
double maxP=INT_MIN;
int size=nums.size();
for(int i=0;i<size;i++){
    if(prefix==0) {prefix=1;}
    if(suffix==0) {suffix=1;}
    prefix*=nums[i];
    suffix*=nums[size-i-1];
    maxP=std::max(maxP,std::max(prefix,suffix));
}
return maxP;
}
int main(){
    std::vector<int> nums={2,3,-2,4};
    int maxProduct=MaxSubPro(nums);
    std::cout<<"Maximum product of subarray is : "<<maxProduct;
    return 0;
}