// in this given problem we have given an integer array and a integer value k , ,, we have to check if there exists a good subarray whose sum is a multiple of k 
//and size of subarray should be > 2
#include<iostream>
#include<vector>
#include<unordered_map>

//brute force approach , TC : O(n^2)
bool BcheckSubarraySum(std::vector<int>&nums , int k){
    int n = nums.size();
    for(int i = 0 ; i<n;i++){
        int sum = nums[i];
        for(int j = i+1 ; j<n ;j++){
            sum+=nums[j];
            if(sum % k == 0){
                return true;
            }
        }
    }
    return false;
}

bool OcheckSubarraySum(std::vector<int>&nums , int k){
int n = nums.size();
// std::cout<<n<<std::endl;
if(n < 2) return false;
//PrefixSum for storing cumulative sum
// std::vector<int>PS(n+1);
// PS[0]=0;
// PS[1]=nums[0];
// for(int i = 2 ;i<n+1;i++){
//     PS[i]=PS[i-1]+nums[i-1];
// }
std::unordered_map<int,int>M;
// M[0]=0;
M[0]=-1;
// for(int j =1;j<n+1;j++){

//     int val = PS[j]%k;
//     //if remainder exists in map then we will check length of subarray by subtracting current index by the remainder index from map
//     if(M.find(val) != M.end()){
//         if(j - M[val] >= 2){
//             return true;
//         }
//     }
//     //only storing the first occurenece to avoid failing valid cases
//    else{

//        M[PS[j]%k] = j;
//    }
// }
// return false;
int cumSum=0;
for(int i = 0 ; i<n ; i++){
    cumSum+=nums[i];
    int rem = cumSum%k;
    if(M.find(rem) != M.end()){
        if(i - M[rem] >= 2){
            return true;
        }
    }
    else{
        M[rem] = i;
    }
}
return false;
}

int main(){
    // std::vector<int> nums = {23,2,4,6,7};
    std::vector<int> nums = {0,1,0,3,0,4,0,4,0};
    int value = 5;
    if(OcheckSubarraySum(nums,value)){
        std::cout<<"Given array has a good subarray";
    }
    else{
        std::cout<<"Given array has no good subarray";
    }
    return 0;
}