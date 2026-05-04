//Given an Array nums of size n containing all elements in range [0,n]
//Each element is unique and only 1 element is missing , find the missing number and return it
//For ex array = { 0 , 1 , 3} , size = 3 , so elements should be [0,1,2,3] but in given array 2 is missing , so we return that
#include<iostream>
#include<vector>



//1st appproach
int MissingNumber(std::vector<int>& nums){
int n = nums.size();
int Xor1 =0 , Xor2=0 , XorT=0;
for(int i = 0; i<=n; i++){
Xor1^=i;
}
for(int j = 0; j<n; j++){
Xor2^=nums[j];
}
XorT=Xor1^Xor2;
return XorT;
}

//2nd approach
int MissingNumberII(std::vector<int>& nums){
int n = nums.size();
int actualSum=0,expectedSum=0;
for(int i=0;i<=n;i++){
expectedSum+=i;
}
for(int elem:nums){
    actualSum+=elem;
}
int missingNum=expectedSum - actualSum;
return missingNum;
}

int main(){

    std::vector<int>nums = {9,6,4,2,3,5,7,0,1};
    int Missingnumber=MissingNumberII(nums);
    std::cout<<"The missing number in given array is : "<<Missingnumber<<std::endl;
    return 0;
}