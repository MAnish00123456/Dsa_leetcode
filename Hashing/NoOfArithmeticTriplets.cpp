//In this problem we have given an integer array 'nums' which is strictly increasing and we have been given an positive integer diff, we have to return the count of unique Arithmetic triplets if they follow given condition
//i<j<k and nums[j]-nums[i] == diff and nums[k]-nums[j] == diff

#include <iostream>
#include <vector>
#include<unordered_map>
//Brute force
int arithmeticTriplets(std::vector<int> &nums, int diff)
{
    int n = nums.size();
    int count = 0;
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((nums[j]-nums[i] == diff) && (nums[k] - nums[j] == diff)){
                    count+=1;
                }
            }
        }
    }
    return count;
}

//optimal
int OparithmeticTriplets(std::vector<int>&nums , int diff){
int n = nums.size();
std::unordered_map<int,int>M;
for(int i =0;i<n;i++){
    M[nums[i]]=i;
}
int count =0;
for(int j=0;j<n;j++){
    int val1 = nums[j]-diff;
    int val2 =nums[j]+diff;
    if((M.find(val1) != M.end()) && (M.find(val2) != M.end())){
        count+=1;
    }
}
return count;
}


int main()
{
    std::vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    int CountOfArithmmeticTriplets = OparithmeticTriplets(nums, diff);
    std::cout << "Number of unique Arithmetic triplets : " << CountOfArithmmeticTriplets;
    return 0;
}