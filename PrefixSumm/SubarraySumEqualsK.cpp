//in this problem we have given an 9nteger array 'nums' and a sum value equal to 'k'(given in question) ,, Now we have to return the count of subarrays in given array whoose sum is 
//equal to our k ,, for ex nums = [1,1,1] and k equals to 2 ,, so our count of subarrays will be 2 ,


//930. Binary Subarrays With Sum , same to same question

#include <iostream>
#include <vector>
#include<unordered_map>


//Brute force approach ,, we just find all subarrays and their sum and then check if sum = k then we increase the count value]
//tbe time complexity will ve O(n^2) and space complexity will be O(1)
int BruteForcesubarraySum(std::vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count += 1;
            }
        }
    }
    return count;
}

//Optimal approach would  be using 'Prefix sum' ,, in which we will create an PrefixSum array with all values equal to 0 and size will be equal to n ,,
//We will store the prefix sum of each index value,,,  we know that SubarraySum(i,j) = PS[j] - PS[i-1] and  in our question we been given sum equal to k ,, so 
//Eq will be k = PS[j] - PS[i-1] ,, and now we know our PS[j] and k so we find PS[i-1] , lets say it as val ,, we will maintain an unordered map in which we will store our 
//PS[j] and its freq couunt.. We will check if our val exist in map , if yes then we add the frequency to our count value. If our PS[j] == k then we increment our count
int OptimalsubarraySum(std::vector<int> &nums , int k){
    // int n = nums.size();
    // std::vector<int> PrefixSum(n,0);
    // PrefixSum[0]=nums[0];
    // for(int i = 1 ; i < n ; i++){
    //     PrefixSum[i] = PrefixSum[i-1] + nums[i];
    // }
    // std::unordered_map<int,int>M;
    // int count =0;
    // for(int j=0;j<n;j++){
    //     if(PrefixSum[j] == target){
    //         count++;
    //     }
    //     int val = PrefixSum[j] - target;
    //     if(M.find(val) != M.end()){
    //         count+=M[val];
    //     }
    //     if(M.find(PrefixSum[j]) == M.end()){
    //         M[PrefixSum[j]]=0;
    //     }
    //     M[PrefixSum[j]]++;
    // }
    // return count;
    int n = nums.size();
std::vector<int> Prefixsum(n+1);
Prefixsum[0]=0;
Prefixsum[1]=nums[0];
for(int i = 2 ; i<n+1 ; i++){
    Prefixsum[i]= Prefixsum[i-1] + nums[i-1];
}
std::unordered_map<int,int>M; int count = 0;
for(int j=0;j<n;j++){
    //case 1 , if current prefixsum equals to our target
    if(Prefixsum[j+1] == k){
        count++;
    }
    //case 2 , 
    int val = Prefixsum[j+1] - k;
    if(M.find(val)!=M.end()){
        count+=M[val];
    }
    if(M.find(Prefixsum[j+1]) == M.end()){
        M[Prefixsum[j+1]] == 0;
    }
    M[Prefixsum[j+1]]++;
}
return count;
}


int main()
{
    std::vector<int> nums = {-1, -1, 1};
    int target = 0;
    int count = OptimalsubarraySum(nums, target);
    std::cout << count << std::endl;
    return 0;
}